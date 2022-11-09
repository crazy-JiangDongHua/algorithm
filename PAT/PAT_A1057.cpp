#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
const int N=100010;
const int sqrN=316;
int n,x;
int ht[N];
int block[sqrN+1];
string cmd;

void peekMedian(){
    int k=(s.size()+1)/2;
    int i=0,sum=0;
    while(sum<k){
        sum+=block[i++];
    }
    sum-=block[i-1];
    i=(i-1)*sqrN;
    while(sum<k){
        sum+=ht[i++];
    }
    printf("%d\n",i-1);
}

void push(int num){
    s.push(num);
    ht[num]++;
    block[num/sqrN]++;
}

void pop(){
    int num=s.top();
    s.pop();
    ht[num]--;
    block[num/sqrN]--;
    printf("%d\n", num);
}

int main(){
    cin>>n;
    while(n--){
        cin>>cmd;
        if(cmd=="Pop"){
            if(s.empty())
                printf("Invalid\n");
            else
                pop();
        }else if(cmd=="PeekMedian"){
            if(s.empty())
                printf("Invalid\n");
            else
                peekMedian();
        }else{
            cin>>x;
            push(x);
        }
    }
    return 0;
}