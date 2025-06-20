class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // first two hard-coded rows
        int arrx[1] = {1};
        int arry[2] = {1, 1};

        vector<vector<int>> mat;

        if (numRows == 1) {
            // wrap arrx in a vector and return
            mat.emplace_back(begin(arrx), end(arrx));
            return mat;
        }
        else if (numRows == 2) {
            // wrap arrx and arry and return
            mat.emplace_back(begin(arrx), end(arrx));
            mat.emplace_back(begin(arry), end(arry));
            return mat;
        }
        else{
            mat.emplace_back(std::begin(arrx), std::end(arrx));
            mat.emplace_back(std::begin(arry), std::end(arry));

            for (int i = 3; i <= numRows; ++i ){
                vector <int> newline(i);
                newline[0] = 1;
                newline[i-1] = 1;

                for (int y = 1; y < i-1; ++y ){
                    newline[y] = mat[i - 2][y - 1] + mat[i - 2][y];
                }
                mat.emplace_back(std::move(newline));
                }
            return mat;
        }
    }
};