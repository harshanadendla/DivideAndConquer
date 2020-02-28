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
const int N=1e5+1;
const int mod=1e9+7;

struct point
{
    double x,y;
};

double min(double a,double b) 
{
    return (a<b) ? a : b ;
}

bool how1(point a,point b) 
{
    return a.x<b.x ;
}

bool how2(point a,point b) 
{
    return a.y<b.y ;
}

double dist(point a,point b) 
{
    return sqrt(  (b.y-a.y)*(b.y-a.y)  +  (b.x-a.x)*(b.x-a.x)  );
}

double stripMin(point strip[],int n,double d)
{
    double res=d;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n && strip[j].y-strip[i].y<res;j++)
        {
            for(int k=j+1;k<n && strip[k].y-strip[j].y<res;k++)
            {
                double d=dist(strip[i],strip[j]) + dist(strip[j],strip[k]) + dist(strip[k],strip[i]);
                if(d<res) res=d;
            }
        }
    }
    return res;
}

double prune(point points[],int n)
{
    double res=DBL_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                double d=dist(points[i],points[j]) + dist(points[j],points[k]) + dist(points[k],points[i]);
                if(d<res) res=d;
            }
        }
    }
    return res;
}

double solve(point points[],int n)
{
    if(n<=3) return prune(points,n);

    int mid=n/2;
    point p=points[mid];

    double dl=solve(points,mid);
    double dr=solve(points+mid,n-mid);

    double d=min(dl,dr);

    int j=0;
    point strip[n];
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

    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        point points[n];
        for(int j=0;j<n;j++)
        {
            cin>>points[j].x>>points[j].y;
        }
        sort(points,points+n,how1);
        printf("Case %d: %.10f\n",i,solve(points,n));
    }

    return 0;
}