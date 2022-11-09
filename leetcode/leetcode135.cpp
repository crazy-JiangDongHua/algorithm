// 两次扫描
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1;
        }
        int right=1,ans=max(1, left[n-1]);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                right++;
            else
                right=1;
            ans+=max(left[i],right);
        }
        return ans;
    }
};

// 一次扫描
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),ans=1;
        int pre=1, inc=1, dec=0;
        for(int i=1;i<n;i++){
            if(ratings[i]>=ratings[i-1]){
                dec=0;
                pre=ratings[i]==ratings[i-1]?1:pre+1;
                ans+=pre;
                inc=pre;
            }else{
                dec++;
                if(dec==inc)dec++;
                pre=1;
                ans+=dec;
            }
        }
        return ans;
    }
};