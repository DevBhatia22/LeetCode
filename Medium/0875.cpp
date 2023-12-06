class Solution {
public:
    long long help(int mid, std::vector<int> v){
        long long answer = 0;
        for(int i:v){
            answer += i / mid;
            if(i % mid){
                answer++;
            }
        }
        return answer;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        std::sort(v.begin(), v.end());
        int start = 1, end = v[v.size() - 1], mid, answer = v[v.size() - 1];
        while(start <= end){
            mid = (start + end) / 2;
            long long temp = help(mid, v);
            if(temp > h){
                start = mid + 1;
            }
            else{
                answer = mid;
                end = mid - 1;
            }
        }
        return answer;
    }
};