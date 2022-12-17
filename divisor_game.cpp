class Solution {
public:
    int num_of_times=0;
    int return_val;
    bool divisorGame(int n) {
        if (n <=1){//set up base case
            printf("inside recursion base case\n");
            printf("num_of_times %i\n",num_of_times);
            if (num_of_times %2 == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
        num_of_times +=1;
        return_val = divisorGame(n-1);
        printf("return_val = %i\n",return_val);
        return return_val;
        //return 0; //placeholder
    }
};