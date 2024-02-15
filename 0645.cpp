class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> map(nums.size(), 0);
        for(int i:nums){
            map[i - 1]++;
        }
        std::vector<int> answer(2, 0);
        for(int i = 0; i < map.size(); i++){
            if(map[i] == 2){
                answer[0] = i + 1;
            }
            if(map[i] == 0){
                answer[1] = i + 1;
            }
        }
        return answer;
    }
};