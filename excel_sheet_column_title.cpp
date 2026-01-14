class Solution {
public:
    string convertToTitle(int columnNumber) {

        string return_str;

        int curr_val = columnNumber;
        char curr_char = '@';

        while(!(curr_val <=0)){
        
        if (curr_val <= 26){
            curr_char  += curr_val;
            curr_val = -1;
            //set it to 0
        }

        else{
            while (curr_val >26 && curr_char != 'Z'){
                curr_val -= 26;
                //maybe something here since 703 instead of AAA is [A  ? oh but [ is right after Z in the ascii chart
                // if (first_char <= 'A'){
                //     break;
                // }
                curr_char +=1;
                }
        }

     cout << curr_char << endl;
     return_str.push_back(curr_char);

    }
        
        

       




        //ok so the thing is I know the loop structure should be 
        //curr_val -= 26 until it gets to less than 26

        // need to find out how to make this loop work with multiple letters (not just 2)

        //maybe do it manually for 3 letters and see if that helps find the correct loop algo?
        return return_str;


        //maybe 703 since it's over 27? that's the pattern
    }
};