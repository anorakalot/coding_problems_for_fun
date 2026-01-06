class Solution {
public:
    string convertToTitle(int columnNumber) {
        //so the thing is divide by 26 and that's how many characters it goes up by
        //for the first one?

        //is there a way to automate the thing maybe a hashmap like 1 to A 2 to B 
        //that would save time execution but would take a little time to setup.

        //then the next thing is to find out how many letters there are
        //keep going until it's 26? then 

        //but that only seems to work for up to 2 what about 3 or more

        string return_str;


        //oh what the pattern is every 26 the first6 letter changes up by one
        //

        // maybe there's an easier addition method

        // return_str = 

        //at 53 it goes to BA

        //maybe first loop see how many letters there are first?
        //so if it's under 26 it's 1 it it's over 26 and under 703 it's 2 (there's no clean divisioni so probably do addition)
        //in the solution so it's easier

        //I don't think that's 

        //maybe have to do it as it's going on so maybe minus 26 each time and see what the remaining thing is and that's the alogirhtm?

        //so if more than 26 see what's remaining and if it's less than 26 correlate it to the remiaining

        //fudge it let's just solve it one 2 letters at least for now then expand the algorithm later

        //78 - 26 - 26
        //maybe keep it up to 0 - 26 then that's the last letter

        //so example algorithm is if it's over 26 keep minusing 26 until it's between 0 - 26 
        //the number of times it was minused 26 until it gets there is the first letter in the str;
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


        //do the secondchar;
        if (curr_val < 26 && curr_val != -1){
            second_char += curr_val;
            curr_val = -1;
        }


        return_str.push_back(second_char);

        // char
        //ok so this is failing due to not taking into account less than 26 right off the bat
        //and I still need to find a efficient way to map 26 and under
        //more ascii chart stuff? like - '0'


        //maybe make a char vector where the index corresponds to the number from 1 - 26 for the numbers?
        return return_str;
    }
};