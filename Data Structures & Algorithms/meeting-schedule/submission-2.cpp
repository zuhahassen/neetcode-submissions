/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        if (!intervals.size()) return true;

        sort(intervals.begin(), intervals.end(), cmp);

        int start = intervals[0].start; 
        int end = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < end || intervals[i].end <= end) {
                return false;
            }

            start = min(start, intervals[i].start);
            end = max(end, intervals[i].end);
        }

        return true;
    }
};
