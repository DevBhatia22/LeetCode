class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer;
        int count = 0;
        for(int i:nums){
            if(count == 0){
                answer = i;
            }
            if(answer == i){
                count++;
            }
            else{
                count--;
            }
        }
        return answer;
    }
};