class Solution {
public:
    string convertToTitle(int columnNumber) {

        string return_str;

        int curr_val = columnNumber;
        char curr_char = '@';

        while(!(curr_val <=0)){
        
        cout << "curr_val pos 1: " << curr_val <<endl;
        if (curr_val <= 26){
            curr_char  += curr_val;
            curr_val = -1;
            //set it to 0
        }
       
        
        else{
         cout << "curr_val pos 2: " << curr_val <<endl;
            while (curr_val >26 && curr_char != '['){


                curr_val -= 26;
                //maybe if it reaches z but needs to go over then we make it so that it goes over back to A because this means 
                //it needs to do another
                curr_char +=1;
                }
            if (curr_char == '['){
                curr_char = 'A';
            }
        }
        cout << "curr_val pos 3: " << curr_val <<endl;
        

     cout << curr_char << endl;
     return_str.push_back(curr_char);
     
     //reset it back to curr_char
     curr_char = '@';
    }
        
        

       //26*26 + 26 = 702 (ZZ the last of the 2 letters)
        




        //maybe do it manually for 3 letters and see if that helps find the correct loop algo?
        return return_str;


        //maybe 703 since it's over 27? that's the pattern
    }
};