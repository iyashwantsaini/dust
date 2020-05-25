#include<stdio.h>

struct times
{	
       int p,art,but,rnt;
};
void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].art > a[j].art)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
    //    for(int i=0;i<pro;i++){
    //        printf("%d ",a[i].p);
    //        printf("%d ",a[i].art);
    //        printf("%d ",a[i].but);
    //        printf("\n");
    //    }
       return;
}

int main()
{
       int i,j,pro,time,remain,flag=0,ts;
       scanf("%d",&pro);
       struct times a[pro];
       remain=pro;
       int tempo;
       for(i=0;i<pro;i++)
       {
              scanf("%d%d%d",&a[i].p,&a[i].art,&a[i].but);
              a[i].rnt = a[i].but;
       }
       sortart(a,pro);
       ts=1;

       for(i=0;remain!=0;)
       {        
              if(a[i].rnt<=ts && a[i].rnt>0)
              {      printf("%d ",a[i].p);
                     time = time + a[i].rnt;
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {      a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf("%d ",a[i].p);
              }
              if(a[i].rnt<=0 && flag==1)
              {
                     remain--;
                     flag=0;
              }
              if(i==pro-1)
                     i=0;
              else if(a[i+1].art <= time)
                     i++;
              else
                     i=0;
       }
       
       return 0;
}