class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        std::vector<std::vector<std::pair<long long, long long>>> adj(n, std::vector<std::pair<long long, long long>>());
        std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<std::pair<long long, long long>>> pq;
        std::vector<long long> answers(n, LLONG_MAX);
        std::vector<long long> visits(n, 0);
        
        for(std::vector<int> i:roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        long long answer = 0;
        long long min = LLONG_MAX;
        pq.push({0, 0});
        answers[0] = 0;
        visits[0] = 1;
        while(!pq.empty()){
            long long des = pq.top().first;
            long long curr = pq.top().second;
            pq.pop();
            for(std::pair<long long, long long> i:adj[curr]){
                if(answers[i.first] > des + i.second){
                    answers[i.first] = (des + i.second);
                    pq.push({answers[i.first], i.first});
                    visits[i.first] = 0;
                }
                if(answers[i.first] == des + i.second){
                    visits[i.first] += visits[curr];
                    visits[i.first] %= 1000000007;
                }
            }
        }
        return visits[n - 1];
    }
};