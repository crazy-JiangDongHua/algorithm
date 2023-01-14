class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        unsigned int mask=~(((unsigned int)(~0))>>(32-(j-i+1))<<i);
        return (N&mask)|(M<<i);
    }
};