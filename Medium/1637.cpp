class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::vector<int> vec(points.size(), 0);
        for(int i = 0; i < points.size(); i++){
            vec[i] = points[i][0];
        }
        std::sort(vec.begin(), vec.end());
        int answer = 0;
        for(int i = 0; i < vec.size() - 1; i++){
            if(vec[i + 1] - vec[i] > answer){
                answer = vec[i + 1] - vec[i];
            }
        }
        return answer;
    }
};