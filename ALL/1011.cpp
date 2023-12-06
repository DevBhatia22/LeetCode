class Solution {
public:
    long long help(int mid, std::vector<int> weights){
        long long answer = 0, added = 0;
        for(int i:weights){
            if(added + i > mid){
                answer++;
                added = i;
            }
            else{
                added += i;
            }
        }
        if(added){
            answer++;
        }
        return answer;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0, end = 0;
        for(int i:weights){
            end += i;
            if(i > start){
                start = i;
            }
        }
        while(start <= end){
            int mid = (start + end) / 2;
            int function = help(mid, weights);
            if(function > days){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return start;
    }
};