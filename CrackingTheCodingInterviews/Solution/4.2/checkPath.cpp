/*! Author: qwchen
 *! Date  : 2017-01-07
 *! 栈和队列: 4.1 二叉树平衡检查
 *！题目描述：有向路径检查
 *      对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。
 */

/*
struct DGraphNode {
    int label;  // label是图的结点的ID
    vector<struct DGraphNode *> neighbors;  // 结点的所有邻居节点
    DGraphNode(int x) : label(x) {}
};*/

/*
 * 思路：深度优先
 *   寻找有向图中结点a和b之间是否存在路径，即是否存在a->b的路径 或者 存在b->a的路径，因此需要进行两次判断
 *   寻找a->b是否存在路径，可以使用深度优先搜索，而由于我们不知道图中结点的个数，应该使用map来做为辅助数组，标记结点是否已经被访问过
 * 时间复杂度：0(n)
 * 空间复杂度：O(n)
 */
class Path {
public:
    bool checkPath(DGraphNode* a, DGraphNode* b) {
        if (a == nullptr || b == nullptr) return false;
        unordered_map<DGraphNode*, bool> mapping;
        if (dfs(a, b, mapping)) return true;
        mapping.clear();
        if (dfs(b, a, mapping)) return true;
        return false;
    }

private:
    bool dfs(DGraphNode* a, DGraphNode* b, unordered_map<DGraphNode*, bool>& mapping) {
        if (a == b) return true;
        mapping[a] = true;
        for (auto c: a->neighbors) {
            if (mapping.find(c) == mapping.end()) mapping[c] = false;
            if (!mapping[c] && dfs(c, b, mapping)) return true;
        }
        return false;
    }
};


/*
 * 思路：广度优先
 *   寻找有向图中结点a和b之间是否存在路径，即是否存在a->b的路径 或者 存在b->a的路径，因此需要进行两次判断
 *   寻找a->b是否存在路径，可以使用深度优先搜索，而由于我们不知道图中结点的个数，应该使用map来做为辅助数组，标记结点是否已经被访问过
 * 时间复杂度：0(n)
 * 空间复杂度：O(n)
 */
class Path {
public:
    bool checkPath(DGraphNode* a, DGraphNode* b) {
        if (a == nullptr || b == nullptr) return false;
        unordered_map<DGraphNode*, bool> mapping;
        if (bfs(a, b, mapping)) return true;
        mapping.clear();
        if (bfs(b, a, mapping)) return true;
        return false;
    }

private:
    bool bfs(DGraphNode* a, DGraphNode* b, unordered_map<DGraphNode*, bool>& mapping) {
        queue<DGraphNode*> q;
        q.push(a);
        while (!q.empty()) {
            DGraphNode* c = q.front();
            q.pop();
            if (c == b) return true;
            mapping[c] = true;
            for (auto d: c->neighbors) {
                if (mapping.find(d) == mapping.end()) mapping[d] = false;
                if (!mapping[d]) q.push(d);
            }
        }
        return false;
    }
};

