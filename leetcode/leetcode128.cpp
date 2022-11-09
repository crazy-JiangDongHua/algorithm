//方法1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans=0;
        for(int i:nums){
            // 如果存在i-1，那么从i-1开始的序列长度一定比i开始的长
            // 所以不需要从i-1开始搜索，相当于只对每个序列的最左端点开始搜索。
            if(!s.count(i-1)){
                int cnt=1;
                while(s.count(i+1)){
                    i++;cnt++;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};

//方法2
class Solution {
private:
    class UFS{
        private:
            unordered_map<int, int> s;
        public:
            UFS(vector<int>& nums){
                for(int& i:nums)
                    s[i]=i;
            }
            int count(int x){
                return s.count(x);
            }
            int find(int x){
                return x==s[x]?x:s[x]=find(s[x]);
            }
            void myunion(int x, int y){
                int fx=find(x);
                int fy=find(y);
                if(fx!=fy)
                    s[fx]=fy;
            }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        UFS ufs(nums);
        for(int& i:nums){
            if(ufs.count(i+1))
                ufs.myunion(i,i+1);
        }
        int ans=0;
        for(int& i:nums){
            ans=max(ans, ufs.find(i)-i+1);
        }
        return ans;
    }
};