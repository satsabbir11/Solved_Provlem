const int mxN = 1e+5,K = 20;
int sa[mxN], pos[mxN], tmp[mxN],st[mxN][K+1],lcp[mxN],pre[mxN], gap, N;

bool comp(int x, int y) {
if(pos[x] != pos[y])return pos[x] < pos[y];
x += gap;
y += gap;
return (x < N && y < N) ? pos[x] < pos[y] : x > y; }

void suffix(string &s) {
for (int i = 0; i < N; i++) sa[i] = i, pos[i] = s[i];
for (gap = 1;; gap <<= 1) {
sort(sa, sa+N, comp);
for (int i = 0; i < N-1; i++)
tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
for (int i = 0; i < N; i++)
pos[sa[i]] = tmp[i];
if (tmp[N - 1] == N - 1) break; } }

int check(int m, string &s, string &x) {
int f = -1, k = x.size(), j = sa[m];
if (N - j >= k)f = 0;
for (int i = 0; i < min(N - j, k); i++) {
if (s[j+i] < x[i]) return -1;
if (s[j+i] > x[i]) return 1; }
return f; }

int patternExistsLB(int l,int r, string &s, string &x) {
int ans=-1;
while (l <= r) {
int m = l + (r-l)/2;
int v = check(m, s, x);
if (v == 0){
ans = m; r = m - 1; }
else if (v == 1) r = m - 1;
else l = m + 1; }
return ans; }
int patternExistsRB(int l,int r, string &s, string &x) {
int ans=-1;
while (l <= r) {
int m = l + (r-l)/2;
int v = check(m,s, x);
if (v == 0) {
ans = m; l = m + 1;}
else if (v == -1) l = m + 1;
else r = m - 1; }
return ans; }

int patternCount(int l,int r, string s,string &x) {
int L=patternExistsLB(l,r,s,x);
if(L==-1)return 0;
int R=patternExistsRB(L,r,s,x);
return (R-L)+1; }

int query(int l, int r) {
int j = log2(r-l+1);
return min(st[l][j], st[r-(1<<j)+1][j]) + 1; }

void buildIdx() {
for (int i = 0; i < N; i++)
st[i][0] = sa[i];

for (int j = 1; j <= K; j++) {
for (int i = 0; i + (1<<j) <= N; i++) {
st[i][j] = min(st[i][j-1], st[i + (1<<j-1)][j-1]); } } }

int findFirstIdx(int l,int r, string s,string &x) {
int L=patternExistsLB(l,r,s,x);
if(L==-1)return -1;
int R=patternExistsRB(L,r,s,x);
return query(L,R); }

void build_lcp(string &s){
for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
int j = sa[pos[i] + 1];
while (s[i + k] == s[j + k]) k++;
lcp[pos[i]] = k;
if (k) k--; } }

long long int getUniqueSubCnt() {
long long int sm = accumulate(lcp, lcp+N, 0LL);
long long int tot = ((long long)1*(N)*(N+1))/2;
tot-=sm;
return tot; }

void printEveryUnqiueSubStirngCnt() {
int prev = 0;
for (int i = 0; i < N; i++) {
pre[prev + 1]++;
pre[N - sa[i] + 1]--;
prev = lcp[i]; }
for (int i = 1; i <= N; i++) {
cout << pre[i] << ' ' ;
pre[i+1] += pre[i];} }

string kthDistinctSubstring(string s,long long k){
long long prev = 0;
long long cur = 0;
for (int i = 0; i < N; i++){
if (cur + (N-sa[i]) - prev >= k) {
long long j = prev;
string ans = s.substr(sa[i], j);
while (cur < k){
ans += s[sa[i]+j];
cur++; j++; }
return ans; }
cur += (N-sa[i]) - prev;
prev = lcp[i]; }
return ""; }