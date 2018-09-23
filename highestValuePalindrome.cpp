#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
string highestValuePalindrome(string &s,int k){
	int n=s.length();
	vector<int>mismatch;
	int i=0,j=n-1;
	while(i<j){
		if(s[i]!=s[j])
			mismatch.push_back(i);
		i++;j--;
	}
	if(mismatch.size()>k) return "-1";//if the number of mismatch is larger than k we can't convert it to palindrome
	for(auto a:mismatch){
		char b=max(s[a],s[n-a-1]);
		s[a]=b;
		s[n-a-1]=b;
	}
	int c=k-mismatch.size();//number of change left
	int l=0;
	while(c>0 && l<n/2){
		if(s[l]=='9'){//already 9,skip it
			l++;
		}else{
			if(find(mismatch.begin(),mismatch.end(),l)!=mismatch.end()){//we have already considered one change
				c-=1;
			}else{
				if(c<2) break;//only one change left so break.
				c-=2;
			}
			s[l]='9';
			s[n-l-1]='9';	
			l++;
		}
		
	}
	int g=-1;
	for(auto a:mismatch){//search for mismatch pos which we haven't considered
		if(a>=l){
			g=a;
			break;
		}
	}
	if(c>=1){
		if(g!=-1){//use the last left change
			s[g]='9';
			s[n-g-1]='9';
		}else if(n%2!=0)//incase all mismatch have been considered and only the middle of oddlength palindrome is left
			s[n/2]='9';
	}
	return s;
}
int main(){
	string s;
	int k,n;
	cin>>n>>k>>s;
	cout<<highestValuePalindrome(s,k)<<endl;
	return 0;
}
