#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int n;
int arr[100];

TreeNode* mirrorTree(TreeNode* root)
{
    if (root == NULL) return NULL;
    TreeNode *temp = new TreeNode(root->val);
    temp->left   = root->left ;
    temp->right  = root->right;
    root->left = mirrorTree(root->left );
    root->right  = mirrorTree(root->right);
    swap(root->left, root->right);
    return root;
}

void build(TreeNode *root, int cnt)
{
    TreeNode *L = NULL;
    TreeNode *R = NULL;
    if ((cnt<<1|1) <= n)
    {
        R = new TreeNode(arr[cnt<<1|1]);
        L = new TreeNode(arr[cnt<<1]);
    }
    else if ((cnt<<1) <= n)
    {
        L = new TreeNode(arr[cnt<<1]);
    }
    else return;
    root->left = L;
    root->right = R;
    build(L, cnt<<1);
    build(R, cnt<<1|1);
}

void Print(TreeNode *root)
{
    if (root == NULL) return;
    cout << root->val << "  ";
    Print(root->left);
    Print(root->right);
}

int main(void)
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    TreeNode *root = NULL;
    root = new TreeNode(arr[1]);
    build(root, 1);
    root = mirrorTree(root);
    Print(root);
    return 0;
}