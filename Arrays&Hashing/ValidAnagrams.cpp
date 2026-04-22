class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n!=m){
            return false;
        }

        // 1. Brute Force
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s == t;

        // 2.using hash map

        // unordered_map<char,int> countS;
        // unordered_map<char,int> countT;

        // for(int i=0;i<n;i++){
        //     countS[s[i]]++;
        //     countT[t[i]]++;
        // }
        // return countS == countT;

        //3. using vector
        vector<int> count(26,0);
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for(int val : count){
            if(val!=0){
                return false;
            }
        }
        return true;
    }
};