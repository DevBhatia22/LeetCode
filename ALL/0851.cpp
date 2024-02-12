class Solution {
private:
    std::vector<int> visited;
public:
    
    int dfs(std::vector<std::vector<int>>& adj, std::vector<int>& answer, std::vector<int>& quiet, int current){
        visited[current] = 1;
        int value = current;
        for(int i:adj[current]){
            if(!visited[i]){
                int temp = dfs(adj, answer, quiet, i);
                if(quiet[temp] < quiet[value]){
                    value = temp;
                }
            }
            else{
                if(quiet[answer[i]] < quiet[value]){
                    value = answer[i];
                }
            }
        }
        answer[current] = value;
        return value;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        visited.resize(quiet.size(), 0);
        std::vector<std::vector<int>> adj(quiet.size(), std::vector<int>());
        
        std::vector<int> indegree(quiet.size(), 1);
        for(std::vector<int> i:richer){
            adj[i[1]].push_back(i[0]);
        }
        
        std::vector<int> answer(quiet.size(), 0);
        for(int i = 0; i < quiet.size(); i++){
            if(!visited[i]){
                dfs(adj, answer, quiet, i);
            }
        }
        
        return answer;
    }
};