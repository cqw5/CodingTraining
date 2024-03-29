/*! Source: https://leetcode.com/problems/merge-k-sorted-lists/
 *! Author: qwchen
 *! Date  : 2016-11-04
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <algorithm>

using namespace std;

/* 
 * 单链表结点
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * 归并排序的思路（推荐）：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
 * 时间复杂度：k个链表合并，每一个链表平均长度n，大概需要合并log(k)次
 *  第1轮合并 k/2 个链表，每一个合并时间复杂度为 2n
 *  第2轮合并 k/4 个链表，每一个合并时间复杂度为 4n
 *  第i轮合并 k/(i+1)个链表，每一个合并时间复杂度为 (i+1)n
 *  总的时间复杂度为: k/2*2n + k/4*4n + ... + k/(i+1)*(i+1)n = kn + kn + ... + kn = kn * log(k)
 * 空间复杂度：递归会使用到 O(logk) 空间代价的栈空间。
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, lists.size()-1);
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high) {
        if (low > high) return nullptr;
        if (low == high) return lists[low];
        int mid = (low + high) / 2;
        ListNode* left = mergeSort(lists, low, mid);
        ListNode* right = mergeSort(lists, mid+1, high);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* p;
        if (list1->val <= list2->val) {
            p = list1;
            p->next = merge(list1->next, list2);
        } else {
            p = list2;
            p->next = merge(list1, list2->next);
        }
        return p;
    }
};


/* 
 * 合并k个有序链表
 * 使用一个小顶堆来协助实现，小顶堆中保存每个有序链表中最小的元素: pair(链表的序号, 链表结点)
 * 先将每个有序链表的第一个结点放入到小顶堆中，然后从小顶堆pop最小的元素放到合并的链表中，并将pop出来的元素所在链表的首节点push到堆中(若该链表不为空的话)
 * 当堆为空时，即已经遍历完所有的顶点
 * 时间复杂度：O(n1 + n2 + ... + nn) * logk
 * 空间复杂度：O(k)
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* list = new ListNode(0);  // 用首节点简化代码
        ListNode* p = list;
        // 取每个链表的首结点，构成小顶堆
        vector<pair<int, ListNode*>> minheap;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                minheap.push_back(make_pair(i, lists[i]));
                lists[i] = lists[i]->next;
            }
        }
        make_heap(minheap.begin(), minheap.end(), greaterPair);
        // 不断取出堆中最小的元素，追加到合并的链表中，并将该元素原先所在链表的首节点加入到小顶堆中
        while(!minheap.empty()){
            pair<int, ListNode*> top = minheap.front();
            p->next = top.second;
            p = p->next;
            pop_heap(minheap.begin(), minheap.end(), greaterPair);
            minheap.pop_back();
            if(lists[top.first]){
                minheap.push_back(make_pair(top.first, lists[top.first]));
                push_heap(minheap.begin(), minheap.end(), greaterPair);
                lists[top.first] = lists[top.first]->next;
            }
        }
        return list->next;
    }
    
private:
    // 自定义比较函数
    static bool greaterPair(pair<int, ListNode*> &p1, pair<int, ListNode*> &p2){
        return p1.second->val > p2.second->val;
    }
};

void testSolution(){
    ListNode* l1 = new ListNode(2); // [2, 7]
    ListNode* l2 = new ListNode(1); // [1, 6]
    ListNode* l3 = new ListNode(4); // [4, 5]
    l1->next = new ListNode(7);
    l2->next = new ListNode(6);
    l3->next = new ListNode(5);
    vector<ListNode*> lists = {l1, l2, l3};
    Solution solution;
    ListNode* list = solution.mergeKLists(lists);
    ListNode* p = list;
    cout << "[";
    while(p){
    	cout << p->val << " ";
    	p = p->next;
    } 
    cout << "]" << endl;
}

int main(){
	testSolution();
	return 0;
}