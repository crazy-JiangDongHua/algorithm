这一章是关于数组与字符串的联系。

1. 面试题01.01 判定字符是否唯一：第一想法是用哈希表，时间复杂度 $O(n)$ ，空间复杂度为 $O(C)$ ，$C$ 表示字符集的大小。因为只包含小写字符，所以可以用一个int值作为哈希表，第i个bit表示字符c是否出现过，其中`i=c-'a'`。如果要求空间复杂度为 $O(1)$ ，如果不可改变字符串则可以将每一个字符与其他所有字符比较，时间复杂度为 $O(n^2)$ 。如果可以改变字符串，就可以先排序字符串再检查，时间复杂度为 $O(n\log n)$
2. 面试题01.02 判定是否互为字符重排：使用哈希表统计两个字符串的字符频率，然后比较是否相同。
3. 面试题01.03 URL化：经典题目，原地修改从后往前遍历，创建新内存从前往后拼就行。
4. 面试题01.04 回文排列：使用哈希表，回文串具备的性质是最多一个字符出现奇数次，其他字符都是偶数次。因为直关心奇偶性，所以并不需要实际统计频率，因此只需要用bit数组做哈希表节省空间。
5. 面试题01.05 一次编辑：首先根据长度判断，长度相等再检查能否通过替换变成相等字符串，长度差1再检查能否通过增加或删除变成相等字符串。
6. 面试题01.06 字符串压缩：一种是动态申请内存，遍历一次，一种是先算压缩后的长度，然后一次性申请内存，然后再遍历一次。
7. 面试题01.07 旋转矩阵：经典题，旋转90度等于先对角线翻转再水平翻转。这本书里给出了一个新方法，就是对每层进行环形旋转，这样每个元素只需要访问一次，时间复杂度常系数减半了。
8. 面试题01.08 零矩阵：经典题目，用第一行第一列存0，再优化用第一列存0。
9. 面试题01.09 字符转轮转：假设切分成两部分x和y，有s1=xy和s2=yx，那么yx一定是s1+s1=xyxy的子串，搜索子串的kmp算法是 $O(len(s1)+len(s2))$