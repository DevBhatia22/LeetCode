class Solution {
public:
    std::vector<std::vector<bool>> visited;
    void dfs(std::vector<std::vector<char>> &board, int i, int j){
        if(visited[i][j] == true){
            return;
        }
        visited[i][j] = true;
        std::vector<int> temp({-1, 0, 1, 0, -1});
        for(int l = 0; l < 4; l++){
            int I = i + temp[l];
            int J = j + temp[l + 1];
            if(I >= 0 && I < board.size() && J >= 0 && J < board[0].size() && board[I][J] == 'O'){
                dfs(board, I, J);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        visited.resize(board.size(), std::vector<bool>(board[0].size()));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size()-  1){
                    if(visited[i][j] == false && board[i][j] == 'O'){
                        dfs(board, i, j);
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();