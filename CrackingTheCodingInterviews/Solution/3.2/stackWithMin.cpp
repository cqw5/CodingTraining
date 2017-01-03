/*! Author: qwchen
 *! Date  : 2017-01-03
 *! 栈和队列: 3.2
 *！题目描述：
 *    设计一个栈，除了push和pop方法，还支持min方法，可以返回栈中的最小值。push、pop和min三个方法的时间复杂度都为O(1)
 *！Solution
 *    解法1、解法2、解法3的时间复杂度都为O(1)，解法2不用对每个元素都创建对象，更节省空间，解法2比解法1更优
 *    解法3是对解法2做了改进，解法3是最优解法
 */

// 这道题要注意考察的核心是min方法，因此可以直接继承stack来简化代码

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

/*
 * 解法1：
 *   栈中存放的元素不在是简单的元素，而是一个类，该类有两个属性，一个是该元素的值，一个是当前的最小元素
 */
class NodeWithMin {
public:
    int value;
    int min;
    NodeWithMin(int theValue, int theMin): value(theValue), min(theMin) {}
};

class StackWithMin1: public stack<NodeWithMin> {
public:
    // 重写push方法
    void push(int theValue) { 
        int theMin = theValue < min()? theValue: min();
        NodeWithMin node(theValue, theMin);
        stack<NodeWithMin>::push(node);
    }

    int min() {
        return stack<NodeWithMin>::empty()? INT_MAX: stack<NodeWithMin>::top().min; // 栈为空时调用min会返回INT_MAX
    }
};


/*
 * 解法2：
 *   用一个辅助栈，来存到当前最小的元素。即原始栈每push一个元素，辅助栈就push一个当前最小的元素；元素栈每pop一个元素，辅助栈也pop一个元素
 */
class StackWithMin2: public stack<int> {
public:
    // 重写push方法，原始栈和辅助栈都要push
    void push(int theValue) {
        stack<int>::push(theValue);
        if (theValue < min()) {
            minStack.push(theValue);
        }
        else {
            minStack.push(min());
        }
    }

    // 重写pop方法，原始栈和辅助栈都要pop
    void pop() {
        if (stack<int>::empty()) {
            throw new range_error("out of range");
        }
        stack<int>::pop();
        minStack.pop();
    }

    int min() {
        return minStack.empty()? INT_MAX: minStack.top();
    }

private:
    stack<int> minStack;
};


/*
 * 解法3：
 *   用一个辅助栈，来存到当前最小的元素。
 *   对解法2做了改进，新来的元素，只有小于等于min元素，才将其push到辅助栈；pop元素时，只有pop的元素刚好是min元素，才pop辅助栈
 */
class StackWithMin3: public stack<int> {
public:
    // 重写push方法，原始栈和辅助栈都要push
    void push(int theValue) {
        stack<int>::push(theValue);
        if (theValue <= min()) {
            minStack.push(theValue);
        }
    }

    // 重写pop方法，原始栈和辅助栈都要pop
    void pop() {
        if (stack<int>::empty()) {
            throw new range_error("out of range");
        }
        if (stack<int>::top() == min()) {
            minStack.pop();
        }
        stack<int>::pop();
    }

    int min() {
        return minStack.empty()? INT_MAX: minStack.top();
    }

private:
    stack<int> minStack;
};

void test() {
    // StackWithMin1 s;
    // StackWithMin2 s;
    StackWithMin3 s;
    s.push(5); 
    cout << s.min() << endl;
    s.push(6); cout << s.min() << endl;
    s.push(3); cout << s.min() << endl;
    s.push(7); cout << s.min() << endl;
    s.pop();   cout << s.min() << endl;
    s.pop();   cout << s.min() << endl;
}

int main() {
    test();
    return 0;
}

