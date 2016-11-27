/*! Author: qwchen
 *! Date  : 2016-11-27
 *  42.2 左旋转字符串
 */

#include <iostream>
#include <string>

using namespace std;

/* 
 * 思路：
 *   现在每个子串分别逆序，然后再将整个字符串逆序
 *   或者先将整个字符串逆序，再分别将两个子串逆序
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0 || n <= 0 || n >= str.size()) {
            return str;
        }
        reverse(str, 0, n-1);
        reverse(str, n, str.size()-1);
        reverse(str, 0, str.size()-1);
        return str;
    }

private:
    void reverse(string& str, int low, int high) {
        while (low < high) {
            swap(str[low++], str[high--]);
        }
    }
};

void testSolution() {
	string s = "abcXYZdef";
	Solution sol;
	cout << sol.LeftRotateString(s, 3) << endl;
}

int main() {
	testSolution();
	return 0;
}