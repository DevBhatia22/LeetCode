class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int frequency[101] = {0};
        int maxFrequency = 0;
        for(int i:nums){
            frequency[i]++;
            if(frequency[i] > maxFrequency){
                maxFrequency = frequency[i];
            }
        }
        int answer = 0;
        for(int i = 0; i < 101; i++){
            if(frequency[i] == maxFrequency){
                answer += maxFrequency;
            }
        }
        return answer;
    }
};