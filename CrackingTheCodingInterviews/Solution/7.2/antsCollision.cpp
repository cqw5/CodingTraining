/*! Author: qwchen
 *! Date  : 2017-02-15
 *! 数学基础: 7.2 碰撞的蚂蚁
 *！题目描述：
 *    在n个顶点的多边形上有n只蚂蚁，这些蚂蚁同时开始沿着多边形的边爬行，请求出这些蚂蚁相撞的概率。
 *    (这里的相撞是指存在任意两只蚂蚁会相撞)
 *    给定一个int n(3<=n<=10000)，代表n边形和n只蚂蚁，请返回一个double，为相撞的概率。
 */

/*
 * 思路：
 *   当其中有两只蚂蚁相互朝着对方而行时，就会发生碰撞。
 *   因此，要使蚂蚁不碰撞，就得所有蚂蚁往一个方向爬行（要么顺时针，要么逆时针），算出这个概率P，1-P即为碰撞的概率
 */

// 直接公式法
class Ants {
public:
    double antsCollision(int n) {
        return 1 - 2 * pow(0.5, n);
    }
};

// 化简公式
class Ants {
public:
    double antsCollision(int n) {
        return 1 - 1.0 / pow(2, n-1);
    }
};

// 2^(n-1)替换为位运算1<<(n-1)
class Ants {
public:
    double antsCollision(int n) {
        return 1 - 1.0 / (1 << (n - 1));
    }
};

