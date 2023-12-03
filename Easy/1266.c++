class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        std::ios_base::sync_with_stdio(false);
        int minAnswer = 0;
        std::vector<int> prev = points[0];
        for(int i = 1; i < points.size(); i++){
            minAnswer += std::max(std::abs(prev[0] - points[i][0]), std::abs(prev[1] - points[i][1]));
            prev = points[i];
        }
        return minAnswer;
    }
};