/*! Author: qwchen
 *! Date  : 2016-11-21
 *  32. 整数中1出现的次数（从1到n整数中1出现的次数）
 * 此题有一个非常巧妙的解法，见https://leetcode.com/discuss/44281/4-lines-o-log-n-c-java-python，时间复杂度为logn
 */

#include <iostream>

using namespace std;

/*
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int numberOf1Between1AndN(int n) {
        int count = 0;
    	for (int i = 1; i <= n; i++) {
            int num = i;
            while (num != 0) {
                if (num % 10 == 1) {
                    count++;
                }
                num /= 10;
            }
        }
        return count;
    }
};


class Solution {
public:
    int NumberOf1Between1AndN(int n) {
        int count = 0;
        int len = size(n);
        for(int i = 0; i < len; i++) {
            count += numberOf1(n, i);
        }
        return count;
    }
    
    int size(int n){
        int count = 0;
        while(n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }
    
    int numberOf1(int n, int d) {
        int powOf10 = pow(10, d);
        int nextPowOf10 = powOf10 * 10;
        int roundDown = n - n % nextPowOf10;
        int roundUp = roundDown + nextPowOf10;
        int digit = (n / powOf10) % 10;
        if(digit > 1) {
            return roundUp / 10;
        }
        else if(digit < 1) {
            return roundDown / 10;
        }
        else {
            int right = n % powOf10;
            return roundDown/10 + right + 1;
        }
        
    }
    
    int pow(int base, int exp) {
        int res = 1;
        for(int i = 0; i < exp; i++) {
            res *= base;
        }
        return res;
    }
};


void testSolution() {
	Solution sol;
	cout << sol.numberOf1Between1AndN(12) << endl;
	cout << sol.numberOf1Between1AndN(21345) << endl;
}

int main() {
	testSolution();
	return 0;
}