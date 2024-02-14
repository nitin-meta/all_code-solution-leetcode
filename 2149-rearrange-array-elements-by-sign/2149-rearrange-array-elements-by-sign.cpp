class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),i=0,j=1;
        vector<int>res(n);//necessary to declare size "n" else runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
        for(auto &it:nums){
            //Agar positive hua to even index
            if(it>0){
                res[i]=it;
                i+=2;
            }
            //Nhi to negative wala odd index pe
            else{
                res[j]=it;
                j+=2;
            }
        }
        return res;
    }
};