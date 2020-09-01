/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9

*/

class Solution {
public:
		vector <string> vec;
		string fin="";
		void fun(string s,string s1,bool vis[4],int i){
	if(s1.size() == 4){
				if((int(s1[0])-48)>2 || (int(s1[2])-48)>5);
				else{
						
						if((int(s1[0])-48)==2 && (int(s1[1])-48)>=4);
						else{
							//  cout<<s1<<" ";
						fin=max(fin,s1);
						}
				}
		return ;
	}
	for(int j=0;j<4;j++){
	//	cout<<j<<" ";
		if(vis[j]==false){
						vis[j]=true;
			fun(s,s1+s[j],vis,i+1);
			vis[j]=false;
		}
	}
}
		string largestTimeFromDigits(vector<int>& A) {
				string s="";
			 for(auto i: A){
					 s=s+to_string(i);
			 }
				bool vis[4];
				for(int i=0;i<4;i++)
						vis[i]=false;
				fun(s,"",vis,0);
				if(fin=="")
						return fin;
			 // cout<<fin[0];
			//  string h=fin;
				fin= fin.substr(0,2)+":"+fin.substr(2,4);
				
				return fin;
		}
};
