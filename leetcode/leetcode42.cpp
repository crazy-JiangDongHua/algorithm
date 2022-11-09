// 两遍扫描
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n, 0);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1], height[i]);
        }
        int right=height[n-1],ans=min(right,left[n-1])-height[n-1];
        for(int i=n-2;i>=0;i--){
            right=max(right,height[i]);
            ans+=min(right,left[i])-height[i];
        }
        return ans;
    }
};

// 一遍扫描
class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1, ans=0;
        int lmax=0,rmax=0;
        while(l<=r){
            lmax=max(height[l],lmax);
            rmax=max(height[r],rmax);
            if(lmax<rmax){
                ans+=lmax-height[l];//l位置能接雨水的最大高度
                l++;
            }else{
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};

// 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, n=height.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && height[s.top()]<height[i]){
                int m=s.top();s.pop();
                if(s.empty())break;
                int l=s.top();
                ans+=(i-l-1)*(min(height[i],height[l])-height[m]);
            }
            s.push(i);
        }
        return ans;
    }
};