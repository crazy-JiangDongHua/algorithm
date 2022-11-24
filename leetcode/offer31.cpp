class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size())
            return false;
        stack<int> s;
        auto it_push=pushed.begin(), it_pop=popped.begin();
        while(it_pop!=popped.end()){
            while(it_push!=pushed.end() && (s.empty() || s.top()!=*it_pop)){
                s.push(*it_push);
                it_push++;
            }
            if(s.top()!=*it_pop)
                return false;
            s.pop();
            it_pop++;
        }
        return it_push==pushed.end() && s.empty();
    }
};