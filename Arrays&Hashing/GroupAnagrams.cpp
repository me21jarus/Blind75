class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string,vector<string>> map;

        vector<vector<string>> ans;
        
        // 1. using sorting
        // for(auto& s:strs){
        //     string dup = s;
        //     sort(dup.begin(),dup.end());
        //     map[dup].push_back(s);
        // }
        // for(auto& pair:map){
        //     ans.push_back(pair.second);
        // }

        // 2.using hash table
        for(auto& s:strs){
            vector<int> count(26,0);
            for(char c:s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1;i<26;i++){
                key+= ','+count[i];
            }
            map[key].push_back(s);
        }
        for(auto& pair:map){
            ans.push_back(pair.second);
        }
        return ans;
    }
};