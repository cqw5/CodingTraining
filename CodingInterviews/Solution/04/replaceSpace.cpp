/*! Author: qwchen
 *! Date  : 2016-11-9
 * 4：替换空格
 * 思路：遍历字符串一遍，确定字符串空格个数、用指针p1指向字符串替换前的最后一个位置、用指针p2指向字符串替换后的最后一个位置
 *       从后往前遍历字符串一遍，把p1指针的元素移到p2处，如果刚好是空格，就替换为%20
 * 时间复杂度：O(n)
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // length为字符串数组str的总容量
    void replaceSpace(char *str, int length) {
        if (str == NULL || length <= 0) return;  // 字符串为空或者数组长度小于0就直接返回
         int lenStr = 0;
        int numSpace = 0;
        for (int i = 0; str[i] != '\0'; i++){
            lenStr++;
            if (str[i] == ' '){
                numSpace++;
            }
        }
        int newLenStr = lenStr + 2 * numSpace;
        if (newLenStr > length) return;  // 数组长度不够就直接返回，没法修改
        int indexOldStr = lenStr;
        int indexNewStr = newLenStr;
        while(indexOldStr >= 0 && indexNewStr > indexOldStr){
            if (str[indexOldStr] == ' '){
                str[indexNewStr--] = '0';
                str[indexNewStr--] = '2';
                str[indexNewStr--] = '%';
                indexOldStr--;
            } else {
                str[indexNewStr--] = str[indexOldStr--];
            }
        }
    }
};

void testSolution(){
    char str[] = "We are happy.";
    Solution sol;
    sol.replaceSpace(str, 100);
    cout << str << endl;
}

int main(){
    testSolution();
    return 0;
}