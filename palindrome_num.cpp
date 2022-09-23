
class Solution {
public:
    bool isPalindrome(int x) {
        std::string input_str;
        int return_val=-1;//set to initial error val
        input_str = std::to_string(x);
        //printf("input_str= %s\n", input_str.c_str());
        int first_index= 0;
        int last_index = input_str.size()-1;
        //printf("last_index = %i\n",last_index);
        //printf("last_index_str = %c\n",input_str[last_index]);
        
        while(first_index < last_index){
            if(input_str[first_index] != input_str[last_index]){
                // printf("first_index_str != last_index_str");
                // printf("first_index_str = %c\n",input_str[first_index]);
                // printf("last_index_str = %c\n",input_str[last_index]);
                return_val = 0;
                break;
            }
            first_index += 1;
            last_index -=1;
            
        }
        if (return_val == -1){
            return_val = 1;
        }
        
        return return_val;
        //return 0;//placeholder for now
    }
};