class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        std::vector<std::vector<int>> visited(
            heights.size(), std::vector<int>(heights[0].size(), INT_MAX));
        visited[0][0] = 0;
        std::vector<int> temp({-1, 0, 1, 0, -1});
        std::priority_queue <
            std::pair<int, std::pair<int, int>>,
                      std::vector<std::pair<int, std::pair<int, int>>>,
                      std::greater<std::pair<int, std::pair<int, int>>>>
                pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int mad = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int X = x + temp[i];
                int Y = y + temp[i + 1];
                if(X >= 0 && X < heights.size() && Y >= 0 && Y < heights[0].size()){
                    int ad = std::abs(heights[X][Y] - heights[x][y]);
                    ad = std::max(mad, ad);
                    if(visited[X][Y] > ad){
                        visited[X][Y] = ad;
                        pq.push({ad, {X, Y}});
                    }
                }
            }
        }
        return visited[heights.size() - 1][heights[0].size() - 1];
    }
};