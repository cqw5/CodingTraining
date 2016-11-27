/*! Author: qwchen
 *! Date  : 2016-11-27
 *  52. 构建乘积数组
 *  题目描述
 *      给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *     观察到，B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]可以表示为A[0]*A[1]*...*A[i-1]和A[0]*A[1]*...*A[i-1]
 *     用C[i]=A[0]*A[1]*...*A[i-1], D[i]=A[0]*A[1]*...*A[i-1]
 *     则B[i]=C[i]*D[i]
 * 时间复杂度：O(n)
 * 空间复杂度: O(n)
 */
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        int n = A.size();
        if (n == 0) {
            return B;
        }
        vector<int> C(n, 1);
        vector<int> D(n, 1);
        for (int i = 1; i < n; i++) {
            C[i] = C[i-1] * A[i-1];
        }
        for (int i = n-2; i >= 0; i--) {
            D[i] = D[i+1] * A[i+1];
        }
        for (int i = 0; i < n; i++) {
            B.push_back(C[i] * D[i]);
        }
        return B;
    }
};


void testSolution() {
    vector<int> A = {1,2,3,4,5};
    Solution sol;
    vector<int> B = sol.multiply(A);
    for (auto i: B) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}