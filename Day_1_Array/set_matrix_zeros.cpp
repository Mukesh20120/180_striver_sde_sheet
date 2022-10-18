class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //size
        int n=matrix.size();
        int m=matrix[0].size();
        
        //two integer reuqired for row and col
        bool row=false,col=false;
        
        //checking first col if we found 0 we mark col 0
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                 col=true;
                break;
            }
        }
        //checking first row if we found 0 means whole row is 0
        for(int j=0;j<m;j++){
             if(matrix[0][j]==0){
                 row=true;
                 break;
             }
        }
        
        //we will use the row 0 and and col 0 marking for 0 if have
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(matrix[i][j]==0){
                     matrix[0][j]=0;
                     matrix[i][0]=0;
                }
                   
        
        //changing the matrix
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
           
        if(row)
            for(int j=0;j<m;j++)
                matrix[0][j]=0;
        
        if(col)
            for(int i=0;i<n;i++)
                 matrix[i][0]=0;
                
            
        }
};