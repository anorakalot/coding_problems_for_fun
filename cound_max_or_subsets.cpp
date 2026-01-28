class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //trying to think of a bitwise approach that's not just o(n^2) looping through and trying each possible combination

        //wouldn't the max always be all of them together? then it's just a matter of which subsets equal it?
        // cout<<"nums.size()"<< nums.size()<< endl;
        int max_value = 0;
        for (int x = 0; x < nums.size(); x++){
            max_value |= nums[x];
        }

        cout << max_value << endl;

        //would a good way to be checking if the value has a bit set at one of them the max_value is set at?
        //get the subset 2^n then minus all the ones that aren't have the bit values?

        //but all of them would have the bit values

        //woiudn't the combinations just be whichever ones that have the most bits. like if 

        //ok so looking up it's possible to get all subsets using a bit table for the maximum 


        int total_subsets = pow(2,nums.size());

        cout << "total_subsets " << total_subsets << endl;

        //can change to start at 1 since 0 wouldn't matter anyway
        for(int x = 1; x < total_subsets; x++){
            //then based off the binary of each of these get the subset that's from the array index
            //so the way I'm thinking of right now is a for loopwith each bit checking with an and but that's not good

            //is there a fast way to convert a number with it's bits set to 1 to indexes
            //
            
        }
        return 0;//placeholder
    }
};