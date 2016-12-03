/*! Author: qwchen
 *! Date  : 2016-12-03
 *  67. 机器人的运动范围
 *  题目描述
 *    地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
 *    例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 *    但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
 *    请问该机器人能够达到多少个格子？
 */

#include <iostream>

using namespace std;

/*
 * 思路：用一个状态数组visited保存之前访问过的字符，然后再分别按上，下，左，右递归，将每步递归的路径长度累加，并加上1（当前结点）
 */
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            return 0;
        }
        bool *visited = new bool[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            visited[i] = false;
        }
        return movingCount(threshold, rows, cols, 0, 0, visited);
    }
    
private:
    int movingCount(int threshold, int rows, int cols, int row, int col, bool* visited) {
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited)) {
            visited[row * cols + col] = true;
            count = 1 + movingCount(threshold, rows, cols, row+1, col, visited) 
                      + movingCount(threshold, rows, cols, row-1, col, visited) 
                      + movingCount(threshold, rows, cols, row, col+1, visited) 
                      + movingCount(threshold, rows, cols, row, col-1, visited);
        }
        return count;
    }
    
    bool check(int threshold, int rows, int cols, int row, int col, bool* visited) {
        if (row >= 0 && row < rows && col >= 0 && col < cols
            && getDigitSum(row) + getDigitSum(col) <= threshold
            && visited[row * cols + col] != true) {
            return true;
        }
        return false;
    }
    
    int getDigitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number = number/10;
        }
        return sum;
    }
};

void testSolution() {
	Solution sol;
	cout << sol.movingCount(18, 100, 100) << endl;
}

int main() {
	testSolution();
	return 0;
}