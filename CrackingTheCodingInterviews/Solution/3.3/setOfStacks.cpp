/*! Author: qwchen
 *! Date  : 2017-01-03
 *! 栈和队列: 3.3
 *！题目描述：
 *    请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，当前一个栈填满时，新建一个栈。
 *    该数据结构应支持与普通栈相同的push和pop操作。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <class T>
class SetOfStacks {
public:
    SetOfStacks(int theSize = 10) {
        stack<T> s;
        stacks.push_back(s);
        currentStack = 0;
        size = theSize;
    }

    // 将value放入集合栈。若集合栈的最后一个栈未满，直接将value放入最后一个栈；若集合栈的最后一个栈满，新建一个栈，将value放入其中，并将栈放到集合栈中
    void push(T value) {
        if (stacks[currentStack].size() == size) {
            stack<T> s;
            s.push(value);
            stacks.push_back(s);
            currentStack++;
        }
        else {
            stacks[currentStack].push(value);
        }
    }

    // 将pop集合栈中最后一个元素。若pop后集合栈最后一个栈为空，将该栈从集合栈中删除。
    void pop() {
        if (empty()) {
            throw new range_error("Out of range");
        }
        stacks[currentStack].pop();
        if (stacks[currentStack].empty()) {
            if (currentStack != 0) {
                stacks.pop_back();
                currentStack--;
            }
        }
    }

    // 判断整个集合栈是否为空
    bool empty() {
        return stacks[currentStack].empty();
    }

    // 返回栈顶元素，即返回集合栈中最后一个栈的栈顶元素
    T top() {
        if (empty()) {
            throw new range_error("Out of range");
        }
        return stacks[currentStack].top();
    }

private:
    vector<stack<T>> stacks;  // 栈集合
    int currentStack;         // 当前集合顶的栈的下标
    int size;                 // 每个栈的最大容量
};


void test() {
    SetOfStacks<int> stacks;
    for (int i = 0; i < 28; i++) {
        stacks.push(i);
    }
    while (!stacks.empty()) {
        cout << stacks.top() << " ";
        stacks.pop();
    }
}

int main() {
    test();
    return 0;
}

