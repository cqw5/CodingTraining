/*! Source: https://leetcode.com/problems/merge-intervals
 *! Author: qwchen
 *! Date  : 2017-04-03
 *  合并区间
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

/*
 * 思路：
 *   先按照每个区间第一个元素的大小进行排序
 *   从头到尾遍历数组，如果当前区间与上一个区间有重合，则将其合并到上一个区间。（注意end是上一个区间和当前区间中最大的）
 * 时间复杂度：O(nlogn)：排序的时间。 12 ms. beats 82.05% of cpp submissions
 * 空间复杂度：O(n): 存放结果的数组
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval x1, Interval x2) -> bool{return x1.start < x2.start;});
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > cur.end) {
                res.push_back(cur);
                cur = intervals[i];
            }
            else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        res.push_back(cur);
        return res;
    }
};

