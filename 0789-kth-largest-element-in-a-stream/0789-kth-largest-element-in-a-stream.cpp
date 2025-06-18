class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int num: nums){
            add(num);
        }
    }
    
    int add(int val) {
        // If pq size<k, then push in pq
        if(minHeap.size()<k){
            minHeap.push(val);
        }

        // If Not, check the val with root and then add
        else if(val>minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */