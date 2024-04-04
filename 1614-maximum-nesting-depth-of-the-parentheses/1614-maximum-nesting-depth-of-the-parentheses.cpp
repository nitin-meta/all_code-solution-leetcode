class Solution {
public:
    int maxDepth(string s) {
        int bracket=0,d=0;
        for(auto ch:s){
            if(ch=='(') {
                bracket++;
                d=max(d,bracket);
            }
            else if(ch==')') bracket--;
        }
        return d;
    }
};