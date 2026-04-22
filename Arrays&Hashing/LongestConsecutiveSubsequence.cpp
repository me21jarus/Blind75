class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        unordered_set<int> store(nums.begin(),nums.end());

        // 1.using brute force comparing next element in set
        // for(int num:nums){
        //     int streak = 0,curr = num;
        //     while(store.find(curr) != store.end()){
        //         streak++;
        //         curr++;
        //     }
        //     ans = max(ans,streak);
        // }

        // 2. sorting
        // int curr = nums[0], streak = 0,i=0;
        // if(nums.empty()) return 0;

        // sort(nums.begin(),nums.end());
        // while(i<n){
        //     if(nums[i]!=curr){
        //         curr = nums[i];
        //         streak = 0;
        //     }
        //     while(i<n && nums[i]==curr){
        //         i++;
        //     }
        //     streak++;
        //     curr++;
        //     ans = max(ans,streak);
        // }

        //3.using has set

        // for(int num:store){
        //     if(store.find(num-1) == store.end()){
        //         int len = 1;
        //         while(store.find(num+len)!=store.end()){
        //             len++;
        //         }
        //         ans = max (ans,len);
        //     }
        // }

        // 4.using hash map

        unordered_map<int,int> mp;

        for(int num:nums){
            if(!mp[num]){
                mp[num] = mp[num-1]+mp[num+1]+1;
                mp[num - mp[num-1]] = mp[num];
                mp[num + mp[num+1]] = mp[num];
                ans = max(ans,mp[num]);
            }
        }

        return ans;
    }
};