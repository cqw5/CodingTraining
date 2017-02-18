/*! Author: qwchen
 *! Date  : 2017-02-18
 *! 递归和动态规划: 9.5 字符串排列
 *  题目描述:
 *    编写一个方法，确定某字符串的所有排列组合。
 *    给定一个string A和一个int n,代表字符串和其长度，请返回所有该字符串字符的排列，
 *    保证字符串长度小于等于11且字符串中字符均为大写英文字符，排列中的字符串按字典序从大到小排序。(不合并重复字符串)
 */

/*
 * 思路：
 *   全排列
 * 时间复杂度：前面全排列的时间复杂度为O(n!)，后面排序的时间复杂度为O(n!logn!)
 * 空间复杂度：O(n!)
 */
class Permutation {
public:
    vector<string> getPermutation(string A) {
        vector<string> res;
        int n = A.size();
        if (n <= 0) return res;
        permutation(res, A, 0, n);
        sort(res.rbegin(), res.rend());
        return res;
    }

private:
    void permutation(vector<string> &res, string &A, int k, int n) {
        if (k + 1 == n) {
            res.push_back(A);
        }
        else {
            for (int i = k; i < n; i++) {
                swap(A[k], A[i]);
                permutation(res, A, k+1, n);
                swap(A[k], A[i]);
            }
        }
    }
};

