/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
			 vector<vector<int>> ans;
		if(intervals.size()==0){
			ans.push_back(newInterval);
			return ans;
		}
		int j=0;
		int p=-1;
		int y=0;
		int o=-1;
		for(auto i:intervals){
			
			if((i[0]>=newInterval[0] && i[0]<=newInterval[1]) || (i[1]>=newInterval[0] && i[1]<=newInterval[1]) || (newInterval[0]>=i[0] && newInterval[0]<=i[1]) || (newInterval[1]>=i[0] && newInterval[1]<=i[1])){
			   if(j==0)
				o=y;
				 j=1;
				p=y;
				y++;
				continue;
			}
			if(p!=-1)
				break;
			if(i[0]>newInterval[1]){
				break;
			}
			y++;
		}
		
		if(p==-1){
		 //   cout<<"a";
			int k=0;
		 for(int i=0;i<intervals.size();i++){
			 if(intervals[i][0]>=newInterval[1] && k==0){
				ans.push_back(newInterval); 
				 k=1;
				 i--;
				 continue;
			 }
			 ans.push_back(intervals[i]);
		 }
			if(k==0 && intervals[(intervals.size()-1)][1]<=newInterval[0])
				 ans.push_back(newInterval); 
		}
		else if(o==p){
			for(int i=0;i<intervals.size();i++){
				if(i==o){
					intervals[i][1]=max(intervals[i][1],newInterval[1]);
					   intervals[i][0]=min(intervals[i][0],newInterval[0]);
				}
				ans.push_back(intervals[i]);
			}
		 
		}
		else{
	for(int i=0;i<intervals.size();i++){
		if(i==o){
			intervals[i][1]=max(intervals[p][1],newInterval[1]);
			  intervals[i][0]=min(intervals[p][0],min(intervals[i][0],newInterval[0]));
		}
		if(i>o && i<=p)
			continue;
		ans.push_back(intervals[i]);
	}
		}
		if(newInterval[0]<ans[0][0]){
			ans[0][0]=newInterval[0];
		}
		if(newInterval[1]>ans[(ans.size()-1)][1]){
			ans[(ans.size()-1)][1]=newInterval[1];
		}
	 //   cout<<ans[0][0];
		return ans;
	}
};