/*
ID: colorfu3
LANG: C++
TASK: friday
*/

#include <cstdio>

int N, w, ck[10];

int c[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int k) { return ((k%4==0)&&(k%100!=0))||(k%400==0); }

int main()
{
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);

  scanf("%d", &N);
  for(int i=1900; i<1900+N; i++) //year
    for(int j=0; j<12; j++) //month
      for(int k=1; k<=((leap(i)&&(j==1))?c[j]+1:c[j]); k++) //day
      {
        if(k==13) ck[w]++;
        w = (w+1)%7;
      }

  for(int i=0; i<7; i++)
    if(i<6) printf("%d ", ck[(i+5)%7]);
    else printf("%d\n", ck[(i+5)%7]);

  return 0;
}
