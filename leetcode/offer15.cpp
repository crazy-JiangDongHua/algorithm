// 解法1 对无符号数和有符号正数有效，但是对负数会陷入死循环
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            if(n&1)cnt++;
            n=n>>1;
        }
        return cnt;
    }
};

// 解法2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        unsigned int p=1;
        for(int i=0;i<32;i++){
            if(n&p)cnt++;
            p=p<<1;
        }
        return cnt;
    }
};

// 解法3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            cnt++;
            n=n&(n-1);
        }
        return cnt;
    }
};