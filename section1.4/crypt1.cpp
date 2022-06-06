/*
ID: colorfu3
LANG: C++
TASK: crypt1
*/

#include <cstdio>

int N, dt[11], ck[11], ans;

bool is_exist(int k, int r)
{
  int cnt = 0;
  while(k>10)
  {
    if(!ck[k%10]) return 1;
    cnt++;
    k /= 10;
  }
  if(!ck[k%10]) return 1; cnt++;

  if(cnt==r) return 0;
  return 1;
}

int main()
{
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);

  scanf("%d", &N);
  for(int i=0; i<N; i++)
  {
    scanf("%d", &dt[i]);
    ck[dt[i]] = 1;
  }

  for(int ai=0; ai<N; ai++)
    for(int bi=0; bi<N; bi++)
      for(int ci=0; ci<N; ci++)
        for(int di=0; di<N; di++)
          for(int ei=0; ei<N; ei++){
            int a = dt[ai], b = dt[bi], c = dt[ci], d = dt[di], e = dt[ei];
            int f = (a*100+b*10+c)*e; if(is_exist(f, 3)) continue;
            int g = (a*100+b*10+c)*d; if(is_exist(g, 3)) continue;
            int h = (g*10)+f; if(is_exist(h, 4)) continue;
            ans++;
          }

  printf("%d\n", ans);

  return 0;
}
