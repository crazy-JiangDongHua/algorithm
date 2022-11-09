// 遍历两遍
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0, n=gas.size();
        int start=0;
        while(start<n){
            int sum=0,i;
            for(i=0;i<=n;i++){
                int pos=(start+i)%n;
                sum+=gas[pos]-cost[pos];
                if(sum<0){
                    start+=i+1;
                    break;
                }
            }
            if(i>n)
                return start;
        }
        return -1;
    }
};

//遍历一遍
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0, total=0, n=gas.size(), start=0;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0){
                start=i+1;
                sum=0;
            }
        }
        return total>=0?start:-1;
    }
};