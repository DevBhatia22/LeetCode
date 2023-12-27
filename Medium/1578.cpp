class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int max = neededTime[0];
        char current = colors[0];
        int net = neededTime[0];
        int answer = 0;
        for(int i = 1; i < colors.size(); i++){
            if(current != colors[i]){
                answer += net - max;
                max = neededTime[i];
                current = colors[i];
                net = neededTime[i];
            }
            else{
                if(max < neededTime[i]){
                    max = neededTime[i];
                }
                net += neededTime[i];
            }
        }
        answer += net - max;
        return answer;
    }
};