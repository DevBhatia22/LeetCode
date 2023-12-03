class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 1, max = 1;
        
        for(int i:nums){
            if(!i){
                count = 1;
            }
            else{
                count++;
            }
            if(count > max){
                max = count;
            }
        }
        
        return max-1;
    }
};