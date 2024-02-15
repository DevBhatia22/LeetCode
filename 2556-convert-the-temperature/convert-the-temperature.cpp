class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        std::vector<double> answer(2, 0);
        answer[0] = celsius + 273.15;
        answer[1] = celsius * 1.80 + 32.00;
        return answer;
    }
};