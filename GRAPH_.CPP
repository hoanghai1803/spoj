#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "GRAPH_"                                         
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

int n, m;
int cnt = 0;
int dfn[N], Low[N];
int Count[N];
int CV = 0, Bridge = 0;

vector<int> ad[N];

void Init() {
    scanf("%d%d", &n, &m);
    int u, v;
    FOR(i, 1, m) {
        scanf("%d%d", &u, &v);
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}

void DFS(int u, int Par) {
    dfn[u] = Low[u] = ++cnt;
    itr(int) it;
    int v;
    IT(it, ad[u]) {
        if((v = *it) == Par) continue;
        if(dfn[v]) {
            Low[u] = min(Low[u], dfn[v]);
            continue;
        }
        DFS(v, u);
        Low[u] = min(Low[u], Low[v]);
        Count[u] += (Low[v] >= dfn[u]);
    }   
    CV += Par ? (Count[u] >= 1) : (Count[u] >= 2);
    Bridge += (Low[u] == dfn[u] && Par);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    FOR(u, 1, n) 
        if (!dfn[u]) DFS(u, 0);
    printf("%d %d", CV, Bridge);
}
