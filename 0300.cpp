class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for (int i : nums) {
            if (temp.empty() || i > temp.back()) {
                temp.push_back(i);
            }
            else {
                auto n = lower_bound(temp.begin(), temp.end(), i);
                *n = i;
            }
        }
        return temp.size();
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();