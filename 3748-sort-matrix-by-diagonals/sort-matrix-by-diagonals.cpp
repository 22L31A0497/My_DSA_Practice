class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    vector<int> temp;
    int n = grid.size() , s ;
    if( n==1) return grid;
    //upper triangle...
    int i=0,j=0;
    for(int col_start=1 ; col_start<n ; col_start++){
        i=0 , j=col_start;
        temp.clear();
        while(i<n && j<n){
            temp.push_back(grid[i][j]);
            i++,j++;
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin() , temp.end());
        s = 0;
        i--;
        j--;
        while(i>=0 && j>=col_start){
            grid[i][j] = temp[s++];
            i--;
            j--;
        }
    }
    //lower triangle...
    for(int row_start=0 ; row_start<n ; row_start++){
        i=row_start , j=0;
        temp.clear();
        while(i<n && j<n){
            temp.push_back(grid[i][j]);
            i++,j++;
        }
        sort(temp.begin(),temp.end());
        s=0;
        i--;
        j--;
        while(i>=row_start && j>=0){
            grid[i][j] = temp[s++];
            i--,j--;
        }
    }
    return grid;
    }
};