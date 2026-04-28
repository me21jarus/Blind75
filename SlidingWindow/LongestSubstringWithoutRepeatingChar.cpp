class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // int ans = 0;

        // for(int i=0;i<n;i++){
        //     unordered_set<char> charSet;
        //     for(int j=i;j<n;j++){
        //         if(charSet.find(s[j])!=charSet.end()){
        //             break;
        //         }
        //         charSet.insert(s[j]);
        //     }
        //     ans = max(ans , (int)charSet.size());
        // }
        // return ans;


        unordered_set<char> charSet;
        int n = s.size();
        int ans = 0;
        int l = 0;

        for(int r = 0;r < n; r++){
            while(charSet.find(s[r])!=charSet.end()){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};