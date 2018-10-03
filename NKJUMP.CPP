#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKJUMP"
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
 
const int N = 1e3 + 3;

int n;
bool Connect[N][N];
int F[N];

struct Circle {
	int val;
	int deg_in = 0;
	vector<int> adj;
} cir[N];

bool operator < (Circle a, Circle b) {
	return (a.val < b.val);
}

int Find(int L, int R, int val) {
	if(L > R) return n + 1;
	if(L == R) {
		if(cir[L].val == val) return L;
		return n + 1;
	}
	if(L + 1 == R) {
		if(cir[L].val == val) return L;
		if(cir[R].val == val) return R;
		return n + 1;	
	}
	int M = (L + R) >> 1;
	if(cir[M].val > val) return Find(L, M, val);
	return Find(M, R, val);
}

void Init() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &cir[i].val);
	sort(cir + 1, cir + n + 1);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			int k = Find(j + 1, n, cir[i].val + cir[j].val);
			while(cir[k].val == cir[i].val + cir[j].val) {
				if(!Connect[i][k]) {
					cir[i].adj.push_back(k);
					cir[k].deg_in++;
					Connect[i][k] = 1;
				}
				if(!Connect[j][k]) {
					cir[j].adj.push_back(k);
					cir[k].deg_in++;
					Connect[j][k] = 1;
				}
				k++;
			}
		}
}

void DP() {
	int i, j;
	queue<int> Queue;
	for(int i = 1; i <= n; i++)
		if(!cir[i].deg_in) Queue.push(i), F[i] = 1;
	while(Queue.size()) {
		i = Queue.front(), Queue.pop();
		itr(int) it;
		IT(it, cir[i].adj) {
			F[j = *it] = max(F[j], F[i] + 1);
			--cir[j].deg_in;
			if(!cir[j].deg_in) Queue.push(j);
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res = max(res, F[i]);
	printf("%d", res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    // for(int i = 1; i <= n; i++) cout << cir[i].deg_in << "\n";
    // return 0;
    DP();
}