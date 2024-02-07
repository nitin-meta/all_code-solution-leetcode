class Solution {
public:
    
    typedef pair<char,int>P; 
    string frequencySort(string s) {
        vector<P>vec(123);
        for(auto it:s){
            int freq=vec[it].second;
            vec[it]={it,freq+1};
        }
        sort(vec.begin(),vec.end(),[&](P &p1,P&p2){
            return p1.second>p2.second;
        });
        string res;
        for(auto p:vec){
            res+=string(p.second,p.first);//short-hand 
        }
        return res;
    }
};