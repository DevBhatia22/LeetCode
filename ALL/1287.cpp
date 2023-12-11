class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        n /= 4;
        int current = arr[0];
        int count = 0;
        for(int i:arr){
            if(i == current){
                count++;
            }
            else{
                current = i;
                count = 1;
            }
            if(n < count){
                return current;
            }
        }
        return -1;
    }
};