class Solution {
public:
    std::vector<bool> visited;
    int dfs(std::vector<std::vector<int>>& tree, vector<bool>& hasApple, int curr){
        visited[curr] = 1;
        int answer = 0;
        for(int i:tree[curr]){
            if(!visited[i])
            answer += dfs(tree, hasApple, i);
        }
        if(answer || hasApple[curr]){
            return answer + 2;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        visited.resize(n, 0);
        std::vector<std::vector<int>> tree(n, std::vector<int>());
        for(std::vector<int> i:edges){
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }
        int answer = dfs(tree, hasApple, 0);
        return answer?answer - 2:answer;
    }
};