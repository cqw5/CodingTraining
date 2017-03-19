/*! Author: qwchen
 *! Date  : 2017-02-20
 *! 递归和动态规划: 9.7 洪水
 *！题目描述：
 *    在一个nxm矩阵形状的城市里爆发了洪水，洪水从(0,0)的格子流到这个城市，在这个矩阵中有的格子有一些建筑，洪水只能在没有建筑的格子流动。
 *    请返回洪水流到(n - 1,m - 1)的最早时间(洪水只能从一个格子流到其相邻的格子且洪水单位时间能从一个格子流到相邻格子)。
 *    给定一个矩阵map表示城市，其中map[i][j]表示坐标为(i,j)的格子，值为1代表该格子有建筑，0代表没有建筑。
 *    同时给定矩阵的大小n和m(n和m均小于等于100)，请返回流到(n - 1,m - 1)的最早时间。保证洪水一定能流到终点。
 */

/*
 * 思路：
 *   广度优先搜索，借助队列来实现。
 *   为了不额外开辟存储空间，借助原始的矩阵来存放从起始点到该点的距离。
 *   由于矩阵原本存放着0和1，为了避免和1重复，让距离从2开始计数，然后的距离减去2。
 * 时间复杂度：O(n*m)
 * 空间复杂度：O(n*m)
 */
struct Point{
    int x;  // 0 - n-1
    int y;  // 0 - m-1
    Point() {}
    Point(int theX, int theY) {
        x = theX;
        y = theY;
    }
};

/*
 * （推荐）
 * 用offset数组来表示右下左上的顺时针移动
 */
class Flood {
public:
    int floodFill(vector<vector<int>> map, int n, int m) {
        Point offset[4];
        offset[0].x = 0, offset[0].y = 1;  // 右
        offset[1].x = 1, offset[1].y = 0;  // 下
        offset[2].x = 0, offset[2].y = -1; // 左
        offset[3].x = -1, offset[3].y = 0; // 上
        queue<Point> q;
        Point current(0, 0);
        map[0][0] = 2; // 距离偏移2
        q.push(current);
        while (!q.empty()) {
            current = q.front();
            for (int i = 0; i < 4; i++) {
                Point next(current.x + offset[i].x, current.y + offset[i].y);
                if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m 
                    && map[next.x][next.y] == 0) {
                    map[next.x][next.y] = map[current.x][current.y] + 1;
                    q.push(next);
                }
            }
            q.pop();
        }
        return map[n - 1][m - 1] - 2;
    }
};

/*
 * 与上面一样，四个方向分开写
 */
class Flood {
public:
    int floodFill(vector<vector<int>> map, int n, int m) {
        queue<Point> q;
        Point current(0, 0);
        map[0][0] = 2; // 距离偏移2
        q.push(current);
        while (!q.empty()) {
            current = q.front();
            // 上
            if (current.x > 0 && map[current.x - 1][current.y] == 0) {
                map[current.x - 1][current.y] = map[current.x][current.y] + 1;
                Point up(current.x - 1, current.y);
                q.push(up);
            }
            // 右
            if (current.y < m - 1 && map[current.x][current.y + 1] == 0) {
                map[current.x][current.y + 1] = map[current.x][current.y] + 1;
                Point right(current.x, current.y + 1);
                q.push(right);
            }
            // 下
            if (current.x < n - 1 && map[current.x + 1][current.y] == 0) {
                map[current.x + 1][current.y] = map[current.x][current.y] + 1;
                Point down(current.x + 1, current.y);
                q.push(down);
            }
            // 左
            if (current.y > 0 && map[current.x][current.y - 1] == 0) {
                map[current.x][current.y - 1] = map[current.x][current.y] + 1;
                Point left(current.x, current.y - 1);
                q.push(left);
            }
            q.pop();
        }
        return map[n - 1][m - 1] - 2;
    }
};

/*
 * 与上面的思路一致，但是使用pair来存放点，而不是对象
 */
class Flood {
public:
    int floodFill(vector<vector<int>> map, int n, int m) {
        queue<pair<int, int>> q;
        map[0][0] = 2;
        pair<int, int> current(0, 0);
        q.push(current);
        while (!q.empty()) {
            current = q.front();
            // 上
            if (current.first > 0 && map[current.first - 1][current.second] == 0) {
                map[current.first - 1][current.second] = map[current.first][current.second] + 1;
                pair<int, int> up(current.first - 1, current.second);
                q.push(up);
            }
            // 右
            if (current.second < m - 1 && map[current.first][current.second + 1] == 0) {
                map[current.first][current.second + 1] = map[current.first][current.second] + 1;
                pair<int, int> right(current.first, current.second + 1);
                q.push(right);
            }
            // 下
            if (current.first < n - 1 && map[current.first + 1][current.second] == 0) {
                map[current.first + 1][current.second] = map[current.first][current.second] + 1;
                pair<int, int> down(current.first + 1, current.second);
                q.push(down);
            }
            // 左
            if (current.second > 0 && map[current.first][current.second - 1] == 0) {
                map[current.first][current.second - 1] = map[current.first][current.second] + 1;
                pair<int, int> left(current.first, current.second - 1);
                q.push(left);
            }
            q.pop();
        }
        return map[n - 1][m - 1] - 2;
    }
};


