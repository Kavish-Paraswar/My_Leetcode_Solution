class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, std::vector<int>, std::greater<int>> mini_heap;
    // cond 1 = maxi elementn form maxi_heap <= mini_heap mini eleme
    // cond 2  = maxi_size - mini_size <= 1
    MedianFinder() {}

    void addNum(int num) {
        max_heap.push(num);
        if (!max_heap.empty() && !mini_heap.empty() &&
            max_heap.top() > mini_heap.top()) {
            int top = max_heap.top();
            max_heap.pop();
            mini_heap.push(top);
        }
        if (max_heap.size() > mini_heap.size() + 1) {
            int top = max_heap.top();
            max_heap.pop();
            mini_heap.push(top);
        }

        if (max_heap.size() < mini_heap.size()) {

            int top = mini_heap.top();
            mini_heap.pop();
            max_heap.push(top);
        }
    }

    double findMedian() {
        if (max_heap.size() > mini_heap.size()) {
            return max_heap.top() / 1.0;
        } else if (max_heap.size() < mini_heap.size()) {
            return mini_heap.top() / 1.0;
        } else {
            return ((double)max_heap.top() + mini_heap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */