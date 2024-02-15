class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::priority_queue<int> maxHeap;
        std::map<char, int> map1;
        for(char i:tasks){
            map1[i]++;
        }
        for(auto i:map1){
            maxHeap.push(i.second);
        }
        std::queue<std::pair<int, int>> queue;
        int currentTime = 0;
        while(!maxHeap.empty() || !queue.empty()){
            if(!queue.empty() && queue.front().second <= currentTime){
                maxHeap.push(queue.front().first);
                queue.pop();
            }
            if(!maxHeap.empty()){
                int temp = maxHeap.top();
                maxHeap.pop();
                temp--;
                if(temp){
                    queue.push({temp, currentTime + n + 1});
                }
            }
            currentTime++;
        }
        return currentTime;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();