class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for (int i=0;i<n;i++){
            if(matrix[i][m-1] == target){
                return 1;
            }
            if(matrix[i][m-1] > target){
                for (int j= 0;j<m;j++){
                    if(matrix[i][j] == target){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0;i< matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==target){
                    return 1;
                }
            }
        }
        return 0;
    }
};