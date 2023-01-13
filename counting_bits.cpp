class Solution {
public:
    int i=0;
    vector<int> return_val;
    int num_of_bits = 1;
    int num_of_ones = 0;

    vector<int> countBits(int n) {

        if ((i %2) == 0 && i != 0){//actually need to change i%2 since it would
                                    //work with numbers like 6 when it shouldn't
                                    //and only work for 1 2 4 8 16 32 etc
            num_of_bits +=1;
            num_of_ones = 1;
        }
        else if (i == 0){
            num_of_ones = 0;
        }
        else{//
            num_of_ones +=1;
        }
        return_val.push_back(num_of_ones);

        //should have operation before base case
        if (i == n)//base case for recusion
        {
            return return_val;
        }
        //need to have base case before recursion so that base case can return
        //before recusive call

        return_val = countBits(n);

        return return_val;

    }
};