/*
ID: colorfu3
LANG: C++
TASK: beads
*/

#include <cstdio>

int N, ans;
char s[710];

int main()
{
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);

  scanf("%d %s", &N, s);
  for(int i=0; i<N; i++)
    s[i+N] = s[i];
  for(int i=0; i<N; i++)
  {
    int t = i, j, k;
    if(s[t]=='w') for(; s[t]=='w'; t++);
    for(j=t; ((s[t]==s[j])||(s[j]=='w'))&&(s[j]!='\0'); j++);
    for(k=j; ((s[j]==s[k])||(s[k]=='w'))&&(s[k]!='\0'); k++);
    ans = (ans>(k-i))?ans:(k-i);
  }

  if(ans>N) ans = N;
  printf("%d\n", ans);

  return 0;
}
