class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n){
            int rem=n%10;
            if(ans>INT_MAX/10 || ans <INT_MIN/10) return 0;
            ans=ans*10+rem;
            n=n/10;
        }
        return ans;
    }
    int reverse(int x) {
        return rev(x);
    }
};