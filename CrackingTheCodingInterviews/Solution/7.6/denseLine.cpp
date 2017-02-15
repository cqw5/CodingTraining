/*! Author: qwchen
 *! Date  : 2017-02-15
 *! 计算几何: 7.6 穿点最多的直线
 *  题目描述：
 *    在二维平面上，有一些点，请找出经过点数最多的那条线。
 *    给定一个点集vector p和点集的大小n,没有两个点的横坐标相等的情况,请返回一个vector，代表经过点数最多的那条直线的斜率和截距。
 */


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

/*
 * 思路：
 *   将任意两点连成线，把所有线取出来求出斜率和截距，并用哈希图存储下线条和个数的键值对
 */
class DenseLine {
public:
    vector<double> getLine(vector<Point> p, int n) {
        unordered_map<pair<double, double>, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double slope;
                if (p[i].x == p[j].x) { // 注意斜率可能不存在的情况
                    slope = 0;
                } 
                else {
                    slope = 1.0 * (p[j].y - p[i].y) / (p[j].x - p[i].x);    
                }
                double intercept = p[i].y - p[i].x * slope;
                m[make_pair(slope, intercept)]++;
            }
        }
        int max = 0;
            vector<double> result(2, 0);
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > max) {
                max = it->second;
                result[0] = it->first.first;
                result[1] = it->first.second;
            }
        }
        return result;
    }
};

