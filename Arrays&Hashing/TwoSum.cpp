class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // 1. brute force

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }

        // 2. vector pair
        // vector<pair<int,int>> v;

        // for(int i=0;i<n;i++){
        //     v.push_back({nums[i],i});
        // }

        // sort(v.begin(),v.end());

        // int i=0;
        // int j=n-1;

        // while(i<j){
        //     int sum = v[i].first+v[j].first;

        //     if(sum == target){
        //         return {min(v[i].second,v[j].second),max(v[i].second,v[j].second)};
        //     }
        //     else if(sum < target){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }

        // 3. map using count
        // unordered_map<int,int> map;

        // for(int i=0;i<n;i++){
        //     map[nums[i]] = i;
        // }
        // for(int i=0;i<n;i++){
        //     int diff = target - nums[i];
        //     if(map.count(diff) && map[diff]!=i){
        //         return {i,map[diff]};
        //     }
        // }
        
        //using find in the map
        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
            int diff = target - nums[i];
            if(map.find(diff)!=map.end()){
                return {map[diff],i};
            }
            map.insert({nums[i],i});
        }

        return {};
    }
};