class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        //1. Brute Force
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }

        // 2. using sorting
        // sort(nums.begin(),nums.end());
        // for(int i = 1;i<n;i++){
        //     if(nums[i-1] == nums[i]){
        //         return true;
        //     }
        // }

        // 3. using set
        // unordered_set<int> set;
        // for(int num: nums){
        //     if(set.count(num)){
        //         return true;
        //     }
        //     set.insert(num);
        // }
        // return false;

        return unordered_set<int>(nums.begin(),nums.end()).size() < n;
    }
};