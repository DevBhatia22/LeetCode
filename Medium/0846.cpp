class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize){
            return 0;
        }
        std::map<int, int> map;
        std::priority_queue<int> maxHeap;
        std::queue<int> queue;
        for(int i:hand){
            map[i]++;
        }
        for(std::pair<int, int> i:map){
            maxHeap.push(i.first);
        }
        int counter = 1;
        while(maxHeap.empty() != true){
            int prev = maxHeap.top() + 1;
            for(int i = 0; i < groupSize; i++){
                if(maxHeap.top() != prev - 1){
                    return 0;
                }
                map[maxHeap.top()]--;
                if(map[maxHeap.top()] > 0){
                    queue.push(maxHeap.top());
                }
                prev = maxHeap.top();
                maxHeap.pop();
            }
            while(queue.empty() != true){
                maxHeap.push(queue.front());
                queue.pop();
            }
        }
        return 1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();