/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
    //The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines
     bool sortFun(const Interval &a, const Interval &b){
         return a.start<b.start || (a.start==b.start && a.end<b.end);
        //if(a.start<b.start) return true;
        //else if(a.start==b.start) return a.end<b.end;
        //else return false;
    }
class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(), intervals.end(), sortFun);
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i].start > ret.back().end) 
                ret.push_back(intervals[i]);
            else
                ret.back().end = max(intervals[i].end, ret.back().end);

        }
        return ret;
    }
};