/*
ID: colorfu3
TASK: palsquare
LANG: C++
*/

#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int N;
vector<int> num;

void f(ll k)
{
  if(k==0) return;
  f(k/N);
  if(k%N<10) num.push_back(k%N);
  else num.push_back(k%N+55);
}

void g(ll k)
{
  if(k==0) return;
  g(k/N);
  if(k%N<10) printf("%d", k%N);
  else printf("%c", (char)(k%N+55));
}

bool pal(ll k)
{
  f(k);
  int i;
  for(i=0; i<num.size()/2; i++)
    if(num[i]!=num[num.size()-i-1]) break;
  return i==num.size()/2;
}

int main()
{
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);

  scanf("%d", &N);
  for(int i=1; i<=300; i++){
    ll t = i*i;
    if(pal(t)){
      g(i); printf(" ");
      g(t); printf("\n");
    }
    num.clear();
  }

  return 0;
}
