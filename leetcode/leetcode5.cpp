class Solution {
public:
    string longestPalindrome(string s) {
        // pre process string
        string t="$"; //防止越界
        for(char& c:s){
            t+='#';
            t+=c;
        }
        t+="#%";//防止越界
        int n=2*s.size()+1;
        vector<int> p(n+1, 0);
        int mi=0,r=0,ans=0;
        for(int i=1;i<=n;i++){
            if(mi+r>i){//囊括进来了
                p[i]=min(p[2*mi-i], mi+r-i);
            }else{
                p[i]=1;
            }
            while(t[i-p[i]] == t[i+p[i]])
                p[i]++;
            if(i+p[i]>mi+r){
                mi=i;
                r=p[i];
            }
            // 以#为中心的也必须包括，例如cbbc，最长回文子串是bb
            if(p[i]>p[ans]){
                ans=i;
            }
        }
        return s.substr((ans-p[ans])/2, p[ans]-1);
    }
};