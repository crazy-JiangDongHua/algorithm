### 1. cstdio

标准输入输出库

* `scanf()`: 标准输入，遇到空白符或者读不下去停止
* `printf()`: 标准输出
* `getchar()`: 读取一个字符并返回
* `putchar()`: 输出一个字符 
* `gets(字符串)`: 读一行，遇到换行符号停下，循环时记得要用getchar()读取最后那个换行符号
* `puts(字符串)`: 输出一个字符串，同时加一个换行符号  
* `sscanf(str, format, &n)`: 把str以format形式输出到n中，可以用来字符串转数字
* `sprintf(str, format, n)`: 把n用format形式输出到str中，可以用来数字转字符串

### 2. cmath

* `abs()`: 整数类型绝对值
* `fabs()`: 浮点类型绝对值
* `floor()`: 向下取整
* `ceil()`: 向上取整
* `pow(r, p)`: r^p
* `sqrt()`: 开方
* `log()`: 取自然对数为底的对数
* `round()`: 四舍五入

### 3. cstdlib

* `malloc()`：申请内存，`typename* p = (typename*)malloc(sizeof(typename))`
* `free()`：释放空间

### 4. cstring

* `memset(数组，value, sizeof(数组名字))`: 快速初始化数组，value可以是0（初始化为0），1（初始化为-1），0x3f（部分情况下可以作为无穷大）
* `strlen()`: 字符串长度
* `strcmp(a, b)`: 字典序，a小于b返回负数，a等于b返回0，a大于b返回正数
* `strcpy(a, b)`: 把b复制给a
* `strcat(a, b)`: 把b接到a后面

### 5. cassert

assert宏的原型定义在<cassert>中，其作用是如果它的条件返回错误，则终止程序执行，原型定义为：`void assert( int expression );`
assert的作用是现计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。
可以用来简单测试，大型项目的测试还是用googletest和googlelog。


以下为c++中的标准库函数和stl，使用时出了引用头文件外，还需使用命名空间`using namespace std` or `using std function/class`

**在stl的定义中，如果泛型typename也是一个stl容器，那么定义的时候一定要记得在>>符号之间加上空格，因为c++11之前的的编译器会把它视为移位操作，例如**

```c++
vector<vector<int> > tmp;// right
vector<vector<int>> tmp;// false
```

### 6. iostream

* `cin, cout`: c++标准输入输出，太慢了，建议只有读string采用
* `cin.getline(char str[], len, end='\n')`: 获取一行，PAT不允许用`gets()`

### 7. algorithm

* `sort(start, end, cmp)`: cmp(a, b)返回ture，表示这种情况a放在b前面，只有vector,string,deque可以sort

* `min(a,b)`

* `max(a,b)`

* `swap(a,b)`

* `abs(a)`：x必须是整数，浮点用math库的fabs()

* `reverse(start,end)`：可以将迭代器或指针指向的区间`[strat,end)`元素反转

* `next_permutation(start,end)`：输出迭代器或指针指向的区间`[strat,end)`元素全排列，排列完了返回false

  ```c++
  int a[3];
  do{
      cout<<a[0]<<a[1]<<a[2];
  }while(next_permutation(a,a+3))
  ```

* `fill(start,end,value)`：可以将迭代器或指针指向的区间`[strat,end)`元素填充为value，value可以是任意值，比memset强，但是慢。

* `low_bound(start, end, value)`：本质是二分查找。输出迭代器或指针指向的**有序**区间`[strat,end)`元素中，第一个大于等于value的元素的指针（数组）或者迭代器（stl容器）。

* `upper_bound(start, end, value)`：本质是二分查找。输出迭代器或指针指向的**有序**区间`[strat,end)`元素中，第一个大于value的元素的指针（数组）或者迭代器（stl容器）。

### 8. vector

* 访问方式：
  1. 通过下标访问：`v[index]，index~[0，v.size()-1]`
  2. 通过迭代器访问：`vector<typename>::iterator it = v.begin();*(it+index)`
* `push_back(x)`：在末尾添加一个元素x
* `pop_back()`：在末尾删除一个元素
* `size()`：获取元素的个数
* `clear()`：清空
* `insert(it, x)`：在迭代器it的位置插入x
* `earse(it)`：删除迭代器it处的元素
* `earse(begin, end)`：删除迭代器[begin, end)处的元素

