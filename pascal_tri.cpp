class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //vector<vector<int>>return_val = [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]];
        vector<vector<int>>return_val;
        return_val.resize(numRows,vector<int>(numRows));
        return return_val;
    }
};