class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // using another matrixx and solving
        // vector<vector<int>> mark = matrix;
        // int rows = matrix.size();
        // int cols = matrix[0].size();

        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(matrix[i][j] == 0){
        //             for(int col = 0; col<cols;col++){
        //                 mark[i][col]=0;
        //             }
        //             for(int row = 0; row<rows;row++){
        //                 mark[row][j]=0;
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         matrix[i][j] = mark[i][j];
        //     }
        // }

        // using 2 vectors
        // int rows = matrix.size(), cols = matrix[0].size();

        // vector<bool> rowZero(rows,false);
        // vector<bool> colZero(cols,false);

        // for(int r = 0;r<rows;r++){
        //     for(int c = 0;c<cols;c++){
        //         if(matrix[r][c] == 0){
        //             rowZero[r] = true;
        //             colZero[c] = true;
        //         }
        //     }
        // }
        // for(int r = 0;r<rows;r++){
        //     for(int c = 0;c<cols;c++){
        //         if(rowZero[r] || colZero[c]){
        //             matrix[r][c] = 0;
        //         }
        //     }
        // }

        // using only 1 extra space
        int rows = matrix.size(), cols = matrix[0].size();

        bool rowZero = false;


        for(int r =0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    if(r>0){
                        matrix[r][0] = 0;
                    }
                    else{
                        rowZero = true;
                    }
                }
            }
        }
        for(int r =1;r<rows;r++){
            for(int c=1;c<cols;c++){
                if(matrix[r][0] == 0 || matrix[0][c] == 0){
                    matrix[r][c] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int r=0;r<rows;r++){
                matrix[r][0] = 0;
            }
        }
        if(rowZero){
            for(int c=0;c<cols;c++){
                matrix[0][c] = 0;
            }
        }
    }
};