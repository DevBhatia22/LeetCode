class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0, max = 0, n = 0;
        while(j < nums.size()){
            if(nums[j] == 1){
                while(j < nums.size() && nums[j] == 1){
                    j++;
                    count++;
                }
            }
            else{
                if(n < k){
                    j++;
                    n++;
                    count++;
                }
                else{
                    if(nums[i] == 1){
                        while(nums[i] != 0){
                            i++;
                            count--;
                        }
                    }
                    else{
                        i++;
                        count--;
                        n--;
                    }
                }
            }
            if(count > max){
                max = count;
            }
            std::cout<<" i "<<i<<" j "<<j<<" count "<<count<<" n "<<n<<std::endl;
        }
        return max;
    }
};