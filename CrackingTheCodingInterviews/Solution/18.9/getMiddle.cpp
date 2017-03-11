/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 数据结构：18.9 实时中位数
 *! 题目描述：
 *    现有一些随机生成的数字要将其依次传入，请设计一个高效算法，对于每次传入一个数字后，算出当前所有传入数字的中位数。
 *    (若传入了偶数个数字则令中位数为第n/2小的数字，n为已传入数字个数)。
 *    给定一个int数组A，为传入的数字序列，同时给定序列大小n，请返回一个int数组，代表每次传入后的中位数。保证n小于等于1000。
 *  测试样例：[1,2,3,4,5,6],6
 *  返回：[1,1,2,2,3,3]
 */

/*
 * 思路：
 *   《剑指Offer》有这道题
 *    用一个大顶堆和一个小顶堆来实现，保证大顶堆的元素个数与小顶堆相同或者多一个。
 */
class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            insert(A[i]);
            res.push_back(getMid());
        }
        return res;
    }
private:
    void insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        if (maxHeap.size() - 1 > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    int getMid() {
        if (maxHeap.empty()) {
            return 0;
        }
        return maxHeap.top();
    }
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

