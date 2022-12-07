// 直接递归，超时
class Solution {
private:
    int max_point=6;
    void dicesProbability(int n, int i, int sum, vector<double>& ans){
        if(i==0){
            ans[sum-n]+=1;
            return;
        }
        for(int j=1;j<=max_point;j++){
            dicesProbability(n, i-1, sum+j, ans);
        }
    }
public:
    vector<double> dicesProbability(int n) {
        vector<double> ans(5*n+1, 0.0);
        dicesProbability(n, n, 0, ans);
        double tmp=pow(max_point,n);
        for(double& num:ans){
            num/=tmp;
        }
        return ans;
    }
};

// 用备忘录
class Solution {
private:
    int max_point=6;
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> ans(2, vector<double>(max_point*n+1, 0.0));
        for(int point=1;point<=max_point;point++)
            ans[1][point]+=1;
        for(int i=2,k=0;i<=n;i++,k^=1){
            fill(ans[k].begin(), ans[k].end(), 0.0);
            for(int num=i,max_num=i*max_point;num<=max_num;num++){
                for(int point=1;point<=max_point&&point<num;point++){
                    ans[k][num]+=ans[k^1][num-point];
                }
            }
        }

        double tmp=pow(max_point,n);
        for(double& num:ans[n&1]){
            num/=tmp;
        }
        return vector<double>(ans[n&1].begin()+n, ans[n&1].end());
    }
};