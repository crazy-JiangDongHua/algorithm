class Solution {
private:
    int getNext(int num){
        int temp=num;
        int c1=0, c0=0;
        while((temp&1)==0){
            c0++;temp>>=1;
        }
        while((temp&1)>0){
            c1++;temp>>=1;
        }
        int p=c0+c1;
        // 111...111000...000无解
        if(p==31)
            return -1;
        // 将第p位置1
        num|=(1<<p);
        // 将脱尾p位置0
        num&=(~((1<<p)-1));
        // 将脱尾c1-1位置1
        num|=((1<<(c1-1))-1);
        return num;
    }
    int getPrev(int num){
        int temp=num;
        int c1=0, c0=0;
        while((temp&1)>0){
            c1++;temp>>=1;
        }
        // 000...000111...111无解
        if(temp==0)
            return -1;
        while((temp&1)==0){
            c0++;temp>>=1;
        }
        int p=c0+c1;
        // 将第p位置0
        // 将脱尾p位置0
        num&=(~((1<<(p+1))-1));
        // 在紧临p的右c1+1位置1
        num|=(((1<<(c1+1))-1)<<(c0-1));
        return num;
    }
public:
    vector<int> findClosedNumbers(int num) {
        // 错误输入 负数或者111...111或者000...000无解
        if(num<0 || (~num)==0 || num==0)
            return {-1,-1};
        return {getNext(num), getPrev(num)};
    }
};