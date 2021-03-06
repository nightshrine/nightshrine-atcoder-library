#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define pf push_front
#define sz(x) (ll)(x).size()
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<P> vp;
ll gcd(ll a,ll b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const int INF=1e9;
const ll MX = 1e18;
const ll mod=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);
const string tr="abcdefghijklmnopqrstuvwxyz";
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define YN {puts("YES");}else{puts("NO");}
ll llpow(ll n,ll i){if(i==0){return 1;}ll cnt=n;for(ll j=0;j<i-1;j++){n*=cnt;}return n;}
bool ip/*is_prime*/(long long N) {if (N == 1) return false;for (long long i = 2; i * i <= N; ++i) {if (N % i == 0) return false;}return true;}
int digit(ll N) {int ans = 0;while (N) {++ans;N /= 10;}return ans;}
vector<pair<ll,ll>> pf/*prime_factorize*/(ll n){vector<pair<ll,ll>> res;for(ll a=2;a*a<=n;a++){if(n%a!=0) continue;ll ex=0;while(n%a==0){ex++;n/=a;}res.pb({a,ex});}if(n!=1) res.pb({n,1});return res;}
vector<ll> div/*divisor*/(ll n){  vector<ll> res={1};for(ll a=2;a*a<=n;a++){if(n%a!=0) continue;ll b=n/a;res.pb(b);if(b!=a) res.pb(a);}sort(all(res));return res;}
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
struct UnionFind {
    vector<int> d;
    UnionFind(int n): d(n,-1) {}
    int root(int x) {
        if (d[x] < 0) return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y);}
    int size(int x) { return -d[root(x)];}
};
mint f2(ll n) {if (n == 0) return 1;mint x = f2(n/2);x *= x;if (n%2 == 1) x *= 2;return x;}
mint choose(int n,int a){mint x=1,y=1;rep(i,a){x*=n-i;y*=i+1;}return x/y;}
ll xs/*xorsum nまでのxorの和*/(ll n){ll cnt=(n+1)/2;ll ans=cnt%2;if(n%2==0) ans^=n;return ans;}
ll Fa/*Factorial nの階乗*/(ll n){ll ans=1;rrep(i,n){ans*=i;}return ans;}

int main() {
    int n;cin>>n;
    double ans=0.0;
    for(int i=n-1;i>=1;i--){
        ans+=double(n)/double(i);
    }
    printf("%.10f\n",ans);
    return 0;
}