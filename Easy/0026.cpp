class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 0;

        for(int i = 0; i< nums.size(); i++){
            if(nums[i]!=nums[x]){
                x++;
                nums[x]=nums[i];
            }
        }
        
        
        
        return x+1;

    }
};