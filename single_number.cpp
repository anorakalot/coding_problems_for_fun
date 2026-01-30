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

        
        for (int x = 0; x < nums.size(); x++){
            // if ( (curr_val & nums[x]) != first_val){
            //     return nums[x];
            // }    
            
            // 0100 ^ 0001 = 0101 ^ 0010 = 0110 
            //oh wait a matching pair would make the value less than?
        }

        //hint said xor?
        //0010 ^ 0010 = 0;
        //if they're both equal they would be 0
        //so consecetive would be solved if one index and the other were 0 you could cancel bth of those as suspects
        //but that doesn't fix non consective like 4,1,2,1,2

        //maybe 2 pointers?
        //maybe because it only needs to go through a couple indexes not all of them no but what if the twice are far apart.
        //0100 ^ 0001 = 0101 maybe for loop is if it's greater?


        //ok so for 2 2 1
        // 0010 0010 0001

        //ok wait wouldn't change based on how many nums.size it is if it's 5 
        //there's 2 matching pairs



        //an easy one would be to sort then do this but can't do that (and to check)
        //also can't do double for loop just loop twice checking each number


        return 0;
    }
};