// •︿• \\
/\\    //\
  /\\//\
  
#include <bits/stdc++.h>
using namespace std;
 
const double PI = acos(-1);
const int N=2e5 + 10;
// const int MOD= 998244353 ;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define read(v) for (auto& it : v) scanf("%d", &it);
#define readL(v) for (auto& it : v) scanf("%lld", &it);
#define print(v) for (auto it : v) printf("%d ", it); puts("");
#define printL(v) for (auto it : v) printf("%lld ", it); puts("");
#define oo 1000000007
const int MOD = 1e9 + 7;


// Fenwick Tree
// 0-based indexing
template <typename T>
class Fenwick{
        vector<T> bit;
        int n;
    public:
        Fenwick(int n){
            this->n = n;
            bit.clear();
            bit.resize(n);
        }
        void update(int idx, T val){
            for(; idx < n; idx |= idx + 1){
                bit[idx] += val;
            }
        }
        T query(int idx){
            T res = 0;
            for(; idx >= 0; idx = (idx & (idx + 1)) - 1){
                res += bit[idx];
            }
            return res;
        }
        T query(int l, int r){
            return query(r) - query(l-1);
        }
};


void solve(){
    int n,t,d;
    cin>>n>>t>>d;
    Fenwick<int> f(n);
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        f.update(i,s);
    }
    vector<ii> queries;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        queries.pb({a,b});
    }
    for(int i=0; i<d; i++){
        cout<<"Day "<<i+1<<": ";
        int x; cin>>x;
        for(int j=0;j<x;j++){
            int k; cin>>k; k--;
            f.update(k,1);
        }
        for(auto q: queries){
            cout<<f.query(q.f,q.s)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t=1;
    // scanf("%d",&t);
    
    int tt = t;
    while(t--){
        // printf("case #%d: ",tt-t );
        solve();
    }

    return 0;
}