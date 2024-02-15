class Solution {
private:
    std::vector<int> visited;
    std::vector<int> tempVisited;
    std::stack<int> stk;
public:
    
    bool dfs(std::vector<std::vector<int>>& adj, int current){
        tempVisited[current] = 1;
        visited[current] = 1;
        for(int i:adj[current]){
            if(tempVisited[i]){
                return false;
            }
            else if(visited[i]){
                continue;
            }
            bool value = dfs(adj, i);
            if(!value){
                return false;
            }
        }
        tempVisited[current] = 0;
        stk.push(current);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        tempVisited.resize(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses, std::vector<int>());
        for(std::vector<int> i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                bool value = dfs(adj, i);
                if(!value){
                    return std::vector<int>();
                }
            }
        }
        std::vector<int> answer(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            answer[i] = stk.top();
            stk.pop();
        }
        return answer;
    }
};