这一节专门讲讲暴力枚举。一般形式是给定一个序列，要求这个序列的：1. 所有子集；2. 所有排序；3. 所有组合。求解的方式一般为dfs

1. 求序列的所有子集
一种是通过dfs的方式，每个元素要么选，要么不选。或者用二进制数，来表示所有选择，即[0,$2^n-1$]，第i位为1，表示取第i个元素。

如果序列中存在重复元素，且要求返回的子集不能重复。有两种方式可以去重，一种是记录每个元素出现的次数，然后遍历每个元素出现几次，如x出现y次，那么我们就考虑x出现0-y次的可能。另一种是记录上一个元素i是否被选择，如果上一个元素i没被选择，而且和当前元素j相同。那么选i不选j和不选i选j将会产生相同的子集，所以不能选。

练习：
1. leetcode 78 子集
2. leetcode 90 子集2

2. 求序列的组合
这种相当于是求序列的元素个数为k的所有子集，只需要改一下把递归结束条件从`i==n`改成`i==k`就可以了。

练习：
1. leetcode 77 组合
2. leetcode 40 组合总和2


3. 求序列的所有排列
如果不存在重复元素，可以使用一个标记数组表示当前已经使用的元素，也可以用交换实现。

如果存在重复元素，可以先排序，同样是记录上一个元素i是否被选择，如果上一个元素i没被选择，而且和当前元素j相同，那么在当前位置，之前肯定已经选过i，如果现在选j和之前情况一样，造成重复。

练习：
1. leetcode 46 全排列
2. leetcode 47 全排列2
3. leetcode 17 电话号码的字母组合