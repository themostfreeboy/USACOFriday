/*
ID: themostfreeboy
LANG: C
TASK: friday
*/
#include<stdio.h>
#include<string.h>
int panduan(int x)
{
    int y;
    if(x%400==0)    y=1;
    else if(x%100==0)  y=0;
    else if(x%4==0) y=1;
    else    y=0;
    return y;
}
main () 
{
    FILE *fin=fopen ("friday.in","r");
    FILE *fout=fopen ("friday.out","w");
    int n,cishu[8],i,j,k,m=1,pingrun,date[13][32];
    fscanf(fin,"%d",&n);
    for(i=0;i<=7;i++)    cishu[i]=0;
    for(i=0;i<=12;i++)
        for(j=0;j<=31;j++)
            date[i][j]=0;
    for(i=1;i<=31;i++)
    {
        date[1][i]=1;
        date[3][i]=1;
        date[5][i]=1;
        date[7][i]=1;
        date[8][i]=1;
        date[10][i]=1;
        date[12][i]=1;
    }
    for(i=1;i<=30;i++)
    {
        date[4][i]=1;
        date[6][i]=1;
        date[9][i]=1;
        date[11][i]=1;
    }
    for(i=1;i<=28;i++)      date[2][i]=1;
    for(i=1900;i<=1900+n-1;i++)
    {
        if(panduan(i)==1)    date[2][29]=1;
        if(panduan(i)==0)    date[2][29]=0;
        for(j=1;j<=12;j++)
        {
            for(k=1;k<=31;k++)
            {
                if(date[j][k]==1)
                {
                    if(k==13)
                    {
                        if(m!=0)    cishu[m]++;
                        if(m==0)    cishu[7]++;
                    }
                    m++;
                    m=m%7;
                }
            }
        }
    }
    for(i=6;i<=7;i++)   fprintf(fout,"%d ",cishu[i]);
    for(i=1;i<=4;i++)   fprintf(fout,"%d ",cishu[i]);
    fprintf(fout,"%d\n",cishu[5]);
    fclose(fin);
    fclose(fout);
    return (0);
}
