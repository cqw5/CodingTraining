/*! Author: qwchen
 *! Date  : 2017-01-04
 *! 栈和队列: 3.6 双栈排序
 *！题目描述：
 *      请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
 */

#include <iostream>
#include <stack>

using namespace std;

/*
 * 思路：
 *   用A表示未排序的栈，用B表示排序后的栈
 *   对于A中的每一个元素，将其出栈，放到B中，使得B中已有元素都小于该元素，直到栈A为空为止，具体如下：
 *       将A的栈顶元素出栈，放在临时变量tmp中，如果tmp大于B中所有元素，将tmp入到B中，否则，将B中大于tmp的所有元素出栈，入栈到A中
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class TwoStacks {
public:
    stack<int> twoStacksSort(stack<int> numbers) {
        stack<int> sortedNumbers;
        while (!numbers.empty()) {
            int tmp = numbers.top();
            numbers.pop();
            while (!sortedNumbers.empty() && sortedNumbers.top() > tmp) {
                numbers.push(sortedNumbers.top());
                sortedNumbers.pop();
            }
            sortedNumbers.push(tmp);
        }
        return sortedNumbers;
    }
};

void test() {
    stack<int> numbers;
    for (int i = 5; i > 0; i--) {
        numbers.push(i);
    }
    TwoStacks twoStacks;
    stack<int> sortedNumbers = twoStacks.twoStacksSort(numbers);
    while(!numbers.empty()) {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    cout << endl;
    while(!sortedNumbers.empty()) {
        cout << sortedNumbers.top() << " ";
        sortedNumbers.pop();
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}

