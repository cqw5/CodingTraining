/*! Author: qwchen
 *! Date  : 2017-01-04
 *! 栈和队列: 3.5 用两个栈实现队列
 *！题目描述：
 *    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */

/*
 * 思路：
 *   用两个栈s1和s2
 *   push元素时，直接push到s1
 *   pop元素时，从s2 pop，但是要注意，s2可能为空。
 *       如果s2为空，需要将s1的全部元素出栈，然后入栈到s2
 *       如果s2为空，s1也为空，则抛异常
 */
class Solution {
public:
    void push(int node) {
        s1.push(node);
    }

    int pop() {
        if (s2.empty()) {
            if (s1.empty()) {
                throw new range_error("stack is empty!!!");
            }
            else {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

