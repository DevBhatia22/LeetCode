class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i:nums){
            if(minHeap.size() < k){
                minHeap.push(i);
            }
            else{
                if(minHeap.top() > i){
                    continue;
                }
                else{
                    minHeap.pop();
                    minHeap.push(i);
                }
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size() >= k){
            if(val > minHeap.top()){
                minHeap.pop();
                minHeap.push(val);
            }
        }
        else{
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