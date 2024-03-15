class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack<int> stk;
        std::unordered_map<int, int> map;
        for(int i:nums1){
            map[i] = -1;
        }
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!stk.empty() && nums2[i] >= stk.top()){
                stk.pop();
            }
            if(map[nums2[i]]){
                if(!stk.empty()){
                    map[nums2[i]] = stk.top();
                }
            }
            stk.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = map[nums1[i]];
        }
        return nums1;
    }
};