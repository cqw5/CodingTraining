/*! Source: https://leetcode.com/problems/largest-number
 *! Author: qwchen
 *! Date  : 2017-04-14
 *  把数组排成最大的数
 */

/*
 * 思路：
 *   自定义一个比较规则，将数组中所有元素“从大到小”排序，将排序后的元素拼接起来即可
 *   比较两个字符串的大小时，我们是要使得两个字符串拼接起来的数最小
 *   注意：若字符串前面的元素是0，需要把这些0给清除
 * 时间复杂度：O(nlogn). 3 ms. beats 81.05% of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.size() == 0) return res;
        bool head = true;
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), comp);
        for (int i = 0; i < nums.size(); i++) {
            if (head && stoi(strs[i]) == 0) {
                continue;
            }
            else {
                head = false;
            }
            res += strs[i];
        }
        if (res.size()) {
            return res;
        }
        else {
            return "0";
        }
    }
    
    static bool comp(string s1, string s2) {
        string s3 = s1 + s2;
        string s4 = s2 + s1;
        return s3 > s4;
    }
};

/*
 * 思路：
 *   使用lambla表达式
 * 时间复杂度：O(nlogn). 3 ms. beats 81.05% of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.size() == 0) return res;
        bool head = true;
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), [](string &s1, string &s2) {return s1+s2 > s2+s1;});
        for (int i = 0; i < nums.size(); i++) {
            if (head && stoi(strs[i]) == 0) {
                continue;
            }
            else {
                head = false;
            }
            res += strs[i];
        }
        if (res.size()) {
            return res;
        }
        else {
            return "0";
        }
    }
};