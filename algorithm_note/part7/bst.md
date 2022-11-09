本节来讲二叉搜索树，这在实际生活中用的是真滴多，哪个操作系统不用红黑树，哪个数据库不用B树，如果面试的时候，直接给面试官手写一棵红黑树，这震惊程度不亚于保研面试给老师手推SVM，很硬核，但是也很重要。但是机试一般不会太难，使用avl树一般就能过了，所以这一给出avl树的实现，其他的大家可以根据需要自行学习。

### 1. 二叉搜索树的定义
* 要么二叉搜索树是一棵空树
* 要么二叉搜索树由根结点，左子树和右子树组成，其中左子树和右子树都是二叉搜索树，且左子树全部结点的数据域小于根结点，右子树全部结点的数据域大于根结点。

### 2. 二叉搜索树的基本操作
* 查找
    ```c++
    // 如果找到，返回该结点的指针
    // 如果没找到，返回的也是父结点对应该插入位置的引用，方便insert复用search接口
    node*& search(node*& root, int val){
        if(root==nullptr)return root;
        else if(root->val==val)return root;
        else if(root->val<val){
            search(root->rc, hot, val);
        }else{
            search(root->lc, hot, val);
        }
    }
    ```

* 插入
    ```c++
    // 如果已经存在，就返回现有结点指针
    // 如果不存在，就返回插入结点指针

    // 实现1，按照编程规范，复用search接口
    node* insert(node* root, int val){
        node*& x=search(root, hot, val);
        if(x!=nullptr)//已经存在
            return x;
        else{
            return x=new node(val);
        }
    }

    // 实现2 利用引用插入
    node* insert(node*& root, int val){
        if(root==nullptr){ //空树
            return root=new node(val);
        }
        else if(root->val==val){ //存在
            return root;
        }
        else if(root->val<val){
            return insert(root->rc, val);
        }else{
            return insert(root->lc, val);
        }
    }
    ```

* 建立
    ```c++
    // 一直插入就可以了
    node* create(vector<int>& data){
        node* root=nullptr;
        for(int& val:data){
            insert(root, val);
        }
        return root;
    }
    ```

* 删除
    ```c++
    // 删除可以通过寻找待删除元素的前继或后继，交换元素
    // 然后一直递归知道前继或后继没有左右孩子。
    // 成功删除返回true, 失败返回false

    // 实现1 复用serach接口
    bool remove(node* root, int val){
        node* res=search(root, val);
        if(res==nullptr)
            return false;
        else{
            if(res->lc==nullptr && res->rc==nullptr){//没有左右子树
                delete res；
                return true;
            }else if(res->lc!=nullptr){//有左子树
                node*pre=res->lc;
                while(pre->rc!=nullptr)
                    pre=pre->rc;//寻找前继
                res->val=pre->val;//用前继覆盖res
                return remove(res->lc, pre->val);//在左子树中删除pre
            }else{//有右子树
                node*next=root->rc;
                while(next->lc!=nullptr)
                    next=next->lc;
                root->val=next->val;
                return remove(root->rc, next->val);
            }
        }
    }

    //实现2 边搜索边删除
    bool delete(node* root, int val){
        if(root==nullptr)return false;
        else if(root->val==val){
            if(root->lc==nullptr && root->rc==nullptr){//没有左右子树
                delete root；
                return true;
            }else if(root->lc!=nullptr){//有左子树
                node*pre=root->lc;
                while(pre->rc!=nullptr)
                    pre=pre->rc;//寻找前继
                root->val=pre->val;//用前继覆盖res
                return remove(root->lc, pre->val);//在左子树中删除pre
            }else{//有右子树
                node*next=root->rc;
                while(next->lc!=nullptr)
                    next=next->lc;
                root->val=next->val;
                return remove(root->rc, next->val);
            }
        }
        else if(root->val<val){
            return remove(root->rc, val);//深入右子树继续搜索
        }
        else{
            return remove(root->lc, val);//深入左子树继续搜索
        }
    }
    ```

上述函数其实还可以优化：
* 如果一个结点只有一个子树，那么可以直接用子树替代他，但是需要在`node`结构中增加父结点指针。
* 其实找到前驱或者后继以后，可以不用再递归删除。以前驱为例，其必然没有右子树，所以直接用左孩子替换他的位置就好。这需要在`node`增加父结点指针。没有父结点只能递归到前驱或者后继左右子树都为空才能删除。
* 一直删除前驱或者后继会导致左右子树的高度很不平衡，最坏情况就是退化成一条链。有两种解决方案：
    1. 交替删除前驱和后继
    2. `node`增加高度域，记录子树高度，选择高的那一边删除。

