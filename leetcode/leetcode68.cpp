class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string res;
        int sum=0;
        int pre=-1;
        for(int i=0;i<words.size();i++){
            if(sum+words[i].length()+(i-pre-1)<=maxWidth){
                sum+=words[i].length();
            }else{
                res.clear();
                int num=i-pre-1;
                int cnt=maxWidth-sum;
                if(num==1){
                    res+=words[pre+1]+string(cnt, ' ');
                }else{
                    int interval = cnt/(num-1);
                    int add = cnt%(num-1);
                    for(int j=pre+1;j<i;j++){
                        res+=words[j]+(j<i-1?string(interval,' '):"")+(add>0?" ":"");
                        add--;
                    }
                }
                ans.emplace_back(res);
                sum=words[i].length();
                pre=i-1;
            }
        }
        int num=words.size()-pre-1;
        res.clear();
        for(int j=pre+1;j<words.size();j++){
            res+=words[j]+(j<words.size()-1?" ":"");
        }  
        res+=string(maxWidth-res.length(), ' ');
        ans.emplace_back(res);
        return ans;
    }
};