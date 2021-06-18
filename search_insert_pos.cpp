class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int half_point;
        
        int lower_bound = 0;
        int upper_bound = nums.size()-1;//to get index of last part of vector
        //int upper_bound = *nums.end();
        
        for(int x = 0; x < nums.size(); x++){
            cout << nums[x] << " ";
        }
        cout << endl;
        cout << "target " << target << endl;
        cout << "lower_bound " <<lower_bound << endl;
        cout << "upper_bound " <<upper_bound << endl;
        
                     //(0 + (3-0)) / 2 == 1.5 == 1)        
        half_point = (upper_bound + lower_bound) /2; //(lower_bound + (upper_bound-lower_bound))/ 2;
     
        cout<< "half_point_start_pos " << half_point << endl;
        cout << "nums[half_point] " << nums[half_point] << endl;
     
        
        while (nums[half_point] != target){ //&& (half_point /2 != 0) {
            
//             if (nums[half_point] != target){
//                       
//             }  
            //edge cases
            if (half_point == 0){//if it's zero and not the target then this is the correctg output
    
                break;
            }
            if (half_point >= nums.size() -1){
                break;
            }
            
            if (nums[half_point]> target){ //set lower half
                cout << "nums[half_point]> target set up lower _half" << endl;
                upper_bound = half_point-1;                
                //cout << ""
            }
            
            else if (nums[half_point]<target){ // set upper half 
                lower_bound = half_point +1; //move up lower_bound   
                cout << "nums[half_point]<target set up upper_half" << endl;
                //cout    
            } 
            
                        //2 + (3-2) / 2
            half_point = (upper_bound + lower_bound) / 2;//(lower_bound + (upper_bound-lower_bound))/ 2;
            cout << "half_point_new " << half_point << endl;
           }//end of while loop
        cout << "output is " << half_point << endl << endl;
        
        return half_point; // since it means half_point == target
        
        
      
        
         return 0;//placeholder for now
    
    }// end of function
};


  //testing
        // int test = 20; 
        // for (int x = 0; x < 10; x++){
        //     test /= 2;
        //     cout << test << endl;
        // }
        //int half_point = nums.size()/2;
             
//         if (nums[half_point] == target){
//             return half_point;
//         }
//         else if (nums[half_point] > target){
        
//             searchInsert()            
//         }