用途：

1. 存储数据
2. 实现邻接表可以不用链表了哈哈哈哈

### 9. set

​    set自动去重，有序排列，底层红黑树

* 访问方式：set只能通过迭代器访问

  枚举：`for(set<typename>::iterator it=s.begin();it!=s.end();it++)`

* `insert(x)`：把x插入set中，O(logn)

* `find(x)`：返回x的it，没找到返回s.end()

* `erase(x)`：删除x, O(logn)

* `erase(it)`：删除it指向的元素, O(1)

* `erase(begin, end)`：删除it[begin, end)指向的元素, O(end-begin)

* `size()`：元素个数 O(1)

* `clear()`：清空 O(N)

用途：

1. 需要去重并排序，但是元素很大或者不是int不好直接开散列表
1. 如果需要处理元素不唯一的情况，也可以使用multiset。
1. 如果只需要去重，不需要排序，也可以用unordered_set，底层是散列表

### 10. string

* 访问方式

  1. 通过下标访问：`s[index]，index~[0，s.length()-1]`
  
  2. 通过迭代器访问：`string::iterator it = s.begin();*(it+index)`
* 输入输出

    1. 通过cin，cout
    2. 通过getline(cin, str)读取一行
    3. 通过str.c_str()，再printf
* `operator+=`：`str3 = str1 + str2;str3 += str1;`可以拼接
* `compare operator`：比较字符串的字典序
* `length()/size()`：长度
* `insert(pos, str)/insert(pos, beginit, endit)`：再pos处插入字符串
* `erase(it)/erase(first, last)/erase(pos, length)`：删除，返回下个字符的迭代器
* `clear()`：清除
* `substr(pos, len)`：字串
* `string::npos`：find未找到时候失配的标志
* `find(str)`：返回第一次找到str的位置，未找到返回npos。O(mn)
* `replace(pos, len, str2)/replace(it1, it2, str2)`：替换为str2

### 11. map

map和set的区别在于，set只存储key，而map存储了key和value。map的底层也是红黑树，所以key自动去重而且是有序的。

```c++
template < class Key, // map::key_type
           class T, // map::mapped_type
           class Compare = less<Key>, // map::key_compare
           class Alloc = allocator<pair<const Key,T> >//map::allocator_type
           > class map;
```

* 初始化：`map<key, value> mp;`，如果要用字符串做key，必须用string，不能用char数组，更通俗的说一点，key不要是指针。为什么呢，想想看下面的情况：

  ```c++
  map<char*, int> mp;
  char* str1 = new char[5];
  str1[0] = "a";str1[1]="\0";
  mp[str1] = 1;
  
  // after n line, str1 has been released
  char* str2 = new char[5];
  str2[0] = "a";str2[1]="\0";
  mp.find(str2);// mp.end()
  ```

  明明str1和str2都是指向“a”，为啥会找不到呢，显然两次new出来的地址不一样呀，所以一般不要用指针做key。但是这是一般情况，如果数据量特别大，map的key和value存的都是对象，那相当于数据量翻倍，内存吃不消啊，所以用指针做key也不是不行，怎么解决上述问题呢，用两种办法：

  1. 直接开全局数组，这样指针永远不会作为局部变量被release

  2. 重构比较函数，我们不直接比较指针的地址大小，而是通过比较指针指向对象的大小。例如：

     ```c++
     struct ptrCmp
     {
         bool operator()( const char * s1, const char * s2 ) const
         {
             return strcmp( s1, s2 ) < 0;
         }
     };
     map<char *, int, ptrCmp> mapStr;
     ```

  使用指针的时候必须注意一点，map中的数据用完之后，不要直接clear，而是遍历一遍，把每个key指向的内存都释放，再clear。

* 访问：

  1. 通过下标访问：`mp[key]`访问value
  2. 通过迭代器访问：迭代器访问，`it->first`访问key，`it->second`访问value

* `find(key)`：返回key对应pair的it，没找到返回`mp.end()`

* `erase(it)\erase(key)`：删除，O(1)\O(logN)

* `insert(pair(key, value))\mp[key]=value`：插入,O(logN)

* `size()`：元素个数 O(1)

* `clear()`：清空 O(N)

用途：

