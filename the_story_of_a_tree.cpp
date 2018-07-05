//Practice->algorithm->Graph Theory-> The Story of Tree

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using pi=pair<int,int>;
using vpi=vector<pi>;
int k;
static int cnt=0;
static int c=0;
void dfs(vvi &adj,int src,vector<bool>&visited,int parent[]){
	visited[src]=true;
	for(auto it:adj[src]){
		if(!visited[it])
		{
			dfs(adj,it,visited,parent);
			parent[it]=src;
		}

	}

}
void guessed(int parent[],multimap<int,int>&guess){
	for(auto it:guess){
		if(parent[it.first]==it.second) c++;
	}
	cout<<"c: "<<c<<endl;
	if(c>=k) cnt++;
}
void calculate(int parent[],int src,vvi &adj,vector<bool>&visited,multimap<int,int>&guess){

	visited[src]=true;
	for(int it:adj[src])
	{	int temp,l=0;
		if(!visited[it]){
			bool a=false,b=false;
			temp=parent[it];
			parent[it]=it;
			auto its = guess.equal_range(it);
			for (auto itt = its.first; itt != its.second; ++itt) {
    			if(itt->second==temp)
    				a=true;
    			if(itt->second==it)
    				b=true;
			}
			if(a && !b)
				l--;
			else if(!a && b)
				l++;
			parent[temp]=it;
			its = guess.equal_range(temp);
			a=false;b=false;
			for (auto itt = its.first; itt != its.second; ++itt) {
    			if(itt->second==temp)
    				a=true;
    			if(itt->second==it)
    				b=true;
			}
			if(a && !b)
				l--;
			if(!a && b)
				l++;
			c+=l;
			cout<<"c: "<<c<<endl;
			if(c>=k)
				cnt++;
			calculate(parent,it,adj,visited,guess);
			parent[it]=temp;
			parent[temp]=temp;
			c-=l;
		}

	}


}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;//numbers of nodes
        cin>>n;
        vvi adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);

        }
        int g;
        cin>>g>>k;
        cout<<"k: "<<k<<endl;
        multimap<int,int> guess;
        for(int i=0;i<g;i++){
            int u,v;
            cin>>u>>v;
            guess.insert({v-1,u-1});
        }


        int parent[n];
        for(int i=0;i<n;i++)
            parent[i]=i;
        dfs(adj,0,visited,parent);
        guessed(parent,guess);

        vector<bool>visit(n,false);

        calculate(parent,0,adj,visit,guess);
        int gcd=__gcd(cnt,n);
        cout<<"cnt: "<<cnt<<endl;
        cout<<cnt/gcd<<"/"<<n/gcd<<"\n";
		c=0;
		cnt=0;
    }
	return 0;
}
