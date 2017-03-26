#include<iostream>
using namespace std;
main()
{
    int a[4];
    int i,j,l,count,rem=100;
    for(i=0;i<4;i++)
    {
        cin<<a[i];
    }
    int b[5][9],bin[8];

     for(i=0;i<4;i++)
     {
         l=a[i];
         count=0;
         for(j=0;j<9;j++)
         {
             a[i][j]=0;
         }

         for(j=7;j>=0,rem!=0;j--)
            {
              b[i][j]=l%2;
              rem=l/2;
              if(b[i][j]==1)
                count++;
           }
         if((count%2)==1)
            b[i][8]=1;

     }
      for(i=0;i<9;i++)
      {
          count=0;
          for(j=0;j<4;j++)
          {
            if(b[j][i]==1)
                count++;
          }
          if(count%2==1)
            b[4][i]=1;
      }
}
