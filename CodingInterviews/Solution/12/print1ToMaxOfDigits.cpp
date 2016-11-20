/*! Author: qwchen
 *! Date  : 2016-11-12
 * 12：打印1到最大的n位数
 * 思路：需要考虑到n很大时，这是一个大数了，无法用基本的数据类型来表示，大数需要用字符串或者数组来表示，这是使用vector表示
 *       把问题转为成n个0-9的全排列问题，用vector[i]表示第i位（第一位是第0位）
 *       最后输出时，对于一个数，前面第一个非零元素之前的0都替换为空格
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void print1ToMaxOfNDigits(int n){
        vector<char> num(n);  // 用vector存放该大数
        print(n, 0, num);     // 递归打印
    }

private:
    /*
     * 递归打印大数
     * Parament:
     *     n: int,大数的位数
     *     m: int,当前位，即从左到右第m位（m从0开始，也是用于表示vector的下标）
     *     num: vector<char>，存放大数
     */
    void print(int n, int m, vector<char>& num){
        if (m == n) {
            bool head = true;
            for (int i = 0; i < num.size(); i++){
                if (num[i] == '0' && head){ // 第一个非0元素之前的0都替换为空
                    cout << " ";
                } else {
                    head = false;
                    cout << num[i];
                }
            }
            cout << endl;
            return;
        }
        for (char i = '0'; i <= '9'; i++){
            num[m] = i;
            print(n, m + 1, num);
        }
    }
};

void testSolution(){
    Solution sol;
    sol.print1ToMaxOfNDigits(3);
}

int main(){
    testSolution();
    return 0;
}
