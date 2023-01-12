class Solution {
public:
    int x = 0;
    int val = 0;
    bool return_val;
    bool isPowerOfThree(int n) {
        if (n ==0){
            return 0;
        }
        if (val > n){
            return 0;
        }
        else if (val==n){
            return 1;
        }

        //x+=1;
        val = pow(3,x);
        x+=1;
        return_val = isPowerOfThree(n);

        return return_val;

    }
};