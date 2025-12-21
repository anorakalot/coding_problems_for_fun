class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //maybe the solution relies on filling out each bit?


        //maybe loop through each one

        //it seems it's how many are in the nums.size()-1 

        std::cout<<(nums.size())<< std::endl;
        
        //you could also just do a hash map

        //or maybe it's soemthing with 9

        //ok could also do something like have a vector initialize all to zeros and if that number is in nums
        //add a 1 at that nums index then do another for loop through it
        vector<int> checking_values(nums.size(),0);
        
        for (int x = 0; x < nums.size(); x++){
            checking_values[nums[x]] = 1;
        }

        for (int y = 0; y < checking_values.size(); y++){
            if (checking_values[y] != 1){
                return y;
            }
        }


        return 0;
    }
};