class Solution {
private:
    int getGcd(int x, int y){
        if(x<y)return getGcd(y,x);
        return x%y==0?y:getGcd(y,x%y);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2)return n;
        int ans=0;
        // 以点为中心枚举边
        for(int i=0;i<n;i++){
            if(ans>n/2 || ans>=n-i)
                break;
            unordered_map<int, int> ht;// 斜率，次数
            // 不需要访问之前的点，因为对应直线已经访问过
            for(int j=i+1;j<n;j++){
                // 用分数表示斜率，因为double不能精确比较
                int up=points[j][1]-points[i][1];
                int down=points[j][0]-points[i][0];
                // 化简分数
                if(up==0)down=1;
                else if(down==0)up=1;
                else{
                    // 约定分子不为负数
                    if(up<0){
                        up=-up;
                        down=-down;
                    }
                    int gcd=getGcd(abs(up),abs(down));
                    up/=gcd;
                    down/=gcd;
                }
                ht[up*40001+(down+20000)]+=1;
            }
            for(auto& item:ht){
                ans=max(ans, item.second+1);
            }
        }
        return ans;
    }
};