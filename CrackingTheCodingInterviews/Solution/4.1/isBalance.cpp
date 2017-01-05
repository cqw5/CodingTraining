/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    bool isBalance(TreeNode* root) {
        if (getHeight(root) == -1) return false;
        else                       return true;
    }
    
private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHigh = getHeight(root->left);
        if (leftHigh == -1) return -1;
        int rightHigh = getHeight(root->right);
        if (rightHigh == -1) return -1;
        if (abs(leftHigh - rightHigh) > 1) return -1;
        return max(leftHigh, rightHigh) + 1;
    }
};

