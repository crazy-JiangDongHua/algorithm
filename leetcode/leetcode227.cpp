class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
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
                if(!ops.empty() && cmp(ops.top(), s[i])>0)
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
                        case '*':
                            nums.push(num1*num2);
                            break;
                        case '/':
                            nums.push(num1/num2);
                            break;
                    }
                    ops.pop();
                }
                else
                {
                    ops.push(s[i]);
                    i++;
                }

            }
        }

        while(!ops.empty())
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
                case '*':
                    nums.push(num1*num2);
                    break;
                case '/':
                    nums.push(num1/num2);
                    break;
            }
            ops.pop();
        }
        return nums.top();
    }

    int cmp(char op1, char op2)
    {
        if((op1=='+' || op1=='-') && (op2=='*' || op2=='/'))
            return -1;
        return 1;
    }
};
