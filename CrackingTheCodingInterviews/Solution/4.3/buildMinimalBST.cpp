/*! Author: qwchen
 *! Date  : 2017-01-07
 *! 树和图: 4.3 高度最小的BST
 *！题目描述：
 *      对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
 *      给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。
 */

/*
 * 思路：
 *   这是一个有序数组，选择数组中间的点作为根节点，该点左边的数组元素作为左子树结点，该点右边的数组元素作为右子树结点，递归进行该过程。
 *   如果是构建二叉树，则返回构建的子树的根节点
 *   该题是返回构建的二叉树的高度，就返回子树的高度即可
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn) 递归栈
 */
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        return buildMinimalBST(vals, 0, vals.size() - 1);
    }
    
private:
    int buildMinimalBST(vector<int>& vals, int low, int high) {
        if (low > high) return 0;
        int mid = (low + high) / 2;
        return max(buildMinimalBST(vals, low, mid - 1), buildMinimalBST(vals, mid + 1, high)) + 1;
    }
};

