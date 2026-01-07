class Solution {
public:
    string convertToTitle(int columnNumber) {

        string return_str;

        int curr_val = columnNumber;
        char first_char = '@';
        char second_char = '@';

        if (curr_val <= 26){
            first_char += curr_val;
            curr_val = -1;
            //set it to 0
        }

        while (curr_val >26){
            curr_val -= 26;
            //maybe something here since 703 instead of AAA is [A  ? oh but [ is right after Z in the ascii chart
            // if (first_char <= 'A'){
            //     break;
            // }
            first_char+=1;
        }
        
        cout << first_char<< endl;

        return_str.push_back(first_char);

        cout <<"curr_val before second char" <<curr_val<< endl;
        //do the secondchar;
        if (curr_val <= 26 && curr_val != -1){
            second_char += curr_val;
            curr_val = -1;
            return_str.push_back(second_char);
        }


        //ok so the thing is I know the loop structure should be 
        //curr_val -= 26 until it gets to less than 26

        // need to find out how to make this loop work with multiple letters (not just 2)

        //maybe do it manually for 3 letters and see if that helps find the correct loop algo?
        return return_str;
    }
};