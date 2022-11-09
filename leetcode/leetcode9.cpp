// long long 存储
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long sum=0;
        long long tmp=x;
        while(x>0){
            sum=sum*10+x%10;
            x/=10;
        }
        return sum==tmp;
    }
};

// 反转一半
class Solution {
public:
    bool isPalindrome(int x) {
        // 负数，求模为0，只有0是回文
        if(x<0 || (x%10==0 && x!=0))return false;
        int sum=0;
        while(x>sum){
            sum=sum*10+x%10;
            x/=10;
        }
        return sum==x || sum/10==x;
    }
};