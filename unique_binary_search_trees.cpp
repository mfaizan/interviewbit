/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void *clone(TreeNode *root, TreeNode *clonedRoot, TreeNode **modify, int A)
{
    if(&root->right == modify)
    {
        clonedRoot->right = new TreeNode(A);
        clonedRoot->left = root->left;
        if(root->right)
        {
            clonedRoot->right->left = root->right;
        }
    }
    else if(root->right)
    {
        clonedRoot->right = new TreeNode(root->right->val);
        clonedRoot->left = root->left;
        clone(root->right, clonedRoot->right, modify, A);
    }
}

TreeNode *clone(TreeNode *root, TreeNode **modify, int A)
{
    TreeNode *clonedRoot = new TreeNode(root->val);
    clone(root, clonedRoot, modify, A);

    return clonedRoot;
}

template <typename F>
void for_each_right(TreeNode *root, const F& f)
{
    do
    {
        f(&root->right);
    } while(root = root->right);
}

vector<TreeNode*> Solution::generateTrees(int A) 
{
    if(A == 1)
    {
        TreeNode *root = new TreeNode(1);

        vector<TreeNode*> v{};
        v.push_back(root);

        return v;
    }

    vector<TreeNode*> v = vector<TreeNode*>();
    vector<TreeNode*> trees = generateTrees(A - 1);

    for(TreeNode *root : trees)
    {
        TreeNode *new_root = new TreeNode(A);
        new_root->left = root;
        v.push_back(new_root);

        for_each_right(
            root, 
            [root, A, &v](TreeNode **node)
            {
                v.push_back(clone(root, node, A));
            });
    }

    return v;
}

