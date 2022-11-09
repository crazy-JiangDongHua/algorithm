#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

string deal(string& s, int& e, int n)
{
	// 去除前导 0 
	while(s.length()>0 && s[0]=='0')
		s.erase(s.begin());
	
	if(s.length()>0)
	{
		// 0000.00abc
		if(s[0]=='.')
		{
			s.erase(s.begin());
			e = 0;
			while(s.length()>0 && s[0]=='0')
			{
				s.erase(s.begin());
				e--;
			}
		}
		else // 000abc.abc
		{
			e = 0;
			int k = 0;
			while(k<s.length() && s[k]!='.')
			{
				e++;
				k++;
			}
			if(k<s.length())
				s.erase(s.begin()+k);
		}
	}
	
	// 0000 or 000.000
	if(s.length()==0)
		e = 0;
	
	string res;
	if(n<=s.length())
		res = s.substr(0,n);
	else
	{
		res = s;
		int num = s.length();
		while(num<n)
		{
			res+="0";
			num++;
		}
	}
	return res;
}

int main()
{
	int digit;
	string num1, num2;
	cin >> digit >> num1 >> num2;
	
	int e1,e2;
	num1 = deal(num1, e1, digit);
	num2 = deal(num2, e2, digit);
	
	if(e1==e2 && num1==num2)
		cout << "YES " << "0." << num1 << "*10^" << e1; 
	else
		cout << "NO " << "0." << num1 << "*10^" << e1 << " " << "0." << num2 << "*10^" << e2;
	return 0;	
} 
