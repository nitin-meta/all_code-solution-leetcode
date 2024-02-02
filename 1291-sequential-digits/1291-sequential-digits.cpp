class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
        queue<int>q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u>=low && u<=high) res.push_back(u);
            int rem=u%10;
            if(rem+1<=9){
                q.push(u*10+(rem+1));
            }
        }
        return res;
    }
};