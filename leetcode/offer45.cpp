#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const string& m, const string& n){
    return m+n<n+m;
};


string findMinNumber(const vector<int>& arr){
    vector<string> str_arr;
    for(const int& num:arr){
        str_arr.push_back(to_string(num));
    }
    sort(str_arr.begin(), str_arr.end(), cmp);
    string ans;
    for(const string& str:str_arr)
        ans+=str;
    return ans;
}

int main(){
    vector<int> test_case={3,32,321};
    string ans="321323";
    if(findMinNumber(test_case)==ans)
        cout<<"pass"<<endl;
    else
        cout<<"wrong answer"<<endl;
    return 0;
}