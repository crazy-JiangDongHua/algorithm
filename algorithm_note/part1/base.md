### 1. 基本数据类型

| 数据类型  |                     大致范围                     |         输入输出格式         |                             备注                             |
| :-------: | :----------------------------------------------: | :--------------------------: | :----------------------------------------------------------: |
|    int    |  -2&times;10<sup>9</sup>~2&times;10<sup>9</sup>  |             %md              |                 32位，超过10<sup>9</sup>不用                 |
| long long | -9&times;10<sup>18</sup>~9&times;10<sup>18</sup> |   win: %I64d, linux: %lld    | 64位，比int大用，<br/> **大于int范围的数定义的时候记得加LL** |
|   float   |                    精度6~7位                     |             %.mf             |                      32位，直接用double                      |
|  double   |                   精度15~16位                    |      输入%lf，输出%.mf       |                    64位，浮点数都用double                    |
|   char    |                     -128~127                     | %c or getchar() or putchar() |                       8位，存储ASCII码                       |
|   bool    |                      0 or 1                      |      %d or if-else输出       |              8位，存储器一般最小单位是一个字节               |
|  char[]   |                      自定义                      |              %s              |    字符串，记得给'\0'留一个位置<br/>scanf也是读到空白结束    |
|   const   |                                                  |                              |    常量，必须初始化是赋值，<br/>否则后面就能改就不是常量     |



### 2. 运算符

|    种类    |          运算符           |                             备注                             |
| :--------: | :-----------------------: | :----------------------------------------------------------: |
| 算数运算符 |   +, -, *, /, %, ++, --   | 加，减，乘，除，取模，自增，自减<br/>**整数除法得到的是整数（向下取整）** |
| 关系运算符 |   >, <, >=, <=, ==, !=    |         大于，小于，大于等于，小于等于，等于，不等于         |
| 逻辑运算符 |    &&, &vert;&vert;, !    |                          与，或，非                          |
| 条件运算符 |           A?B:C           |                     A真执行B，否则执行C                      |
|  位运算符  | <<, >>, &, &verbar;, ^, ~ | 左移，右移，位与，位或，位异或，位非<br/>`<<1` or`>>1` 比 `*2` or `/2`更快<br/>**care，移位运算符优先级低于加减** |
| 逗号运算符 |        a,b,c,...,n        |                  他的值为最后一个表达式的值                  |

### 3. 数组

* 二维数组如果特别大，不要放在主函数里面，容易爆栈，可以只放到主函数外，存在静态存储区，一般10^6次方为分界。
