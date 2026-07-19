class MedianFinder {
public:
    // less part
    priority_queue<int, vector<int>, less<int>> maxHeap;  
    // greater part
    priority_queue<int, vector<int>, greater<int>> minHeap;  
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int total = maxHeap.size() + minHeap.size();
        if (total % 2 == 1) {
            return maxHeap.top();
        }
        return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
    }
};
