/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode��
     * @param o1 int����
     * @param o2 int����
     * @return int����
     */
    vector<int> res;
    bool dfs(TreeNode* root, int a, int b) { //�������׶�����dfs����������ֵ��ȷ����������
        if (root == nullptr) return false;
        int flag = false;
        bool l = dfs(root->left, a, b);
        bool r = dfs(root->right, a, b);
        if (root->val == a || root->val == b) flag = true;
        if ((l && r) || (l && flag) || (r && flag)) { //��������ж��ǹ�������
            //1�����Ҷ�Ϊ�棬���ǹ�������
            //2,3�� ������һ�����棬�Լ������������һ��ֵ��
            res.push_back(root->val);
            return true;
        }
        return flag || l || r; //���ص�ֵҪע�⣬ֻҪ�ý����������ҵ��ˣ��ý��͸÷����棬����ý�㱾����Ҫ�ҵ�ֵ���������
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        dfs(root, o1, o2);
        if (res.empty()) return NULL;
        for (auto i : res) {
            cout << i << " ";
        }
        return res[0];
    }
};