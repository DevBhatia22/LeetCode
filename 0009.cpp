class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int y = x;
        long long z = 0;
        while(y){
            z = z * 10 + y % 10;
            y /= 10;
        }
        if(x == z){
            return true;
        }
        return 0;
        return 1;
    }
};