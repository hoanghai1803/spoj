#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "LQDDIV"
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
typedef pair<ll,ll> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;
 
const ll oo = LLONG_MAX;
const int N = 35;
const int M = 7e4;

int n;
int a[N];
bool stt[N];
int m = 0;
ll F[M];
ii x[M], y[M];
int h = 0, k = 0;
 
void Try(int i, int s, int f) {
	if(i > f) {
		m++;
		FORU(i, s, f) 
			if(stt[i]) F[m] += a[i];
			else F[m] -= a[i];
		return; 
	}
	FORU(j, 0, 1) {
		stt[i] = j;
		Try(i + 1, s, f);
	}
}

void Init() {
	scanf("%d", &n);
	FORU(i, 1, n) scanf("%d", &a[i]);
	m = 0;
	Try(1, 1, n / 2);
	sort(F + 1, F + m + 1);
	FORU(i, 1, m)
		if(F[i] != F[i-1]) x[++h].X = F[i], x[h].Y = 1;
		else x[h].Y++;
	m = 0;
	SET_ARR(F, 0);
	Try(n / 2 + 1, n / 2 + 1, n);
	FORU(i, 1, m) F[i] *= -1;
	sort(F + 1, F + m + 1);
	FORU(i, 1, m)
		if(F[i] != F[i - 1]) y[++k].X = F[i], y[k].Y = 1;
		else y[k].Y++;
}

void Solve() {
	ll res = +oo;
	ll cnt = 0;
	ll d1, d2, d, tmp;
	int i = 1, j = 1;
	for(; i <= h && j <= k; i++) {
		for(; j <= k; j++) if(y[j].X > x[i].X) break;
		d1 = abs(y[j-1].X - x[i].X), d2 = abs(y[j].X - x[i].X);
		d = min(d1, d2);
		if(j > k) {
			if(d1 == res) cnt += x[i].Y * y[j - 1].Y;
			if(d1 < res) res = d1, cnt = x[i].Y * y[j - 1].Y;
			break;
		}
		if(d1 < d2) tmp = x[i].Y * y[j - 1].Y;
		if(d1 == d2) tmp = 2*x[i].Y * y[j - 1].Y;
		if(d1 > d2) tmp = x[i].Y * y[j].Y;
		if(d > res) continue;
		if(res == d) {
			cnt += tmp;
			continue;
		}
		res = min3(res, d1, d2);
		cnt = tmp;
	}
	printf("%lld %lld", res, cnt / 2);
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen(input_file,"r",stdin);
		freopen(output_file,"w",stdout);
	#endif
	Init();
	Solve();
}