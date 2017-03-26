#include<iostream>
using namespace std;
main()
{
    char s[4];
    int a[4];
    int i,j,l,count,c,check=0,rem=100;
    /*for(i=0;i<4;i++)
    {
        cin>>a[i];
    }*/
    cin>>s;
    cout<<endl;
    for(i=0;i<4;i++)
    {
        a[i]=s[i];
        cout<<a[i]<<" ";
    }
    int b[5][9];

     for(i=0;i<4;i++)
     {
         l=a[i];
         count=0;
         for(j=0;j<9;j++)
         {
             b[i][j]=0;
         }

         for(j=7;j>=0,l!=0;j--)
            {
              b[i][j]=l%2;
              l=l/2;
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
           else
                b[4][i]=0;
      }
      cout<<endl;
      for(i=0;i<5;i++)
      {
          for(j=0;j<9;j++)
          {
             cout<<b[i][j]<<" ";
          }
          cout<<endl;
      }
       cout<<endl;
        cout<<endl;

b[1][3]=1;
b[2][4]=1;
b[1][4]=1;
b[2][3]=1;

for(i=0;i<4;i++)
{
    count=0;
    for(j=0;j<8;j++)
    {
       if(b[i][j]==1)
            count++;
    }
    if((count%2)==1)
        c=1;
    else
            c=0;
    if(c!=b[i][8])
        check++;
}
 for(i=0;i<8;i++)
      {
          count=0;
          for(j=0;j<4;j++)
          {
            if(b[j][i]==1)
                count++;
          }
          if((count%2)==1)
            c=1;
         else
            c=0;
         if(b[4][i]!=c)
            check++;
      }
cout<<endl<<"Errors are : "<<check;

}
