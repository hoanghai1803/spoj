#include <bits/stdc++.h>

using namespace std;

#define TASK "COWGIRL"
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
#define FORU(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FOR(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
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

const int N = 35;
const int M = 1 << 5;

int T, m, n;
int F[N][M];

inline bool Get_bit(int n, int i) {
	return (n >> (i - 1)) & 1;
}

inline bool Check(int Stt1, int Stt2) {
	int Stt = Stt1 & Stt2;
	FORU(i, 1, m - 1)
		if(Get_bit(Stt, i) && Get_bit(Stt, i + 1)) return false;
	Stt = Stt1 | Stt2;
	FORU(i, 1, m - 1)
		if(!Get_bit(Stt, i) && !Get_bit(Stt, i + 1)) return false;
	return true;
}

void DP() {
	int LastStt = (1 << m) - 1;
	FORU(Stt, 0, LastStt) F[1][Stt] = 1;
	FORU(i, 2, n)
		FORU(Stt, 0, LastStt) {
			F[i][Stt] = 0;
			FORU(PreStt, 0, LastStt) {
				if(!Check(PreStt, Stt)) continue;
				F[i][Stt] += F[i - 1][PreStt];
			}
		}
	int res = 0;
	FORU(Stt, 0, LastStt) res += F[n][Stt];
	printf("%d\n", res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &T);
    while(T--) {
    	scanf("%d%d", &m, &n);
    	if(m > n) swap(m, n);
    	DP();
    }
}
