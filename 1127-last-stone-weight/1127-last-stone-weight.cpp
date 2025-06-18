class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max heap

        for(int num: stones){
            pq.push(num); //Time: O(nlogn)
        }

        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y){
                continue;
            }
            else if(y>x){
                pq.push(y-x);
            }
        }

        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};