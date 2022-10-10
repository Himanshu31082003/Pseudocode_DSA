//Remove Duplicates from Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
void create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i+++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
void RemoveDuplicateSorted(struct Node *p)
{
	struct Node *q;
	q=p->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}
void RemoveDuplicateUnsorted(struct Node *p)
{
    struct Node *q, *r, *temp;
    q = p;
    while (q != NULL && q->next != NULL) 
	{
        r = q;
        while (r->next != NULL) 
		{
            temp = r->next;
			if (q->data == temp->data) 
			{
                //temp = r->next;
                r->next = temp->next;
                free(temp);
            }
            else
                r = r->next;
        }
        q = q->next;
    }
}
int main()
{
	int A[]={10,20,20,40,50,20,50,60};
	create(A,8);
	RemoveDuplicateSorted(first);
	Display(first);
	printf("\n\n");
	RemoveDuplicateUnsorted(first);
	Display(first);
	return 0;
}
