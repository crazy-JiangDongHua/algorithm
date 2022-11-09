class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> num3(num1.length()+num2.length(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                num3[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=1;i<num3.size();i++){
            num3[i]+=num3[i-1]/10;
            num3[i-1]%=10;
        }
        // 删除前导0
        while(num3.size()>1 && num3.back()==0)
            num3.pop_back();
        string res(num3.size(),'0');
        for(int i=0;i<num3.size();i++){
            res[i]=num3[num3.size()-i-1]+'0';
        }
        return res;
    }
};