//Author - Soumik Roy
//Date & Time - May 17, 2021 9:25 AM
//Problem name - C - New Year and Buggy Bot
//Problem url - https://vjudge.net/contest/439238#problem/C
//Time limit - 1000 ms
//Memory Limit - 262 MB    
//Parsed with ai-virtual-assistant https://github.com/Saurav-Paul/AI-virtual-assistant-python
 
#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   1000000007
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define eb                    emplace_back
#define ull                   unsigned long long
#define bug(x)				  cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
pii dir[4]={mp(0,1),mp(0,-1),mp(1,0),mp(-1,0)};
char maze[51][51];
void solve()
{
	int n,m;
	cin>>n>>m;
	pii st,sp;
	string cmd;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
			if(maze[i][j]=='S')
				st=mp(i,j);
			if(maze[i][j]=='E')
				sp=mp(i,j);
		}
	}
	cin>>cmd;
	int ans=0;
	int perm[4]={0,1,2,3};
	do
	{
		pii pos=st;
		for(auto x:cmd)
		{
			pos.F+=dir[perm[x-'0']].F,pos.S+=dir[perm[x-'0']].S;
			if(pos.F>n-1 || pos.F<0 || pos.S>m-1 || pos.S<0)
				break;
			if(maze[pos.F][pos.S]=='#')
				break;
			if(pos==sp)
			{
				ans++;
				break;
			}
		}
		// cout<<pos.F<<" "<<pos.S<<" "<<sp.F<<" "<<sp.S<<endl;
	}while (next_permutation(perm,perm+4));
	cout<<ans<<endl;
}
int main()
{
    #ifndef sabbir
    freopen("/CP_OJ/input.txt", "r", stdin);
    freopen("/CP_OJ/output.txt", "w", stdout);
    #endif

    KAMEHAMEHA
	int t=1;
	// cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		solve();
	}
    return 0;
}
 