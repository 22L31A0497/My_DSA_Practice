// //class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         // int area =0;
//         // for(int i =0;i<height.size();i++){

//         //     for(int j =height.size()-1;j>i;j--){
               
//         //             area = max(area,((j-i)*min(height[i],height[j])));
//         //         }
            
//         }
//         return area;
//     }
//};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;        
    }
};