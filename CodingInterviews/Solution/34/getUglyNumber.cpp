/*! Author: qwchen
 *! Date  : 2016-11-22
 *  34. 丑数: 寻找第n个丑数
 */ 

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 * 该题最直观的想法是逐个检查每个整数，判断该整数是不是丑数。
 * 假设第n个丑数的值为m，则时间复杂度至少为O(mlogm)，其中m>>n；空间复杂度只需要O(1)
 * 然而用于m>>n，使得该方法的时间复杂度非常高，实际运行会超时。
 */
class Solution1 {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            return 0;
        }
        int num = 1;
        int uglyIndex = 0;
        for (; uglyIndex < index; num++) {
            if (isUgly(num)) {
                uglyIndex++;
            }
        }
        num--;
        return num;
    }
 
private:
    bool isUgly(int num) {
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1? true: false;
    }
};

/*
 * 思路：
 *   使用一个数组来保存已经找到的丑数（从小到大排列）
 *   记丑数数组中最大的数为M，数组中第一个乘以2后大于M的结果记为M2，第一个乘以3后大于M的结果记为M3，第一个乘以5后大于M的结果记为M5
 *   则下一个丑数一定是M2 M3 M5中的最小者
 *   另外，我们也不需要每次都遍历一整个数组去寻找第一个乘以2/3/5后大于M的数，而是保持一个指针p2/p3/p5分布指向第一个乘以2/3/5后大于M的数，并不断更新该数。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n) 
 */
class Solution2 {
public:
    int getUglyNumber(int index) {
        if (index <= 0) {
            return 0;
        }
		vector<int> uglyArray = {1};
        int uglyCount = 1;
        int index2 = 0,
            index3 = 0,
            index5 = 0;
        for (; uglyCount < index; uglyCount++) {
            while (uglyArray[index2] * 2 <= uglyArray.back()) {
                index2++;
            }
            while (uglyArray[index3] * 3 <= uglyArray.back()) {
                index3++;
            }
            while (uglyArray[index5] * 5 <= uglyArray.back()) {
                index5++;
            }
            int ugly2 = uglyArray[index2] * 2,
                ugly3 = uglyArray[index3] * 3,
                ugly5 = uglyArray[index5] * 5;
            uglyArray.push_back(minOf3Num(ugly2, ugly3, ugly5));
        }
        return uglyArray.back();
    }
    
private:
    int minOf3Num(int a, int b, int c) {
        return min(min(a, b), c);
    }
};


void testSolution() {
	Solution2 sol;
	cout << sol.getUglyNumber(4) << endl;    // 4
	cout << sol.getUglyNumber(100) << endl;  // 1536
	cout << sol.getUglyNumber(1000) << endl; // 51200000
}

int main() {
	testSolution();
	return 0;
}

