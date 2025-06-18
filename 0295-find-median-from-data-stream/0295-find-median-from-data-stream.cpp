class MedianFinder {
private:
    priority_queue<int> lo; //max heap
    priority_queue<int, vector<int>, greater<int>> hi; //min heap
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num); //add num to max heap

        hi.push(lo.top()); //balancing step
        lo.pop();

        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size()>hi.size() ? lo.top() : (hi.top()+lo.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */