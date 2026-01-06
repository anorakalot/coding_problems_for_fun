class Solution {
public:
    string convertToTitle(int columnNumber) {

        string return_str;


        int curr_val = columnNumber;
        char first_char = '@';
        char second_char = '@';

        if (curr_val < 26){
            first_char += curr_val;
            curr_val = -1;
            //set it to 0
        }

        while (curr_val >26){
            curr_val -= 26;
            first_char+=1;
        }
        
        cout << first_char<< endl;

        return_str.push_back(first_char);

        cout <<"curr_val before second char" <<curr_val<< endl;
        //do the secondchar;
        if (curr_val < 26 && curr_val != -1){
            second_char += curr_val;
            curr_val = -1;
            return_str.push_back(second_char);
        }

        

        return return_str;
    }
};