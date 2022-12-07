// 数学方法
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n<1 || m<1)
            return -1;
        int last=0;
        for(int i=2;i<=n;i++){
            last=(last+m)%i;
        }
        return last;
    }
};

// 循环链表模拟 超时
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n<1 || m<1)
            return -1;
        list<int> l;
        for(int i=0;i<n;i++){
            l.push_back(i);
        }
        list<int>::iterator it=l.begin(), tmp;
        while(l.size()>1){
            for(int i=1;i<m;i++){
                it++;
                if(it==l.end())
                    it=l.begin();
            }
            tmp=next(it);
            if(tmp==l.end())
                tmp=l.begin();
            l.erase(it);
            it=tmp;
        }
        return *it;
    }
};