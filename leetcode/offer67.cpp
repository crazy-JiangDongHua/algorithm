#include <climits>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;


// 原书解答
class Solution1 {
private:
    bool isInputValid=false;
    bool check(int cur, int num, int sign){
        if(sign==1){
            return cur<INT_MAX/10 || (cur==INT_MAX/10 && num<=INT_MAX%10);
        }
        return -cur>INT_MIN/10 || (-cur==INT_MIN/10 && -num>=INT_MIN%10);
    }
public:
    bool get_Flag(){return isInputValid;}
    int strToInt(string str) {
        isInputValid=false;
        string::iterator it=str.begin();
        // 空串
        if(it==str.end())
            return 0;
        int sign=1;
        // 第一个字母
        if(*it=='+' || *it=='-'){
            sign=*it=='+'?1:-1;
            it++;
        }
        int ans=0;
        while(it!=str.end()&&'0'<=*it&&*it<='9'){
            int num=*it-'0';
            if(check(ans, num, sign)){
                ans=ans*10+num;
            }else{
                // 溢出
                return 0;
            }
            it++;
        }
        if(it!=str.end())
            return 0;
        isInputValid=true;
        return ans*sign;
    }
};


// leetcode解答，和原书稍微有点不一样, 但是功能和atoi一样
class Solution {
private:
    bool isInputValid=true;
    bool check(int cur, int num, int sign){
        if(sign==1){
            return cur<INT_MAX/10 || (cur==INT_MAX/10 && num<=INT_MAX%10);
        }
        return -cur>INT_MIN/10 || (-cur==INT_MIN/10 && -num>=INT_MIN%10);
    }
public:
    bool get_Flag(){return isInputValid;}
    int strToInt(string str) {
        isInputValid=true;
        string::iterator it=str.begin();
        if(it==str.end()){
            isInputValid=false;
            return 0;
        }
        // 跳过前段空格
        while(it!=str.end() && *it==' ')
            it++;
        int sign=1;
        // 第一个不等于空格的字母
        if(*it=='+' || *it=='-'){
            sign=*it=='+'?1:-1;
            it++;
        }
        // 正负号后面第一位必须是数字，包含了空串和非法输入的case
        if(!('0'<=*it && *it<='9')){
            isInputValid=false;
            return 0;
        }
        int ans=0;
        // 第一位是数字，开始读取
        while(it!=str.end()&&'0'<=*it&&*it<='9'){
            int num=*it-'0';
            if(check(ans, num, sign)){
                ans=ans*10+num;
            }else{
                isInputValid=false;
                return sign==1?INT_MAX:INT_MIN;
            }
            it++;
        }
        return ans*sign;
    }
};

int main(){
    Solution1 s;
    // 合法正数
    string arr1[]={"5","07","+346","+2334590", to_string(INT_MAX)};
    for(const string& str:arr1){
        assert(s.strToInt(str)==atoi(str.c_str()));
        assert(s.get_Flag());
    }

    // 合法负数
    string arr2[]={"-5","-3457","-09","+2334590", to_string(INT_MIN)};
    for(const string& str:arr2){
        assert(s.strToInt(str)==atoi(str.c_str()));
        assert(s.get_Flag());
    }

    // 非法字符输入
    // 这里书里的函数输出和atoi不一样，atoi会跳过前导空格和后缀非法字符
    assert(atoi("09sf")==9);
    string arr3[]={"sa-5","-sdf3457","d09dfd"};
    for(const string& str:arr3){
        assert(s.strToInt(str)==atoi(str.c_str()));
        assert(!s.get_Flag());
    }

    // 空字符串
    assert(s.strToInt("")==atoi(""));
    assert(!s.get_Flag());

    // 溢出 atoi不返回0 而是返回INTMIN和INTMAX
    // string arr4[]={to_string(0x80000000ll), to_string(-1ll-INT16_MIN)};
    
    // for(const string& str:arr4){
    //     assert(s.strToInt(str)==atoi(str.c_str()));
    //     assert(!s.get_Flag());
    // }

    cout<<"完美通过所有测试";
    return 0;    
}