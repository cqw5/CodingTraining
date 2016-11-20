/*! Author: qwchen
 *! Date  : 2016-11-8
 * 7: 用两个栈实现队列
 */

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()){
            throw new range_error("queue is empty");
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};