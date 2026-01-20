class Solution {
public:
    string convertToTitle(int columnNumber) {

        string return_str;

        int curr_val = columnNumber;
        char curr_char = '@';

        while(!(curr_val <=0)){
        
        cout << "curr_val pos 1 before if: " << curr_val <<endl;
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
                //ok so the above is further supported because it seems to only do curr_char == '[' when it's above 
                //2 letters//so maybe switch it  inside the loop take out the '[' loop condition
                
                curr_char +=1;
                if(curr_char == 'A'){
                    cout <<"is A at curr_val "<< curr_val << endl;
                    
                }

                if(curr_char == 'B'){
                    cout <<"is B at curr_val "<< curr_val << endl;
                    
                }

                if (curr_char >= '['){
                    cout <<"goes into curr_char == [" << endl;
                    cout <<"curr_val in == [: "<< curr_val << endl;
                    curr_char = 'A';
                }

                //maybe there's one more thing that determines if it shold stop other thancurr_char being past ascii chart
                //and it's the curr_val position
                //but I'm stumped on how it knows to stop until it's in the 2 letter range
                //so for 765 it currently outputs CK but the real output is ACK
                //so it's just missing the first letter 
                //maybe make it print at the letter it should be at and see what val it was at it
                //same thing with 810 (outputs ED and but correct output is AED)
                //920 is AEJ too?
                //oh wait maybe it's A until all combinations in the digits before so for 3 it's 2 happen then it's b
                //1600 BIN
                //1650 is BKL

                //maybe do the combination formula? and work backwards?

                }


        }
        cout << "curr_val pos 3 after if and else: " << curr_val <<endl;
        

     cout << curr_char << endl;
     return_str.push_back(curr_char);
     
     //reset it back to curr_char
     curr_char = '@';
    }
        
        

       //26*26 + 26 = 702 (ZZ the last of the 2 letters)
       // 26 ^ 3 + 26 + 26  = 17628 (still not last of 3 letters)




        //maybe do it manually for 3 letters and see if that helps find the correct loop algo?
        return return_str;


        //maybe 703 since it's over 27? that's the pattern
    }
};