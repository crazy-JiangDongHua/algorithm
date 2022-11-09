// 方法一  dp 
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0, n=s.length();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i] = 2+(i>=2?dp[i-2]:0);
                    res = max(res, dp[i]);
                }
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                {
                    dp[i] = dp[i-1]+2+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

// 方法二 stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                stk.push(i);
            else
            {
                int j = stk.top();
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    res = max(res, i-stk.top());
                }
            }
        }
        return res;
    }
}; 

// 方法三 count
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0, left=0, right=0, n=s.length();
        for(int i=0;i<n;i++)
        {
            s[i]=='(' ? left++ : right++;
            if(left==right)
                res = max(res, 2*left);
            else if(left<right)
                left=right=0;
        }
        left=right=0;
        for(int i=n-1;i>=0;i--)
        {
            s[i]=='(' ? left++ : right++;
            if(left==right)
                res = max(res, 2*left);
            else if(left>right)
                left=right=0;
        }
        return res;
    }
}; 