### 3. avl树
二叉搜索树有着一个巨大的缺陷，就是在最坏情况下，树退化成一条链，那么增删改查的时间复杂度为$O(n)$，完全没有体现树形结构的优势。

我们希望最坏情况下，增删改查的时间复杂度为$O(\log n)$，因此平衡二叉搜索树（BBST）就呼之欲出了。首先介绍最简单的AVL树。

avl树高度上界限证明：最坏情况下，应该是每个结点的平衡因子都为1或者都为-1，这样树是最不平衡的。假设高度为$h$的avl树结点数目为$n(h)$，那么有递推公式$n(h)=n(h-1)+n(h-2)+1$，边界条件为$n(0)=1,n(1)=2$。插入介绍一下斐波那契数：递推公式为$F(n)=F(n-1)+F(n-2)$，边界条件为$F(0)=0，F(1)=1$的数列，其通向公式为
$$
F(n)=\frac{1}{\sqrt{5}}({(\frac{1+\sqrt{5}}{2})}^{n}-{(\frac{1-\sqrt{5}}{2})}^{n})
$$
通过斐波那契数转化一下有$n(h)+1=(n(h-1)+1)+(n(h-2)+1)$，又有$n(0)+1=F(3), n(1)+1=F(4)$，所以可知
$$
n(h)=F(h+3)-1=\frac{1}{\sqrt{5}}({(\frac{1+\sqrt{5}}{2})}^{h+3}-{(\frac{1-\sqrt{5}}{2})}^{h+3})-1>\frac{1}{\sqrt{5}}{(\frac{1+\sqrt{5}}{2})}^{h+3}-2
$$

所以有$h < \log_{\frac{1+\sqrt{5}}{2}}(\sqrt{5}(n(h)+2))-3$，换算一下就是$h<1.44\log_{2}(n+2)-1.32$

也可以直接写成3*3矩阵连乘的形式，求出3个特征值把底数矩阵对角化了，直接就导出通项公式，非常暴力。

1. AVL树的定义
AVL树仍然是一棵二叉搜索树，但是加了平衡要求————左右子树高度之差的绝对值不超过1。其中左子树的高度与右子树的高度之差称为该点的平衡因子。因此我们定义新的node结构，包含了`height`和`parent`(`parent`域不是必须的，但是有会方便很多，不然就只能慢慢递归)，根结点的`parent`为`nullptr`
```c++
struct node{
    int data;
    int height;
    node *lc, *rc, *parent;
    node():data(-1),height(0),lc(nullptr),rc(nullptr),parent(nullptr){}
    node(typename val):data(val),,height(0),lc(nullptr),rc(nullptr),parent(nullptr){}
    node(typename val, node* p):data(val),height(0),lc(nullptr),rc(nullptr),parent(p){}
}
```

同时定义更新高度的函数`updateHeight(node* x)`函数，用来更新`x`的高度
```c++
void updateHeight(node* x){
    if(x==nullptr)return;
    int lh=x->lc!=nullptr?x->lc->height:-1;
    int rh=x->rc!=nullptr?x->rc->height:-1;
    x.height=max(lh,rh)+1;
}
```

定义获取结点平衡因子的函数`getBalanceFactor(node* x)`
```c++
int getBalanceFactor(node* x){
    if(x==nullptr)return 0;//空结点算平衡
    int lh=x->lc!=nullptr?x->lc->height:-1;
    int rh=x->rc!=nullptr?x->rc->height:-1;
    return lh-rh;
}
```

定义判断结点是否平衡的函数`isBalance(node* x)`函数，用来查看`x`是否平衡
```c++
bool isBalance(node* x){
    return abs(getBalanceFactor(x))<2;
}
```

2. AVL树的操作
* 查找
    ```c++
    //因为添加了父结点，所以传入一个hot参数一直保持为结果的父结点
    //如果为空树，父结点为nullptr，满足语意
    node*& search(node*& root, node*& hot, int val){
        if(root==nullptr)return root;
        else if(root->data==val)return root;
        else if(root->data<val){
            hot=root;
            return search(root->rc, hot, val);
        }else{
            hot=root;
            return search(root->lc, hot, val);
        }
    }
    ```
