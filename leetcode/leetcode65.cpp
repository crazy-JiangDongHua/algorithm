class Solution {
private:
    enum State{
        STATE_INITIAL,
        STATE_SIGN,
        STATE_INTERGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INTERGE,
        STATE_FLOAT,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_INTEGER
    };
    enum CharType{
        NUMBER,
        SIGN,
        EXP,
        POINT,
        UNKONOW
    };
    CharType convert(char c){
        if('0'<=c && c<='9')
            return NUMBER;
        else if(c=='+' || c=='-')
            return SIGN;
        else if(c=='e' || c=='E')
            return EXP;
        else if(c=='.')
            return POINT;
        else
            return UNKONOW;
    }
public:
    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer={
            {
                STATE_INITIAL,{
                    {NUMBER, STATE_INTERGER},
                    {SIGN, STATE_SIGN},
                    {POINT, STATE_POINT_WITHOUT_INTERGE}
                }
            },
            {
                STATE_SIGN,{
                    {POINT, STATE_POINT_WITHOUT_INTERGE},
                    {NUMBER, STATE_INTERGER}
                }
            },
            {
                STATE_INTERGER,{
                    {POINT, STATE_POINT},
                    {EXP, STATE_EXP},
                    {NUMBER, STATE_INTERGER}
                }
            },
            {
                STATE_POINT_WITHOUT_INTERGE,{
                    {NUMBER, STATE_FLOAT}
                }
            },
            {
                STATE_POINT,{
                    {NUMBER, STATE_FLOAT},
                    {EXP, STATE_EXP}
                }
            },
            {
                STATE_FLOAT,{
                    {NUMBER, STATE_FLOAT},
                    {EXP, STATE_EXP}
                }
            },
            {
                STATE_EXP,{
                    {SIGN, STATE_EXP_SIGN},
                    {NUMBER, STATE_EXP_INTEGER}
                }
            },
            {
                STATE_EXP_SIGN,{
                    {NUMBER, STATE_EXP_INTEGER}
                }
            },
            {
                STATE_EXP_INTEGER,{
                    {NUMBER, STATE_EXP_INTEGER}
                }
            }
        };
        int n=s.length();
        State st=STATE_INITIAL;
        for(int i=0;i<n;i++){
            CharType ct=convert(s[i]);
            if(transfer[st].find(ct) == transfer[st].end()){
                return false;
            }else{
                st=transfer[st][ct];
            }
        }
        return st==STATE_INTERGER || st==STATE_POINT 
            || st==STATE_FLOAT || st==STATE_EXP_INTEGER;
    }
};