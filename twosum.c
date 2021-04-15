class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int> & nums, int target){
    int target_func = target;

    int comparison;
    bool found_answer = 0;
    vector<int> answer(2);
    for (int y = 0; y < nums.size(); y++){
        target_func -= nums[y];// minus the starting location of each search 
        
        for(int x = 0; x < nums.size(); x++){
           if (y == x ){
                continue;
            }
           comparison = (target_func - nums[x]);
           if(comparison == 0){
               answer[1] = x;
               found_answer = 1; //set boolean
               break;
            }
        }//end of inner for loop
        
        if(found_answer == 1){
            answer[0] = y;
            cout << "[" << answer[0] << "," << answer[1] << "]"<< endl;
            break;
        }
        target_func = target;
    }//end of outer for loop
    return answer;
}