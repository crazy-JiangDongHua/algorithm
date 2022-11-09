这一张来讲最大公约数和最小公倍数

* 最大公约数

  一般采用辗转相除法：gcd(a, b) = gcd(b, a%b)

  ```c++
  int gcd(int a, int b)//保证a>=b
  {
      return !b? a : gcd(b, a%b)
  }
  ```

  

* 最小公倍数

  ```c++
  return a * b / gcd(a, b);
  ```

  但是a*b可能溢出，所以一般写成
  
  ```c++
  return a / gcd(a, b) * b
  ```

练习：

1. leetcode1979 找出数组的最大公约数