class Solution
{
public:
    //+1 for how many spaces there are in the messages
    map<string, int> s_to_m;
    map<string, int>::iterator it;
    int count = 0;
    int max_value = 0;
    string max_user;
    int comp_index_s = 0;
    int comp_index_mx = 0;
    char curr_s_char;
    char curr_mx_char;

    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        max_value = 0;
        for (int y = 0; y < messages.size(); y++)
        {
            count = 0;
            for (int x = 0; x < messages[y].size(); x++)
            {
                // printf("%c",messages[y][x]);
                if (messages[y][x] == ' ')
                {
                    count += 1;
                }
            }
            s_to_m[senders[y]] += count + 1;
            if (s_to_m[senders[y]] >= max_value)
            {
                if (s_to_m[senders[y]] == max_value)
                {
                    comp_index_s = 0;
                    comp_index_mx = 0;
                    while (true)
                    { // lexographically bigger check
                        printf("inside lexograph_check\n");
                        printf("senders[y][comp_index_s]== %i , %c\n", senders[y][comp_index_s],
                               senders[y][comp_index_s]);
                        printf("max_user[comp_index_mx] == %i , %c\n", max_user[comp_index_mx],
                               max_user[comp_index_mx]);
                        curr_s_char = senders[y][comp_index_s];
                        curr_mx_char = max_user[comp_index_mx];
                        printf("BEFORE downgrade to lowercase\n");
                        printf("curr_s_char == %i , %c \n", curr_s_char, curr_s_char);
                        printf("curr_mx_char == %i , %c \n", curr_mx_char, curr_mx_char);
                        // if (curr_s_char >= 65 && curr_s_char <= 90){
                        //     curr_s_char +=32;
                        // }
                        // if (curr_mx_char >= 65 && curr_mx_char <= 90){
                        //     curr_mx_char += 32;
                        // }
                        printf("after downgrade to lowercase\n");
                        printf("curr_s_char == %i , %c \n", curr_s_char, curr_s_char);
                        printf("curr_mx_char == %i , %c \n", curr_mx_char, curr_mx_char);
                        if (curr_s_char > curr_mx_char)
                        {
                            printf("inside > statement\n");
                            max_user = senders[y];
                            break;
                        }
                        else if (curr_s_char < curr_mx_char)
                        {
                            printf("inside < statement\n");
                            break;
                        }
                        // only continues if they are equal for that specific index
                        // shoudln't worry about this going on forever because as long as the
                        // 2 values aren't the same word it shouldn't
                        if (comp_index_s < senders[y].size() - 1)
                        {
                            comp_index_s += 1;
                        }
                        if (comp_index_mx < max_user.size() - 1)
                        {
                            comp_index_mx += 1;
                        }
                    }
                    // need to change that
                    //  if (senders[y].size() > max_user.size()){
                    //      max_user = senders[y];
                    //  }
                }

                else
                {
                    max_value = s_to_m[senders[y]];
                    max_user = senders[y];
                }
            }
            // printf("\n");
        }
        // printf("max_user == %s\n",max_user.c_str());
        for (it = s_to_m.begin(); it != s_to_m.end(); it++)
        {
            printf("key == %s value == %i\n", it->first.c_str(), it->second);
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

        printf("max_user %s max_value %i\n", max_user.c_str(), max_value);
        return max_user;
    }
};
// lexographically menas whichever alphabet comes first not the size of the word

// printf("max_user == %s\n",max_user.c_str());
// for (it = s_to_m.begin(); it != s_to_m.end(); it++){
//     printf("key == %s value == %i\n",it->first.c_str(),it->second);
// }
//

// return "apples";//just a placeholder