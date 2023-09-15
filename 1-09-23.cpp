// Count Good Numbers

class Solution {
public:
    int mod =1e9+7;
    long long int solve(int k,long long int n)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return k;
        }
        if(n%2==0)
        {
            long long int t=solve(k,n/2);
            return ((t%mod)*(t%mod))%mod;
        }
        if(n%2!=0)
        {
            long long int t=solve(k,n/2);
            return ((t%mod)*(t%mod)*(k%mod))%mod;
        }
        return 0;
    }
    int countGoodNumbers(long long n) {
        if(n%2==0)
        {
            return ((solve(5,n/2)%mod)*(solve(4,n/2)%mod))%mod;
        }
        else{
            return ((solve(5,n/2+1)%mod)*(solve(4,n/2)%mod))%mod;
        }
    }
};
