class Solution {
private:
    std::vector<std::vector<int>> answer;
public:
    void dfs(std::vector<std::vector<int>>& graph, std::vector<int>& temp, int num, std::vector<bool>& visited){
        if(num >= graph.size() - 1){
            temp.push_back(num);
            answer.push_back(temp);
            temp.pop_back();
        }
        if(visited[num] == 1){
            return;
        }
        visited[num] = 1;
        temp.push_back(num);
        for(int i:graph[num]){
            dfs(graph, temp, i, visited);
            temp.pop_back();
            visited[i] = 0;
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<int> temp;
        std::vector<bool> visited(graph.size(), 0);
        dfs(graph, temp, 0, visited);
        return answer;
    }
};