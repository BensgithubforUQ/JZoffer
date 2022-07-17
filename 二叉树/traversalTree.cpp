#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

//��������ǰ�����
vector<int> pre_order_traversal(TreeNode* root) { //��νǰ����������ǣ��ȱ�����������Ȼ�����������������dfs��һ�֡�
    vector<int> res;
    if (root != nullptr)res.push_back(root->val);
    else return res;
    vector<int> left = pre_order_traversal(root->left);
    vector<int> right = pre_order_traversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

//���������������
vector<int> in_order_Traversal(TreeNode* root) { //��ν������������ǣ��ȱ���������Ȼ��������ڵ�ֵ��Ȼ�������������Ҳ��dfs��һ��
    // write code here
    vector<int>res;
    if (root == nullptr) return res;
    vector<int>left = in_order_Traversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(root->val);
    vector<int>right = in_order_Traversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

//�������ĺ������
vector<int> post_order_Traversal(TreeNode* root) { //traversal��ν������������Ǳ���˳��Ϊ�������������������ڵ��dfs
    // write code here
    vector<int> res;
    if (root == nullptr) return res;
    vector<int> left = post_order_Traversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
    vector<int> right = post_order_Traversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(root->val);
    return res;
}

//������bfs�ĵݹ�д��
void level_order_support(TreeNode* root, vector<vector<int>>& temp, int level) { //�ݹ鷨���������bfs
    if (root == nullptr) return;
    if (level > temp.size()) temp.push_back(vector<int>(0));
    temp[level - 1].push_back(root->val);
    level_order_support(root->left, temp, level + 1);
    level_order_support(root->right, temp, level + 1);
}
vector<vector<int> > levelOrder(TreeNode* root) { //�ݹ鷨��bfs
    // write code here
    vector<vector<int>> res;
    int level = 1;
    level_order_support(root, res, level);
    return res;
}

//������bfs�ǵݹ�д��������˫��ջ��
vector<vector<int> > levelOrder_deque(TreeNode* root) { //����ջ��
    // write code here
    deque<TreeNode*> level;
    vector<vector<int>> res;
    if (root == nullptr) return res;
    level.push_back(root);
    int size = 1;
    while (size) {
        int temp_size = 0;
        vector<int> temp; //temp�������ڼ�¼�����val
        for (int i = 0; i < size; i++) {//size�ǵ�ǰ��Ķ��е�size��С
            temp.push_back(level[0]->val); //���ڵ�ǰ���е�ÿ������ֵ��push
            if (level[0]->left != nullptr) { //���ڵ��к�++
                level.push_back(level[0]->left);
                temp_size++;
            }
            if (level[0]->right != nullptr) {//���ڵ��к�++
                level.push_back(level[0]->right);
                temp_size++;
            }
            level.pop_front(); //���ڵ�������Ѿ����꣬�ӽڵ��Ѿ�����queue��pop
        }
        if (temp.size() != 0) res.push_back(temp);
        size = temp_size;
    }
    return res;
}


void bfs_bendPrint(TreeNode* root, vector<vector<int>>& temp, int level, bool flag) { //֮���δ�ӡ��ʵ���ϻ���bfs��ֻ������������ķ�����һ��
    if (root == nullptr) return;
    if (level > temp.size()) temp.push_back(vector<int>(0));
    if (flag) temp[level - 1].push_back(root->val);
    else temp[level - 1].insert(temp[level - 1].begin(), root->val);
    bfs_bendPrint(root->left, temp, level + 1, !flag);
    bfs_bendPrint(root->right, temp, level + 1, !flag);
}

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    int level = 1;
    bfs_bendPrint(pRoot, res, level, true);
    return res;
}


bool symmetrical_recursion(TreeNode* l, TreeNode* r) { //�ݹ�д�����ж��Ƿ��ǶԳƵĶ�����
    if (l == nullptr && r == nullptr) return true;
    if (l == nullptr || r == nullptr) return false;
    if (l->val != r->val) return false;
    return true && symmetrical_recursion(l->left, r->right) && symmetrical_recursion(l->right, r->left); //��Ҫ˼�����һ���ݹ�
}

bool isSymmetrical(TreeNode* pRoot) {
    if (pRoot == nullptr) return true;
    return symmetrical_recursion(pRoot->left, pRoot->right);
}

bool isSymmetrical_iterate(TreeNode* p) { //����д�������Ʋ���������ַ�
    deque<TreeNode*> tree;
    if (p == nullptr) return true; //�����ǶԳƵ�
    tree.push_front(p->left);
    tree.push_back(p->right);
    while (!tree.empty()) {
        TreeNode* l = tree.front();
        TreeNode* r = tree.back();
        tree.pop_front();
        tree.pop_back();
        if (l == nullptr && r == nullptr) continue; //�սڵ�
        if (l == nullptr || r == nullptr || (r->val != l->val)) return false;
        //�������������˵�����ǿսڵ㣬�����������val��ȣ���ô�������Ǻ�������
        tree.push_front(l->right);
        tree.push_front(l->left);
        tree.push_back(r->left);
        tree.push_back(r->right);
    }
    return true;
}

bool flag = true;
int lowestCommonAncestor(TreeNode* root, int p, int q) { //�������������ӽڵ�Ĺ������ȣ��ݹ�����1�����������ԣ��������ҹ�������ͨ��
    // write code here
    if (root == nullptr) return 0;
    int count = 0;
    count += lowestCommonAncestor(root->left, p, q);
    count += lowestCommonAncestor(root->right, p, q);
    if (root->val == q || root->val == p) count++;
    if (count == 2 && flag) {
        flag = false; //����ط��ܹؼ�����ΪҪ����������ȣ���������flag����һ���ҵ�֮����ٲ�����һ��
        return root->val;
    }
    return count;
}

int lowestCommonAncestor_recursion(TreeNode* root, int p, int q) { //�ݹ����2�����ö���������������
    // write code here
    if (root == nullptr) return 0;
    int mx = max(p, q);
    int mn = min(p, q); //���ö��������������ʣ���������ϸ�С�ڸ��ڵ�
    if (root->val >= mn && root->val <= mx) return root->val;
    int res = 0;
    if (root->val > mx) res = lowestCommonAncestor(root->left, p, q); 
    if (root->val < mn) res = lowestCommonAncestor(root->right, p, q);
    return res;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    //����ǰ����������������������ع�������
    int p = pre.size();
    int v = vin.size();
    if (p != v || p == 0 || v == 0) return NULL;
    TreeNode* root = new TreeNode(pre[0]);
    for (int i = 0; i < p; i++) {
        if (pre[0] == vin[i]) { //������������У����������������Ҳ����������
            //����������������ҵ���ǰ������׸���һ����ֵ��˵���ҵ��˸��ڵ����������
            vector<int> leftpre(pre.begin() + 1, pre.begin() + i + 1); //������
            vector<int> leftvin(vin.begin(), vin.begin() + i);

            root->left = reConstructBinaryTree(leftpre, leftvin); //���ص����������ĸ��ڵ�

            vector<int> rightpre(pre.begin() + i + 1, pre.end()); //������
            vector<int> rightvin(vin.begin() + i + 1, vin.end());

            root->right = reConstructBinaryTree(rightpre, rightvin); //���ص����������ĸ��ڵ�

            break;
        }
    }
    return root;
}

//���װ��ع�������������ǰ���������������ع������������ҵó�����ͼ
int rebuildBinaryTree(vector<int>& pre, vector<int>& vin, vector<vector<int>>& res, int level) {
    int p = pre.size();
    int v = vin.size();
    if (p != v || p == 0 || v == 0) return -1;
    if (res.size() < level + 1) res.push_back(vector<int>(0, 0));
    int root = pre[0];
    for (int i = 0; i < p; i++) {
        if (pre[0] != vin[i]) continue;
        res.push_back(vector<int>(0, 0));
        vector<int> leftpre(pre.begin() + 1, pre.begin() + i + 1);
        vector<int> leftvin(vin.begin(), vin.begin() + i);
        int leftroot = rebuildBinaryTree(leftpre, leftvin, res, level + 1);

        if (leftroot != -1) res[level + 1].push_back(leftroot); //û��Ҫ�󷵻������Ǿ��ö�ά�����Ҽ�¼ÿ���ֵ

        vector<int> rightpre(pre.begin() + i + 1, pre.end());
        vector<int> rightvin(vin.begin() + i + 1, vin.end());
        int rightroot = rebuildBinaryTree(rightpre, rightvin, res, level + 1);
        if (rightroot != -1) res[level + 1].push_back(rightroot);
        break;
    }
    return root;
}

vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
    // write code here
    vector<vector<int>> res;
    int a;
    if ((a = rebuildBinaryTree(xianxu, zhongxu, res, 0)) != -1)
        res[0].push_back(a);
    vector<int> ans;
    cout << res.size() << endl;
    for (int i = 0; i < res.size() - 1; i++) {
        if (!res[i].empty()) ans.push_back(res[i].back()); //ͨ�����ʶ�ά����ÿ�е�ĩβֵ���õ�����ͼ
    }
    return ans;
}
//int main() {
//    TreeNode x(0);
//    cout << sizeof(x) << endl;
//    return 0;
//}