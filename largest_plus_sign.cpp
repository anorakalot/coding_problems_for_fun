#include <iostream>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        //vector<vector<int>> grid(10);
//         vector<int> test_vec;
        
//         for (int test = 0; test < 10; test ++){
//             test_vec.push_back(test);
//            cout <<  test << endl;
//         }
        int grid[n][n];
        //cout <<"mines" <<mines[0][1]<< endl;
        // vector<int> mines_y_pos;
        // vector<int> mines_x_pos;
        //vector<tuple<int,int>> mines_pos;
        vector<pair<int,int>> mines_pos;
        
        cout << "MINES" << endl;
        for(int a = 0; a <  mines.size(); a++){
            for (int b=0; b < mines[a].size(); b+=2){
                cout << "a value:" <<a <<endl;
                cout << "b value:" <<b << endl;
                cout <<"mines[a][b]" <<mines[a][b] << endl;
                
                mines_pos.push_back(make_pair(mines[a][b],mines[a][b+1]));
                cout << "mines_pos[0].first" << mines_pos[a].first << endl;
                cout << "mines_pos[0].second" << mines_pos[a].second << endl;
                //mines_pos.push_back(make_tuple(a,b));
                //tuple<int,int> test = make_tuple(a,b);
                //cout << get<0>test << endl;
                //pair<int,int>  test = make_pair(a,b);
                //cout << test.second << endl;
                //cout << get<1>test << endl;
                // cout << get<0>(mines_pos[0]) << endl;
            }
        }
            
        
        cout << "GRID" << endl;
        int pos_is_mine = 0;
        for (int y = 0; y <n; y++ ){
            
            for(int x = 0; x < n; x++){
                pos_is_mine = 0;
                // //cout <<  mines[y][x]  << endl;
                // if (y < mines.size() || x < mines[a].size){
                //     mines[y]
                // }
                
                for(int i = 0; i < mines_pos.size(); i++){
                  if(mines_pos[i].first == y){
                      if(mines_pos[i].second == x){
                          pos_is_mine = 1;
                          break;
                      }
                  }  
                }//end of looking through mines 
                if (pos_is_mine == 1){
                    grid[y][x] = 0;
                }
                else{
                grid[y][x] = 1;
                }
                // if (mines[y][x] )
                cout << grid[y][x] << " ";
            }
            cout << endl;
        }//end of outer for loop constructing grid;
        
        // //adding mines_position
        // for(int i = 0; i < mies_pos.size(); i++){
        //     grid[mines_pos[]]
        // }
        
        
        return 0;
    }//end of order of largest plus sign function
};