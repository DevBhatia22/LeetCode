class Solution {
public:
    void dfs(std::vector<std::vector<int>> &isConnected, std::vector<bool> &visited, int current){
        visited[current] = true;
        for(int i = 0; i < isConnected[current - 1].size(); i++){
            if(isConnected[current - 1][i] && !visited[i + 1]){
                dfs(isConnected, visited, i + 1);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        std::vector<bool> visited(isConnected.size() + 1, false);
        int answer = 0;
        for(int i = 1; i < visited.size(); i++){
                std::cout<<i<<" "<<visited[i];
            if(!visited[i]){
                dfs(isConnected, visited, i);
                answer++;
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