class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sec = -1;
        int fir = -1;
        for(int i:nums){
            if(i >= fir){
                sec = fir;
                fir = i;
            }
            else if(i > sec){
                sec = i;
            }
        }
        fir = (fir - 1) * (sec - 1);
        return fir;
    }
};