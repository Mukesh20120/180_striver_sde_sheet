class Solution {
public:
    double myPow(double x, int n) {
        bool neg=false;
        if(n<0)
            neg=true;
        double ans=1;
        while(n){
            if(n&1)
                ans*=x;
            n/=2;
            x*=x;
        }
        if(neg)
            return 1/ans;
        return ans;
    }
};