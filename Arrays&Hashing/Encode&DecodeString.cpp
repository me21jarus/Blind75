class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";

        for(auto& s:strs){
            ans+=to_string(s.size())+"#"+s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i =0;
        while(i<s.size()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            ans.push_back(s.substr(i,len));
            i=j;
        }
        return ans;
    }
};
