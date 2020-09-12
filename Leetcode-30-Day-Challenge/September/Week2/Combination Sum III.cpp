/*Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]*/

class Solution {
public:
	vector<vector<int>> des;
	void check(int k,int n,int i,string s){
		if(n<=0){
			if(s.size()==k && n==0)
			{
				vector <int> r;
				for(int i=0;i<k;i++){
					r.push_back((int(s[i])-48));
				}
				des.push_back(r);
			}
			return ;
		}
		for(int y=(i+1);y<=9;y++){
			if((n-y)<0)
				continue;
			check(k,(n-y),y,s+to_string(y));
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		check(k,n,0,"");
		return des;
	}
};