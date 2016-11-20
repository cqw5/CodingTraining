/*! Author: qwchen
 *! Date  : 2016-11-18
 *  22. 栈的压入、弹出序列
 *  思路：如果下一个弹出元素刚好是栈顶元素，那么直接弹出。
 *        如果下一个弹出的元素不在栈顶，我们把压栈序列中还没有入栈的元素压入栈中，直到把下一个需要弹出的元素压入栈顶为止。
 *        如果所有的数字都压入栈了，并且没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }
        stack<int> s;
        int i = 0, j = 0;
        while (i < popV.size()) {        
            if (s.empty()) {
                s.push(pushV[j++]);
            }
            else if (s.top() == popV[i]) {
                s.pop();
                i++;
            }
            else if (j < pushV.size()) {
                s.push(pushV[j++]);
            }
            else {
                return false;
            }
        }
        return true;
    }
};

void testSolution(){
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV1 = {4,5,3,2,1};
    vector<int> popV2 = {4,3,5,1,2};
    Solution sol;
    cout << sol.IsPopOrder(pushV, popV1) << endl;
    cout << sol.IsPopOrder(pushV, popV2) << endl; 
}

int main() {
    testSolution();
    return 0;
}