class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::vector<int> vec(nums.size(), 0);
        int i = 0;
        int j = 1;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] < 0){
                vec[j] = nums[k];
                j += 2;
            }
            else{
                vec[i] = nums[k];
                i += 2;
            }
        }
        return vec;
    }
};