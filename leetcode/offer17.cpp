// 排列
class Solution {
private:
    void dfs(vector<int>& ans, int sum, int n, int i){
        if(i==n){
            if(sum!=0)
                ans.push_back(sum);
            return;
        }
        for(int num=0;num<10;num++){
            dfs(ans, sum*10+num, n, i+1);
        }
    }
public:
    vector<int> printNumbers(int n) {
        if(n<=0)
            return {};
        vector<int> ans;
        dfs(ans, 0, n, 0);
        return ans;
    }
};


// 大数加法
class Solution {
private:
    int add(vector<int>& num){
        int carry=1;
        for(int i=num.size()-1;i>=0;i--){
            num[i]+=carry;
            if(num[i]<10){
                carry=0;
                break;
            }
            carry=num[i]/10;
            num[i]=num[i]%10;
        }
        return carry;
    }

    int sum(vector<int>& num){
        int ans=0;
        for(int i=0, n=num.size();i<n;i++){
            ans=ans*10+num[i];
        }
        return ans;
    }
public:
    vector<int> printNumbers(int n) {
        if(n<=0)
            return {};
        vector<int> ans;
        vector<int> num(n, 0);
        while(!add(num)){
            ans.push_back(sum(num));
        }
        return ans;
    }
};