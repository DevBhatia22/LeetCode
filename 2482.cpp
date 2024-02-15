class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<int> row(n, 0);
        std::vector<int> column(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    row[i]++;
                    column[j]++;
                }
            }
        }
        std::vector<std::vector<int>> answer(n, std::vector<int> (m , 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                answer[i][j] = (row[i] + column[j] - (n - row[i] 
                + m - column[j]));
            }
        }
        return answer;
    }
};