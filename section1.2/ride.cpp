/*
ID: colorfu3
LANG: C++
TASK: ride
*/

#include <cstdio>

int a, b;
char s[10], c[10];

int main()
{
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);

  scanf("%s %s", s, c);

  a = b = 1;
  for(int i=0; s[i]!='\0'; i++)
    a = (a*(s[i]-'A'+1))%47;
  for(int i=0; c[i]!='\0'; i++)
    b = (b*(c[i]-'A'+1))%47;

  if(a==b) printf("GO\n");
  else printf("STAY\n");

  return 0;
}
