class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         map<int,bool> int_to_bool;
        
        int num_non_recur = nums.size();
        printf("num_non_recur (at start) = %i\n\n",num_non_recur);
        if (num_non_recur == 1){//to handle outlier case of 1 
            return num_non_recur;
        }
        //int only_one = 0;
        //int if_odd = 0;
        int redo_once = 0;
        int redo_cnt = 4;
        for (int x =0; x < nums.size(); x++){
            
            printf("current x = %i\n",x);
            printf("current nums[x] = %i\n",nums[x]);
            printf("inside of for loop\n");
            if (nums[x] == -101){
                printf("inside if nums[x] == -101\n");
                break;
            }
            //printf("%i\n",nums[x]);
            int z = x-1;
            //printf("x-1 = %i\n",z);
            //printf("test_3\n");
            if (x+1 <=nums.size()-1){//make sure in range of nums[x+1] comparison
                //printf("test_5\n");
                if (nums[x] == nums[x+1]){
                    // if (only_one == 0){
                    // only_one = 1;
                
                    printf("inside if nums[x] == nums[x+1] \n");
                    if (nums[x] != -101){
                        num_non_recur -=1;
                    }
                    //it's picking up zeroes at the end that's why num-non_recur keeps
                    //getting lowered
                    printf("(in_btw) num_non_recur = %i\n\n",num_non_recur);
                    //nums[x+1] = NULL;
                    nums[x+1] = -101;
                    for (int y = x+1; y < nums.size()-1; y++){
                        //printf("test_1\n");
                        if (y == nums.size()-1){
                            break;
                        }
                        nums[y] =nums[y+1];//error is here stops at test 1
                        //printf("test_2\n");
                        //nums[y+1] = NULL;
                        nums[y+1] = -101;
                    }
                        printf("DEBUG FOR LOOP IN X+1 COMP\n");
                        for (int z = 0; z < nums.size(); z++){
                            printf("%i ",nums[z]);
                        }
                        printf("\n\n");
                        printf("END OF DEBUG LOOP IN X+1 COMP\n");
                }//end of if nums[x] == nums[x+1]
                //}
            }
           //problem is else if not letting it go into this other comparison
            //else if (x-1 >= 0){//make sure there's range for nums[x-1] comparison
             if (x-1 >= 0){//make sure there's range for nums[x-1] comparison
                //printf("test 6\n");
  
                if (nums[x] == nums[x-1]){//bug is here [1,2]
                    // if (only_one == 0){
                    // only_one = 1;
                    printf("inside if nums[x] == nums[x-1]\n");
                    printf("current x %i\n ",x);
                    if (nums[x] != -101){
                    num_non_recur -=1;
                    }
                    //nums[x] = NULL;
                    nums[x] = -101;
                    for (int y = x;y< nums.size()-1; y++){
                        //printf("inside x-1 comp for loop restructuring vector\n");
                        nums[y] = nums[y+1];
                        //nums[y+1] = NULL;
                        nums[y+1] = -101;
                    }
                printf("DEBUG FOR LOOP IN X-1 COMP\n");
                for (int z = 0; z < nums.size(); z++){
                    printf("%i ",nums[z]);
                }
                printf("\n\n");
                printf("END OF DEBUG LOOP IN X-1 COMP\n");
                }//end of else if
                //}
            }
            //printf("test_4\n");
            printf("DEBUG FOR LOOP AT THE END\n");
            for (int z = 0; z < nums.size(); z++){
                printf("%i ",nums[z]);
            }
            printf("\n\n");
            printf("END OF DEBUG LOOP AT THE END\n");
            //only_one = 0;
            
            // if (redo_once ==1){
            //     redo_once = 0;
            // }
            // else if (redo_once ==0){
            //     x=x-1;
            //     redo_once = 1;
            // }
            
            //if(redo_cnt )
            
            //if still have stuff == to x+1 or x-1 stay on that x
            if (x+1 <=nums.size()-1){
                
                if (nums[x] == nums[x+1]){
                printf("inside ending x+1 comp\n");
                    
                
                if (x == 0){
                    printf("if equal to zero\n");
                    //x =0;//problem is still zero when added so it goes to 1
                    x = -1;
                }
                
                else{
                    x -=1;//redo at this specific x since it'll be +1 so it comes
                    
                    }
                }
                //out to the same
            }
            else if (x-1 >= 0){
                if (nums[x] == nums[x-1]){
                    x -=1;
                }
            }
            
        }//end of for loop
        printf("num_non_recur (at end) = %i",num_non_recur);
        return num_non_recur;
    }
};
//error is at -43 