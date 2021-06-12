class Solution {
public:
    int romanToInt(string s) {
        int output;
        for (int x = 0; x < s.size(); x++){
           
           //if ()
           
           cout << "x " << x << endl;
           cout << "s[x]" << s[x] << endl;
//            if (s[x] == 'I'){
//                 if (s[x+1] == 'V'){
//                   output += 4;
//                   x += 2;//skip ahead 2 places since we already use the next string variable  
//                 }
//                 else if (s[x+1] == 'X'){
//                     output += 9;
//                     x+= 2;
//                 }
//                 else{//just add 1
//                     output += 1;
//                 }               
//            }
//            else if (s[x] == 'V'){
//                output += 5;
//            }   
//            else if (s[x] == 'X'){
//                if (s[x+1] == 'L'){
//                         output += 40;
//                         x+= 2;
//                 }
//                 else if (s[x+1] == 'C'){
//                     output += 90;
//                     x+= 2;
//                 }
//                 else{
//                     output += 10;
//                 }
//            }
//             else if (s[x] == 'L'){
//                 output += 50;
//             }
         
//             else if (s[x] == 'C'){
//                 if (s[x+1] == 'D'){
//                         output += 400;
//                         x+= 2;
//                     }
//                 else if (s[x+1] == 'M'){
//                     output += 900;
//                     x+= 2;
//                 }
//                 else{
//                     output += 100;
//                 }
//             }
//             else if (s[x] == 'D'){
//                 output += 500;
//             }
//             else if (s[x] == 'M'){
//                   output += 1000;
//             }
            switch(s[x]){
                case 'I':
                    //output +=1;
                    if (s[x+1] == 'V'){
                      output += 4;
                      x += 2;//skip ahead 2 places since we already use the next string variable  
                    }
                    else if (s[x+1] == 'X'){
                        output += 9;
                        x+= 2;
                    }
                    else{//just add 1
                        output += 1;
                    }
                    break;
                case 'V':
                    output += 5;
                    break;
                case 'X':
                    if (s[x+1] == 'L'){
                        output += 40;
                        x+= 2;
                    }
                    else if (s[x+1] == 'C'){
                        output += 90;
                        x+= 2;
                    }
                    else{
                        output += 10;
                    }
                    break;
                case 'L':
                    output += 50;
                    break;
                case 'C':
                    if (s[x+1] == 'D'){
                        output += 400;
                        x+= 2;
                    }
                    else if (s[x+1] == 'M'){
                        output += 900;
                        x+= 2;
                    }
                    else{
                        output += 100;
                    }
                    break;
                    
                case 'D':
                    output += 500;
                    break;
                case 'M':
                    output += 1000;
                    break;
                    
            }//end of switch statement
       }//end of for loop 
        return output;
           
    }//end of function
};