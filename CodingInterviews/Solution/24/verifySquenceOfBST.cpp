/*! Author: qwchen
 *! Date  : 2016-11-19
 *  24. 二叉搜索树的后序遍历序列
 *  思路：在二叉搜索树的后序遍历中，最后一个数是树的根节点。数组中前面的数字可以分为两部分：
 *            第一部分是根节点的左子树，他们都比根节点的值要小。
 *            第二部分是根节点的右子树，他们都比根节点的值要大。
 *        我们可以从数组中找到第一个大于等于根节点的值：
 *            如果该值是数组的第一个元素，说明根节点没有左子树；寻找右子树中最小的数，如果右子树存在小于根节点的数，则这不符合后序遍历序列，返回false，否则递归判断右子树序列
 *            如果该值是数组的最后一个元素（即根节点），说明根节点没有右子树；递归判断左子树序列。
 *            如果不是以上两种情况，说明根节点存在左子树和右子树，递归判断左子树序列和右子树序列。
 *            递归的终止条件是：树中只有一个结点，1个结点的话，肯定能作为后序遍历序列，直接返回true。
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) { // 该题认为空序列不是空树的后序遍历
            return false;
        }
        return verify(sequence, 0, sequence.size() - 1);
    }

private:
    /*
     * 从序列sequence[low: high]中寻找第一个大于等于val的元素，返回其下标
     */
    int greatEqual(vector<int>& sequence, int low, int high, int val) {
        int i = low;
        for (; i <= high; i++) {
            if (sequence[i] >= val) {
                break;
            }
        }
        return i;
    }
    
    /*
     * 返回序列sequence[low: high]中最小的元素
     */
    int min(vector<int>& sequence, int low, int high) {
        int minVal = INT_MAX;
        for (int i = low; i <= high; i++) {
            if (sequence[i] < minVal) {
                minVal = sequence[i];
            }
        }
        return minVal;
    }

    /*
     * 判断序列sequence[low: high]是否是二叉搜索树的后序遍历序列
     */    
    bool verify(vector<int>& sequence, int low, int high) {
        if (low >= high) {
            return true;
        }
        int second = greatEqual(sequence, low, high, sequence[high]);
        if (second == low) {
            if (min(sequence, low, high - 1) < sequence[high]) {
                return false;
            }
            else {
                return verify(sequence, low, high - 1);
            }
        }
        else if (second == high) {
            return verify(sequence, low, high - 1);
        }
        else {
            if (min(sequence, second, high - 1) < sequence[high]) {
                return false;
            }
            else {
                return verify(sequence, low, second - 1) && verify(sequence, second, high - 1);
            }
        }
    }
};

void testSolution(){
    vector<int> seq1 = {5,7,6,9,11,10,8}; // true
    vector<int> seq2 = {7,4,6,5};         // false
    Solution sol;
    cout << sol.VerifySquenceOfBST(seq1) << endl;
    cout << sol.VerifySquenceOfBST(seq2) << endl;
}

int main() {
    testSolution();
    return 0;
}

