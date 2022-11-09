这一节复习字符串匹配。字符串匹配指的是，给定两个字符串`text`（文本串）和`pattern`（模式串），需要判断`pattern`是否为`text`的子串。

最简单的思路就是暴力，枚举`text`的起始位置，然后逐位与`pattern`比较。这种算法事件复杂度为$O(mn)$，`m`和`n`分别指`text`和`pattern`的长度。这种时间复杂度是不可能承受的，下面介绍kmp算法，只需要$O(m+n)$的时间复杂度。

首先介绍`next`数组，`next[i]`表示子串`s[0-i]`的前缀`s[0~k]`等于后缀`s[i-k~i]`的最大的`k`，前缀后缀可以部分重叠，但是不能是`s[i]`本身。`next`数组的求法如下。
1. 初始化`next`数组，令`j=next[0]=-1`
2. 让`i`在`[1～len-1]`遍历，执行34，求解`next[i]`
3. 不断令`j=next[j]`，直到`j`回退为-1，或者是`s[i]==s[j+1]`成立。
4. 如果`s[i]==s[j+1]`，则`next[i]=j+1`。否则`next[i]=j`。
```c++
void getNext(string& s, vector<int>& next){
    int j=-1;
    next[0]=j;
    for(int i=1;i<s.length();i++){
        while(j!=-1 && s[j+1]!=s[i])
            j=next[j];
        if(s[j+1]==s[i])
            j++;
        next[i]=j;
    }
}
```

接下来介绍kmp算法，有了`next`数组的铺垫后，kmp算法就非常简单了，思路就是每次失配时，利用之前已经匹配的前缀，不必重头匹配，而是从最长的和后缀相同的前缀处开始匹配：
1. 初始化`j=-1`，表示`pattern`被匹配的最后一位
2. 初始化`i=0`，表示`text`待匹配的比较位
3. 让`i`不断遍历`text`的每一个位置，执行45来试图匹配`text[i]`和`pattern[j+1]`
4. 不断令`j=next[j]`，直到`j`退回-1，或者`text[i]==pattern[j+1]`
5. 如果`text[i]==pattern[j+1]`，则令`j++`。如果`j`达到`n-1`，则匹配成功。
```c++
// 判断pattern是否为text子串
bool kmp(string& text, string& pattern){
    int m=text.length(), n=pattern.length();
    vector<int> next(n, 0);
    getNext(pattern, next);
    int j=-1;
    for(int i=0;i<m;i++){
        while(j!=-1 && text[i]!=pattern[j+1])
            j=next[j];
        if(text[i]==pattern[j+1])
            j++;
        if(j==n-1)
            return true;
    }
    return false;
}

// 统计pattern在text中出现位置和次数
vector<int> kmp(string& text, string& pattern){
    int m=text.length(), n=pattern.length();
    vector<int> next(n+1, 0);
    getNext(pattern, next);
    vector<int> ans;
    int j=-1;
    for(int i=0;i<m;i++){
        while(j!=-1 && text[i]!=pattern[j+1])
            j=next[j];
        if(text[i]==pattern[j+1])
            j++;
        if(j==n-1){
            ans.push_back(i-n+1);
            j=next[j];
        }
    }
    return ans;
}
```

然后来分析一下kmp算法的时间复杂度，首先看`i`，`i`只在`for`循环中变化，因此时间复杂度为$O(m)$。接下来考虑`j`的变化，`j`初始为-1，for循环中每次最多+1，所以while循环中减法最多执行m次，否则小于-1，所以时间复杂度也是$O(m)$。求`next`数组所需要的时间为$O(n)$，分析方法类似。综上可得kmp算法的时间复杂度为$O(m+n)$。

但是任然有优化的空间。看一个例子：`text="ababacab"`，`pattern=ababab`，当`i=5`和`j=4`时失配，那么应该执行`j=next[j]=next[4]=2`，然后我们比较`text[i]=text[5]='c'`和`pattern[j+1]=pattern[3]='b`，fuck，又失配了，又得执行`j=next[j]`。但是这里我们可以看出一点端倪，`pattern[3]==pattern[5]=='b'`，那`pattern[5]`失配了，`pattern[3]`肯定失配啊，所以这种移动是没有意义的，我们在求`next`数组的时候，应该加上一个限制条件，即`s[j+1]!=s[i+1]`。假设新的`next`数组为`nextval`，表示子串`s[0-i]`失配时，`i`应该退回的最佳位置。
```c++
void getNextVal(string& s, vector<int>& nextval){
    int j=-1;
    nextval[0]=-1;
    for(int i=1;i<s.length();i++){
        while(j!=-1 && s[i]!=s[j+1])
            j=nextval[j];
        if(s[i]==s[j+1])
            j++;
        if(j==-1 || s[j+1]!=s[i+1]){// j==-1就不用再回退了，这里i+1最大为s.length，s[s.length()]为'\0'，而j必然小于i，所以一定失配
            nextval[i]=j;
        }else{
            nextval[i]=nextval[j];
        }
    }
}
```


练习：
1. leetcode 28 找出字符串中第一个匹配的下标