* 插入
    插入可能会导致失衡。
    1. 首先要明白的是，**插入只能让从插入结点到root的路径上的结点失衡。**
    2. 其次，该路径上的第一个失衡结点的平衡因子为2或者-2，因为只插入一个结点，最多只能改变一个单位的树高。
    3. 失衡结点必然是插入结点的祖父结点或更往上结点，因为插入结点和插入结点的父结点不可能失衡，如果没有祖父结点，则不会失衡。
    4. （此段可以参考P324图9-31）失衡的情况分为四种，LL,LR,RL,RR。以LL为例子，设第一个失衡结点为为`g(grandfather)`，**其左子树高度比右子树高2**，说明结点插入在左子树中，**原来`g`的平衡因子为1**。设`g`的左孩子为`f(father)`，右子树为`t0`。
        再来分析`f`，设`f`的左孩子为`v`，右子树为`t1`。设`v`的左子树为`t3`，右子树为`t2`。**`f`的平衡因子为1**（LL，-1为LR，不可能为0，因为插入后`f`的平衡因子为0，要么原来为1，在右子树插入；要么原来为-1，在左子树插入；要么原来为0，在任意子树插入。这三种情况都不会改变`f`的高度，那这样`g`的平衡因子也就不会变了，与假设不符）。
        
        **这说明原本`f`的平衡因子为0**（不可能为-1，因为插入一个结点最多增加一个高度使得平衡因子为0或-2；也不可能为1，如果是这样就不会改变`f`的高度，那这样`g`的平衡因子也就不会变了），左右子树高度一致。然后在左子树插入一个结点后，导致平衡因子变成1。设`f`的左孩子为`v`，右子树为`t1`。那么可以知道`height(t1)=height(t0)`。
        
        再来分析`v`，**`v`现在的平衡因子为1或-1**，同理不可能为0，因为那样`v`高度不变，不会导致`f`的平衡因子从0变为-1。同理，**`v`之前的平衡因子为0。**由此我们可以得出`height(t3)=height(t2)=height(t1)-1=height(t0)-1`。因为在`t2`或`t3`中插入了一个结点，导致'g'失衡。
    
    5. 失衡的调整：通过左旋和右旋。对于不同形式插入导致的不平衡对应的调整如下：
        * LL:对`g`右旋
        * LR:先对`f`左旋，在对`g`右旋
        * RR:对`g`左旋
        * RL:先对`f`右旋，在对`g`左旋
        旋转定义如下：
        ```c++
        void L(node* root){
            node* x=root->rc;
            node* p=root->parent;
            root->rc=x->lc;
            x->lc->parent=root;
            x->lc=root;
            root->parent=x;
            x->parent=p;
            if(p!=nullptr){
                Node*& fromp2root=p->lc==root?p->lc:p->rc;
                formp2root=x;
            }
            updateHeight(root);
            updateHeight(x);
        }

        // 右旋就是把左旋里面所有的左右换一下就可以了
        void R(node* root){
            node* x=root->lc;
            node* p=root->parent;
            root->lc=x->rc;
            x->rc->parent=root;
            x->rc=root;
            root->parent=x;
            x->parent=p;
            if(p!=nullptr){
                Node*& fromp2root=p->lc==root?p->lc:p->rc;
                formp2root=x;
            }
            updateHeight(root);
            updateHeight(x);
        }
        ```
    6. 上述4种复杂的操作最终可以转化为3+4重构，假设提到的`g`,`f`,`v`三个结点，`t0`,`t1`,`t2`,`t3`四个子树的根结点（可能为空），在中序序列下的顺序（从左到右）是`a`,`b`,`c`和`t0`,`t1`,`t2`,`t3`，那么我们需要做的操作就是令`t0`,`t1`作为`a`的左右子树，`t2`,`t3`作为`c`的左右子树，`a`,`b`作为`c`的左右孩子，就可以了。
        ```c++
        node* connect34(node* a, node* b, node* c, node* t0, node* t1, node* t2, node* t3){
            b->lc=a;b->rc=c;
            a->parent=b;c->parent=b;
            a->lc=t0;a->rc=t1;
            if(t0!=nullptr)t0->parent=a;
            if(t1!=nullptr)t1->parent=a;
            c->lc=t2;c->rc=t3;
            if(t2!=nullptr)t2->parent=c;
            if(t3!=nullptr)t3->parent=c;
            updateHeight(a);
            updateHeight(b);
            updateHeight(c);
            return b;
        }
        ```
    7. 经过调整以后，**原本`g`为根结点的子树高度复原**，因此更上的祖先结点不会再失衡，因此插入结点后最多只需要一次调整，因此插入花费$O(\log n)$时间，调整花费$O(1)$时间。插入函数定义如下：
        ```c++
        // 有parent指针的结点可以沿着parent指针一路往上找失衡结点。
        // 没有parent指针的结点只能通过递归的方式来隐式保存父结点信息。
        
        // 第一种采用旋转的方式调整，同时假设node没有parent域，通过递归实现，旋转函数中的有关parent的操作可以直接忽略
        node* insert(node*& root, int val){
            if(root==nullptr)return new node(val);
            else if(root->data==val)return root;
            else if(root->data<val){
                node* x=insert(root->right, val);
                updateHeight(root);
                if(!getBalance(root)){
                    if(getBalanceFactor(root->rc)==1){//RL
                        L(root->rc);
                        R(root)
                    }
                    else if(getBalanceFactor(root->rc)==-1)//RR
                        L(root);
                    else//不可能
                        throw error;
                }
                return x;
            }else{
                node* x=insert(root->left, val);
                updateHeight(root);
                if(!getBalance(root)){
                    if(getBalanceFactor(root->lc)==1)// LL
                        R(root);
                    else if(getBalanceFactor(root->lc)==-1){//LR
                        L(root->lc);
                        R(root);
                    }
                    else //不可能
                        throw error;
                }
                return x;
            }
        }

        // 上面的程序其实可以再优化，因为最多只有一次调整，经过调整后，子树高度复原，更上层的节点无需再更新高度。因此可以添加一个bool参数或者全局bool变量，表示是否调整过，如果调整过或本来就存在，则可直接返回，无需更新高度和判断失衡

        // 第二种采用3+4重构的方式调整，同时假设node有parent域，通过迭代实现，复用search接口
        node* insert(node* root, int val){
            node* hot=nullptr;
            node*& x=search(root, hot, val);
            if(x!=nullptr)return x;
            x=new node(val, hot);
            node *g=x;
            while(g!=nullptr){
                node* p=g->parent;
                if(!isBalance(g)){
                    if(getBalanceFactor(g)==2){//L
                        if(getBalanceFactor(g->lc)==1){//LL
                            node *f=g->lc, *v=f->lc;
                            root=connect34(v, f, g, v->lc, v->rc, f->rc, g->rc);
                        }else if(getBalanceFactor(g)==-1){//LR
                            node *f=g->lc, *v=f->rc;
                            root=connect34(f, v, g, f->lc, v->lc, v->rc, g->rc);
                        }else
                            throw error;
                    }else if(getBalanceFactor(g)==-2){//R
                        if(getBalanceFactor(g->lc)==1){//RL
                            node *f=g->rc, *v=f->lc;
                            root=connect34(g, v, f, g->lc, v->lc, v->rc, f->rc);
                        }else if(getBalanceFactor(g)==-1){//RR
                            node *f=g->rc, *v=f->rc;
                            root=connect34(g, f, v, g->lc, f->lc, v->lc, v->rc);
                        }else
                            throw error;
                    }else
                        throw error;
                    
                    root->parent=p; 
                    if(p!=nullptr)
                        (p->lc==g?p->lc:p->rc)=root;
                    break; //调整完之后子树高度复原，不需要在往上更新高度了
                }else{
                    updateHeight(g);
                    g=p;
                }
            }
            return x;
        }
        ```
    8. 插入有可能导致祖父结点及以上所有祖先结点失衡，但是只需要做出一次调整

