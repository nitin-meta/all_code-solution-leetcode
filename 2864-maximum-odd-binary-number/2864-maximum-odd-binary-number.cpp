class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length(),i=0;
        string res=string(n,'0');
        for(char &ch:s){
            if(ch=='1'){
                if(res[n-1]=='1'){
                    res[i]='1';
                    i++;
            }
                else res[n-1]='1';
            }
        }
        return res;
    }
};