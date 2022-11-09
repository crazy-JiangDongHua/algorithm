这一节学一下字符串哈希，然后做一点字符串基础的题目。

之前复习hash的时候简单介绍了一下字符串哈希，通过将26个字母看作26进制数然后取模可以映射为整数，但是取模以后就失去了唯一性，可能发生冲突。好消息是，如果把进制数设为$10^7$级别的素数（例如10000019），同时把mod设置为一个$10^9$级别的素数（例如1000000007），那么产生冲突的概率很小，几乎不会冲突

例如给出一系列string，让求不重复的字符串有多少个。最直接的思路就是塞到unordered_set或者map里面，但是也可以自己hash，这样更快，实现如下：
```c++
const int mod=1000000007;
const int p=10000019;
vector<string> str_arr;
vector<int> ans;
long long strhash(string& s){
    long long sum=0;
    for(char& c:sum){
        sum=(sum*p+(c-'0'))%mod;
    }
    return sum;
}
int main(){
    for(string& s:str_arr){
        ans.push_back(strhash(s));
    }
    int cnt=0;
    for(int i=0;i<ans.size();i++){
        if(i==0 || ans[i]!=ans[i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0
}
```

其他用字符串hash求解最长公共子序列和最长回文子串，感觉属于奇技淫巧一类，show出来很牛逼但是没啥用，所以先不学了，以后有用到在学。

练习：
1. leetcode 125 验证回文串：使用双指针，原地判断。每次都将两个指针移动到距离最近的合法字符处，然后比较是否相同。
2. leetcode 8 字符串转整数：算是比较简单的模拟，需要注意截断。
3. leetcode 67 二进制求和：简单模拟，二进制版的大数求和。
4. leetcode 10 正则表达式匹配：非常有挑战的一道题，可以用动态规划解决，每次碰见`'*'`，都可以匹配0次或任意次，此时状态转移可以参考完全背包的思想，只需匹配一次像前一个状态转移。可以用滚动数组压缩空间。更标准和通用的写法时有限状态自动机，但是有两个难点：第一是不同的pattern对应不同的有限状态自动机，需要动态生成。第二是对于相同的输入，可以对应多个转移状态，按道理是可以转换自动机变成只有唯一转移状态的，但是我忘了。。。以后复习编译原理的时候再来补上
5. leetcode 44 通配符匹配：和leetcode10思路相同。
6. leetcode 14 最长公共前缀：可以横向扫描，即先选两个找出最长前缀，然后再一次用前缀和后面字符串比较，找最后的字符串。也可以纵向扫描，就是先比较每个字符串的第一个字符，然后再第二个...。时间复杂度都是$O(mn)$
7. leetcode 65 有效数组：通过有限状态自动机解决。
8. leetcode 12 整数转罗马数字：可以通过模拟。也可以硬编码每一位的所有可能。
9. leetcode 13 罗马数字转整数：模拟，如果一个罗马数字比后面的数字大，那就加，如果小就减。
10. leetcode 38 外观数列：本质上只是依次统计字符串中连续相同字符的个数，使用双指针即可。也可以打表加速。
11. leetcode 242 有效的字母异味词：统计字符频率
12. leetcode 49 字母异位词分组：字母异位词只是字符位置不同，但是每个字符的出现频率是相同的，对每个字符串做排序之后，异位词一定相同。
13. leetcode 71 简化路径：使用栈来存储每个文件夹的名字，遇到空或者`"."`就跳过，遇到`".."`就弹出一个文件夹，返回上一级。
14. leetcode 58 最后一个单词的长度：简单模拟。