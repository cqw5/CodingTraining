/*! Author: qwchen
 *! Date  : 2016-11-12
 * 14. 调整数组顺序使奇数位于偶数前面
 * 思考：该题保证不保证奇数和奇数，偶数和偶数之间的相对位置不变，解法不同。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 假设不需要保证奇数和奇数，偶数和偶数之间的相对位置不变
 * 使用两个指针，i指向数组的首位，并不断向右移动寻找偶数；j指向数组的末尾，并不断向左移动寻找奇数；
 * 如果i指向偶数而j指向奇数，交换i与j的元素；
 * 终止条件是：i >= j
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        if (n == 0 || n == 1) return;
        int i = 0, j = n - 1;
        while(i < j){
            while(i < j && (array[i] & 1) == 1) i++;
            while(i < j && (array[j] & 1) == 0) j--;
            if (i < j) swap(array[i], array[j]);
        }
    }
};

/*
 * 假设需要保证偶数和偶数之间的相对位置不变
 * 借鉴插入排序的思想，不断把奇数插入到前面适合的位置。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 */
class Solution1 {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        if (n == 0 || n == 1) return;
        int nextIndex = 0; // nextIndex，标记期望下一个奇数存到的位置
        if (array[0] & 1 == 1) {
            nextIndex++;
        }
        for(int i = 1; i < n; i++){
            if (array[i] & 1 == 1){
                for (int j = i - 1; j >= nextIndex; j--){
                    swap(array[j], array[j+1]);
                }
                nextIndex++;
            }
        }
    }
};

/*
 * 假设需要保证偶数和偶数之间的相对位置不变
 * 借鉴归并排序的思想，使用一个辅助数组。
 * 其实该题还可以用两个辅助数组，一个存放奇数，一个存放偶数，就只需要遍历原来的数组一遍。
 * 时间复杂度：O(n): 3n
 * 空间复杂度：O(n)
 */
class Solution2 {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        if (n == 0 || n == 1) return;
        vector<int> temp;
        for (int i = 0; i < n; i++){
            if ((array[i] & 1) == 1){
                temp.push_back(array[i]);
            }
        }
        for (int i = 0; i < n; i++){
            if ((array[i] & 1) == 0){
                temp.push_back(array[i]);
            }
        }
        array.assign(temp.begin(), temp.end());
    }
};


/*
 * 假设需要保证偶数和偶数之间的相对位置不变
 * 与Solution3类似，只是用两个辅助数组，一个存放奇数，一个存放偶数，就只需要遍历原来的数组一遍。
 * 时间复杂度：O(n): 2n
 * 空间复杂度：O(n)
 */
class Solution3 {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        if (n == 0 || n == 1) return;
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < n; i++){
            if ((array[i] & 1) == 1){
                odd.push_back(array[i]);
            } else {
                even.push_back(array[i]);
            }
        }
        int i = 0;
        for(; i < odd.size(); i++){
            array[i] = odd[i];
        }
        for(int j = 0; j < even.size(); j++){
            array[i+j] = even[j];
        }
    }
};


void testSolution(){
    vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    vector<int> array1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> array2 = {1, 2, 3, 4, 5, 6, 7};
    Solution sol;
    Solution1 sol1;
    Solution2 sol2;
    sol.reOrderArray(array);
    sol1.reOrderArray(array1);
    sol2.reOrderArray(array2);
    for (int a: array){
        cout << a << " ";
    }
    cout << endl;
    for (int a: array1){
        cout << a << " ";
    }
    cout << endl;
    for (int a: array2){
        cout << a << " ";
    }
    cout << endl;
}

int main(){
    testSolution();
    return 0;
}
