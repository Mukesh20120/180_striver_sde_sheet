class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        //to rotate this without extra space
        //we need to transpose the matrix
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<i;j++)
                swap(mat[i][j],mat[j][i]);
            
        //now we need to reverse the row to get the 90 degree rotate
        for(int i=0;i<mat.size();i++)
          reverse(mat[i].begin(),mat[i].end());
    }
};