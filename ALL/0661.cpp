class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        std::vector<std::vector<int>> answer(n, std::vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool left = j > 0;
                bool down = i < n - 1;
                bool up = i > 0;
                bool right = j < m - 1;
                int N = 0;
                int D = 0;
                if(left ||up){
                    if(left){
                        N += img[i][j - 1];
                        D++;
                    }
                    if(up){
                        N += img[i - 1][j];
                        D++;
                    }
                    if(left && up){
                        N += img[i - 1][j - 1];
                        D++;
                    }
                }
                if(right || down){
                    if(right){
                        N += img[i][j + 1];
                        D++;
                    }
                    if(down){
                        N += img[i + 1][j];
                        D++;
                    }
                    if(right && down){
                        N += img[i + 1][j + 1];
                        D++;
                    }
                }
                if(left && down){
                    N += img[i + 1][j - 1];
                    D++;
                }
                if(right && up){
                    N += img[i - 1][j + 1];
                    D++;
                }
                N += img[i][j];
                D++;
                answer[i][j] = N/D;
            }
        }
        return answer;
    }
};