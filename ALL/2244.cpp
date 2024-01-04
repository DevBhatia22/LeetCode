class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        std::unordered_map<int, int> map;
        for(int i:tasks){
            map[i]++;
        }
        int answer = 0;
        for(std::pair<int, int> i:map){
            if(i.second <= 1){
                answer = -1;
                break;
            }
            while(i.second % 3){
                answer++;
                i.second -= 2;
            }
            answer += i.second / 3;
        }
        return answer;
    }
};