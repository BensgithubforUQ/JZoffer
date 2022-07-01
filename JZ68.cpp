/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode��
     * @param p int����
     * @param q int����
     * @return int����
     */


    vector<int> pos;
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        if (root == nullptr) return 0;
        int count = 0;
        if (root->val == p || root->val == q) count = 1;
        count += lowestCommonAncestor(root->left, p, q);
        count += lowestCommonAncestor(root->right, p, q);
        if (count == 2) //pos.push_back(root->val);
            return root->val;
        cout << pos.size() << endl;
        return count;
    }
};