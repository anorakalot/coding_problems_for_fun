class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //it always starta with ones on the first and last indexes
        // and it increases the number by 1 per each one going down
        
        vector<vector<int>> return_2d_array;
        return_2d_array.push_back({1});

        if (numRows > 1 ){
            return_2d_array.push_back({{1,1}});   
        }

        //it always start with these 2
        
        if(numRows >= 2){

        
            vector<int> curr_vec;

            for (int x = 3 ; x < numRows ; x++){
                curr_vec.resize(x);
                cout << curr_vec.size() << endl;
            }

        }

    return return_2d_array;
    }
};