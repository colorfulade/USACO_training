/*
ID: colorfu3
LANG: C++
TASK: gift1
*/

#include <cstdio>
#include <cstring>

int N, a, b, d[20];
char s[20][20], c[20], v[20];

bool same(char *p, char *q)
{
  if(strlen(p)!=strlen(q)) return 0;

  int n = strlen(p), i;
  for(i=0; i<n; i++)
    if(p[i]!=q[i]) break;

  return i==n;
}

int main()
{
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  scanf("%d", &N);
  for(int i=0; i<N; i++)
    scanf("%s", s[i]);

  int T = N;
  while(T--)
  {
    scanf("%s %d%d", c, &a, &b);
    if(b==0) continue;
    for(int i=0; i<b; i++)
    {
      scanf("%s", v);
      for(int j=0; j<N; j++)
        if(same(v, s[j]))
        {
          d[j] += a/b;
          break;
        }
    }

    for(int i=0; i<N; i++)
      if(same(c, s[i]))
      {
        d[i] -= a;
        d[i] += (a%b);
        break;
      }
  }

  for(int i=0; i<N; i++)
    printf("%s %d\n", s[i], d[i]);

  return 0;
}
