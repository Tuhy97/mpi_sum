void BubbleSort(int* pData,int Count)
{
int iTemp;
for(int i=1;i<Count;i++)
{
    for(int j=Count-1;j>=i;j--)
    {
      if(pData[j]<pData[j-1]) [Page]
      {
        iTemp = pData[j-1];
        pData[j-1] = pData[j];
        pData[j] = iTemp;
      }
    }
}
}
