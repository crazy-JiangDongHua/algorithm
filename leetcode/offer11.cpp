class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty())
            throw std::exception();
        int l=0, r=(int)numbers.size()-1;
        while(l<r){
            int m=((r-l)>>1)+l;
            if(numbers[m]<numbers[r]){
                r=m;
            }else if(numbers[m]>numbers[r]){
                l=m+1;
            }else{
                r--;
            }
        }
        return numbers[l];
    }
};