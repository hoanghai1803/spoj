#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "VMUNCH"                                          
#define input_file TASK".INP"                                  
#define output_file TASK".OUT"                                 
                                                               
#define X first                                               
#define Y second                                              
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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int N = 1e2 + 2;

int R, C;
char s[N][N];
int Byre_x, Byre_y;
int Bess_x, Bess_y;
bool Visited[N][N];
int F[N][N];

queue<ii> Queue;

void Init() {
    scanf("%d%d", &R, &C);
    FOR(i, 1, R) {
        scanf("%s", s[i]+1);
        FOR(j, 1, C) {
            if(s[i][j] == 'B') Byre_x = i, Byre_y = j;
            if(s[i][j] == 'C') Bess_x = i, Bess_y = j;
        }
    }
    SET_ARR(Visited, false);
}

inline bool Valid(int x, int y) {
    return (x >= 1 && x <= R && y >= 1 && y <= C);
}

void Bfs() {
    Queue.push(ii(Bess_x, Bess_y));
    int i, j;
    while(Queue.size()) {
        i = Queue.front().X, j = Queue.front().Y;
        Queue.pop();
        FOR(t, 0, 3) {;
            int x = i + dx[t];
            int y = j + dy[t];
            if(Valid(x, y) && s[x][y] != '*' && !Visited[x][y]) {
                Visited[x][y] = true;
                F[x][y] = F[i][j] + 1;
                Queue.push(ii(x, y));
            }
        }
    }

}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    Bfs();
    printf("%d", F[Byre_x][Byre_y]);
}
