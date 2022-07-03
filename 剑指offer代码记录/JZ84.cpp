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
     * @param sum int����
     * @return int����
     */
    int res = 0;
    void dfs(TreeNode* root, int sum, bool del) {
        if (root == nullptr) return;
        if (!del) { //�����û�м�������ԭֵ��ȥ
            dfs(root->left, sum, del);
            dfs(root->right, sum, del);
        }
        del = true;//��ֵ֮�󣬾Ͳ��ܽ����洫ԭֵ�ģ��Ժ���붼��
        int temp = 0;
        temp = sum - root->val;
        if (temp == 0) res++;
        dfs(root->left, temp, del);
        dfs(root->right, temp, del);
    }
    int FindPath(TreeNode* root, int sum) {
        // write code here
        dfs(root, sum, false);
        return res;

    }
};


