/*! Author: qwchen
 *! Date  : 2017-02-18
 *! 递归和动态规划: 9.4 集合的子集
 *  题目描述:
 *    请编写一个方法，返回某集合的所有非空子集。
 *    给定一个int数组A和数组的大小int n，请返回A的所有非空子集。保证A的元素个数小于等于20，且元素互异。
 *    各子集内部从大到小排序,子集之间字典逆序排序
 */

/*
 * 思路：
 *   用n个数{a1,a2,...,ai,...,an-1,an}，每个数可以在或者不在子集中，总共有2^n中可能
 *   n-1个数的所有子集是n个数的所有子集中an没出现的情况的子集。即：P(n) = P(n-1) + P(n-1) * an
 *   如：
 *   n=0: {}
 *   n=1: {} {a1}
 *   n=2: {} {a1}  {a2} {a1 a2}
 *   n=3: {} {a1}  {a2} {a1 a2}    {a3} {a1 a3} {a2 a3} {a1 a2 a3}
 * 时间复杂度：求子集的时间复杂度为O(2^n)，但是排序的时间复杂度为O(2^n * log2^n)
 * 空间复杂度：O(2^n)
 */
class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        vector<vector<int>> res;
        if (A.size() == 0 || n == 0) return res;
        sort(A.rbegin(), A.rend()); // 从大到小排序
        vector<int> subSet1;
        vector<int> subSet2 = {A[0]};
        res.push_back(subSet1);
        res.push_back(subSet2);
        for (int i = 1; i < n; i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                vector<int> subSet(res[j]);
                subSet.push_back(A[i]);
                res.push_back(subSet);
            }
        }
        sort(res.rbegin(), res.rend());
        res.pop_back();
        return res;
    }
};

