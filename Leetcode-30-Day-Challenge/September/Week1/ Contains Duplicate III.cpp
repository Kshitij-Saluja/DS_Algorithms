/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false*/

class Solution {
public:
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
				if(nums.size()==0)
						return false;
				int c;
				vector <pair<int,int> > adj;
				pair<int,int> p;
				for(int i=0;i<nums.size();i++){
					 p.first=nums[i];
					 p.second=i;
						adj.push_back(p);
				}
				sort(adj.begin(),adj.end());
				for(int i=0;i<=(nums.size()-1);i++){
					 // cout<<nums[i]<<" ";
						for(int j=(i+1);j<nums.size();j++){
								if(abs(adj[j].second-adj[i].second)>k){
										continue;
								}
								if(j==nums.size()){
							break;
								}
								nums[i]=adj[i].first;
								nums[j]=adj[j].first;
								if(nums[i]==-2147483648 || nums[j]==-2147483648){
										if(nums[i]==-2147483648 && nums[j]>0)
											 break;
										if(nums[j]==-2147483648 && nums[i]>0)
												break;
										c=abs(nums[i]-nums[j]);
								if(c<=t)
										return true;
								}
								if(nums[i]>0 && nums[j]<0)
								{
										if(abs(nums[j])>(INT_MAX-nums[i]))
											 break;
								}
								if(nums[j]>0 && nums[i]<0)
								{
										if(abs(nums[i])>(INT_MAX-nums[j]))
												break;
								}
								if(nums[j]<0 && nums[i]<0)
								{
										if(abs(nums[j])>(INT_MAX-abs(nums[i])))
										break;
								}
								c=abs(nums[i]-nums[j]);
								if(c<=t){
									//  cout<<nums[i]<<" "<<nums[j];
										return true;
								}
								break;
								}
								
						}
				return false;
		}
};