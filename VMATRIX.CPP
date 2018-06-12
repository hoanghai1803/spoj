#include <bits/stdc++.h>

using namespace std;

#define TASK "VMATRIX"
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

const int N = 1e3 + 3;

int T, n;

struct Matrix {
    int item[N][N];
    Matrix operator * (Matrix);
    bool operator == (Matrix);
} A, B, C, Base;

Matrix Matrix::operator * (Matrix a) {
    Matrix tmp;
    FOR(i, 1, n) {
        tmp.item[1][i] = 0;
        FOR(k, 1, n)
            tmp.item[1][i] += item[1][k] * a.item[k][i], tmp.item[1][i] %= 10;
    }
    return tmp;
}

bool Matrix::operator == (Matrix a) {
    FOR(i, 1, n)
        if(item[1][i] != a.item[1][i]) return false;
    return true;
}

inline void Init() {
    scanf("%d", &n);
    char s[N];
    FOR(i, 1, n) {
        scanf("%s", s + 1);
        FOR(j, 1, n) A.item[i][j] = s[j] - '0';
    }
    FOR(i, 1, n) {
        scanf("%s", s + 1);
        FOR(j, 1, n) B.item[i][j] = s[j] - '0';
    }
    FOR(i, 1, n) {
        scanf("%s", s + 1);
        FOR(j, 1, n) C.item[i][j] = s[j] - '0';
    }
    FOR(i, 1, n) Base.item[1][i] = 1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d", &T);
    while(T--) {
        Init();
        if((Base*A)*B == (Base*C)) printf("YES\n"); else printf("NO\n");
    }
}
