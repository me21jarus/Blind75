class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        //using 2 loops
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> count;
        //     int maxf = 0;
        //     for(int j=i;j<n;j++){
        //         count[s[j]]++;
        //         maxf = max(maxf, count[s[j]]);
        //         if((j-i+1) - maxf <= k){
        //             ans = max(ans, j-i+1);
        //         }
        //     }
        // }


        //using 1 loop sliding window
        int l = 0, maxf = 0;
        unordered_map<char,int> count;
        for(int r = 0; r < n; r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while((r-l+1) - maxf > k){
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};