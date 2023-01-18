class Solution {
public:
    int return_val;
    //vector<int> memo{38,0};//set up a vector with a size 38 and all values set to 0 initally
    int tribonacci(int n) {
        //if inside memoization
        printf("top of func\n");
        printf("n == %i\n",n);
        // if (memo[n] != 0){
        //     printf("if can use memo use memo\n");
        //     return memo[n];
        // }

        //base case
        if (n == 0){
            return 0;
        }
        else if (n == 1){
            return 1;
        }
        else if (n == 2){
            return 1;
        }

        else if (n >=3){
            //return_val = tribonacci(n)+ tribonacci(n-1) + tribonacci(n-2);
            return_val = tribonacci(n-1) + tribonacci(n-2)+ tribonacci(n-3);
        }
        printf("return_val == %i\n");
        // //save in vector memoization
        // if (memo[n] == 0 && n != 0){
        //     printf("can save inside memo\n");
        //     memo[n] = return_val;
        // }

        return return_val;


    }
};