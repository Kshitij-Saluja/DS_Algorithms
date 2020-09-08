/*Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
*/






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector <string> vec;
	void preorder(TreeNode *root,string s){
		if(root==NULL)
			return ;
		if(root->left==NULL && root->right==NULL){
			vec.push_back((s+to_string(root->val)));
		}
		preorder(root->left,s+to_string(root->val));
		preorder(root->right,s+to_string(root->val));
	}
	int sumRootToLeaf(TreeNode* root) {
		preorder(root,"");
		int S=0;
		for(auto i:vec){
			int k1=i.size();
			int y=pow(2,(k1-1));
			int s=0;
			for(int k=0;k<i.size();k++){
				if(i[k]=='1')
					s=s+y*1;
				y=y/2;
			}
		 
			S=S+s;
		}
		return S;
	}
};