#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#define fi first
#define se second
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (ll)(x).size()
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
ll gcd(ll a,ll b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll MX = 1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
  int h,w;
  cin>>h>>w;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  vector<string> s(h);
  rep(i,h) cin>>s[i];
  int ans=0;
    vector<vector<int>> dist(h,vector<int>(w,INF));
    queue<P> q;
    dist[a-1][b-1]=0;
    q.push(P(a-1,b-1));
    while(!q.empty()){
      int i=q.front().first;
      int j=q.front().second; q.pop();
      rep(dir,4){
        int ni=i+di[dir], nj=j+dj[dir];
        if(ni<0||ni>=h||nj<0||nj>=w) continue;
        if(s[ni][nj]=='#') continue;
        if(dist[ni][nj]!=INF) continue;
       dist[ni][nj]=dist[i][j]+1;
       q.push(P(ni,nj));
      }
    }
  cout<<dist[c-1][d-1]<<endl;
}