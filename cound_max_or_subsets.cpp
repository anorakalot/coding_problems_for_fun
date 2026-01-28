class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //trying to think of a bitwise approach that's not just o(n^2) looping through and trying each possible combination


        //wouldn't the max always be all of them together? then it's just a matter of which subsets equal it?

        int max_value = 0;
        for (int x = 0; x < nums.size(); x++){
            max_value |= nums[x];
        }

        cout << max_value << endl;


        return 0;//placeholder
    }
};