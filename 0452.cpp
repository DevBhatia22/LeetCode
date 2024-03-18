class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());
        int left = points[0][0], right = points[0][1];
        int answer = 0;
        for(int i = 1; i < points.size(); i++){
            if(right >= points[i][0]){
                left = std::max(left, points[i][0]);
                right = std::min(right, points[i][1]);
            }
            else{
                answer++;
                left = points[i][0];
                right = points[i][1];
            }
        }
        return answer + 1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();