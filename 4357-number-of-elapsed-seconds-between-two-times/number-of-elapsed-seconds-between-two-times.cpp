
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr = (endTime[0] - '0') * 10 + (endTime[1] - '0') -
                 ((startTime[0] - '0') * 10 + (startTime[1] - '0'));

        int min = (endTime[3] - '0') * 10 + (endTime[4] - '0') -
                  ((startTime[3] - '0') * 10 + (startTime[4] - '0'));

        int sec = (endTime[6] - '0') * 10 + (endTime[7] - '0') -
                  ((startTime[6] - '0') * 10 + (startTime[7] - '0'));

        if (sec < 0) {
            sec += 60;
            min--;
        }

        if (min < 0) {
            min += 60;
            hr--;
        }

        return (hr * 3600) + (min * 60) + sec;
    }
};
