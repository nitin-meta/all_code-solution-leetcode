class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        vector<int>res;
        unordered_set<int>st(num1.begin(),num1.end()),st1;
        for(auto it:num2){
            if(st.find(it)!=st.end()) st1.insert(it);
        }
        for(auto it:st1) res.push_back(it);
        return res;                     
    }
};