1. 建立字符串与整数之间的映射
2. 判断大整数是否存在（直接开哈希爆内存，要手写好点的hash函数）
3. 如果要一个key对应多个value，那也可以用multimap。如果不需要key有序，也可以用底层是散列表的unordered_map

### 12. queue

队列，先进先出

* 访问：`front()`访问队头，`back()`访问队尾。
* `push()`：队尾入队
* `pop()`：队头出队
* `empty()`：检测是否为空
* `size()`：队列规模

careful:

* 使用front()和back()之前，要先检查empty()
* 如果想首尾插入，可以使用双头队列deque。

### 13. priority_queue

头文件是`<queue>`，优先级队列，底层是最大堆，原型如下：

```c++
template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue
```

* `top()`：访问堆顶元素

* `push()`：插入元素

* `pop()`：删除元素

* `empty()`

* `size()`

* 设置为小根堆

  ```c++
  priority_queue<T,vector<T>, Great<T>> heap;
  //如果T不是基础数据类型，那我们就写一个函数对象，作为great<T>
  class cmp{
      bool operater()(const T& e1, const T& e2)const
      {
          return el>e2;
      }
  }
  //或者在类里面重载<
  bool operator<(const T& temp)const//后面的const一定记得加，这样才可以保证两个变量都是const,因为less<T>要求这样
  {
      return *self>temp;
  } 
  //或者定义友元函数重载<
  ```

用途：

* dijkstra算法优化
* 哈夫曼树优化
* 其他

### 14. stack

* `top()`：访问堆顶元素
* `push()`：插入元素
* `pop()`：删除元素
* `empty()`
* `size()`

用途：

* 模拟递归，防止爆栈，因为栈空间有限，函数递归不能太深。

### 15. pair

头文件为`<utility>`，因为map用到了pair，所以头文件`<map>`包含了`<utility>`。pair就是很简单又很实用的两元素结构体：

```c++
struct pair{
    typeName1 first;
    typeName2 second;
}
```

* pair的比较：默认先比first，first相等再比second

### 16. unordered_set

无序集合，底层散列表，类模板如下：

```c++
template < class Key,//容器中存储元素的类型
           class Hash = hash<Key>,//确定元素存储位置所用的哈希函数
           class Pred = equal_to<Key>,//判断各个元素是否相等所用的函数
           class Alloc = allocator<Key>//指定分配器对象的类型
           > class unordered_set;
```

* 访问方式：unordered_set只能通过迭代器访问

  枚举：`for(unordered_set<typename>::iterator it=s.begin();it!=s.end();it++)`

* `insert(x)`：把x插入set中，O(l)

* `find(x)`：返回x的it，没找到返回s.end()

* `count(x)`：返回x的个数

* `erase(x)`：删除x, O(1)

* `erase(it)`：删除it指向的元素, O(1)

* `erase(begin, end)`：删除it[begin, end)指向的元素, O(end-begin)

* `size()`：元素个数 O(1)

* `clear()`：清空 O(N)

* `empty()`

### 17. unordered_map

无序集合，底层散列表，和unordered_set区别就是，多存了value，用pair表示，类模板如下：

```c++
template < class Key,                        //键值对中键的类型
           class T,                          //键值对中值的类型
           class Hash = hash<Key>,           //容器内部存储键值对所用的哈希函数
           class Pred = equal_to<Key>,       //判断各个键值对键相同的规则
           class Alloc = allocator< pair<const Key,T> >  // 指定分配器对象的类型
           > class unordered_map;
```

* 访问：

  1. 通过下标访问：`mp[key]`访问value
  2. 通过迭代器访问：迭代器访问，`it->first`访问key，`it->second`访问value
* `find(key)`：返回key对应pair的it，没找到返回`mp.end()`
* `erase(it)\erase(key)`：删除，O(1)\O(1)
* `insert(pair(key, value))\mp[key]=value`：插入,O(1)
* `size()`：元素个数 O(1)
* `clear()`：清空 O(N)
* `count(x)`：返回以x做key的键值对的个数



练习（queue和stack的练习放在第5章，priority_queue的练习放在第7章）：

* PAT A1039 Course List for Student：不能直接用`map<string, vector<int>>`，最后一组数据太大会超时。所以要用字符串hash来加快映射，使用`unordered_map<string, vector<int>>`
* PAT A1060 Are They Equal: 注意分两种情况讨论，



  

