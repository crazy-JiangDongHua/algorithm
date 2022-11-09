#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 40010;
// char snames[MAXN][5];
unordered_map<string, vector<int> > mp;
int n,k,cid;
string sname;

int main()
{
	cin>>n>>k;
	while(k--)
	{
		cin>>cid>>n;
		while(n--)
		{
			cin>> sname;
			unordered_map<string, vector<int> >::iterator it = mp.find(sname);
			if(it != mp.end())
			{
				it->second.push_back(cid);
			}
			else
			{
				mp.insert(pair<string, vector<int> >(sname, {cid}));
			}
		}
	}
	while(cin>>sname)
	{
		cout<<sname;
		unordered_map<string, vector<int> >::iterator it = mp.find(sname);
		if(it == mp.end())
		{
			cout<<" 0"<<endl;
			continue;
		}
		sort(it->second.begin(), it->second.end());
		cout<<" "<<it->second.size();
		for(int i=0;i<it->second.size();i++)
			cout<<" "<<it->second[i];
		cout<<endl;
	}
	return 0;	
} 
