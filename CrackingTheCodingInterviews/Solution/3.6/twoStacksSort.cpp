
#include <iostream>
#include <stack>

using namespace std;

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

