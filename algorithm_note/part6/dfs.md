深度优先搜索

1. 01背包

```c++
int n, cap, maxValue = 0;//物品数量，背包容量，最大价值
int w[maxn], v[maxn];//物品重量和价值

void dfs(int index, int sumW, int sumV)
{
    if(index == n)
        return;
    dfs(index+1, sumW, sumV); //不选index
    if(sumW + w[index] <= cap)
    {// 剪枝
        if(sumV + v[index] > maxValue)
            maxValue = sumV + v[index];
        dfs(index + 1, sumW+w[index], sumV+v[index]);
    }
}
```

2. 枚举N个整数中选择K个数，使他的和为X，并且给出平方和最大的那个

```c++
//arr中N个整数，选K个数，使他的和为X，并且给出平方和最大的那个
int N, K, X, maxSumSqu = -1, arr[maxn] = {0};
//标记为，最大
vector<int> temp, ans;
void dfs(int index, int nowK, int sum, int sumsqu)
{
    if(nowK==K && sum==X)
    {
        if(sumsqu >= maxSumSqu){
            maxSumSqu = sumsqu;
            ans = temp;
        }
        return;
    }
    if(index==N || nowK>K || sum>X)
        return;
    temp.push_back(arr[index]);
    //取index表示可以重复选，index+1表示不可以重复选
    dfs(index, nowK+1, sum+arr[index], sumsqu+arr[index]*arr[index]);
    temp.pop_back();
    //不选index
    dfs(index+1, nowK, sum, sumsqu)
}
```

3. 模板

```c++
void dfs()
{
    node top;
    stack s;
    s.push(top);
    while(!s.empty())
    {
        node temp = s.pop();
        process temp;
        for node n in  temp.neighbors:
        	s.push(n);
    }
}
```

练习：
1. leetcode 131 分割回文串:用dfs遍历所有的分割方式，注意写法,**此写法是遍历字符串的子串组合的模版**。对于判断`i~j`的子串是否为回文串，我们可以使用dp提前计算或者记忆话搜索存储，避免重复计算。
    ```c++
    void dfs(int i, int n, vector<string>& ans, string& s){
        if(i==n){
            // 处理ans
            return
        }
        for(int j=i;j<n;j++){
            ans.push_back(s.substr(i,j-i+1));
            dfs(j+1, n, ans, s);
            ans.pop_back();
        }
    }
    ```
2. leetcode 62 不同路径：直接用dfs会超时，要配上记忆化搜索，所以也可以用dp。最快的方法是用排列组合方法。
3. leetcode 63 不同路径2: 改一下递推公式，有石头的位置路径数量一定为0。也可以用dp做。
4. leetcode 51&52 : 八皇后问题，经典深搜，因为行肯定不同，所以相当于深搜列的排列。可以用哈希表加速冲突判定。
5. leetcode 93 复原IP地址：可以使用leetcode131的模版，遍历字符串的子串组合，同样也可以使用记忆话搜索来加速。还有一个小技巧就是ip地址要小于256，所以只需要尝试3位以内的子串。时间复杂度为$O(n*3^\text{levelCount})$，因为IP地址只有四段，所以最多只有四层，即$\text{levelCount}=4$。
6. leetcode 39 组合总和: 如前述例题。
7. leetcode 40 组合总和2: 当候选数组有重复元素，为了避免答案重复，我们记录候选数组中每个数出现的次数，然后在遍历时，遍历每个数可能出现的次数。一种可行的剪枝方法是，先取大的数，这样后面的数一取就超过了target，就剪枝了。**需要把此题和有重复元素的全排列对比，这两题分别给出了排列(A)和组合(C)，在候选数组有重复元素时，怎么样避免重复**。
8. leetcode 22 括号生成: 遍历2n个位置，通过任何时候右括号数量小于左括号数量来剪枝。
9. leetcode 79 单词搜索：遍历所有格子，开始深搜，利用当前位置字符和待匹配字符是否相等剪枝，给字符乘-1表示被访问，节省空间。
10. leetcode 37 解数独：从行的角度去遍历，通过三个数组作为hash表，来迅速判断当前位置的取值是否合法。可以使用位运算来代替hash表，同时也可能存在某些位置只能填固定的数，那么可以通过预处理先填上，减少时间复杂度。

需要注意要求所有可行解=和一个可行解的dfs模版：
```c++
// 求所有解
void dfs(){
    if("满足停止条件"){
        // 记录ans
        res.push_back(ans);
        return;
    }
    for(“所有可能分支”){
        dfs();
    }
}

// 求一个解
bool dfs(){
    if("满足停止条件"){
        // 处理ans;
        return true;
    }
    for(“所有可能分支”)
        if(dfs())
            return true;// 因为只要一个解，所以找到后直接返回，不用再去处理其他分支
    return false;
}
```