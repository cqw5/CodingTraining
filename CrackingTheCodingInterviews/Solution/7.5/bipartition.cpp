/*! Author: qwchen
 *! Date  : 2017-02-15
 *! 计算几何: 7.5 平分的直线
 *  题目描述：
 *    在二维平面上，有两个正方形，请找出一条直线，能够将这两个正方形对半分。假定正方形的上下两条边与x轴平行。
 *    给定两个vecotrA和B，分别为两个正方形的四个顶点。请返回一个vector，代表所求的平分直线的斜率和截距，保证斜率存在。
 */


/*
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
};*/

/*
 * 思路：
 *   所求直线肯定经过两个正方形的中心点，利用两个中心点的坐标求出斜率与截距即可
 *   注意数据类型，注意使用对角的两个点
 */
class Bipartition {
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        double xa = (A[0].x + A[2].x) / 2.0;
        double ya = (A[0].y + A[2].y) / 2.0;
        double xb = (B[0].x + B[2].x) / 2.0;
        double yb = (B[0].y + B[2].y) / 2.0;
        double s = (yb - ya) / (xb - xa);
        double t = ya - xa * s;
        vector<double> result = {s, t};
        return result;
    }
};

