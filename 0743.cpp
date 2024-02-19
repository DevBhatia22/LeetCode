class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1, std::vector<std::pair<int, int>>());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::vector<int> answers(n + 1, INT_MAX);
        
        for(std::vector<int> i:times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        pq.push({0, k});
        answers[k] = 0;
        answers[0] = 0;
        while(!pq.empty()){
            int des = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            for(std::pair<int, int> i:adj[curr]){
                if(answers[i.first] > des + i.second){
                    answers[i.first] = des + i.second;
                    pq.push({des + i.second, i.first});
                }
            }
        }
        
        int answer = answers[0];
        for(int i:answers){
            if(answer < i){
                answer = i;
            }
            if(answer == INT_MAX){
                return -1;
            }
        }
        
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();