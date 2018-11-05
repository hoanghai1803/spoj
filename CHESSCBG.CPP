#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "CHESSCBG"
#define input_file TASK".INP"
#define output_file TASK".OUT"
 
#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();++i)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();++i)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define FORU(i,a,b) for (int i=(a); i<=(b); i++)
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

const int N = 1 << 18;

int Begin_Stt, End_Stt;
int F[N];
bool Free[N];

inline int Id(int u, int v) {
    return (u - 1) * 4 + v;
}

inline bool Valid(int u, int v) {
    return (u && u <= 4 && v && v  <= 4);
}

inline bool Get_Bit(int n, int i) {
    return (n >> (i - 1)) & 1;
}

inline void Turn_Off(int& n, int i) {
    n = n & ~(1 << (i - 1));
}

inline void Turn_On(int& n, int i) {
    n = n | (1 << (i - 1)); 
}

void Init() {
    char a[5], b[5];
    FORU(u, 1, 4) {
        scanf("%s", a + 1);
        FORU(v, 1, 4) Begin_Stt = ((a[v] - '0') << (Id(u, v) - 1)) + Begin_Stt;
    }
    FORU(u, 1, 4) {
        scanf("%s", b + 1);
        FORU(v, 1, 4) End_Stt = ((b[v] - '0') << (Id(u, v) - 1)) + End_Stt;
    }
    F[Begin_Stt] = 0;
    SET_ARR(Free, true);
}

void Bfs() {
    queue<int> Q;
    Q.push(Begin_Stt), Free[Begin_Stt] = false;
    while(Q.size()) {
        int Stt = Q.front(), F_Cur = F[Stt];
        Q.pop();
        FORU(u, 1, 4)
        FORU(v, 1, 4) if(Get_Bit(Stt, Id(u, v))) {
            Turn_Off(Stt, Id(u, v));
            FORU(t, 0, 3) {
                int x = u + dx[t], y = v + dy[t];
                if(!Valid(x, y)) continue;
                if(Get_Bit(Stt, Id(x, y))) continue;
                Turn_On(Stt, Id(x, y));
                if(!Free[Stt]) {
                    Turn_Off(Stt, Id(x, y));
                    continue;
                }
                F[Stt] = F_Cur + 1, Free[Stt] = false;
                if(Stt == End_Stt) {
                    printf("%d", F[Stt]);
                    return;
                }
                int cnt = 0;
                Q.push(Stt);
                Turn_Off(Stt, Id(x, y));
            }
            Turn_On(Stt, Id(u, v));
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
}