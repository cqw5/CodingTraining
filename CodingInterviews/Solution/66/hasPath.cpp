/*! Author: qwchen
 *! Date  : 2016-12-03
 *  66. 矩阵中的路径
 *  题目描述
 *    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 *    路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 *    如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
 *    例如 "abcesfcsadee" 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的
 *    第一行第二个格子之后，路径不能再次进入该格子。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 用一维数组表示矩阵 
 * 用一个状态数组visited保存之前访问过的字符，然后再分别按上，下，左，右递归
 */
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        if (matrix == NULL || rows <= 0 || cols <= 0 || str == NULL) {
            return false;
        }
        bool *visited = new bool[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            visited[i] = false;
        }
        int pathLength = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (hasPath(matrix, rows, cols, str, row, col, pathLength, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool hasPath(char* matrix, int rows, int cols, char* str, int row, int col, int pathLength, bool* visited) {
        if (str[pathLength] == '\0') {
            return true;
        }
        bool isPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols 
            && matrix[row * cols + col] == str[pathLength]
            && visited[row * cols + col] == false) {
            pathLength++;
            visited[row  * cols + col] = true;
            isPath = hasPath(matrix, rows, cols, str, row-1, col, pathLength, visited) 
                  || hasPath(matrix, rows, cols, str, row+1, col, pathLength, visited)
                  || hasPath(matrix, rows, cols, str, row, col-1, pathLength, visited) 
                  || hasPath(matrix, rows, cols, str, row, col+1, pathLength, visited);
            if (isPath == false) {
                pathLength--;
                visited[row * cols + col] = false;
            }
        }
        return isPath;
    }

};

/*
 * (推荐)
 * 用二维数组表示矩阵
 */
class Solution2 {
public:
    bool hasPath(vector<vector<char>> &matrix, int rows, int cols, string &str) {
        vector<bool> line(cols, false);
        vector<vector<bool>> visited(rows, line);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (hasPath(matrix, rows, cols, i, j, str, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
       }

private:
    bool hasPath(vector<vector<char>> &mat, int rows, int cols, int i, int j, string &str, int k, vector<vector<bool>> &visited) {
        if (k == str.size()) return true;
        if (i >= 0 && i < rows && j >= 0 && j < cols && mat[i][j] == str[k] && visited[i][j] == false) {
            visited[i][j] = true;
            if (hasPath(mat, rows, cols, i, j+1, str, k+1, visited)
                || hasPath(mat, rows, cols, i+1, j, str, k+1, visited)
                || hasPath(mat, rows, cols, i, j-1, str, k+1, visited)
                || hasPath(mat, rows, cols, i-1, j, str, k+1, visited)) {
                return true;
            }
            visited[i][j] = false;
        } 
        return false;
    }
};        
/*
void testSolution() {
    char* matrix = "abcesfcsadee";
    char* str1 = "bcced";
    char* str2 = "abcb";
    Solution sol;
    cout << sol.hasPath(matrix, 3, 4, str1) << endl;
    cout << sol.hasPath(matrix, 3, 4, str2) << endl;
}
*/
void testSolution2() {
    vector<vector<char>> matrix = {{'a', 'b', 'c', 'e'}, 
                                   {'s', 'f', 'c', 's'},
                                   {'a', 'd', 'e', 'e'}};
    string str1 = "bcced";
    string str2 = "abcb";
    Solution2 sol;
    cout << sol.hasPath(matrix, 3, 4, str1) << endl;
    cout << sol.hasPath(matrix, 3, 4, str2) << endl;
}

int main() {
    // testSolution();
    testSolution2();
    return 0;
}

