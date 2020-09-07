/*A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.*/

class Solution {
public:
	vector<int> partitionLabels(string S) {
		int k=0;
		unordered_map <char,int> m;
		unordered_map <char,int> m2;
		for(auto i:S){
			if(m2.find(i)==m2.end())
			{
				m2[i]=k;
			}
			m[i]=k;
			k++;
		}
		int e=m[S[0]];
		int p=0;
		int u=0;
		vector <int> vec;
		for(int i=0;i<S.size();i++){
			if(m[S[i]]<=e){
				continue;
			}
		 if(m2[S[i]]>e){
			vec.push_back((i-u));
			u=i;
		 }   
		e=m[S[i]];
			
		 
		}
		vec.push_back((S.size()-u));
		return vec;
	}
};