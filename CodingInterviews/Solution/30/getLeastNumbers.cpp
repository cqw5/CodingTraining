/*! Author: qwchen
 *! Date  : 2016-11-21
 *  30. 最小（大）的k个数
 * 此题要求当 k>元素 个数时认为是非法输入，也返回空
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 最小的K个数
 * 思路：借鉴快速排序的paritition函数
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)
 * 缺点：会修改原始的数组
 */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int> input, int k) {
        vector<int> res;
        if (input.size() == 0 || k == 0 || input.size() < k) {
            return res;
        }
        getKMin(input, 0, input.size()-1, k-1);
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }

private:
    int paritition(vector<int>& input, int low, int high) {
        int key = input[low];
        while(low < high) {
            while(low < high && input[high] >= key) high--;
            input[low] = input[high];
            while(low < high && input[low] <= key) low++;
            input[high] = input[low];
        }
        input[low] = key;
        return low;
    }
    void getKMin(vector<int>& input, int low, int high, int k) {
        if (low >= high) return;
        int mid = paritition(input, low, high);
        if(k < mid)      getKMin(input, low, mid-1, k);
        else if(k > mid) getKMin(input, mid+1, high, k);
    }
};


/*
 * 思路：开辟一个堆来保存当前前k小的元素，新来一个元素时，与堆中最大的元素比较，如果新元素小于堆中最大元素，pop堆中最大元素并push新来的元素，否则跳过该新来的元素。
 * 时间复杂度：O(nlogk)
 * 空间复杂度：O(k)
 * 表面上看该方法的时间复杂度和空间复杂度都要比前面的方法多，但是该方法不修改原来的数组，而且还能做到只需要在内存中开辟大小为k的堆，
 * 不需要一次性把整个原始数组都加入到内存中，对于大规模数据或者流数据，该方法实际上更加适合
 */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int> input, int k) {
        vector<int> result;
        if (input.size() == 0 || k == 0 || input.size() < k) {
            return result;
        }
        priority_queue<int> heap;
        for (int i = 0; i < k; i++) {
            heap.push(input[i]);
        }
        for (int i = k; i < input.size(); i++) {
            if (input[i] < heap.top()) {
                heap.pop();
                heap.push(input[i]);
            }
        }
        while(!heap.empty()) {
            result.insert(result.begin(), heap.top());
            heap.pop();
        }
        return result;
    }
};


/*
 * 最大的K个数（和最小的k个数基本一样，不同的地方只是在parition函数中
 *    * 比较input[high] >= key时，改为input[high] <= key
 *    * 比较input[low] <= key时，改为input[low] >= key
 * 思路：借鉴快速排序的paritition函数
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)
 * 缺点：会修改原始的数组
 */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int> input, int k) {
        vector<int> res;
        if (input.size() == 0 || k == 0 || input.size() < k) {
            return res;
        }
        getKMax(input, 0, input.size()-1, k-1);
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }

private:
    int paritition(vector<int>& input, int low, int high) {
        int key = input[low];
        while(low < high) {
            while(low < high && input[high] <= key) high--;
            input[low] = input[high];
            while(low < high && input[low] >= key) low++;
            input[high] = input[low];
        }
        input[low] = key;
        return low;
    }
    void getKMax(vector<int>& input, int low, int high, int k) {
        if (low >= high) return;
        int mid = paritition(input, low, high);
        if(k < mid)      getKMax(input, low, mid-1, k);
        else if(k > mid) getKMax(input, mid+1, high, k);
    }
};


void testSolution() {
    vector<int> input = {4,5,1,6,2,7,3,8};
    int k = 4;
    Solution3 sol;
    vector<int> result = sol.getLeastNumbers(input, k);
    for (int elem: result) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(){
    testSolution();
    return 0;
}

