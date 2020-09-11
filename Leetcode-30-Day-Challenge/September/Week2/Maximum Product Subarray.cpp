/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/
class Solution {
public:
					vector <int> find;
		int check(vector <int>& nums,int i,int j){
				if((j-i)<=1){
						return nums[i];
				}
				int k1=0;
				int p=-1;
				int u1=1;
				int u=-1;
				for(int k=i;k<j;k++){
						u1=u1*nums[k];
				if(nums[k]<0 && k1==0){
						k1++;
						p=k;
						u=k;
						continue;
				}
						if(nums[k]<0){
								u=k;
								k1++;
						}
				}
				if(k1%2==0){
						return u1;
				}
					int pro=1;
				for(int h=i;h<u;h++){
						pro=pro*nums[h];
				}
				 int pro1=1;
				for(int h=(p+1);h<j;h++){
						pro1=pro1*nums[h];
				}
				return max(pro,pro1);
				
		}
		int maxProduct(vector<int>& nums) {
				if(nums.size()==0){
						return 0;
				}
				if(nums.size()==1)
						return nums[0];
				int k=0;
				int o=0;
				int p=-1;
				int u=1;
			int s=INT_MIN;
				for(int i=0;i<nums.size();i++){
					 s=max(s,nums[i]);
						if(nums[i]==0){
								find.push_back(i);
								o=1;
						}
				}
				if(nums[nums.size()-1]!=0)
						find.push_back((nums.size()));
				s=max(s,check(nums,0,find[0]));
			 // cout<<s;
				for(int i=1;i<find.size();i++){
						s=max(s,check(nums,find[(i-1)]+1,find[i]));
				}
				return s;
		}
};