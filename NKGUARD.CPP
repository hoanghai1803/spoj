#include <bits/stdc++.h>                                      
                                                               
using namespace std;                                           
                                                               
#define TASK "NKGUARD"                                         
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

const int N = 7e2 + 2;

int m, n;
int res = 0;
int h[N][N];
bool Visited[N][N];

queue<ii> Queue;

void Init() {
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
       FOR(j, 1, n) {
          scanf("%d", &h[i][j]);
       }
    SET_ARR(Visited, false);
}

inline bool Valid(int i, int j) {
    return(i && i <= m && j && j <= n);
}

bool Bfs(int a, int b) {
    Queue.push(ii(a, b));
    int i,j;
    bool Chk = false;
    while(Queue.size()) {
        i = Queue.front().ST, j = Queue.front().ND;
        Queue.pop();
        FOR(x, -1, 1)
            FOR(y, -1, 1){
                Chk |= (Valid(i + x,j + y) && h[i + x][j + y] > h[a][b]);
                if(Valid(i + x, j + y) && h[i + x][j + y] == h[a][b] && !Visited[i + x][j + y])
                    Queue.push(ii(i + x, y + j)), Visited[i + x][j + y] = true;
            }
    }
    return !Chk;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    FOR(i, 1, m)
        FOR(j, 1, n)
            if(!Visited[i][j]) res += Bfs(i,j);
    printf("%d", res);
}
