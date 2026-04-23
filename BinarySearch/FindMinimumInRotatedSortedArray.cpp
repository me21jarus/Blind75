class Solution {
public:
    int findMin(vector<int>& nums) {
        // int ans = INT_MAX;

        int n = nums.size();

        //1.brute force
        // for(int i=0;i<n;i++){
        //     if(nums[i] < ans){
        //         ans = nums[i];
        //     }
        // }
        // return ans;

        // 2. using BS
        // int ans = nums[0];
        // int l = 0,r = n-1;
        // while(l<=r){
        //     if(nums[l]<nums[r]){
        //         ans = min(ans,nums[l]);
        //         break;
        //     }
        //     int mid = l + (r-l)/2;
        //     ans = min(ans,nums[mid]);
        //     if(nums[mid] >= nums[l]){
        //         l=mid+1;
        //     }
        //     else{
        //         r = mid-1;
        //     }
        // }
        // return ans;

        // 3. using BS with lower bound
        int l = 0, r = n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] < nums[r]){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return nums[l];
    }
};