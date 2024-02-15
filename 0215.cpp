class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + k);
        for(int i = k; i < nums.size(); i++){
            if(nums[i] >= minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        
        return minHeap.top();
    }
};
auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();