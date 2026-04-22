class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         res = max(res,min(height[i],height[j])*(j-i));
        //     }
        // }

        int l =0,r=n-1;

        while(l<r){
            res = max(res,min(height[l],height[r])*(r-l));
            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};