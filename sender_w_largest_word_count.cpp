class Solution {
public:
    //+1 for how many spaces there are in the messages
    map<string,int> s_to_m;
    map<string,int>::iterator it;
    int count=0;
    int max_value=0;
    string max_user;

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        max_value = 0;
        for (int y = 0; y < messages.size(); y++){
            count = 0;
            for (int x = 0; x< messages[y].size();x++){
                // printf("%c",messages[y][x]);
                if (messages[y][x] ==  ' '){
                    count +=1;
                }
            }
            s_to_m[senders[y]] += count +1;
            if (s_to_m[senders[y]] >= max_value){
                if (s_to_m[senders[y]] == max_value){
                    if (senders[y].size() > max_user.size()){
                        max_user = senders[y];
                    }
                }

                else{
                    max_value = s_to_m[senders[y]];
                    max_user = senders[y];
                }
            }
            printf("\n");
        }
        //printf("max_user == %s\n",max_user.c_str());
        for (it = s_to_m.begin(); it != s_to_m.end(); it++){
            printf("key == %s value == %i\n",it->first.c_str(),it->second);
            // if (it->second == max_value){
            //     if (it->first.size() > max_user.size()){
            //         max_user=it->first;
            //     }
            // }
            // else if (it->second > max_value){
            //     //printf("inside second\n");
            //     max_value = it->second;
            //     max_user = it->first;
            // }

        }

        printf("max_user %s max_value %i\n",max_user.c_str(),max_value);
        return max_user;


    }
};

        // printf("max_user == %s\n",max_user.c_str());
        // for (it = s_to_m.begin(); it != s_to_m.end(); it++){
        //     printf("key == %s value == %i\n",it->first.c_str(),it->second);
        // }
        //

        //return "apples";//just a placeholder