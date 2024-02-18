class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n, std::vector<std::pair<int, int>>());
        for(std::vector<int> i:flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        std::queue<std::pair<int, int>> pq;
        std::vector<int> visited(n, INT_MAX);
        pq.push({0, src});
        visited[src] = 0;
        k++;
        while(!pq.empty()){
            int size = pq.size();
            if(!k){
                break;
            }
            k--;
            while(size--){
                int c = pq.front().first;
                int s = pq.front().second;
                pq.pop();
                for(std::pair<int, int> i:adj[s]){
                    if(visited[i.first] > c + i.second){
                        visited[i.first] = c + i.second;
                        pq.push({visited[i.first], i.first});
                    }
                }
            }
        }
        return (visited[dst] < INT_MAX? visited[dst]:-1);
    }
};