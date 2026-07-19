class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int n : nums) {
            min_heap.push(n);
            if (min_heap.size() > K) {
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > K) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
