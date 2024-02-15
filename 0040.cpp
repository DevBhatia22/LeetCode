class Solution {
public:
    int helpMeNa(vector<vector<int>> &answer, vector<int> &arr, vector<int> temp, int sum, int index){
        if(sum == 0){
            answer.push_back(temp);
            return 0;
        }
        if(index >= arr.size() || sum < 0){
            return 0;
        }
        
        int prev = -1;
        for(int i = index; i < arr.size(); i++){
            if(prev == arr[i]){
                prev = arr[i];
                continue;
            }
            temp.push_back(arr[i]);
            helpMeNa(answer, arr, temp, sum - arr[i], i + 1);
            temp.pop_back();
            prev = arr[i];
        }
        return 0;
    }
    vector<vector<int>> combinationSum2(vector<int> &arr, int sum)
    {
        
        // Write your code here.
        sort(arr.begin(), arr.end());
        std::vector<int> temp;
        std::vector<vector<int>> answerHere;
        helpMeNa(answerHere, arr, temp, sum, 0);
        return answerHere;
        
    }
};