class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        set<vector<int>> temp;
        sort(nums.begin(),nums.end());

        // 1.brute force with 3 loops
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k] == 0){
        //                 temp.insert({nums[i],nums[j],nums[k]});
        //             }
        //         }
        //     }
        // }
        // return vector<vector<int>> (temp.begin(),temp.end());

        // 2. using hashmap
        // unordered_map<int,int> mp;
        // for(int i:nums){
        //     mp[i]++;
        // }
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]--;
        //     if(i>0 && nums[i] == nums[i-1]) continue;
        //     for(int j = i+1;j<n;j++){
        //         mp[nums[j]]--;
        //         if(j>i+1 && nums[j] == nums[j-1]) continue;

        //         int target = -(nums[i]+nums[j]);
        //         if(mp[target]>0){
        //             ans.push_back({nums[i],nums[j],target});
        //         }
        //     }
        //     for(int j=i+1;j<n;j++){
        //         mp[nums[j]]++;
        //     }
        // }

        // 3. 2 pointer

        for(int i=0;i<n;i++){
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;

            int l = i+1,r = n-1;

            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];

                if(sum<0){l++;}
                else if(sum>0){r--;}
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return ans;
    }
};