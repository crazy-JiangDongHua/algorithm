// 方法一 通用模板 注意一元负号变二元减法
class Solution {
private:
    // + - ( )
    int priorty[4][4] = {
        {1, 1, -1, 1},
        {1, 1, -1, 1},
        {-1, -1, -1, 0},
        {'\0', '\0', '\0', '\0'}
    };

public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        ops.push('(');
        s = s + ")";
        for(int i=0;i<s.length();)
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }
            else if('0'<=s[i] && s[i]<='9')
            {
                int num = 0;
                while(i<s.length() && '0'<=s[i] && s[i]<='9')
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                nums.push(num);
            }
            else
            {
                if(s[i]=='-')//一元变二元, 关键步骤
                {
                    bool flag = true; //假定是一元
                    int j = i-1;
                    while(j>=0)
                    {
                        if(s[j] == ' ')
                        {
                            j--;
                            continue;
                        }
                        else if('0'<=s[j] && s[j]<='9' || s[j]==')')
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        nums.push(0);
                }
                int tmp = cmp(ops.top(), s[i]);
                if(tmp>0)
                {
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    switch(ops.top())
                    {
                        case '+':
                            nums.push(num1+num2);
                            break;
                        case '-':
                            nums.push(num1-num2);
                            break;
                    }
                    ops.pop();
                }
                else if(tmp<0)
                {
                    ops.push(s[i]);
                    i++;
                }
                else //左右括号相遇
                {
                    ops.pop();
                    i++;
                }

            }
        }
        return nums.top();
    }

    int cmp(char op1, char op2)
    {
        int i,j;
        switch(op1)
        {
            case '+':
                i=0;break;
            case '-':
                i=1;break;
            case '(':
                i=2;break;
            case ')':
                i=3;break;
        };
        switch(op2)
        {
            case '+':
                j=0;break;
            case '-':
                j=1;break;
            case '(':
                j=2;break;
            case ')':
                j=3;break;
        };
        return priorty[i][j];
    }
}; 

// 方法二
class Solution {
public:
    int calculate(string s) {
        int res=0, n=s.length();
        stack<int> signs;
        signs.push(1);
        int sign = signs.top();
        for(int i=0;i<n;)
        {
            if(s[i]==' ')
            {
                i++;
            }
            else if(s[i]=='(')
            {
                signs.push(sign);
                i++;
            }
            else if(s[i]==')')
            {
                signs.pop();
                i++;
            }
            else if(s[i]=='+')
            {
                sign = signs.top();
                i++;
            }
            else if(s[i]=='-')
            {
                sign = signs.top()*-1;
                i++;
            }
            else
            {
                int num = 0;
                while(i<n && '0'<=s[i] && s[i]<='9')
                {
                    num = num*10 +(s[i]-'0');
                    i++;
                }
                res += num*sign;
            }
        }
        return res;
    }
}; 
