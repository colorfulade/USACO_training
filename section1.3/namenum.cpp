/*
ID: colorfu3
TASK: namenum
LANG: C++
*/

#include <cstdio>
#include <cstring>

int N, flag;
char s[5010][20], v[20];
char c[10][5] = {
  {},
  {},
  {'A', 'B', 'C'},
  {'D', 'E', 'F'},
  {'G', 'H', 'I'},
  {'J', 'K', 'L'},
  {'M', 'N', 'O'},
  {'P', 'R', 'S'},
  {'T', 'U', 'V'},
  {'W', 'X', 'Y'},
};

int main()
{
  //load dict.txt file
  freopen("dict.txt", "r", stdin);
  for(int i=0; i<5000; i++)
    scanf("%s", s[i]);

  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);

  scanf("%s", v);
  for(int i=0; i<5000; i++)
  {
    if(strlen(s[i])!=strlen(v)) continue;
    for(int j=0; s[i][j]!='\0'; j++)
    {
      int t = v[j]-'0', r;
      if(t<2) goto e;
      for(r=0; r<3; r++)
        if(c[t][r]==s[i][j]) break;
      if(r==3) goto u;
    }

    for(int j=0; s[i][j]!='\0'; j++)
      printf("%c", s[i][j]);
    puts("");
    flag = 1;
    u:;
  }
  e:;

  if(!flag) printf("NONE\n");

  return 0;
}
