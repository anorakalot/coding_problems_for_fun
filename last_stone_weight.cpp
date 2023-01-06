class Solution {
public:
    int keep_going = 1;
    int y=0;
    int x=0;
    int z=0;
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int x = 0; x < stones.size();x ++){
            pq.push(stones[x]);
        }

        while (pq.size() >1){
          y= pq.top();
          pq.pop();
          x = pq.top();
          pq.pop();
          //got the 2 highest values in pq

          if (x != y){
              //both are destroyed
            z = y -x;
            pq.push(z);
          }
          //else nothing elseif equal then they are destroyed;

        }
        if (pq.size() == 0){
            return 0;
        }
        else{
            return pq.top();//last remaining stone
        }
        //return 0; // placeholder
    }
};