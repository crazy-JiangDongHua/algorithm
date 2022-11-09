class Solution {
public:
    int primePalindrome(int n) {
        int inv;
        int len =1;
        while(n>pow(10,len*2)-1)
            len++;
        for(;len<=5;len++)
        {
            int max = pow(10,len);
            //先检测所有奇数位回文，因为他们更小
            for(int root=pow(10,len-1);root<max;root++)
            {
                //奇数位回文
                inv = odd_reverse(root);
                inv = root * (max/10) + inv;
                if(inv >= n && isPrime(inv))
                    return inv;
            }
            for(int root=pow(10,len-1);root<max;root++)
            {
                //偶数位回文
                inv = even_reverse(root);
                inv = root * max + inv;
                if(inv >= n && isPrime(inv))
                    return inv;   
            }
        }
        return inv; //永远不会到
    }

    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        int sqr = sqrt(n);
        for(int i=2;i<=sqr;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }

    int even_reverse(int n)
    {
        int res=0;
        while(n!=0)
        {
            res = res*10 + n%10;
            n /= 10;
        }
        return res;
    }

    int odd_reverse(int n)
    {
        int res = 0;
        n /= 10;
        while(n!=0)
        {
            res = res*10 + n%10;
            n /= 10;
        }
        return res;
    }
};
