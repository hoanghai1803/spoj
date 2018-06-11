#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                    
#define TASK "MAXARR1"                                         
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
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)                
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)               
#define FORS(i,a,b,d) for (int i=(a); i!=(b); i+=(d))          
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

const int N = 1e5 + 5;

int n, T;
ll A[N], MAX[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    A[0] = 0, A[1] = 1;
    MAX[1] = 1;
    FOR(i, 2, N - 1) {
        if(i & 1) A[i] = A[i / 2] + A[i / 2 + 1]; else A[i] = A[i / 2];
        MAX[i] = max(MAX[i - 1], A[i]);
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        printf("%lld\n", MAX[n]);
    }
}
