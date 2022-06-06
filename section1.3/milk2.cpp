/*
ID: colorfu3
TASK: milk2
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int N, a, b;
struct point { int x, y; } d[5010];

bool cmp(point a, point b) { return (a.x<b.x)||((a.x==b.x)&&(a.y<b.y)); }

int main()
{
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);

  scanf("%d", &N);
  for(int i=0; i<N; i++)
    scanf("%d%d", &d[i].x, &d[i].y);

  sort(d, d+N, cmp);

  int s = d[0].x, e = d[0].y;
  for(int i=1; i<N; i++)
  {
    if(s<=d[i].x && d[i].y<=e) continue;
    if(d[i].x<=e)
    {
      e = d[i].y;
      a = max(a, e-s);
    }
    else
    {
      b = max(b, d[i].x-e);
      s = d[i].x, e = d[i].y;
    }
  }
  a = max(a, e-s);

  printf("%d %d\n", a, b);

  return 0;
}
