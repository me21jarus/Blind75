class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;

        // for(int i=0;i<32;i++){
        //     if((1<<i) & n){
        //         res++;
        //     }
        // }

        while(n!=0){
            res+= (n&1) ? 1 : 0;
            n = n>>1;
        }
        return res;
    }
};