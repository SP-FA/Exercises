#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int num = 0;

TreeNode *dfs(vector<int>& preorder, vector<int>& inorder, int left, int right)
{
    if (left == right) return NULL;
    TreeNode *head = NULL;
    for (int i=left;i<right;i++)
    {
        if (preorder[num] == inorder[i])
        {
            num++;
            head = new TreeNode(inorder[i]);
            head->left  = dfs(preorder, inorder, left, i    );
            head->right = dfs(preorder, inorder, i+1 , right);
            break;
        }
    }
    return head;
}

TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int left = 0;
    int right = inorder.size();
    TreeNode *head = dfs(preorder, inorder, left, right);
    return head;
}

int main(void)
{
    return 0;
}