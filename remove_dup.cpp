class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         map<int,bool> int_to_bool;
        
        int num_non_recur = nums.size();
        printf("num_non_recur = %i\n\n",num_non_recur);
        for (int x =0; x < nums.size(); x++){
            //printf("%i\n",nums[x]);
            if (nums[x] == nums[x+1]){
                //num_non_recur -=1;
                nums[x+1] = NULL;
                for (int y = x+1; y < nums.size(); y++){
                    nums[y] =nums[y+1];
                    nums[y+1] = NULL;
                }
                
            }//end of if 
            else if (nums[x] == nums[x-1]){
                nums[x] = NULL;
                for (int y = x;y< nums.size(); y++){
                    nums[y] = nums[y+1];
                    nums[y+1] = NULL;
                }
                
            }//end of else if
            printf("DEBUG FOR LOOP\n");
            for (int z = 0; z < nums.size(); z++){
                printf("%i ",nums[z]);
            }
            printf("\n\n");
            printf("END OF DEBUG LOOP\n");
        }//end of for loop
        printf("num_non_recur = %i",num_non_recur);
        return num_non_recur;
    }
};
