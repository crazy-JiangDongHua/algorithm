二叉树的遍历分为四种：
1. 先序遍历：根结点->左子树->右子树；
2. 中序遍历：左子树->根结点->右子树；
3. 后序遍历：左子树->右子树->根结点；
4. 层次遍历：从根结点开始，从上层往下层遍历。
前三种方法一般通过递归实现，最后一种方法一般通过bfs实现。实际上，先序遍历等价于树的dfs，层次遍历等价于树的bfs。

沿用上节给出的`struct node`定义，给出四种遍历方法的实现。
### 1. 先序遍历
1. 递归写法
```c++
void preorderTravel(node* root){
    if(root==nullptr)return;
    // 处理root->data
    preorderTravel(root->lc);
    preorderTravel(root->rc);
}
```
2. 迭代写法
```c++
// 第一种 使用栈模拟递归
void preorderTravel(node* root){
    if(root==nullptr)return;
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* cur=s.top();s.pop();
        // 处理cur->data
        if(cur->rc!=nullptr)s.push(cur->rc);
        if(cur->lc!=nullptr)s.push(cur->lc);
    }
}

// 第二种 模拟先序遍历的本质————先沿着最左侧通路自顶向下访问沿途所有结点，再自底向上一次遍历这些结点的右子树
void preorderTravel(node* root){
    stack<node*> s;
    while(true){
        //从当前节点出发，沿左分支不断深入，直至没有左分支的节点；沿途节点遇到后立即访问
        while(root!=nullptr){ 
            // 处理x->data
            if(root->rc!=nullptr)s.push(root->rc); //右孩子入栈暂存        
            root=root->lc;  //沿左分支深入一层   
        }
        if(s.empty())break;
        // 转向右子树
        root=s.top();s.pop();
    }
}

// 第三种 morris遍历 每次访问完右子树，就需要回溯，第二种方法通过栈记录了回溯的位置。
// 实际上我们可以借鉴中序遍历迭代的第二种方法，每次回溯到succ()的右结点就可以。
// succ()需要借助father指针域，这里给出一个morris遍历，借助为空的右孩子指针，直接指向succ
// 两者的本质都是一样的，就是右子树为空时需要回溯，怎么找到回溯的地方就产生了不同的算法。
// morris算法有左子树的结点将被访问两次，没有左子树的结点被访问一次，寻找mostRigth需要沿着左子树的最右侧通路走两次，最多每个结点走两次，所以时间复杂度为O(4n)=O(n)
void preorderTraval(node* root){
    node* mostRight;//左子树中最右结点，右子树必然为空，需要回溯
    while(root!=nullptr){
        mostRigth=root->lc;
        if(mostRigth==nullptr){//没有左子树
            //处理root->val
            root=root->rc;//深入右子树
        }
        else{
            while(mostRigth->rigth!=nullptr && mostRigth!=root){
                mostRigth=mostRigth->rc;
            }
            if(mostRigth->rigth==nullptr){//还没有标记回溯位置
                mostRight->rc=root;
                //处理root->val
                root=root->lc;//深入左子树
            }else{ //打了标记了，说明是回溯
                mostRight->rc=nullptr;//取消标记
                root=root->rc;//深入右子树
            }
        }
    }
}
```


