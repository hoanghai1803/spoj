#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "KMIN"                                            
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

const int N = 5e4 + 4;

int n, m, k;
ll a[N], b[N];
ll sum;
ll res[N];

MAX_HEAP(ll) Heap;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d%d", &m, &n, &k);
    FOR(i, 1, m) scanf("%lld", &a[i]);
    FOR(j, 1, n) scanf("%lld", &b[j]);
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
    FOR(i, 1, m)
        FOR(j, 1, n) {
            sum = a[i] + b[j];
            if(Heap.size() >= k && sum > Heap.top()) break;
            if((Heap.size() >= k) && (Heap.top() > sum)) Heap.pop(), Heap.push(sum);
            if(Heap.size() < k) Heap.push(sum);
        }
    int i = 0;
    while(Heap.size()) res[++i] = Heap.top(), Heap.pop();
    FORD(i, k, 1) printf("%lld\n", res[i]);
}
