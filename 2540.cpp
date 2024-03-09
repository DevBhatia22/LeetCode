class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums2[j] > nums1[i]){
                i++;
            }
            else if(nums2[j] < nums1[i]){
                j++;
            }
            else{
                return nums2[j];
            }
        }
        return -1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();