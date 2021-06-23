class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> conv;
        //pair<int,string>
        conv.insert(make_pair(1,"I"));
        conv.insert(make_pair(5,"V"));
        conv.insert(make_pair(10,"X"));
        conv.insert(make_pair(50,"L"));
        conv.insert(make_pair(5,"V"));
        conv.insert(make_pair(5,"V"));
        conv.insert(make_pair(5,"V"));
        
            
        for (auto& x :conv){
            cout << x.first << " " << x.second;
        }
        
        //FOCUS ON NORMAL INT_SYMBOL VALUES BEFORE SPECIAL PLACEMENT EDGE CASES
        //the while loop will probably be infinite if edge case is present in loop
        //so I'm putting in a failsafe loop_counter for now
        
        
        int sub_value = 1000;//starting value for roman integer M which is highest
        while(){
            num -= sub_value;
            if (num<0) { //this means it's not the right amount since it should
                        //all come to zero exactly
                
            num += sub_value;   //add back up the value since it's not the correct sub value
            }
            else if (num > 0){
                cout << conv[sub_value]; //cout 
            }
            else if(num == 0){
                cout << conv[sub_value];
                break;//
            }
            sub_value /= 2;
            //at the end of a loop divide sub_value by half and then start loop again
            //since diff between symbols is half the previous one.
            
        }//end of while loop
        
        return "apples";//placeholder return fcuntion
    }//end of intToRoman question
};