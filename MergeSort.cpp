#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
const int N=1e5;
const int mod=1e9+7;

vi merge(vi l,vi r)
{
    vi res;
    int i=0,j=0,m=l.size(),n=r.size();
    while(i<m && j<n)
    {
        if(l[i]<r[j])
        {
            res.pb(l[i++]);
        }
        else
        {
            res.pb(r[j++]);
        }
    }
    while(i<m)
    {
        res.pb(l[i++]);
    }
    while(j<n)
    {
        res.pb(r[j++]);
    }
    return res;
}

vi mergeSort(vi array,int l,int r)
{
    if(l>r) return vi{};
    if(l==r) return vi{array[l]};
    int mid=l+(r-l)/2;
    vi left=mergeSort(array,l,mid);
    vi ryt=mergeSort(array,mid+1,r);
    return merge(left,ryt);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    //o0badboy0o
    
    int n;
    cin>>n;
    
    vi array(n);
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }

    array=mergeSort(array,0,n-1);

    for(int i : array) cout<<i<<" ";

    return 0;
}