class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // using extra space
        int n = matrix.size();
        // vector<vector<int>> rotate(n,vector<int>(n));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         rotate[j][n-1-i] = matrix[i][j];
        //     }
        // }

        // matrix = rotate;

        // using moving corners and others
        // int l = 0, r = n-1;
        // while(l<r){
        //     for(int i=0;i<r-l;i++){
        //         int top = l;
        //         int bottom = r;
        //         //save topleft
        //         int topLeft = matrix[top][l+i];

        //         //move bottomleft to topleft
        //         matrix[top][l+i] = matrix[bottom-i][l];

        //         //move bottomright to bottomleft
        //         matrix[bottom-i][l] = matrix[bottom][r-i];

        //         //move bottomleft to topright
        //         matrix[bottom][r-i] = matrix[top+i][r];

        //         //move top left to top right
        //         matrix[top+i][r] = topLeft;
        //     }
        //     r--;
        //     l++;
        // }

        // using reverse and transpose
        reverse(matrix.begin(),matrix.end());

        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};