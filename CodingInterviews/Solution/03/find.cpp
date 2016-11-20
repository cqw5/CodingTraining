/*! Author: qwchen
 *! Date  : 2016-11-9
 * 3：二维数组中查找
 * 思路：这是杨氏矩阵的查找问题，可以从右上角出发查找，也可以从最下角出发查找
 *       从右上角出发：如果target<array[i][j]，则往左走j-1；如果target>array[i][j]，则往下走i+1; 如果target == array[i][j]，即找到了，返回true。
 *       从左下角出发：如果target<array[i][j]，则往上走i-1；如果target>array[i][j]，则往右走j+1; 如果target == array[i][j]，即找到了，返回true。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int numRow = array.size();
        if (numRow == 0) return false;
        int numCol = array[0].size();
        if (numCol == 0) return false;
        for (int i = 0, j = numCol - 1; i < numRow && j >= 0; ){
            if (target < array[i][j]) j--;
            else if (target > array[i][j]) i++;
            else return true;
        }
        return false;
    }
};

void testSolution(){
    vector<vector<int>> array = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };
    Solution sol;
    cout << sol.Find(array, 1) << endl;
    cout << sol.Find(array, 5) << endl;
}

int main(){
    testSolution();
    return 0;
}
