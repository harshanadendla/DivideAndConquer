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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    //o0badboy0o

    int T,l,r,i,ans=0;
    cin>>T;

    while(T--)
    {
        ans=0;
        cin>>l>>r>>i;
        if(i<l)
        {
            cout<<"-1\n";
            continue;
        }

        while(l<=r)
        {
            ans++;
            cout<<l<<" "<<r<<"\n";

            if(l==r && r==i) break;

            int mid=(l+r)/2;

            if(i<=mid)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}