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


int root_idx;
unordered_map<int, int> inorder_idx; // map of elements->idx in inorder

TreeNode* build_tree(vector<int>& postorder, int in_start, int in_end)
{
    if(in_start>in_end) return nullptr;
    TreeNode* new_node = new TreeNode(postorder[root_idx--]);
    if(in_start==in_end) return new_node;
    int in_idx = inorder_idx[new_node->val];
    // build the right subtree first!
    new_node->right = build_tree(postorder,in_idx+1,in_end); 
    //build left-subtree later
    new_node->left = build_tree(postorder,in_start,in_idx-1);
    return new_node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    root_idx = n-1; // first root(wrt postorder)
    for(int i=0;i<n;i++)
        inorder_idx[inorder[i]] = i;
    return build_tree(postorder, 0, n-1);
}


int main() {
    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> inorder = {4,2,5,1,6,3,7};
    TreeNode* root = buildTree(inorder, postorder);
    // verify the tree structure:
    cout << root->val << " "<< endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->left->left->val << " " << root->left->right ->val << " " << root->right->left->val << " " << root->right->right->val << endl;
    return 0;
}