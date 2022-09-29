class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         map<int,bool> int_to_bool;
        int num_non_recur = nums.size();
        //printf("%i\n\n",num_non_recur);
        for (int x =0; x < nums.size(); x++){
            //printf("%i\n",nums[x]);
            if (nums[x] == nums[x+1]){
                num_non_recur -=1;
                for (int y = x; y < nums.size(); y++){
                    nums[y] = nums[y+1];
                    nums[y+1]= NULL;
                    //debug for loop
                    //printf("DEBUG FOR LOOP\n");
                    for (int z = 0; z < nums.size(); z++){
                        //printf("%i\n",nums[z]);
                    }
                    //printf("END OF DEBUG LOOP");
                }
            }
        }//end of for loop
        return num_non_recur;
    }
};