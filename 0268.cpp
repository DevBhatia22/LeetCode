class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        
        len = len*(len+1)/2;
        
        for(int i:nums){
            len-=i;
        }
        
        return len;
    }
};