### 2. 中序遍历
1. 递归写法
```c++
void inorderTravel(node* root){
    if(root==nullptr)return;
    inorderTravel(root->lc);
    // 处理root->data
    inorderTravel(root->rc);
}
```
2. 迭代写法
```c++
// 第一种 中序遍历的本质————沿着最左侧通路，自底向上依次访问沿途各结点及其右子树
void inorderTravel(node* root){
    stack<node*> s;
    while(true){
        while(root!=nullptr){
            s.push(root);
            root=root->lc;
        }
        if(s.empty())break;
        root=s.top();s.pop();
        // 处理root->data
        // 转向右子树
        root=root->rc;
    }   
}

// 第二种 直接去找当前结点在中序序列中的后继结点，分两种情况
// 1. 该结点有右子树，则其直接后继必然存在，此时只需转入右子树，再沿该子树的最左侧通路朝左下方深入，直到抵达子树中最靠左〈有最小)的节点
// 2. 该结点没有右子树，则若其直接后继存在，必为该节点的某一祖先，且是将当前节点纳入其左子树的最低祖先。于是首先沿右侧通路朝堪上方上升，当不能继续前进时，再朝右上方移动一步即可。
// 此时我们假设node结构多了一个指针域father，指向其父结点
node* succ(node* x){   //定位节点v的直接后继
    if(x==nullptr)return nullptr;    
    node* s; //记录后继的临时变量    
    if(x->rc!=nullptr){ //若有右孩子，则直接后继必在右子树中，具体地就是    
        s=x->rc; //右子树中        
        while (s->lc!=nullptr)s=s->lc; //最靠左（最小）的节点    
    }    
    else{ //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
        s=x;
        while(s->father!=nullptr && s->father->rc==s) s=s->father; //逆向地沿右向分支，不断朝左上方移动        
        s=s->father; //最后再朝右上方移动一步，即抵达直接后继（如果存在）    
    }    
    return s;
}

// 以上的迭代式遍历算法都需使用辅助栈，尽管这对遍历算法的渐进时间复杂度没有实质影响，但所需辅助空间的规模将线性正比于二又树的高度，在最坏情况下与节点总数相当
// 该版本未使用任何结构，总体仅需O(1)的辅助空间，属于就地算法。当然，因需要反复调用succ()，时间效率有所倒退。相当于用succ()和回溯标志取代了栈。
void inorderTravel(node* root){
    bool backtrack=false; //前一步是否刚从右子树回溯————省去栈，仅O(1)辅助空间    
    while(true){
        if(!backtrack && root!=nullptr && root->lc!=nullptr){//若有左子树且不是刚刚回溯，则
            root=root->lc;//深入遍历左子树
        }else{//否则——无左子树或刚刚回溯（相当于无左子树）
            //处理root->data
            if(root!=nullptr && root->rc!=nullptr){//若其右子树非空，则
                root=root->rc;//深入右子树继续遍历 
                backtrack=false;//并关闭回溯标志
            }else{//若右子树空，相当于右子树遍历完了，则回溯
                if(root=succ(root)==nullptr)break;//回溯（含抵达末节点时的退出返回）
                backtrack=true;
            }
        }
    }
}

// morris
// morris算法有左子树的结点将被访问两次，没有左子树的结点被访问一次，寻找mostRigth需要沿着左子树的最右侧通路走两次，最多每个结点走两次，所以时间复杂度为O(4n)=O(n)
void inorderTravel(node* root){
    node* mostRigth=nullptr;//左子树最右结点
    while(root!=nullptr){
        mostRight=root->lc;
        if(mostRight!=nullptr){//有左子树
            while(mostRight->rc!=nullptr && mostRight->!=root)
                mostRight=mostRight->rc;//左子树最右结点
            if(mostRigth->rc!=nullptr){ //还没打标记
                mostRigth->rc=root;
                root=root->lc;
            }else{ //打了标记，说明是回溯
                //处理root->data
                root=root->rc;//深入右子树
                mostRight->right=nullptr;//取消标记
            }
        }else{//没有左子树
            // 处理root->data
            root=root->rc;//深入右子树
        }
    }
}

```

### 3. 后序遍历
1. 递归写法
```c++
void postorderTravel(node* root){
    if(root==nullptr)return;
    postorderTravel(root->lc);
    postorderTravel(root->rc);
    // 处理root->data
}
```
2. 迭代写法
```c++
// 方法1 使用栈模拟递归
void postorderTravel(node* root){
    if(root==nullptr)return;
    stack<node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        root=s1.top();s1.pop();
        s2.push(root);
        if(root->lc!=nullptr)s1.push(root->lc);
        if(root->rc!=nullptr)s1.push(root->rc);
    }
    while(!s2.empty()){
        root=s2.top();s2.pop();
        // 处理root->data
    }
}

// 方法2 后序遍历的本质：沿着最左侧通路，自底向上依次访问沿途各结点的右子树以及该结点
// 后序的回溯和先序和中序的回溯不同，先序和中序只有当前结点无右结点时回溯，而后序不仅在无右结点时回溯，还有右子树访问完了的回溯
// 所以不能简单用一个backtrack标志来表示回溯，还需要添加pre来记录回溯结点，看是不是当前结点的右孩子来判断是不是在右子树访问完的时候的回溯。
void postorderTravel(node* root){
    stack<node*> s;
    bool backtrack=false;
    node* pre=nullptr;//回溯之前的结点
    while(true){
        while(root!=nullptr){
            s.push(root);
            root=root->lc;
        }
        if(s.empty())return;
        root=s.top();
        if(root->rc!=nullptr && root->rc!=pre){//不是从右孩子回溯的，从左孩子回溯的，还是要继续遍历右子树
            root=root->rc;
        }else{
            //处理root->data
            s.pop();
            pre=root;
            root==nullptr;//表示回溯
        }
    }
}

// 还有mirros算法，太复杂了不想看了
```

### 4. 层次遍历
```c++
void layerorderTravel(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* cur=q.front();
        q.pop();
        // 处理cur->data
        if(cur->lc!=nullptr)q.push(cur->lc);
        if(cur->rc!=nullptr)q.push(cur->rc);
    }
}
```


