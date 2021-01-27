#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
typedef long long ll;
void BubbleSort(int* pData,int Count)
{
int iTemp;
for(int i=1;i<Count;i++)
{
    for(int j=Count-1;j>=i;j--)
    {
      if(pData[j]<pData[j-1])
      {
        iTemp = pData[j-1];
        pData[j-1] = pData[j];
        pData[j] = iTemp;
      }
    }
}
}
int random(int n)
{
    return (ll)rand() * rand() % n;
}
 
int main()
{
    srand((unsigned)time(0)); // 初始化随机种子
    int a[100000];
   //随机生成1e5 个绝对值小于1e9的整数
   int n = 100000;
   int m = 1e9;
   for(int i = 0; i <= n; ++i)
   {
       a[i] = random(2 * m + 1) - m;
   }
   BubbleSort(a,100000);
   for (int i=0;i<100;i++)
   //显示100个数据，实际上有100000个
    cout<<a[i]<<\" \";
    cout<<\"\\n\";
   return 0;
}

