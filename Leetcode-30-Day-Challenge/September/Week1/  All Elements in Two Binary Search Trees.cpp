/*Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5]*/




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
		vector <int> k1;
		vector <int> k2;
public:
		void preorder(TreeNode* root,int k){
				if(root==NULL)
						return ;
			
				preorder(root->left,k);
					if(k==0)
						k1.push_back(root->val);
				if(k==1)
						k2.push_back(root->val);
				 preorder(root->right,k);
		}
		vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
				preorder(root1,0);
				 preorder(root2,1);
				vector <int> mer;
				int n1=k1.size();
				int n2=k2.size();
				int i=0;
				int j=0;
				while(i<n1 && j<n2){
						if(k1[i]<k2[j]){
								mer.push_back(k1[i]);
								i++;
						}
						else if(k2[j]<k1[i])
						{
								 mer.push_back(k2[j]);
								j++;
						}
				 else{
									mer.push_back(k1[i]);
					 i++;
								mer.push_back(k2[j]);
								j++;
						}
				}
						while(i<n1){
								mer.push_back(k1[i]);
								i++;
						}
							while(j<n2){
								mer.push_back(k2[j]);
								j++;
						}
				return mer;
		}
};