class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; 

        // Time: O(nlogk)
        for(int num: nums){
            if(minHeap.size()<k){  //Space: O(k)
                minHeap.push(num);
            }
            else if(num > minHeap.top()){
                minHeap.pop();
                minHeap.push(num);
            }
        }
        return minHeap.top(); //Time: O(1)
    }
};