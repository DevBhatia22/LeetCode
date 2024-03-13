class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int start = 1, end = n;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            int leftSum = mid * (mid + 1) / 2;
            int rightSum = total - leftSum + mid;
            if(leftSum == rightSum){
                return mid;
            }
            if(leftSum < rightSum){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};