#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<int,int> inorder_index;
int pre_index=0;

TreeNode* construct(vector<int>& preorder, int in_start, int in_end)
{
    if(in_start > in_end) return nullptr;
    TreeNode* root = new TreeNode(preorder[pre_index++]);
    if(in_start == in_end) return root;
    int in_index = inorder_index[root->val];
    root->left = construct(preorder, in_start, in_index-1);
    root->right = construct(preorder, in_index+1, in_end);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int i=0,j=inorder.size()-1;
    for(int i=0;i<inorder.size();i++)
    {
        inorder_index[inorder[i]]=i;
    }
    return construct(preorder, i, j);
}


int main() {
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> inorder = {4,2,5,1,6,3,7};
    TreeNode* root = buildTree(preorder, inorder);
    // verify the tree structure:
    cout << root->val << " "<< endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->left->left->val << " " << root->left->right ->val << " " << root->right->left->val << " " << root->right->right->val << endl;
    return 0;
}