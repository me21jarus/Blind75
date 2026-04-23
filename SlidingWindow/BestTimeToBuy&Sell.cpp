class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        // 1.Brute force using  2 loops
        // for(int i=0;i<n;i++){
        //     int buy = prices[i];
        //     for(int j=i+1;j<n;j++){
        //         int sell = prices[j];
        //         ans = max(ans, (sell-buy));
        //     }
        // }

        // 2.using 2 pointer approach
        // int i=0,j=1;
        // while(j<n){
        //     if(prices[i]<prices[j]){
        //         int profit = prices[j] - prices[i];
        //         ans = max(profit,ans);
        //     }
        //     else{
        //         i=j;
        //     }
        //     j++;
        // }

        // 3.using dp
        int minBuy = prices[0];
        for(int& sell:prices){
            ans=max(ans,sell-minBuy);
            minBuy = min(minBuy,sell);
        }
        
        return ans;
    }
};