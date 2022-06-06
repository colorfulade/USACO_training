/*
ID: colorfu3
TASK: dualpal
LANG: C++
*/

#include <cstdio>
#include <vector>
using namespace std;

int C, N;
vector<int> num;

void f(int k, int r)
{
  if(k==0) return;
  f(k/r, r);
  if(k%r<10) num.push_back(k%r);
  else num.push_back(k%r+55);
}

bool pal(vector<int> k)
{
  int i;
  for(i=0; i<k.size()/2; i++)
    if(k[i]!=k[k.size()-i-1]) break;
  return i==k.size()/2;
}

int main()
{
  freopen("dualpal.in", "r", stdin);
  freopen("dualpal.out", "w", stdout);

  scanf("%d%d", &C, &N);
  while(C)
  {
    ++N;
    int cnt = 0;
    for(int i=2; i<=10; i++){
      f(N, i);
      if(pal(num)) cnt++;
      num.clear();
    }

    if(cnt>=2){
      printf("%d\n", N);
      C--;
    }
  }

  return 0;
}
