1. 普通树结点
```c++
struct node{
    int data;
    vector<node*> childs;
}
```

2. 树的先序遍历
```c++
void preorderTravel(node* root){
    // 处理root->val
    for(node*& child:root->childs)
        preorderTravel(child);
}
```

3. 树的层序遍历
```c++
void layerorderTravel(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* root=q.front();
        q.pop();
        // 处理root->val
        for(node*& child:root->childs)
            q.push(child);
    }
}
```