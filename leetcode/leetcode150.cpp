class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++)
        {
            if(string("+-*/").find(tokens[i]) != string::npos)
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch(tokens[i][0])
                {
                    case '+':
                        stk.push(num1+num2);
                        break;
                    case '-':
                        stk.push(num1-num2);
                        break;
                    case '*':
                        stk.push(num1*num2);
                        break;
                    case '/': 
                        stk.push(num1/num2);
                        break;         
                }
            }
            else
            {
                int num = 0;
                int j=0;
                int flag=1;
                if(tokens[i][j]=='-')
                {
                    j++;
                    flag=-1;
                }
                for(;j<tokens[i].size();j++)
                    num = num*10 + (tokens[i][j]-'0');
                stk.push(num*flag);
            }
        }
        return stk.top();
    }
};
