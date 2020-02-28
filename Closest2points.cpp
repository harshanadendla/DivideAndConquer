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

struct point
{
    int x,y;
};

bool how1(point a,point b)
{
    return a.x<b.x;
}

bool how2(point a,point b)
{
    return a.y<b.y;
}

double dist(point a,point b)
{
    return sqrt( ((b.y-a.y)*(b.y-a.y)) + ((b.x-a.x)*(b.x-a.x)) );
}

double bruteForce(point points[],int n)
{
    double ans=DBL_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double d=dist(points[i],points[j]);
            if(d<ans) ans=d;
        }
    }
    return ans;
}

double stripMin(point strip[],int n,double d)
{
    double ans=d;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n && strip[j].y-strip[i].y<ans;j++)
        {
            double q=dist(strip[i],strip[j]);
            if(q<ans) ans=q;
        }
    }
    return ans;
}

double solve(point points[],int n)
{
    if(n<=3) return bruteForce(points,n);

    int mid=n/2;
    point p=points[mid];

    double dl=solve(points,mid);
    double dr=solve(points+mid,n-mid);

    double d=min(dl,dr);

    point strip[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(abs(points[i].x-p.x)<d) strip[j++]=points[i];
    }

    sort(strip,strip+j,how2);
    return min(d,stripMin(strip,j,d));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //o0badboy0o
    
    int n,a,b;
    cin>>n;
    point points[n];

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        points[i].x=a;
        points[i].y=b;
    }

    sort(points,points+n,how1);
    printf("%.10lf\n",solve(points,n));

    return 0;
}