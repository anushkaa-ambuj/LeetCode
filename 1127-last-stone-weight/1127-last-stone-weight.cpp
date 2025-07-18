class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max heap

        // Add in heap
        for(int num: stones){
            pq.push(num); //Time: O(nlogn)
        }


        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            
            int x = pq.top();
            pq.pop();

            if(x!=y){
                pq.push(y-x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};