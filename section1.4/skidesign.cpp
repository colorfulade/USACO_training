/*
ID: colorfu3
LANG: C++
TASK: skidesign
*/

#include <cstdio>
#include <climits>

int N, d[1010];

int main()
{
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);

  scanf("%d", &N);
  for(int i=0; i<N; i++)
    scanf("%d", &d[i]);

  long long ans = LLONG_MAX;
  for(int st=0; st<=83; st++)
  {
    int ed = st+17;
    long long sum = 0;
    for(int i=0; i<N; i++)
    {
      if(d[i]<st) sum += (st-d[i])*(st-d[i]);
      if(d[i]>ed) sum += (d[i]-ed)*(d[i]-ed);
    }
    if(ans>sum) ans = sum;
  }

  printf("%lld\n", ans);

  return 0;
}
