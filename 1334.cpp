class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<int>> adj(n, std::vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++){
            adj[i][i] = 0;
        }
        for(std::vector<int> i:edges){
            adj[i[0]][i[1]] = i[2];
            adj[i[1]][i[0]] = i[2];

        }
        for(int cp = 0; cp < n; cp++){
            for(int i = 0; i < n; i++){
                if(i == cp){
                    continue;
                }
                for(int j = 0; j < n; j++){
                    if(j == cp || j == i){
                        continue;
                    }
                    if(adj[i][cp] == INT_MAX || adj[cp][j] == INT_MAX){
                        continue;
                    }
                    adj[i][j] = std::min(adj[i][j], adj[i][cp] + adj[cp][j]);
                }
            }
        }
        int min = INT_MAX;
        int answer = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(adj[i][j] <= distanceThreshold){
                    count++;
                }
            }
            std::cout<<count<<'\n';
            if(min >= count){
                min = count;
                answer = i;
            }
        }
        return answer;
    }
};