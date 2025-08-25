class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res;
        int dir = 1, n = mat.size(), m = mat[0].size(),i=0,j=0;
        res.push_back(mat[0][0]);
        while((i<n && j<m && i>=0 && j>=0)){ 
            // movement : ((i+1) && (j-1)) || ((i-1) && (j+1))
   
            if((i == 0 || (i == n-1 )) && (j+1)<m)
                j++;
            else if( i==0 && (j+1) == m)
                i++;
            else if(j == 0 || (j == m-1))
                i++;
            
            if(!(i<n && j<m && i>=0 && j>=0))
                break;

            res.push_back(mat[i][j]);
            if( (i+1) <n && (j-1) >=0){
                while(i<(n-1) && j>0){
                    i++;
                    j--;
                    res.push_back(mat[i][j]);
                }
            } else{
                while(i>0 && j<(m-1)){
                    i--;
                    j++;
                    res.push_back(mat[i][j]);
                }
            }
        }
        
        return res;
    }
};