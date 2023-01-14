class Solution {
public:
    int exchangeBits(int num) {
        unsigned int x=(unsigned int)(num);
        x=((x&0xaaaaaaaa)>>1) | ((x&0x55555555)<<1);
        return (int)(x);
    }
};