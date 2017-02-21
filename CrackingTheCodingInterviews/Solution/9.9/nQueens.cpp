/*! Author: qwchen
 *! Date  : 2017-02-21
 *! 递归和动态规划: 9.9 n皇后问题
 *！题目描述：
 *    请设计一种算法，解决著名的n皇后问题。
 *    这里的n皇后问题指在一个nxn的棋盘上放置n个棋子，使得每行每列和每条对角线上都只有一个棋子，求其摆放的方法数。
 *    给定一个int n，请返回方法数，保证n小于等于10
 */

/*
 * 思路：
 *   用一个一维数组cols来表示n*n棋盘，其中cols的下标表示行，cols的值表示列
 *   对于cols的第i个下标，即棋盘的第i行，用n种可能，但必须满足所选用的列没有被其他皇后占用，并且对角线也没有被其他皇后占用。
 *   即满足for index < i; cols[index] != cols[i] 且 |cols[i] - cols[index]| != |i - index|
 * 时间复杂度：O(n!)
 */
class Queens {
public:
    int nQueens(int n) {
        vector<int> cols(n, 0);
        int count = 0;
        placeQueens(cols, n, 0, count);
        return count;
    }

private:
    void placeQueens(vector<int> &cols, int n, int row, int &count) {
        if (row == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (row == 0 || checkValid(cols, row, i)) {
                cols[row] = i;
                placeQueens(cols, n, row + 1, count);
            }
        }
    }
    
    bool checkValid(vector<int> &cols, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (cols[i] == col) { // 检查同一列有无其他皇后
                return false;
            }
            if (abs(row - i) == abs(col - cols[i])) { // 检查对角线有无其他皇后
                return false;
            }
        }
        return true;
    }
};

