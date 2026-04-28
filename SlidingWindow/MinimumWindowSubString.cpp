class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int n = s.length();

        if(n < t.length() || s.empty() || t.empty()) return ans;
        if(s == t) return s;

        // unordered_map<char,int> mp;

        // for(auto& c : t){
        //     mp[c]++;
        // }

        // pair<int,int> res = {-1,-1};
        // int resLen = INT_MAX;

        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> countS;
        //     for(int j=i;j<n;j++){
        //         countS[s[j]]++;

        //         bool flag = true;
        //         for(auto &[c, cnt] : mp){
        //             if(countS[c] < cnt){
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if(flag && (j-i+1) < resLen){
        //             resLen = j-i+1;
        //             res = {i,j};
        //         }
        //     }
        // }

        unordered_map<char,int> window, countT;
        for(char c : t){
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        int l = 0;
        pair<int,int> res = {-1,-1};

        for(int r = 0;r<n;r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need){
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first,resLen);
    }
};