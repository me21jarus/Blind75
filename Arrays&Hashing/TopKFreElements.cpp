class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        int n = nums.size();

        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        // 1.using map and pair of vector

        // vector<pair<int,int>> v;
        // for(auto& temp : map){
        //     v.push_back({temp.second,temp.first});
        // }
        // sort(v.rbegin(),v.rend());
        // for(int i=0;i<k;i++){
        //     ans.push_back(v[i].second);
        // }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto& e:map){
            heap.push({e.second,e.first});
            if(heap.size() > k){heap.pop();}
        }
        for(int i=0;i<k;i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};