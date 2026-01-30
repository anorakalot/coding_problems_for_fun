class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //maybe something with and?

        //base case out of the way
        if(nums.size() == 1){
            return nums[0];
        }

        int curr_val = 0xFF & nums[0];
        int first_val = curr_val;

        int num_of_matching_pairs = (nums.size() -1) / 2;

        cout << "num_of_matching_pairs: " <<num_of_matching_pairs << endl;

        
        for (int x = 1; x < nums.size(); x++){
            // if ( (curr_val & nums[x]) != first_val){
            //     return nums[x];
            // }    
        }


        //ok so for 2 2 1
        // 0010 0010 0001

        //ok wait wouldn't change based on how many nums.size it is if it's 5 
        //there's 2 matching pairs



        //an easy one would be to sort then do this but can't do that (and to check)
        //also can't do double for loop just loop twice checking each number


        return 0;
    }
};