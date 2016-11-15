/*! Author: qwchen
 *! Date: 2016-11-15
 * 从排序矩阵中查找从小到大的第k个数。
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 最快的方案
 * 思想：二分查找。
 *       先找出矩阵中最小的元素low和最大的元素high，计算其均值mid；
 *       计算矩阵中小于等于mid的元素的个数count：
 *           如果count < k， 即k大于中间元素，则k在矩阵[mid+1, high]的后半部分
 *           如果count >= k，即k小于等于中间元素，则k在[low, mid]的前半部分
 *       不断缩减矩阵范围，直到low == high时，矩阵中剩下的这个元素就是第k个数
 */
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high  = matrix[n-1][n-1];
        while(low < high){
            int mid = low + (high - low) / 2;
            int count = getLessEqual(matrix, mid);
            if (k > count) low = mid + 1;
            else           high = mid;
        }
        return low;
    }

private:
	/*
     * 查找排序矩阵中，小于等于mid的元素的个数
     */
    int getLessEqual(vector<vector<int>>& matrix, int mid){
        int n = matrix.size();
        int i = n-1, j = 0;
        int count = 0;
        while(i >= 0 && j < n){
            if (matrix[i][j] > mid) {
                i--;
            }
            else {
                count += i + 1;
                j++;
            }
        }
        return count;
    }
};


/*
 * 实现：利用堆
 *       用一个小顶堆存储第一行元素
 *       执行以下步骤k-1次：
 *           取出堆顶元素，如果堆顶元素的x坐标小于n-1，将堆顶元素所在列的下一个元素放到堆中。
 *       最后堆顶元素就是第k个元素
 *       内部类class Point是矩阵的顶点，存储坐标和值
 */
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Point, vector<Point>, greater<Point>> pq;
        for (int i = 0; i < n; i++){
            Point point(0, i, matrix[0][i]);
            pq.push(point);
        }
        for (int i = 0; i < k-1; i++){
            Point point = pq.top();
            pq.pop();
            if (point.x < n-1){
                Point point2(point.x + 1, point.y, matrix[point.x + 1][point.y]);
                pq.push(point2);
            }
        }
        return pq.top();
    }
    
private:
    class Point {
        public:
        int x;
        int y;
        int val;
        Point(int x, int y, int val):x(x),y(y),val(val){}
        operator int() const {
            return val;
        }
    };
};


void testSolution(){
    vector<vector<int>> matrix = {
        {1, 5, 7},
        {3, 7, 8},
        {4, 8, 9}
    };
    Solution1 sol1;   
    Solution2 sol2;
    cout << sol1.kthSmallest(matrix, 4) << endl;  // 5
    cout << sol2.kthSmallest(matrix, 4) << endl;  // 5
}

int main(){
    testSolution();
    return 0;
}

