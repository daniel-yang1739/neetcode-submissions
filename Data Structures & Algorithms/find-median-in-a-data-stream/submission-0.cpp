class MedianFinder {
public:
    priority_queue<int> lessHeap;
    priority_queue<int, vector<int>, greater<int>> greaterHeap;
    
    void addNum(int num) {
        if (lessHeap.empty() || num <= lessHeap.top()) {
            lessHeap.push(num);
        } else {
            greaterHeap.push(num);
        }
        if (lessHeap.size() > greaterHeap.size() + 1) {
            int top = lessHeap.top();
            lessHeap.pop();
            greaterHeap.push(top);
        }
        if (lessHeap.size() < greaterHeap.size()) {
            int top = greaterHeap.top();
            greaterHeap.pop();
            lessHeap.push(top);
        }
    }
    
    double findMedian() {
        int total = lessHeap.size() + greaterHeap.size();
        if (total % 2 == 0) {
            return (lessHeap.top() + greaterHeap.top()) / 2.0;
        } else {
            return lessHeap.top();
        }
    }
};
