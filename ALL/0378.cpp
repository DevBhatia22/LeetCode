class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int> maxHeap;
        for(std::vector<int> i:matrix){
            for(int temp:i){
                maxHeap.push(temp);
                if(maxHeap.size() > k){
                    maxHeap.pop();
                }
            }
        }
        return maxHeap.top();
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();