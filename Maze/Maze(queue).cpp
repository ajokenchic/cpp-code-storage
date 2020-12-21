
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//사이즈 지정
#define x 9
#define y 9
//출구 지정
#define exit_a 5
#define exit_b 8

typedef struct Pos{
   int a, b;
} Pos;
queue<Pos>point;
vector<Pos>trc;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
   int s = NULL;
   char m[x][y] = { {0, 0, 0, 0, 0, 0, 0, 1, 1} ,
                        {0, 1, 1, 0, 1, 1, 0, 1, 0} ,
                        {0, 0, 0, 1, 0, 0, 0, 1, 0} ,
                        {0, 1, 0, 0, 1, 1, 0, 0, 0} ,
                        {0, 1, 1, 1, 0, 0, 1, 1, 1} ,
                        {0, 1, 0, 0, 0, 1, 0, 1, 0} ,
                        {0, 0, 0, 1, 0, 0, 0, 1, 0} ,
                        {0, 1, 1, 1, 0, 1, 0, 0, 0} ,
                        {0, 1, 1, 1, 0, 1, 0, 1, 0} };
   m[0][0] = -1;
   
   point.push({ 0, 0 });
   while (!point.empty()){
      Pos t = point.front();
      point.pop();
      for (int i = 0; i < 4; i++){
         int aa = t.a + dx[i];
         int bb = t.b + dy[i];
         if (aa >= 0 && bb >= 0 && aa < x && bb < y && m[aa][bb] == 0)   {
            point.push({ aa,bb });
            m[aa] [bb]= m[t.a][t.b] - 1;
            if (aa == exit_a && bb == exit_b){
               s = point.size();
               for (int i=0;i<s;i++){
                  point.pop();
               }
               break;
            }
         }
      }   
   }
   if (!s) printf("No Exit!");
   else 
      for (int i = 0; i < x; i++)   {
         for (int j = 0; j < y; j++) printf("[%3d]", m[i][j]);
         printf("\n");
      }
//----------------------------------------------------------------------------------------------------------
int idx=m[exit_a][exit_b];
int a=exit_a;
int b=exit_b;
trc.push_back({a,b});
int aa;
int bb;
while(idx!=-1)
{
  for (int i = 0; i < 4; i++){
         aa=a+dx[i];
         bb=b+dy[i];
          if(aa >= 0 && bb >= 0 && aa < x && bb < y && m[aa][bb] == (idx+1)){
            trc.push_back({aa,bb});
            a=aa;
            b=bb;
            idx+=1;
            break;
          }
        }
}
  for(auto t:trc) 
  {
    printf("[%d,%d]\n",t.a,t.b);
    m[t.a][t.b]=77;
  }
  trc.clear();
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<y;j++)
    {
      if(m[i][j]==77)printf("□");
      else printf("■");
    }
    printf("\n");
  }
}