### 5. 已知两个遍历序列，重建二叉树树。
给定中序序列，和先序序列、后序序列以及层序序列三个中的任意一个，都可以重建二叉树。后面是那个序列可以给出根结点的信息，中序序列可以根据根结点的信息分割序列，给出左右子树的信息。

但是只给定先序序列、后序序列以及层序序列中的两个，是无法重建二叉树的，因为无法区分左右子树。

1.  给定先序序列和中序序列重建二叉树
```c++
node* create(vector<int>& preSq, vector<int>& inSq, int postL, 
            int postR, int inL, int inR){
    if(inL>=inR)
        return nullptr;
    node* root = new node(preSq[preL]);
    int id;
    for(id=inL;id<inR;id++){
        if(inSq[id]==root->data)
            break;
    }
    int numLeft=id-inL;
    root->lc=create(preSq, inSq, preL+1, preL+1+numLeft, inL, id);
    root->rc=create(preSq, inSq, preL+1+numLeft, preR, id+1, inR);
    return root;
}
```

2. 给定后序序列和中序序列重建二叉树
```c++
node* create(vector<int>& postSq, vector<int>& inSq, int postL, 
            int postR, int inL, int inR){
    if(inL>=inR)
        return nullptr;
    node* root = new node(postSq[postR-1]);
    int id;
    for(id=inL;id<inR;id++){
        if(inSq[id]==root->data)
            break;
    }
    int numLeft=id-inL;
    root->lc=create(postSq, inSq, postL, preL+numLeft, inL, id);
    root->rc=create(postSq, inSq, postL+1+numLeft, preR-1, id+1, inR);
    return root;
}
```

3. 给定层序序列和中序序列重建二叉树
```c++
node* create(vector<int>& layerSq, vector<int>& inSq, int layerL, 
            int layerR, int inL, int inR){
    if(inL>=inR)
        return nullptr;
    int i,j;bool f=false;
    for(i=layerL;i<laterR;i++){//从低层到高层，低层是高层的根结点，首先命中的就是当前中序序列的根结点
        for(j=inL;j<inR;j++){
            if(insq[j]==layerSq[i]){
                f=true;break
            }
        }
        if(f)break;
    }
    node* root = new node(inSq[j]);
    root->lc=create(layerSq, inSq, i+1, layerR, inL, j);
    root->rc=create(layerSq, inSq, i+1, layerR, j+1, inR);
    return root;
}
```

### 6. 静态链表
就是把指针域变数组index了，判空条件从`nullptr`变成`-1`。

### 7. 镜像树的遍历
把左右子树的遍历顺序换一下就行


练习：
1. leetcode 144 二叉树的先序遍历。
2. leetcode 145 二叉树的后序遍历。
3. leetcode 94 二叉树的中序遍历。
4. leetcode 102 二叉树的层序遍历。
5. leetcode 107 二叉树的层序遍历2：层序遍历的结果反过来就行了。
6. leetcode 103 二叉树的锯齿形层次遍历：普通层次遍历加一个`bool`变量，表示该层是否反转。
7. leetocde 99 恢复二叉树：交换两个数会导致中序序列出现两个逆序对，边中序遍历边找到他们就可以。
8. leetcode 100 相同的树：选一种遍历依次对比元素是否一样，dfs或者bfs都可以，注意nullptr也要比较，因为结构也要相同。
9. leetcode 101 对称树：思路和上一题差不多，dfs或者bfs都可以。
10. leetcode 110 平衡二叉树: 后序遍历记录树的高度，用全局遍历记录结果，也可以通过返回不会出现的高度表示不平衡。
11. leetcode 114 二叉树展开为链表：先序遍历，边遍历边串起来，需要用栈保存丢失的右结点信息。也利用morris的思想，直接找把左子树的最右结点和右结点串起来，利用空的指针域保存右结点信息。
12. leetcode 116 填充每个结点的下一个右侧指针: 可以只用层次遍历，也可以利用上一层建好的next指针来建立下一层的next指针。
13. leetcode 117 填充每个结点的下一个右侧指针: 可以使用层次比那里，也可以利用上一层建好的next指针来建立下一侧个的next指针。因为不一定是满二叉树，所以需要把下一层的节点看作待串的链表，以此保留上一个结点的信息。
14. leetcode 105 从前序序列和中序序列构建二叉树。
15. leetcode 106 从中序与后序遍历序列构造二叉树.
16. leetcode 889 根据前序和后序遍历构造二叉树：这题有多个答案，因为如果只有一个子树的话，根据前序和后序是分不清是左子树还是右子树的。采用和前两题一样的递归思路，任选一个答案就行。