/*! Author: qwchen
 *! Date  : 2016-11-21
 *  33. 把数组排成最小的数
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 自己实现快排
 */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res = "";
        if (nums.size() <= 0) return res;
        vector<string> strs;
        for (int num: nums) {
            strs.push_back(to_string(num));
        }
        sort(strs, 0, strs.size()-1);
        for (string s: strs) {
            res.append(s);
        }
        return res;
    }
private:
    void sort(vector<string>& strs, int low, int high) {
        if (low >= high) return;
        int mid = partition(strs, low, high);
        sort(strs, low, mid-1);
        sort(strs, mid+1, high);
    }

    int partition(vector<string>& strs, int low, int high) {
        string cur = strs[low];
        while(low < high) {
            while(low < high && strs[high] + cur >= cur + strs[high]) high--;
            strs[low] = strs[high];
            while(low < high && strs[low] + cur <= cur + strs[low]) low++;
            strs[high] = strs[low];
        }
        strs[low] = cur;
        return low;
    }
};

/*
 * 自定义一个比较规则，将数组中所有元素“从小到大”排序，将排序后的元素拼接起来即可
 * 比较两个字符串的大小时，我们是要使得两个字符串拼接起来的数最小，因此比较两个字符串m与n的拼接mn和nm，如mn<nm，则认为m<n
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string result = "";
        if (numbers.size() == 0) {
            return result;
        }
        vector<string> str;
        for (int num: numbers) {
            str.push_back(num2str(num));
        }
        sort(str.begin(), str.end(), compare);
        for (string subStr: str) {
            result.append(subStr);
        }
        return result;
    }

private:
    string num2str(int num) {
        stringstream s;
        s << num;
        return s.str();
    }
    
    static bool compare(string s1, string s2) {
        string s1Copy = s1 + s2;
        string s2Copy = s2 + s1;
        return s1Copy < s2Copy;
    }
};


class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strs;
        for(int num: numbers) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), compare);
        string res = "";
        for(string str: strs) {
            res += str;
        }
        return res;
    }
    
    static bool compare(string s1, string s2) {
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        return s1s2 <= s2s1;
    }
};


void testSolution(){
    vector<int> numbers = {3, 32, 321};
    Solution sol;
    string s = sol.PrintMinNumber(numbers);
    cout << s << endl;
}

int main() {
    testSolution();
    return 0;
}

