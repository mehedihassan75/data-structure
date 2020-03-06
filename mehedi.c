#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};


void push(int vv);
void display();
void pop();

struct node *top=NULL,*temp;


int main()
{
    int c,v;
    while(1)
    {
        printf("\n ------- menu \n");
        printf("\n press 1 for push \n");
        printf("\n press 2 for display \n");
        printf("\n press 3 for pop \n");
        printf("\n press 0 for quit \n");
        printf("\n enter your choice \n");
        scanf("%d",&c);

        switch(c)
        {
            case 0: exit(0);
                    break;

            case 1: printf("\n choice = push \n");
                    printf("\n enter value \n");
                    scanf("%d",&v);
                    push(v);
                    break;

           case 2: printf("\n choice = display \n");
                   if(top!=NULL)
                    display();
                   else
                    printf("\n stack is empty");
                   break;

          case 3: printf("\n choice = pop \n");
                   if(top!=NULL)
                    pop();
                   else
                    printf("\n stack is empty");
                   break;

         default: printf("\n wrong choice \n");
                  break;
        }
    }
}




void push(int vv)
{
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=vv;
        temp->link=top;
        top=temp;
    }
}

void display()
{
    temp=top;
    while(temp!=NULL)
    {
        printf("\n %d \n",temp->data);
        temp=temp->link;
    }
}

void pop()
{
    temp=top;
    top=top->link;
    free(temp);
    printf("\n deleted successfully \n");
}
