class Solution {
public:
    std::vector<std::vector<bool>> visited;
    std::vector<int> temp;
    void dfs(std::vector<std::vector<char>>& board, int i, int j){
        visited[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int newI = i + temp[k];
            int newJ = j + temp[k + 1];
            if(newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size() && !visited[newI][newJ] && board[newI][newJ] == 'X'){
                dfs(board, newI, newJ);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        visited.resize(board.size(), std::vector<bool>(board[0].size(), 0));
        temp = {-1, 0, 1, 0, -1};
        int count = 0;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(!visited[i][j] && board[i][j] == 'X'){
                    dfs(board, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};