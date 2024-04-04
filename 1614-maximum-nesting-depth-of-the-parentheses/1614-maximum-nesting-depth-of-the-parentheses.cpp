class Solution {
public:
    int maxDepth(string s) {
        int d=0;
        stack<char>st;
        for(auto ch:s){
            if(ch=='(') st.push(ch);
            else if(ch==')') st.pop();
            d=max(d,(int)st.size());
        }
        return d;
    }
};