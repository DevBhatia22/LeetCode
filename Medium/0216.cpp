class Solution {
public:
    void Help(std::vector<vector<int>> &answer, std::vector<int> temp, int total_nums, int sum, int value){
        if(total_nums == 0){
            if(sum == 0){
                answer.push_back(temp);
                return;
            }
            else{
                return;
            }
        }
        if(value > 9){
            return;
        }
        if(sum < 0){
            return;
        }
        Help(answer, temp, total_nums, sum, value + 1);
        temp.push_back(value);
        sum -= value;
        Help(answer, temp, total_nums - 1, sum, value + 1);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> answer;
        std::vector<int> temp;
        Help(answer, temp, k, n, 1);
        return answer;
    }
};