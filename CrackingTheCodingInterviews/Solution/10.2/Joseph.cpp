/*! Author: qwchen
 *! Date  : 2017-02-22
 *! 链表：10.2 约瑟夫问题II
 *! 题目描述：
 *    约瑟夫问题是一个著名的趣题。这里我们稍稍修改一下规则。
 *    有n个人站成一列。并从头到尾给他们编号，第一个人编号为1。然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。
 *    接着第二轮再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。
 *    以此类推直到剩下以后一个人。现在需要求的即是这个人的编号。
 *    给定一个int n，代表游戏的人数。请返回最后一个人的编号
 */

/*
 *
 * 思路：
 *   换一个思路，就是每一轮遍历，只保留编号为1的人。
 *
 */
class Joseph {
public:
    int getResult(int n) {
        if (n <= 0) return 0;
        list<int> circle;            // 因为有大量的删除操作，使用链表来表示这个数据结构
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }
        auto cur = circle.begin();   // 当前的位置
        auto next = circle.begin();  // 下一个位置（因为链表删除当前结点后，当前指针会为空，需要提前保留下一个位置）
        auto last = circle.begin();  // 最后一个报数的位置，以便作为下一轮的第一个位置
        int m = 2;                   // m代表每一轮数数的长度
        int len = 0;                 // 当前队列的长度
        int count = 0;               // 当前已经输了多少人，当count == len时，数完一轮
        while (circle.size() > 1) {
            len = circle.size();
            count = 1;
            while(count <= len) {
                for (int i = 0; i < m; i++) { // 一轮报数
                    if (i == 0) {             // 如果是1，保留
                        last = cur;
                        next = ++cur;
                    }
                    else {
                        next = circle.erase(cur); // 如果不是1，删除，返回下一位
                    }
                    if (next == circle.end()) { // 如果下一位是链表尾部的下一位（NULL），让下一位指向头部，从而形成循环链表
                        next = circle.begin();
                    }
                    cur = next;
                    count++;
                    if (count > len) break;
                }
            }
            m++;
            cur = last;   // 将上一轮最后一个报数的人作为下一轮第一个报数的人
        }
        return circle.front();
    }
};

