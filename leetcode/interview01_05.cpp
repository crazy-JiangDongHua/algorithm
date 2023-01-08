class Solution {
private:
    bool swapAway(string& first, string& second){
        int i=0;
        bool findDiff=false;
        while(i<first.length()){
            if(first[i]!=second[i]){
                if(findDiff)
                    return false;
                findDiff=true;
            }
            i++;
        }
        return true;
    }
    bool addAway(string& first, string& second){
        int i=0,j=0;
        while(i<first.length() && j<second.length()){
            if(first[i]!=second[j]){
                if(i!=j)
                    return false;
                j++;
            }else{
                i++;j++;
            }
        }
        return true;
    }
public:
    bool oneEditAway(string first, string second) {
        if(first.length()==second.length())
            return swapAway(first, second);
        else if(first.length()+1==second.length())
            return addAway(first, second);
        else if(first.length()==second.length()+1)
            return addAway(second, first);
        else
            return false;
    }
};