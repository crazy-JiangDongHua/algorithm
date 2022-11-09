class Solution {
public:
    int clumsy(int n) {
        if(n == 1)
    		return 1;
    	else if(n == 2)
    		return 2*1;
    	else if(n == 3)
    		return 3*2/1;
    	else if(n == 4)
    		return 4*3/2+1;
        int res = n*(n-1)/(n-2)+(n-3);
        n -= 4;
        return res-f(n);
    }
    int f(int n){
        if(n == 1)
    		return 1;
    	else if(n == 2)
    		return 2*1;
    	else if(n == 3)
    		return 3*2/1;
    	else if(n == 4)
    		return 4*3/2-1;
    	else if(n > 4)
    		return n*(n-1)/(n-2)-(n-3)+f(n-4);
        else //n==0 or other
            return 0;
    }
};
