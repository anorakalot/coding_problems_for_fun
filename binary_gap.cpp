using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        //ok so a preliminary solution is to do just a bit loop over each bit (masking with and to get only the value we're looking at right now)
        // then left shift that bit mask by 1

        int mask = 0x01;

        int highest_counter = 0;
        int curr_counter = 0;
        int curr_val = 0;

        bool one_is_found = false;
        bool first_one_is_found = false;
        bool second_one_is_found = false;
        //first check that it starts at a 1 then keep track of the times it shows up a 1 then 2 different cases based if 
        //there already was a one or not


        //!!!oh wait now I get it it's because need to differentiate between finding ending 1 and only finding the first 1 and nothing else

        //now just need to reset to
        for (int x = 0; x < 10; x++){
            //meaning there's a 1 at this bit value spot
            cout << "mask" << mask << endl;
            cout <<"n " << n << endl;
            curr_val = mask & n;
            cout <<"mask & n " << curr_val << endl;
            
            if ((curr_val) > 0){
                if(first_one_is_found == false){
                    cout << "first_one_is_found == 1"<< endl;
                    first_one_is_found = true;
                }
            
                //this is the last one it found
                //it was already found a 1
                else if (first_one_is_found == true){
                    // second_one_is_found = true;
                    curr_counter += 1;
                    cout << "curr counter found second one : " << curr_counter << endl;
                    if (curr_counter > highest_counter){
                        highest_counter = curr_counter;
                    }
                    curr_counter = 0;
                    first_one_is_found = true;
                }
            }

            else if (first_one_is_found == true){

                curr_counter +=1;
                cout << "curr counter only first one is found : " << curr_counter << endl;
                // if (curr_counter > highest_counter){
                //         highest_counter = curr_counter;
                // }
            }
            mask <<= 1;

            cout << endl<<endl;



        }//end of for loop 

        return highest_counter;
    }
};