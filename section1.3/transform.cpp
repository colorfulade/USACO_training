/*
ID: colorfu3
TASK: transform
LANG: C++
*/

#include <cstdio>
#include <vector>
using namespace std;

typedef vector< vector<char> > vvc;

int N;
vvc s, c;

bool safe(int a, int b) { return (0<=a&&a<N)&&(0<=b&&b<N); }

vvc cw(vvc k)
{
  int t1 = 1, x1 = 0, y1 = 0, a[20][20] = {};
  while(t1<=N*N){
    for(; !a[x1][y1]&&(y1<N); y1++) a[x1][y1] = t1++; y1--; x1++;
    for(; !a[x1][y1]&&(x1<N); x1++) a[x1][y1] = t1++; x1--; y1--;
    for(; !a[x1][y1]&&(y1>=0); y1--) a[x1][y1] = t1++; y1++; x1--;
    for(; !a[x1][y1]&&(x1>=0); x1--) a[x1][y1] = t1++; x1++; y1++;
  }

  int t2 = 1, x2 = 0, y2 = N-1, b[20][20] = {};
  while(t2<=N*N){
    for(; !b[x2][y2]&&(x2<N); x2++) b[x2][y2] = t2++; x2--; y2--;
    for(; !b[x2][y2]&&(y2>=0); y2--) b[x2][y2] = t2++; y2++; x2--;
    for(; !b[x2][y2]&&(x2>=0); x2--) b[x2][y2] = t2++; x2++; y2++;
    for(; !b[x2][y2]&&(y2<N); y2++) b[x2][y2] = t2++; y2--; x2++;
  }

  vvc ret(N+1, vector<char>(N+1));
  for(int i=0; i<N; i++)
    for(int j=0; j<10; j++)
      for(int ii=0; ii<N; ii++)
        for(int jj=0; jj<N; jj++)
          if(a[i][j]==b[ii][jj])
            ret[ii][jj] = k[i][j];
  return ret;
}

vvc reflect(vvc k)
{
  vvc ret(N+1, vector<char>(N+1));
  for(int i=0; i<N; i++)
    for(int j=0, r=N-1; j<N, r>=0; j++, r--)
      ret[i][j] = k[i][r];
  return ret;
}

bool cmp(vvc a, vvc b)
{
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      if(a[i][j]!=b[i][j]) return 0;
  return 1;
}

int main()
{
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);

  //scan
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    vector<char> tmp;
    for(int j=0; j<N; j++){
      char t; scanf(" %c", &t);
      tmp.push_back(t);
    }
    s.push_back(tmp);
  }
  for(int i=0; i<N; i++){
    vector<char> tmp;
    for(int j=0; j<N; j++){
      char t; scanf(" %c", &t);
      tmp.push_back(t);
    }
    c.push_back(tmp);
  }

  //
  vvc k = cw(s), r = cw(cw(s)), m = cw(cw(cw(s)));
  if(cmp(k, c)) { printf("1\n"); return 0; }
  if(cmp(r, c)) { printf("2\n"); return 0; }
  if(cmp(m, c)) { printf("3\n"); return 0; }
  if(cmp(reflect(s), c)) { printf("4\n"); return 0; }
  if(cmp(reflect(k), c) || cmp(reflect(r), c) || cmp(reflect(m), c)) { printf("5\n"); return 0; }
  if(cmp(s, c)) { printf("6\n"); return 0; }
  printf("7\n");

  return 0;
}
