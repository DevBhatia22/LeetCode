class MedianFinder {
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        else if(minHeap.empty()){
            if(maxHeap.top() > num){
                minHeap.push(-maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
                return;
            }
            else{
                minHeap.push(-num);
                return;
            }
        }
        if(maxHeap.top() > num){
            if(maxHeap.size() == minHeap.size()){
                maxHeap.push(num);
                return;
            }
            else{
                maxHeap.push(num);
                minHeap.push(-maxHeap.top());
                maxHeap.pop();
                return;
            }
        }
        else{
            if(maxHeap.size() == minHeap.size()){
                minHeap.push(-num);
                maxHeap.push(-minHeap.top());
                minHeap.pop();
                return;
            }
            else{
                minHeap.push(-num);
                return;
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() < maxHeap.size()){
            return maxHeap.top();
        }
        else{
            double temp1;
            double temp2;
            temp1 = maxHeap.top();
            temp2 = -minHeap.top();
            return temp1 + (temp2 - temp1) / 2;
        }
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */