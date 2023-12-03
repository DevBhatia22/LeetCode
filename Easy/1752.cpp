class Solution {
public:
    bool check(vector<int>& nums) {
    int last_element =INT_MIN;
    bool flag = false;
    for(int i:nums){
        if(i<last_element){
            if(flag || nums[0] < nums.back()){
                return 0;
            }
            flag = true;
        }
        last_element = i;
    }
    return 1;
    }
};