#include <stdio.h>
#include<stdlib.h>
void display (int b[],int k);
int Insert_Last (int b[],int k,int m);
int Insert_sp_position(int b[],int k,int m,int q);
int deletion(int b[],int k,int q);
void Linear_search(int b[], int k, int q);
void Binary_search (int b[],int k,int q);
void bubble_sort(int b[],int k);

int main()
{
    int n,a[100],i,c,v,p,q;
    printf("Enter the number of values");
    scanf("%d",&n);
    printf("\nEnter values:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);

    while(1)
    {

           printf("\n........menu.......");
           printf("\npress 0 for quit");
           printf("\npress 1 for insertion at last position");
           printf("\npress 2 for specific insertion");
            printf("\npress 3 for display");
            printf("\npress 4 for deletion from specific position");
              printf("\npress 5 for linear search");
               printf("\npress 6 for bubble sort");
                printf("\npress 7 for binary search");
                 printf("\nenter your choice\n");
                 scanf("%d",&c);
                 switch(c)
                 {
                     case 0:exit(0);
                            break;
                    case 1: printf("\nchoice=insertion at last position");
                            printf("\nenter new value\n");
                            scanf("%d",&v);
                            n=Insert_Last (a,n,v);
                    break;
                    case 2: printf("\nchoice=insertion specific position");
                            printf("\n enter value\n");
                            scanf("%d",&v);
                        M:  printf("\nenter position between %d to %d",1,n+1);
                            scanf("%d",&p);
                            if(p>=1 && p<=n+1)
                            n= Insert_sp_position(a,n,v,p);
                            else
                            {
                                printf("\n wrong position");
                                goto M;
                            }
                            break;
                    case 3: printf("\nchoice display\n\n");
                           if(n!=0)
                            display(a,n);
                            else
                            printf("\n no data to display\n");
                            break;
                    case 4: printf("\n choice= deletion from specific position");
                            if (n!=0)
                            {
                                printf("\n Enter position between %d to %d",1,n);
                                scanf("%d",&p);
                                if(p>=1 && p<=n)
                                    n= deletion(a,n,p);
                                else
                                    printf("wrong position");
                            }
                            else
                                printf("No data to delete\n");
                            break;
                    case 5: printf("\n choice= linear search");
                            printf("\n enter the value for searching");
                            scanf("%d",&v);
                            Linear_search(a,n,v);
                            break;
                    case 6: printf("\n choice= Binary search");
                            printf("\n Enter the value for searching");
                            scanf("%d",v);
                            Binary_search(a,n,v);
                            break;
                    case 7: printf("\n choice= bubble sort");
                            bubble_sort (a,n);
                            break;
                    default:
                           break;
                    }
       }
return 0;

}

 void display (int b[],int k)
    {
        int j;
        for (j=1;j<=k;j++)
        printf("%d\n",b[j]);
    }
  int Insert_Last (int b[],int k,int m)
    {
        b[k+1]=m;

        printf("\n inserted successfully \n");
        return k+1;
    }

    int Insert_sp_position(int b[],int k,int m,int q)
    {


        int j;
        for (j=k;j>=q;j--)
        b[j+1]=b[j];
        b[q]=m;
        printf("\ninserted successfully\n");

        return k+1;
    }
    int deletion(int b[],int k, int q)
    {
        int i;
        for(i=q; i<k; i++)
        {
            b[i]=b[i+1];
        }
        printf("\n deleted successfully\n");
        return k-1;
    }
        void Linear_search(int b[], int k, int q)
        {
            int i,c=0;
            for(i=1; i<=k; i++)
            {
                if(q==b[i])
                {
                    printf("\n found at position: %d \n",i);
                    c=c+1;
                }
            }
            if (c==0)
                printf("\n not found");
            else
                printf("total found= %d",c);
        }
        void Binary_search (int b[],int k,int q)
        {
            int beg,end,mid;
            bubble_sort(b,k);
            beg=1;
            end=k;
            do
            {
                mid= (beg+end)/2;
                if(q<b[mid])
                    end= mid-1;
                else
                    beg=mid+1;
            }
            while (q!= b[mid] && beg<= end);
            if (q== b[mid])
                printf("\n found \n");
            else
                printf("Not found");
        }
        void bubble_sort(int b[],int k)
        {
            int i,j,t;
            for (i=1; i<= k; i++)
            {
                for(j=i;j<= k-i;j++)
                {
                    if(b[j]>b[j+i])
                    {
                        t=b[j];
                        b[j]=b[j+1];
                        b[j+1]=t;
                    }
                }
            }
            printf(" sorted successfully");
        }
