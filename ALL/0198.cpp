class Solution {
public:
std::vector<int> memory;
    int help(std::vector<int> vec, int index){
        if(index >= vec.size()){
            return 0;
        }
        if(memory[index] != -1){
            return memory[index];
        }
        int answer = std::max(help(vec, index + 2) + vec[index], help(vec, index + 1));
        memory[index] = answer;
        return answer;
    }
    int rob(vector<int>& nums) {
        memory.resize(nums.size(), -1);
        return help(nums, 0);
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();