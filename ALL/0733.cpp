class Solution {
public:
    int currentColor;
    void dfs(std::vector<std::vector<int>>& image, int i, int j, int color){
        if(image[i][j] == color){
            return;
        }
        image[i][j] = color;
        std::vector<int> temp({-1, 0, 1, 0, -1});
        for(int x = 0; x < 4; x++){
            int newi = i + temp[x];
            int newj = j + temp[x + 1];
            if(newi >= 0 && newi < image.size() && newj >= 0 && newj < image[0].size() && image[newi][newj] == currentColor){
                dfs(image, newi, newj, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        currentColor = image[sr][sc];
        dfs(image, sr, sc, color);
        return image;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();