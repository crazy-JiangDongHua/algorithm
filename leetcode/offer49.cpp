class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyArr={1};
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++){
            int ugly=min(2*uglyArr[p2], min(3*uglyArr[p3], 5*uglyArr[p5]));
            uglyArr.push_back(ugly);
            if(ugly==2*uglyArr[p2])
                p2++;
            if(ugly==3*uglyArr[p3])
                p3++;
            if(ugly==5*uglyArr[p5])
                p5++;
        }
        return uglyArr[n-1];
    }
};