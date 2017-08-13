/*! Author: qwchen
 *! Date  : 2016-11-17
 *  21. 包含min函数的栈
 *  思路：在栈中维护一个成员变量记录最小元素minElem。
 *        当push元素时，如果新的元素小于最小元素，更新minElem。push操作的时间复杂度：O(1)
 *        当pop元素时，要判断pop的元素是否为minElem，如果是就在pop之后寻找栈中元素的最小元素，这步操作的时间复杂度为: O(n)
 *                     如果pop的元素不是minElem，则直接pop出栈顶元素，这步操作的时间复杂度是：O(1)
 *                     最坏情况是每次pop都pop到最小元素，此时pop的操作的时间复杂度为: O(n)
 * 
 * 还有另一种思路是用空间换时间，用一个与数据栈大小相等的辅助栈，辅助栈的栈顶元素代表当前数据栈中的最小元素。
 * 当push元素时，除了向数据栈push元素，同时还向辅助栈push当前数据栈中最小的元素。
 * 当pop元素时，数据栈和辅助栈都要同时pop元素
 */

class Solution {
public:
    Solution() {
        minElem = INT_MAX;
    }
    
    void push(int value) {
        stack.push_back(value);
        if (value < minElem) {
            minElem = value;
        }
    }
    
    void pop() {
        if (stack.empty()) {
            throw new range_error("out of range");
        }
        bool popMin = false;
        if (top() == minElem) {
            popMin = true;
        }
        stack.pop_back();
        if (popMin == true) {
            minElem = INT_MAX;
            for (int i = 0; i < stack.size(); i++) {
                minElem = stack[i] < minElem ? stack[i]: minElem;
            }
        }
    }
    
    int top() {
        if (stack.empty()) {
            throw new range_error("out of range");
        }
        return stack.back();
    }
    
    int min() {
        if (stack.empty()) {
            throw new range_error("out of range");
        }
        return minElem;
    }

private:
    vector<int> stack;
    int minElem;
};

/*
 * 另一种思路：推荐
 *   用两个栈，一个保存原来的元素，一个保存每一个元素对应栈中的最小数。
 */
class Solution {
public:
    void push(int value) {
        baseStack.push(value);
        if(minStack.empty()) {
            minStack.push(value);
        }
        else{
            minStack.push(minStack.top() < value? minStack.top(): value);
        }
    }
    void pop() {
        baseStack.pop();
        minStack.pop();
        
    }
    int top() {
        return baseStack.top();
    }
    int min() {
        return minStack.top();
    }
    stack<int> baseStack;
    stack<int> minStack;
};


