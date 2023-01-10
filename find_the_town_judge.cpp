class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> map_to_find_judge;
        int judge=-1;
        bool everyone_trusts_judge_val=1;
        for (int y = 0; y < trust.size(); y++){
            map_to_find_judge[trust[y][0]]+=1;
            printf("\n");
        }

        for (int x = 1; x <= n; x++){
            if (map_to_find_judge[x] ==0){
                printf("x == %i does not trust anyone!\n",x);
                for (int y = 0; y < trust.size(); y++){//for loop check everyone trusts judge
                    if (trust[y][1] != x){
                        printf("not everyone trusts judege\n");
                        everyone_trusts_judge_val = 0;
                    }
                }
                if (everyone_trusts_judge_val ==1){
                    judge = x;

                }
            }
        }

        return judge;//placeholder
    }
};