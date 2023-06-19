class MedianFinder {
public:
    priority_queue<long >large;
    priority_queue<long, vector<long>, greater<long>>small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        large.push(num);
        small.push(large.top());
        large.pop();
        if(small.size()>large.size()){
            large.push(small.top());
            small.pop();
        }
        return;
    }
    
    double findMedian() {
        return (large.size()+small.size())%2==0?double(large.top()+small.top())/2:large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
