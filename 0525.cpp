class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        int answer = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                sum++;
            }
            else{
                sum--;
            }
            if(map.find(sum) == map.end()){
                map[sum] = i;
            }
            else{
                answer = std::max(answer, i - map[sum]);
            }
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();