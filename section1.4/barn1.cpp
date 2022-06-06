/*
ID: colorfu3
TASK: barn1
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int M, S, C, d[210], ck[210];
vector<int> V;

bool cmp(int a, int b) { return a>b; }

int main()
{
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);

  scanf("%d%d%d", &M, &S, &C);
  for(int i=0; i<C; i++)
    scanf("%d", &d[i]);

  sort(d, d+C);

  for(int i=1; i<C; i++)
  {
    if((d[i]-d[i-1])==1) continue;
    else V.push_back(d[i]-d[i-1]-1);
  }

  sort(V.begin(), V.end(), cmp);

  int t = d[C-1]-d[0]+1;
  if(M>=C) printf("%d\n", C);
  else if(M==1) printf("%d\n", t);
  else
  {
    for(int i=0; i<M-1; i++)
      t -= V[i];
    printf("%d\n", t);
  }

  return 0;
}
