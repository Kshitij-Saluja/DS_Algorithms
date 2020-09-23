/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map <int,int> m;
		vector<int> v;
		unordered_set <int> s;
		for(auto i: nums){
			m[i]++;
			if(m[i]>nums.size()/3)
				s.insert(i);
		}
		for(auto i:s)
		v.push_back(i);
		return v;
	}
}