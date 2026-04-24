class Solution {
public:
    int count(int n){
        int res = 0;
        while(n!=0){
            res+= (n&1) ? 1:0;
            n = n>>1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        // vector<int> ans;

        // for(int i=0;i<=n;i++){
        //     int res = count(i);
        //     ans.push_back(res);
        // }

        // return ans;

        vector<int> ans(n+1,0);

        for(int i=0;i<=n;i++){
            int num = i;
            while(num!=0){
                ans[i]++;
                num &=(num-1);
            }
        }
        return ans;
    }
};