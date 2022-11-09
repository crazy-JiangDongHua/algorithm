这些题目都比较简单，所以没有完整把题干和代码列出了，大家可以有选择地尝试，感兴趣的可以通过PAT官网看看题干，完整代码在PAT文件夹下。

1. PAT B1001 害死人不偿命的(3n+1)猜想

2. PAT B1032 挖掘机技术哪家强

2. codeup 1934 找x

3. PAT B1036 跟奥巴马一起编程

3. codeup 1928 日期差值

4. PAT B1022 D进制的A+B

   进制转换是考试的热点，这里简单说一下X进制数转换到Y进制数的模板，方便大家在上机时快速完成。

   1. X进制 to 10进制

      ```c++
      int res=0, product=1;
      while(num != 0)
      {
          res += (num%10) * product;
          product *= X;
          num /= 10;
      }
      ```
      
   2. 10进制 to Y进制
   
      ```c++
      int stack[], cnt=0;
      do
      {
          stack[cnt++] = num%Y;
          num /= Y;
      }while(num != 0)
      ```
   
      这样stack从第cnt-1位到第0位就是答案
   
7. codeup 5901 回文串

5. PAT B1009 说反话
