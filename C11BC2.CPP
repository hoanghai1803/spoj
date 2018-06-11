#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "C11BC2"
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
 
const int N = 1e4+4;
 
int n, m;
int Id[N];
int cnt = 0;
 
vector<int> ad[N];
 
void Init() {
	scanf("%d%d", &n, &m);
	int v, id;
	FORU(u, 2, n) {
		scanf("%d%d", &v, &id);
		if(id == 1) {
			ad[u].push_back(v);
			ad[v].push_back(u);
		}
	}
}
 
void DFS(int u) {
	Id[u] = cnt;
	itr(int) it;
	IT(it, ad[u]) 
		if(!Id[*it]) DFS(*it);
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen(input_file,"r",stdin);
		freopen(output_file,"w",stdout);
	#endif
	Init();
	FORU(u, 1, n)
		if(!Id[u]) {
			cnt++;
			DFS(u);
		}
	int u, v;
	while(m--) {
		scanf("%d%d", &u, &v);
		if(Id[u] != Id[v]) printf("YES\n"); else printf("NO\n");
	}
}