class Solution {
public:
//iterative solution
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

            int row_index_2d = 1;
            int first_col_index_2d = 0;
            int last_col_index_2d = 1;

            for (int x = 3 ; x <= numRows ; x++){
                if(x > 3){
                    curr_vec.clear();
                }
                curr_vec.resize(x);
                curr_vec[0] = 1;
                curr_vec[x-1] = 1;

                first_col_index_2d = 0;
                last_col_index_2d = 1;

               //maybe go through all of the ones with zerothen calculate what they should be
               //keep track of the 2 current indexes of the previous vector above it
               //then move them up 1 by 1 after adding and putting them together
               
               for(int z = 1; z < x-1; z++){
                 curr_vec[z] = return_2d_array[row_index_2d][first_col_index_2d] + 
                               return_2d_array[row_index_2d][last_col_index_2d];

               }
                
                
                row_index_2d += 1;

                /////////////////////
                //printout debugging
                cout << "curr_vec_array" << endl;
                for(int y = 0; y < x; y++){
                
                cout << curr_vec[y] << " ";
                cout << endl;
                //////////////////////

               }
               
               
            }

        }

    return return_2d_array;
    }
};