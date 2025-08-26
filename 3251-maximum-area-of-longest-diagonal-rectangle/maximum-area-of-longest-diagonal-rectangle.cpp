// class Solution {
// public:
//     int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
//     int maxiarea =INT_MIN;
//     int n = dimensions.size();
//     for(int i=0;i<n;i++){
//         int area=1;
//         for(int j=0;j<2;j++){
//             area *= dimensions[i][j];

//         }
//         maxiarea = max(area,maxiarea);
//     }
//     return maxiarea;
        

//     }
// };
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = -1;   // store squared diagonal
        int maxArea = -1;     // store area of rectangle
        int n = dimensions.size();

        for (int i = 0; i < n; i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            
            int diagSq = length * length + width * width; // (L^2 + W^2)
            int area = length * width;

            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }
        return maxArea;
    }
};
