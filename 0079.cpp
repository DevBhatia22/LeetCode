class Solution {
public:
    bool dfs(int i, int j, std::vector<std::vector<char>>& board, int index, std::string& word, int* temp){
        if(index >= word.size()){
            return true;
        }
        int save = board[i][j];
        board[i][j] = '0';
        for(int k = 0; k < 4; k++){
            int I = i + temp[k];
            int J = j + temp[k + 1];
            if(I >= 0 && I < board.size() && J >= 0 && J < board[0].size() && board[I][J] == word[index] && board[I][J] != '0'){
                bool temp1 = dfs(I, J, board, index + 1, word, temp);
                if(temp1){
                    return true;
                }
            }
        }
        board[i][j] = save;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int temp[5] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool temp1 = dfs(i, j, board, 1, word, temp);
                    if(temp1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();