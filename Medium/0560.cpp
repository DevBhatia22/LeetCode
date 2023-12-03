class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int pre = 0, count = 0;
        std::unordered_map<int, int> map1;
        map1[pre] = 1;
        for(int i:nums){
            pre += i;
            count += map1[pre - k];
            map1[pre]++;
        }
        return count;
    }
};