* 删除
    
    删除也可能导致失衡.
    1. 失衡结点的平衡因子为2或者-2，因为只删除一个结点，最多只能改变一个单位的树高。
    2. 失衡结点必然是删除结点的**父结点**，不会导致再往上的祖先结点的失衡，因为父结点失衡不会影响父结点的高度。
    3. 失衡也分为四种情况LL,LR,RR,RL。以LL和LR为例。（可参考邓俊辉ppt）
        * LL:设失衡结点`g`，删除前平衡因子为1，删除后平衡因子为2。设左孩子为`f`，右子树为`t0`，`t0`被删除一个结点导致高度-1。`f`删除前后平衡因子不变，可以为1或者0。假设左孩子为`v`，右子树为`t1`。假设`v`的左右子树分别为`t3`和`t2`，`v`的平衡因子任意。这种情况只需要对`g`做右旋，如果`f`平衡因子为1，则旋转后子树高-1，如果为0，则旋转后子树高不变。
        * LR:设失衡结点`g`，删除前平衡因子为1，删除后平衡因子为2。设左孩子为`f`，右子树为`t0`，`t0`被删除一个结点导致高度-1。`f`删除前后平衡因子不变，为-1。假设左子树为`t3`，右孩子为`v`。假设`v`的左右子树分别为`t2`和`t1`，`v`的平衡因子任意。这种情况需要先对`f`左旋，然后对`g`做右旋，旋转后子树高-1。
    4. 四种情况的调整方式和前述是一样的，只是LR和RL调整过后子树高度必然-1，LL和LR经过调整后子树高度可能-1。
    4. 经过调整后，子树高度可能发生变化，所以再往上的祖父结点又可能失衡，所以需要不断往上，查看结点失衡情况，最多调整$O(\log n)$次。查找也是需要花费$O(\log n)$时间。

    ```c++
    bool remove(node* root, int val){
        node* hot=nullptr;
        node* x=search(root, hot, val);
        if(x==nullptr)return false;
        if(x->lc==nullptr && x->rc==nullptr){//叶子结点
            if(hot!=nullptr)
                hot->lc==x?hot->lc:hot->rc=nullptr;
            delete x;
        }
        else if(x->lc==nullptr){//没有左子树，有右子树
            x->rc->parent=hot;
            if(hot!=nullptr)
                hot->lc==x?hot->lc:hot->rc=x->rc;
            delete x;
        }
        else if(x->rc==nullptr){//没有右子树，有左子树
            x->lc->parent=hot;
            if(hot!=nullptr)
                hot->lc==x?hot->lc:hot->rc=x->lc;
            delete x;
        }
        else{//既有右子树又有左子树
            node* next=x->rc;//后继结点
            while(next->lc!=nullptr)
                next=next->lc;
            x->data=next->data;
            hot=next->parent;
            if(next->rc!=nullptr)
                next->rc->parent=hot;
            if(hot!=nullptr)
                hot==x?hot->rc:hot->lc=x->rc;
            delete next;
        }

        // 调整重平衡 O(logn)
        while(hot!=nullptr){
            Node *p=hot->parent;
            if(!isBalance(hot)){
                if(getBalanceFactor(hot)==2){//L
                    if(getBalanceFactor(hot)>=0){//LL
                        node *f=hot->lc,*v=f->lc;
                        root=connect34(v,f,hot,v->lc,v->rc,f->rc,hot->rc);
                    }else{//LR
                        node *f=hot->lc,*v=f->rc;
                        root=connect34(f,v,hot,f->lc,v->lc,v->rc,hot->rc);
                    }
                }else if(getBalanceFactor(hot)==-2){//R
                    if(getBalanceFactor(hot)<=0){//RR
                        node *f=hot->rc,*v=f->rc;
                        root=connect34(hot,f,v,hot->lc,f->lc,v->lc,v->rc);
                    }else{//RL
                        node *f=hot->rc,*v=f->lc;
                        root=connect34(hot,v,f,hot->lc,v->lc,v->rc,f->rc);
                    }
                }else
                    throw error;
                root->parent=p;
                if(p!=nullptr)
                    (p->lc==hot?p->lc:p->rc)=root;
            }else
                updateHeight(hot);
            hot=p;
        }
        return true;
    }
    ```

