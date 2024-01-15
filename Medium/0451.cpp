class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> map;
        std::priority_queue<std::pair<int, char>> priorityQueue;
        for(auto i:s){
            map[i]++;
        }
        for(auto i:map){
            priorityQueue.push({i.second, i.first});
        }
        std::string answer;
        while(priorityQueue.empty() != true){
            int times = priorityQueue.top().first;
            int what = priorityQueue.top().second;
            priorityQueue.pop();
            for(int temp = 0; temp < times; temp++){
                answer += what;
            }
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();