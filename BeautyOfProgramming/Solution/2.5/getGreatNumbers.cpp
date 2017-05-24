/*! Author: qwchen
 *! Date  : 2017-05-24
 *  寻找最大的K个数
 *  注意要考虑到数组的长度<k的情况。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *   借鉴快速排序的思路
 * 时间复杂度：O(N)
 * 空间复杂度：O(logN)
 */
class Solution1 {
public:
    vector<int> getGreatNumbers(vector<int> a, int k) {
        vector<int> res;
        if (k > a.size()) return res;
        sort(a, 0, a.size()-1, k-1);
        for (int i = 0; i < k; i++) {
            res.push_back(a[i]);
        }
        return res;
    }
    
    void sort(vector<int>& a, int low, int high, int k) {
        if (low < high) {
            int mid = parition(a, low, high);
            if (k > mid)      sort(a, mid+1, high, k);
            else if (k < mid) sort(a, low, mid-1, k);
        }
    }
    
    int parition(vector<int>& a, int low, int high) {
        int key = a[low];
        while (low < high) {
            while (low < high && a[high] <= key) high--;
            a[low] = a[high];
            while (low < high && a[low] >= key) low++;
            a[high] = a[low];
        }
        a[low] = key;
        return low;
    }
};


int main() {
	vector<int> a = {1,9,2,3,4,8,5,6,7,0};
	int k = 5;
	Solution1 sol1;
	vector<int> b = sol1.getGreatNumbers(a, k);
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}