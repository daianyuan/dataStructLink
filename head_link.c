#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct lnode
{
	int data;
	struct lnode *next;
 }lnode;
typedef struct lnode * link;

void create(link p,int a)
{
	link s = (link)malloc(sizeof(lnode));
	
	s->data = a;
	
	s->next = p->next;
	
	p->next = s;	
}  

void display(link p)
{
	printf("%d\n",p->data);
}

int main(int argc, char *argv[]) {
	
	link head,p;  //p可以部动态分配内存，head必须要动态分配，因为要连接在堆上的的结构体 
	
	int i;
	
	int  a[] = {1,2,3,4,5,6};
	
	head = (link)malloc(sizeof(lnode));
	
	p = (link)malloc(sizeof(lnode));   //加上这一句更好,自然要有free() 
	
	head->next = NULL;
	
	for(i=5;i>=0;i--)
	{
		create(head,a[i]);	
	}
	
	p = head->next;
	
	while(p!=NULL)
	{
		display(p);
		
		p = p->next;
	}
	
	free(head);
	
	free(p);
	
	system("pause");
	
	return 0;
}
