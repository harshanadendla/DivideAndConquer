//blind ga dont follow what is given in qstn...understand what is happening
//idi telusu...but still din't do \__/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

template<size_t>
struct debug{};

template <class T>
ostream& print_tuple(ostream& out, const T& t, debug<1> ) {
    return out << get<tuple_size<T>::value-1>(t);
}

template <class T, size_t idx>
ostream& print_tuple(ostream& out, const T& t, debug<idx> ) {
    out << get< tuple_size<T>::value-idx >(t) << " , ";
    return print_tuple(out, t, debug<idx-1>());
}

template <class... Args>
ostream& operator<<(ostream& out, const tuple<Args...>& t) {
    out << "\n[";
    print_tuple(out, t, debug<sizeof...(Args)>());
    return out << "]\n";
}

template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define dbg(x) cerr<<x<<"\n"
#define bug(x) cout<<"hi"<<x<<endl

const int N=1e5+5;
const int mod=1e9+7;

int Madd(int a,int b) {
    return ((a%mod)+(b%mod)+mod)%mod;
}

int Mmull(int a,int b) {
    return ((a%mod)*(b%mod)+mod)%mod;
}

//#define test_cases

string go(string s1) {
	int n=s1.size();
	if (n%2) {
		return s1;
	}
	string l=go(s1.substr(0,n/2));
	string r=go(s1.substr(n/2));
	if (r<l) {
		swap(l,r);
	}
	return l+r;
}

void solve() {
	string s1,s2;
	cin>>s1>>s2;
	if(s1==s2) {
		cout<<"YES"<<endl;
	} else {
		go(s1)==go(s2) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif

    int t=1;
#ifdef test_cases
    cin>>t;
#endif

    while(t--) {
        solve();
    }

    return 0;
}