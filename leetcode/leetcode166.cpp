class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long a = (long long)numerator;
        long long b = (long long)denominator;
        if(a%b == 0)
            return to_string(a/b);

        string ans;
        if(a<0 ^ b<0)
            ans.push_back('-');
        
        a = abs(a);
        b = abs(b);
        long long k = a/b;
        long long r = a%b;
        ans.append(to_string(k));
        ans.push_back('.');

        string fracpart;
        unordered_map<long long, int> hash;
        int index = 0;
        while(r!=0 && hash.find(r)==hash.end())
        {
            hash[r] = index;
            index++;
            r *= 10;
            k = r/b;
            r = r%b;
            fracpart.append(to_string(k));
        }

        if(r!=0)
        {
            index = hash[r];
            ans.append(fracpart.substr(0,index));
            ans.push_back('(');
            ans.append(fracpart.substr(index));
            ans.push_back(')');
        }
        else
        {
            ans.append(fracpart);
        }

        return ans;
    }
};
