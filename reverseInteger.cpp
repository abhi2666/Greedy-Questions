class Solution {
public:
    int reverse(int x) {
        long revNum = 0;
        bool negative = false;
        if(x < 0)
        {
            negative = true;
            x = abs(x);
        } 

        while(x > 0)
        {
            revNum = (revNum*10) + (x%10);
            x /= 10;
        }
        if(revNum > INT_MAX) return 0;

        return negative ? (int)(-1*revNum) : (int)revNum;
    }
};