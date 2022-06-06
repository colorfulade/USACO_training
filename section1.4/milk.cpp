/*
ID: colorfu3
TASK: milk
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, total, ans;
struct point { int x, y; } d[5010];

bool cmp(point a, point b) { return (a.x<b.x)||((a.x==b.x)&&(a.y<b.y)); }

int main()
{
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);

  scanf("%d%d", &N, &M);
  for(int i=0; i<M; i++)
    scanf("%d%d", &d[i].x, &d[i].y);

  sort(d, d+M, cmp);
  for(int i=0; i<M; i++)
  {
    int t = min(N-total, d[i].y);
    ans += (d[i].x*t);
    total += t;
  }

  printf("%d\n", ans);

  return 0;
}
