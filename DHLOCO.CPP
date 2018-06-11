#include <bits/stdc++.h>

using namespace std;

#define TASK "DHLOCO"
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

ll n;
int M;

struct Matrix {
    int item[3][3];
    Matrix operator * (Matrix);
} Base, First;

Matrix Matrix::operator * (Matrix a) {
    Matrix ret;
    FOR(i, 0, 2)
        FOR(j, 0, 2) {
            ret.item[i][j] = 0;
            FOR(k, 0, 2) ret.item[i][j] += item[i][k] * a.item[k][j], ret.item[i][j] %= M;
        }
    return ret;
}

void Init() {
    scanf("%lld", &n);
    scanf("%d", &M);
    Base = {0,0,1,
            1,0,1,
            0,1,1};
    First = {1,2,4};
}

inline Matrix Pow(ll n) {
    if(n == 1) return Base;
    Matrix tmp = Pow(n / 2);
    if(n & 1) return tmp * tmp * Base;
    return tmp * tmp;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    if(n == 1) printf("1");
    if(n == 2) printf("2");
    if(n == 3) printf("4");
    if(n > 3) printf("%d", (First * Pow(n - 3)).item[0][2]);
}