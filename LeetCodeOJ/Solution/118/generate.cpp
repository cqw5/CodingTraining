/*! Source: https://leetcode.com/problems/pascals-triangle
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  Pascal三角
 *    给定numRows=5，生成：
 *    [[1],
 *     [1,1],
 *     [1,2,1],
 *     [1,3,3,1],
 *     [1,4,6,4,1]
 *    ]
 */

/*
 * 思路：
 *   每一层，除了第一个后最后一个元素外，其他元素满足：
 *   A[i][j] = A[i-1][j-1] + A[i-1][j]
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) return res;
        res.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> layer = {1};
            for (int j = 1; j < i; j++) {
                layer.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            layer.push_back(1);
            res.push_back(layer);
        }
        return res;
    }
};

