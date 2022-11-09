class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        memset(last, -1, sizeof(last));
        int maxlen = 0, n=s.length(), start=0;
        for(int i=0; i<n; i++)
        {
            if(last[s[i]] >= start)
            {
                maxlen = max(maxlen, i-start);
                start = last[s[i]]+1;
            }
            last[s[i]] = i;
        }
        return max(maxlen, n-start);//别忘了最后一个子串
    }
};
