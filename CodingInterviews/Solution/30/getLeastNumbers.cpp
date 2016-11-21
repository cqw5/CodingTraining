/*! Author: qwchen
 *! Date  : 2016-11-21
 *  30. 最小的k个数
 * 此题要求当 k>元素 个数时认为是非法输入，也返回空
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 思路：借鉴快速排序的paritition函数
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)
 * 缺点：会修改原始的数组
 */
class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int> input, int k) {
        vector<int> result;
        if (input.size() == 0 || k == 0 || input.size() < k) {
            return result;
        }
        paritition(input, 0, input.size()-1, k-1);
        for (int i = 0; i < k; i++) {
            result.push_back(input[i]);
        }
        return result;
    }

private:
    void paritition(vector<int>& input, int low, int high, int k) {
        if (low >= high) {
            return;
        }
        int lt = low,
            gt = high;
        int key = input[low];
        while(lt < gt) {
            while(lt < gt && input[gt] >= key) {
                gt--;
            }
            input[lt] = input[gt];
            while(lt < gt && input[lt] <= key) {
                lt++;
            }
            input[gt] = input[lt];
        }
        input[lt] = key;
        if (k < lt) {
            paritition(input, low, lt-1, k);
        }
        else if (k > lt) {
            paritition(input, lt+1, high, k);
        }
    }
};

/*
 * 思路：借鉴三向切分快速排序的paritition函数
 * 如果数组存在大量重复元素，属于该方法比Solution1快。
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)
 * 缺点：会修改原始的数组
 */
class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int> input, int k) {
        vector<int> result;
        if (input.size() == 0 || k == 0 || input.size() < k) {
            return result;
        }
        paritition(input, 0, input.size()-1, k-1);
        for (int i = 0; i < k; i++) {
            result.push_back(input[i]);
        }
        return result;
    }

private:
    void paritition(vector<int>& input, int low, int high, int k) {
        if (low >= high) {
            return;
        }
        int lt = low,
            mid = low+1,
            gt = high;
        int key = input[low];
        while(mid <= gt) {
            if (input[mid] > key) {
                swap(input[mid], input[gt--]);
            }
            else if (input[mid] < key) {
                swap(input[mid++], input[lt++]);
            }
            else {
                mid++;
            }
        }
        if (k < lt) {
            paritition(input, low, lt-1, k);
        }
        else if (k > gt) {
            paritition(input, gt+1, high, k);
        }
    }
};

/*
 * 思路：开辟一个堆来保存当前前k小的元素，新来一个元素时，与堆中最大的元素比较，如果新元素小于堆中最大元素，pop堆中最大元素并push新来的元素，否则跳过该新来的元素。
 * 时间复杂度：O(nlogk)
 * 空间复杂度：O(k)
 * 表面上看该方法的时间复杂度和空间复杂度都要比前面的方法多，但是该方法不修改原来的数组，而且还能做到只需要在内存中开辟大小为k的堆，
 * 不需要一次性把整个原始数组都加入到内存中，对于大规模数据或者流数据，该方法实际上更加适合
 */
class Solution3 {
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