* 建立
    和bst一样，不停插入结点就可以了。



### 4. 红黑树
avl的缺点在于删除可能需要调整$\log n$次，红黑树可以克服这个问题，插入删除都最多只需要调整1次。

因为红黑树比较复杂，面试中考到的几率不大，现在也还没用到，所以先留着，以后有时间就学。


练习：
1. leetocde 96 不同的二叉搜索树：首先认识到一点，以`i`为根结点的BST，其左子树由元素`[1,i)`构成，右子树由元素`(i,n]`构成。使用动态规划，定义`dp[i]`表示由`i`个元素能构成的子树的种类，那么可知递归边界`dp[0]=1`，`dp[1]=1`，因为空树只有一种，一个结点的树也只有一种。一个树确定根结点后，其可能的种类就是左子树的种类乘上右子树的种类，所以可知递归方程$dp[i]=\sum_{k=1}^{i} dp[k-1]\times dp[i-k]$
2. leetcode 95 不同的二叉搜索树2：模拟上一题的思路，使用递归求解，也可以转为dp求解，共用子树的内存，因为子树不需要指定父结点，所以可以是很多结点的孩子。
3. leetcode 98 验证二叉搜索树：利用递归，保证左子树元素都小于根结点，右子树元素都大于根结点，递归函数传递上下界参数。也可以用中序遍历模拟，如果有逆序对就不是。
4. leetcode 108 将有序数组转换为二叉搜索树: 二分法，中点去中间偏左偏右都可以
5. leetcode 109 将有序链表转换为二叉搜索树：如果采用与前一题想动的思路，因为链表不可以在$O(1)$的时间找到终点，所以时间复杂度将由$O(n)$变为$O(n\log n)$。因此我们改变思路，可以先不去确定中点的位置，先去生成左子树，然后head指针自然走到中点，我们就可以在$O(1)$的时间找到中点再复制中点的值。这其实是一种自底向上的思路。