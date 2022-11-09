// 大数求和
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            int tmp=digits[i]+carry;
            digits[i]=tmp%10;
            carry=tmp/10;
        }
        if(carry>0)
        digits.insert(digits.begin(),carry);
        return digits;
    }
};

// 找后缀9
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                break;
            }
        }
        if(i>=0)digits[i]+=1;
        else digits.insert(digits.begin(),1);
        return digits;
    }
};