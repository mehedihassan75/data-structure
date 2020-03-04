#include<stdio.h>
#include<stdlib.h>


struct node{
   int a;
   struct node *p;
};


void insertion_at_last_position(struct node *head,int value);
void insertion_specific_position(struct node *head,int vv,int pp);
int count(struct node *head);
void display(struct node *head);
void deletion(struct node *head,int pp);
void linear_search(struct node *head,int vv);


int main(){
  int n,i,c,v,p,q;
  struct node *list;
  list=(struct node*)malloc(1*sizeof(struct node));
  list->a=0;
  list->p=NULL;
  while(1){
    printf("\n----menu-----\n");
    printf("\n press 0 for quit");
    printf("\n press 1 for insertion at last position");
    printf("\n press 2 for specific position");
    printf("\n press 3 for display");
    printf("\n press 4 for count node");
    printf("\n press 5 for deletion specific position");
    printf("\n press 6 for linear search\n");
    printf("\n enter your choice\n");
    scanf("%d",&c);
    switch(c){
          case 0:exit(0);
                 break;
          case 1:printf("\n choice =insertion at last last position\n");
                 printf("\nenter new value");
                 scanf("%d",&v);
                 insertion_at_last_position(list,v);
                 break;

          case 2:printf("\n choice =insertion specific position\n");
                 printf("\n enter value");
                 scanf("%d",&v);
                 if(list->p!=NULL)
                 {
                     printf("enter position between %d to %d",1,count(list));
                     scanf("%d",&p);
                     if(p>=1&&p<=count(list))
                        insertion_specific_position(list,v,p);
                     else{
                        printf("wrong position\n");
                     }
                 }
                 else
                    printf("please initialize the list first\n");
                    break;

         case 3:printf("\n choice display\n");
                if(list->p!=NULL)
                    display(list);
                else
                    printf("\n no information to display");
                break;

        case 4:printf("\n choice =count node\n");
               n=count(list);
               printf("\ntotal node =%d",n);
               break;

        case 5:
               printf("\nchoice=deletion from specific position\n");
               n=count(list);
               if(n!=0)
               {
                   printf("\n enter position between %d to %d\n",1,n);
                   scanf("%d",&p);
                   if(p>=1&&p<=n)
                    deletion(list,p);
                   else
                   {
                       printf("\n wrong position\n");
                   }
               }
               else
                printf("\n the list is empty\n");
               break;

        case 6: printf("\n choice=linear search\n");
                printf("\n enter search value\n");
                scanf("%d",&v);
                if(count(list)==0)
                    printf("\n list is empty\n");
                else
                    linear_search(list,v);
                break;

        default:
                break;

    }
  }
}



void insertion_at_last_position(struct node *head,int value)
{
struct node *temp;
while(head->p!=NULL)
    head=head->p;
temp=(struct node*)malloc(1*sizeof(struct node));
temp->a=value;
temp->p=head->p;
head->p=temp;

}



void insertion_specific_position(struct node *head,int vv,int pp)
{
    int i=0;
    struct node *temp;
    while(head->p=NULL){
        if(i==pp-1)
            break;
        head=head->p;
        i++;
    }
   temp=(struct node*)malloc(1*sizeof(struct node));
   temp->a=vv;
   temp->p=head->p;
   head->p=temp;


}
int count(struct node *head)
{

int t=0;
while(head->p!=NULL)
{
    t++;
    head=head->p;
}
return t;
}



void display(struct node *head)
{

while(head->p!=NULL)
{
    printf("\t%d \t",head->p->a);
    head=head->p;
}
}



void deletion(struct node *head,int pp)
 {
     struct node *temp;
     int i=0;
     if(pp==1)
     {
         temp=head->p;
         head->p=temp->p;
         free(temp);
     }
     else
     {
         while(head->p!=NULL)
         {
             if(i==pp-1)
                break;
             head=head->p;
             i++;
         }
         temp=head->p;
         head->p=temp->p;
         free(temp);
     }
 }


 void linear_search(struct node *head,int vv)
 {
     int c=0;
     while(head->p!=NULL)
     {
         if(vv==head->p->a)
         {
             printf("\n found\n");
             c=1;
             break;
         }
         else
            head=head->p;
     }
     if(c==0)
        printf("\n not found\n");
 }

