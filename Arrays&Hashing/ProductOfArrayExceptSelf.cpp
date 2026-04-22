class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        //1. Brute Force
        // for(int i=0;i<n;i++){
        //     int prod = 1;
        //     for(int j =0;j<n;j++){
        //         if(i!=j){
        //             prod*=nums[j];
        //         }
        //     }
        //     ans.push_back(prod);
        // }

        // 2. array with one pass
        // int prod = 1;
        // int zeroCount = 0;

        // for(int num:nums){
        //     if(num!=0){
        //         prod*= num;
        //     }
        //     else{
        //         zeroCount++;
        //     }
        // }

        // if(zeroCount>1){
        //     return vector<int>(n,0);
        // }

        // for(int i=0;i<n;i++){
        //     if(zeroCount > 0){
        //         ans[i] = (nums[i]==0) ? prod : 0;
        //     }
        //     else{
        //         ans[i] = prod/nums[i];
        //     }
        // }

        //3.using prefix and suffix
        // vector<int> prefix(n);
        // vector<int> suffix(n);

        // prefix[0] = 1;
        // suffix[n-1] = 1;

        // for(int i=1;i<n;i++){
        //     prefix[i] = nums[i-1]*prefix[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i] = nums[i+1]*suffix[i+1];
        // }
        // for(int i=0;i<n;i++){
        //     ans[i] = prefix[i]*suffix[i];
        // }
        
        //return ans;

        // 4. without using extra array
        vector<int> res(n,1);
        for(int i=1;i<n;i++){
            res[i] = res[i-1]*nums[i-1];
        }

        int postfix = 1;
        for(int i=n-1;i>=0;i--){
            res[i]*= postfix;
            postfix*=nums[i];
        }

        return res;
    }
};