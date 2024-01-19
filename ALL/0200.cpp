class Solution {
public:
    int numIslands(vector<vector<char>> grid) {
        int answer = 0;
        std::queue<std::pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    q.push({i, j});
                    while(!q.empty()){
                        int I = q.front().first;
                        int J = q.front().second;
                        if(grid[I][J] == '0'){
                            q.pop();
                            continue;
                        }
                        if(I > 0){
                            q.push({I - 1, J});
                        }
                        if(J > 0){
                            q.push({I, J - 1});
                        }
                        if(I < grid.size() - 1){
                            q.push({I + 1, J});
                        }
                        if(J < grid[0].size() - 1){
                            q.push({I, J + 1});
                        }
                        q.pop();
                        grid[I][J] = '0';
                    }
                    answer++;
                }
            }
        }
        return answer;
    }
};