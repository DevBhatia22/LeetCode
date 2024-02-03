class Solution {
private:
    std::vector<int> visited;
public:
    bool dfs(std::vector<std::vector<int>>& graph, int color, int current, int prev){
        if(visited[current] != color && visited[current]){
            return false;
        }
        if(visited[current]){
            return true;
        }
        visited[current] = color;
        color *= -1;
        for(int i:graph[current]){
            if(i == prev){
                continue;
            }
            bool temp = dfs(graph, color, i, current);
            std::cout<<i<<" "<<temp<<" ";
            if(!temp){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        visited.resize(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            if(!visited[i]){
                if(!dfs(graph, 1, i, -1)){
                    return false;
                }
            }
        }
        return true;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();