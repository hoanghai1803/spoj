#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "NDCCARD"                                         
#define input_file TASK".INP"                                  
#define output_file TASK".OUT"                                 
                                                            
#define ST first                                               
#define ND second                                            
#define itr(t) vector<t>::iterator                             
#define ritr(t) vector<t>::reverse_iterator                  
#define IT(i,v) for (i=v.begin();i!=v.end();i++)               
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)            
#define MAX_HEAP(t) priority_queue<t>                         
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >    
#define FOR(i,a,b) for (long long i=(a); i<=(b); i++)       
#define FORD(i,a,b) for (long long i=(a); i>=(b); i--)         
#define abs(x) ((x)>=0?(x):-(x))                               
#define sqr(x) (x)*(x)                                         
#define max3(a,b,c) max((a),max((b),(c)))                      
#define min3(a,b,c) min((a),min((b),(c)))                      
#define SET_ARR(a,v) memset(a,v,sizeof(a))                     
#define ALL(x) (x).begin(),(x).end()                          
                                                               
typedef long long ll;                                          
typedef unsigned long long ull;                                
typedef pair<int,int> ii;                                      
typedef pair<int,ii> iii;                                      
typedef pair<double,double> dd;                                
typedef pair<double,dd> ddd;                                   
                                                              

const int oo = INT_MAX;
const int N = 1e4 + 4;

int n, m;
int res = -oo;
int a[N];

int Inspect(int L, int R, int S) {
    int ret = -oo;
    for (; L < R; L++){
        while( L < R - 1 && S < a[L] + a[R] ) R--;
        if (a[L] + a[R] <= S) ret = max(ret, a[L] + a[R]);
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    FOR(i, 1, n - 2) res = max(res, a[i] + Inspect(i + 1, n, m - a[i]));
    printf("%d", res);
}
