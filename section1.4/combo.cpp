/*
ID: colorfu3
LANG: C++
TASK: combo
*/

#include <cstdio>

int N, J[5], M[5], ans;

bool f(int k, int r)
{
  if(k<r) { int t = k; k = r; r = t; }
  if(k-r<=2 || N-k+r<=2) return 1;
  return 0;
}

int main()
{
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);

  scanf("%d", &N);
  for(int i=0; i<3; i++)
    scanf("%d", &J[i]);
  for(int i=0; i<3; i++)
    scanf("%d", &M[i]);

  for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++)
      for(int k=1; k<=N; k++) {
        if(f(i, J[0]) && f(j, J[1]) && f(k, J[2])) ans++;
        else if(f(i, M[0]) && f(j, M[1]) && f(k, M[2])) ans++;
      }

  printf("%d\n", ans);

  return 0;
}
