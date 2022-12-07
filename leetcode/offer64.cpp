// 使用数组隐式循环调用构造函数
class Temp{
    private:
        static int n;
        static int sum;
    public:
        Temp(){n++;sum+=n;}
        int getSolution(int n){
            Temp::n=0;Temp::sum=0;
            Temp* arr=new Temp[n];
            delete[] arr;
            return Temp::sum;
        }
};

// 类外初始化
int Temp::n=0;
int Temp::sum=0;

class Solution {
public:
    int sumNums(int n) {
        return Temp().getSolution(n);
    }
};


// 使用static 函数指针 和 !!
class Solution {
private:
    static int fun1(int n){
        return 0;
    }
    static int fun2(int n){
        static int (* arr[2])(int)={fun1, fun2};
        return n+arr[!!(n-1)](n-1);
    }
public:
    int sumNums(int n) {
        return fun2(n);
    }
};


// 使用非static函数指针 和 !!
class Solution {
private: 
    int fun1(int n){
        return 0;
    }
    int fun2(int n){
        static int (Solution::* arr[2])(int)={&Solution::fun1, &Solution::fun2};
        return n + (this->*arr[!!(n-1)])(n-1);
    }
public:
    int sumNums(int n) {
        return fun2(n);
    }
};