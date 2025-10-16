#include <iostream>
#include <array>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* array_to_BST(array<int,10> &nums, int left, int right)
{
    if(left > right) return nullptr;
    int mid = left + (right-left)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = array_to_BST(nums, left, mid-1);
    root->right = array_to_BST(nums, mid+1, right);
    return root;
}

int main()
{
    array<int,10> nums = {-10,-3,0,5,9,12,15,20,25,30};
    TreeNode* root = array_to_BST(nums, 0, nums.size()-1);
    cout << "Root value: " << root->val << endl;
    cout << "Left child of root: " << root->left->val << endl;
    cout << "Right child of root: " << root->right->val << endl;
    return 0;
}