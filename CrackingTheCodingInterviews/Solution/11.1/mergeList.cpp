/*! Author: qwchen
 *! Date  : 2017-02-24
 *! 查找与排序：11.1 有序数组合并
 *! 题目描述：
 *    给定两个排序后的数组A和B，其中A的末端有足够的缓冲空间容纳B，编写一个方法，将B合并到A
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *   使用归并排序，从后往前排
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class MergeList {
public:
	vector<int> merge(vector<int> a, vector<int> b, int lenA, int lenB) {
		if (lenA == 0) return b;
		if (lenB == 0) return a;
		int i = lenA - 1;
		int j = lenB - 1;
		int k = lenA + lenB - 1;
		while (i >=0 && j >= 0) {
			if (a[i] > b[j]) {
				a[k--] = a[i--];
			}
			else {
				a[k--] = b[j--];
			}
		}
		if (i >= 0) {
			a[k--] = a[i--];
		}
		if (j >= 0) {
			a[k--] = b[j--];
		}
		return a;
	}
};

int main() {
	vector<int> a = {1, 2, 4, 6, 0, 0, 0, 0, 0, 0};
	vector<int> b = {3, 5, 7};
	int lenA = 4, lenB = 3;
	MergeList ml;
	vector<int> c = ml.merge(a, b, lenA, lenB);
	for (int i = 0; i < lenA + lenB; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
}

