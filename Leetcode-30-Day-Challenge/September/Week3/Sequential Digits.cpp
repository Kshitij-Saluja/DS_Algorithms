/*An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]*/

class Solution {
public:
		vector<int> sequentialDigits(int low, int high) {
		int n=1;
				int p=low;
				int k=0;
				vector <int> ans;
				while((p/10)!=0){
						p=p/10;
						k++;
				}
				int p2=high;
				int k2=0;
				while(p2!=0){
						p2=p2/10;
						k2++;
				}
				int u=k;
				int j=p;
				while(j!=9){
						k=u;
				p=j*pow(10,k);
				k--;
				int s=p;
						int y=j;
				while(k!=-1){
			 y++;
						if(k>=9 )
								break;
						if(y==10)
								break;
								if(s>(INT_MAX-y*pow(10,k)));
						else
					 s=s+y*pow(10,k);
						k--;
				}
				if(k==-1 && s<=high && s>=low)
				ans.push_back(s);
						j++;
		}
				int u3=u+1;
				while(u3<=k2){
						j=1;
						while(j!=9){
						k=u3;
									if(k>=9){
							 //       cout<<k;
								break;
									}
				p=j*pow(10,k);
				k--;
				int s=p;
						int y=j;
				while(k!=-1){
			 y++;
							if(k>=9)
								break;
						if(y==10)
								break;
				if(s>(INT_MAX-y*pow(10,k)));
						else
					 s=s+y*pow(10,k);
						k--;
				}
						 if(k==-1 && s<=high && s>=low) 
				ans.push_back(s);
						j++;   
				}
						u3++;
				}
				return ans;
		}
};