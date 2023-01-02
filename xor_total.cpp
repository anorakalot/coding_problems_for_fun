class Solution {
public:
    int total_xor_val = 0;
    int curr_xor_val = 0;
    vector<int> curr_nums;
    map<vector<int>,int> nums_used_before;

    int subsetXORSum(vector<int>& nums) {

        if (nums_used_before[curr_nums] == 0){
            //meaning hasn't been used before
            //need to now do xor_total
            for (int x = 0; x < curr_nums.size(); x++){
                if (x==0){
                    curr_xor_val = curr_nums[x];
                }
                else{
                    curr_xor_val = curr_xor_val ^ curr_nums[x];
                }
            }//eofl
            printf("curr_xor_val == %i\n",curr_xor_val);
            printf("total_xor_val == %i\n",total_xor_val);

            //don't forget to set nums_used_before == 1 so it doesn't go off again for
            //this particular value

        }

        for (int x = 0; x < nums.size(); x++){
            curr_nums.push_back(nums[x]);
            subsetXORSum(nums);
            for (int z = 0; z < curr_nums.size(); z++){
                if (curr_nums[z] == nums[x]){

                }
            }
        }

        return total_xor_val;
        //return 5^1^6;//placeholder / checking xor operator
    }
};