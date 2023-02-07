本章介绍哈夫曼树。首先介绍两个基本概念：
* 叶子结点的带权路径长度：叶子结点的权值乘它到根结点的路径长度
* 树的带权路径长度：所有叶子结点的带权路径长度之和

给定n个数，需找一棵二叉树，使得树的所有叶子结点的权值恰好为这n个数，且树的带权路径长度最小，这样的树就是哈夫曼树。哈夫曼树可以不唯一，但是最小树的带权路径长度一定唯一

哈夫曼树的构建过程，太简单直接给代码。。。
```c++
struct node{
    int data;
    node *lc, *rc;
    // 为了方便还可以加一个father指针
    node():data(-1),lc(nullptr),rc(nullptr){}
    node(int val):data(val),lc(nullptr),rc(nullptr){}
}

struct cmp{
    bool operator()(const node*& a, const node*& b) const{
        return a->data>b->data;
    }
}

node* create(vector<int>& arr){
    priority_queue<node*, vector<node*>, cmp> pq;
    for(int& i:arr){
        pq.push(new node(i));
    }
    while(pq.size()>1){
        node *a=pq.top();pq.pop();
        node *b=pq.top();pq.pop();
        node *root=new node(a->data+b->data);
        root->lc=a;
        root->rc=b;
        pq.push(root);
    }
    return pq.front();
}
```

对于计算机中的字符，其实都是用01串来表示的。将字符转为01串叫做编码，反之称为解码。为了在解码的时候不产生歧义，每个字符的编码不应该称为其他字符编码的前缀，这叫做无前缀编码。怎么做到无前缀编码呢，我们考虑用一颗二叉树来编码，每个字符都是叶子结点，从根结点到叶子结点的唯一路径，向左为0，向右为1，路径对应的01串就是字符的编码。这样的编码一定是无前缀的，这棵二叉树就叫做编码树。如果叶子结点的权值为字符出现的频率，那么出现编码树的带权路径长度就是文本编码后的长度，我们自然希望越小越好，所以编码树应该采用哈夫曼树的形式，这样产生的编码也叫哈夫曼编码。

编码：
1. 建树
2. dfs，每到叶结点就把<字符，编码>对存到编码表里面

解码
1. 从根结点沿着编码向左向右走，每走到叶结点就输出一个字符
2. 重复1直到没有编码