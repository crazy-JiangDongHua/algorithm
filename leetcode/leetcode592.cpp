class Solution {
public:
    string fractionAddition(string expression) {
        fraction a, b;
        int i=0;
        a = readnum(i, expression);
        while(i<expression.length())
        {
            b = readnum(i, expression);
            a = add(a, b);
        }
        return to_string(a.up) + "/" + to_string(a.down);
    }

    struct fraction{
        int up;
        int down;
        fraction():up(0),down(0){};
    };

    fraction readnum(int& i, const string& expression)
    {
        fraction res;
        int flag = 1;
        if(expression[i]=='-')
        {
            flag = -1;
            i++;
        }
        else if(expression[i]=='+')
        {
            i++;
        }
        while(i<expression.length() && '0'<=expression[i] && expression[i]<='9')
        {
            res.up = res.up*10 + (expression[i]-'0');
            i++;
        }
        i++; // '\'
        while(i<expression.length() && '0'<=expression[i] && expression[i]<='9')
        {
            res.down = res.down*10 + (expression[i]-'0');
            i++;
        }
        res.up *= flag;
        return res;
    }

    int gcd(int a, int b)
    {
        if(a<b)
            swap(a,b);
        return b==0?a:gcd(b,a%b);
    }

    void reduction(fraction& f)
    {
        if(f.down<0)
        {
            f.up *= -1;
            f.down *= -1;
        }
        if(f.up==0)
            f.down=1;
        else
        {
            int tmp = gcd(abs(f.up), abs(f.down));
            f.up /= tmp;
            f.down /= tmp;
        }
    }

    fraction add(const fraction& a, const fraction& b)
    {
        fraction res;
        res.down = a.down*b.down;
        res.up = a.up*b.down + a.down*b.up;
        reduction(res);
        return res;
    }


};
