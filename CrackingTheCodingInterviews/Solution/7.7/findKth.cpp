/*! Author: qwchen
 *! Date  : 2017-02-15
 *! 数学基础: 7.6 第k个数
 *  题目描述:
 *    有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
 *    给定一个数int k，请返回第k个数。保证k小于等于100。
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 思路：
 *   3个素数因子3、5、7分为三个队列q3,q5,q7，其中最初存放3，5，7
 *   之后每次添加找到三个队列头中最小的数，起初为3，将3移出队列q3后，在q3添加3*3，在q5添加3*5,q7中添加3*7，
 *   此时可知q3{3*3},q5{5,3*5},q7{7,3*7}
 *   下一轮找到最小数为5，重复上述步骤，将5从q5移出，添加5*5到q5，因为5*3已经添加过所以不需要添加到q3中，将5*7添加到q7，
 *   结果q3{3*3},q5{3*5,5*5},q7{7,3*7,5*7}
 *   依次找到第k个数
 * 时间复杂度：O(k)
 * 空间复杂度：O(k)
 */
class KthNumber {
public:
    int findKth(int k) {
        if (k <= 0) return 0;
        queue<int> q3;
        queue<int> q5;
        queue<int> q7;
        q3.push(3);
        q5.push(5);
        q7.push(7);
        int minValue;
        for (int i = 0; i < k; i++) {
            int v3 = q3.front();
            int v5 = q5.front();
            int v7 = q7.front();
            minValue = min(min(v3, v5), v7);
            if (minValue == v3) {
                q3.pop();
                q3.push(minValue * 3);
                q5.push(minValue * 5);
                q7.push(minValue * 7);
            }
            else if (minValue == v5) {
                q5.pop();
                q5.push(minValue * 5);
                q7.push(minValue * 7);
            } 
            else {
                q7.pop();
                q7.push(minValue * 7);
            }
        }
        return minValue;
    }
};

/* 错误
class KthNumber {
public:
    void findKth(int k) {
        vector<long long> a = {1};
        int i = 0;
        while(a.size() <= k) {
            while(a[i] * 7 <= a.back()) i++;
            if (a[i] * 3 > a.back()) a.push_back(a[i] * 3);
			else if (a[i] * 5 > a.back()) a.push_back(a[i] * 5);
            else a.push_back(a[i] * 7);
            cout << a.back() << endl;
        }

    }
};
*/

int main() {
    KthNumber s;
    cout << s.findKth(16) << endl;
    return 0;
}

