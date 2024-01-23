class Solution {
public:
    std::vector<std::vector<bool>> visited;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        visited.resize(mat.size(), std::vector<bool>(mat[0].size(), 0));
        std::vector<std::vector<int>> answer(
            mat.size(), std::vector<int>(mat[0].size(), 0));
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int time = 1;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                std::vector<int> temp({-1, 0, 1, 0, -1});
                for(int l = 0; l < 4; l++){
                    int i = q.front().first;
                    int j = q.front().second;
                    i += temp[l];
                    j += temp[l + 1];
                    if(i > -1 && i < mat.size() && j > -1 && j < mat[0].size() && !visited[i][j]){
                        q.push({i, j});
                        visited[i][j] = true;
                        if(mat[i][j] == 1){
                            answer[i][j] = time;
                        }
                    }
                }
                q.pop();
            }
            time++;
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