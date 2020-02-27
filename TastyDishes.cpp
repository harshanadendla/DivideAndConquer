#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
const int mod=1e9+7;
const int N=2e5+1;

int n,k;
int a[N];

int solve(int l,int r)
{
    if(l>=r) return 0;

    int mid=(l+r)/2;
    int sum=0,ans=0,idx=-1;
    int minV=LLONG_MAX;
    unordered_map<int,int> jodi;

    for(int i=l;i<=r;i++)
    {
        if(a[i]<minV)
        {
            minV=a[i];
            idx=i;
        }
        else if(a[i]==minV && abs(i-mid)<abs(idx-mid))
        {
            idx=i;
        }
    }

    for(int i=idx-1;i>=l;i--)
    {
        sum+=a[i];
        jodi[sum%k]++;
    }

    sum=0;
    ans+=jodi[0];
    for(int i=idx+1;i<=r;i++)
    {
        sum+=a[i];
        if(sum%k==0) ans++;
        ans+=jodi[(k-sum%k)%k];
    }

    return ans+solve(l,idx-1)+solve(idx+1,r);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //o0badboy0o

    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    cout<<solve(1,n);

    return 0;
}