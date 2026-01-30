class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //maybe something with and?

        int curr_val = 0xFF & nums[0];
        int first_val = curr_val;

        for (int x = 1; x < nums.size(); x++){
            if ( (curr_val & nums[x]) != first_val){
                return nums[x];
            }    
        }

        //ok so for 2 2 1
        // 0010 0010 0001

        //an easy one would be to sort then do this but can't do that (and to check)


        //also can't do double for loop just loop twice checking each number


        return 0;
    }
};