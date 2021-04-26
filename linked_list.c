#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node{

	int info;
	struct node *link;
};

struct node *create_list(struct node *head);
void display(struct node *head);
void count(struct node *head);
void search(struct node *head,int data);

struct node *addatbeg(struct node *head,int data);
struct node *addatend(struct node *head,int data);
struct node *addafter(struct node *head,int data,int item);
struct node *addbefore(struct node *head,int data,int item);
struct node *addatpos(struct node *head,int data,int pos);
struct node *del(struct node *head,int data);
struct node *reverse(struct node *head);

int main(){

	struct node *head=NULL;
	int choice,data,item,pos;
	while(1){
		printf("**PLEASE ENTER THE CORRECT VALUE**\n");
		printf("1.Create list\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add at the beginning\n");
		printf("6.Add at the end\n");
		printf("7.Add before node\n");
		printf("8.add after node\n");
		printf("9.Add at the position\n");
		printf("10.Delete the node\n");
		printf("11.Reverse the node\n");
		printf("12.Exit\n");
		
		printf("Enter your choice\n");
		scanf("%d",&choice);

		switch(choice){
		
			case 1:
				head=create_list(head);
			        break;
			case 2:
				display(head);
				break;
			case 3:
				count(head);
				break;
			case 4:
				printf("Enter the element to be searched:\n");
				scanf("%d",&data);
				search(head,data);
				break;
			case 5:
				printf("Enter the element to be inserted at beg:\n");
				scanf("%d",&data);
				addatbeg(head,data);
				break;
			case 6:
				printf("Enter the element to be inserted at end:\n");
				scanf("%d",&data);
				addatend(head,data);
				break;
			case 7:
				printf("Enter the element and node after to be inserted:\n");
				__fpurge(stdin);
				scanf("%d %d",&data,&item);
				addafter(head,data,item);
				break;
			case 8:
				printf("Enter the element and node before to be inserted:\n");
				__fpurge(stdin);
				scanf("%d %d",&data,&item);
				addbefore(head,data,item);
				break;
			case 9:
				printf("Enter the element and position to be inserted:\n");
				__fpurge(stdin);
				scanf("%d %d",&data,&pos);
				addatpos(head,data,pos);
				break;
			case 10:
				printf("Enter the element to be deleted:\n");
				scanf("%d",&data);
				del(head,data);
				break;
			case 11:
				head=reverse(head);
				break;

			case 12:
				exit(1);
			default:
				printf("Please enter the correct choice\n");

		}
	
	}

}

void display(struct node *head){

	struct node *p;
	if(head==NULL){
		printf("\n");
		printf("The list is empty\n");
	}
	p=head;
	printf("\n");
	while(p!=NULL){

		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}

void count(struct node *head){

	struct node *p;
	p=head;
	int count=0;
	while(p!=NULL){
		count++;
		p=p->link;
	}
	printf("\n");
	printf("The no of nodes in the link list are: %d\n",count);
	printf("\n");
}

void search(struct node *head,int data){

	struct node *p;
	p=head;
	int count=0;
	while(p!=NULL){
	
		if(p->info==data){
		
			printf("The node found at position %d\n",count);
			return;
		}
		count++;
		p=p->link;
	}
	printf("Sorry,item not found\n");
}

struct node *addatbeg(struct node *head,int data){

	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->link=head; 
	temp->info=data;
	head=temp;
	return head;
}

struct node *addatend(struct node *head,int data){

	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	p=head;
	while(p->link!=NULL){
	
		p=p->link;
	}
	p->link=temp;
	temp->info=data;
	temp->link=NULL;
	return head;	
}

struct node *addafter(struct node *head,int data,int item){

	struct node *p,*temp;
	p=head;
	while(p!=NULL){
	
		if(p->info==item){
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
		}
		p=p->link;
	}
	printf("The link is not present in the node\n");
	return head;
}

struct node *addbefore(struct node *head,int data,int item){

	struct node *p,*temp;
	if(head==NULL){
	
		printf("The list is empty\n");
		return head;
	}
	if(item==head->info){
	
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=head;
		head=temp;
		return head;
	}

	p=head;

	while(p!=NULL){
		if(p->link->info==item){
		
			temp=(struct node *)malloc(sizeof(struct node));
			temp->link=p->link;
			p->link=temp;
			return head;
		}
		p=p->link;
	}
	printf("the node is present in the list\n");
	return head;
}

struct node *addatpos(struct node *head,int data,int pos){

	struct node *temp,*p;
	int count=1;
	if(head==NULL){
		
		printf("The List is empty\n");
		return head;
	}
	p=head;
	if(count==pos){
	
		temp=(struct node *)malloc(sizeof(struct node));
		temp->link=head;
		temp->info=data;
		head=temp;
		return head;
	}
	while(p!=NULL){
	
		count++;
		if(count==pos){
			temp=(struct node *)malloc(sizeof(struct node));
			temp->link=p->link;
			p->link=temp;
			temp->info=data;
			return head;
		}
	p=p->link;
	}
printf("You have entered the wrong Position\n");
}


struct node *create_list(struct node *head){

	int n,data;
	printf("Enter the No of nodes you want to create\n");
	scanf("%d",&n);
	if(n==0){
	
		return head;
	}
	
	printf("enter the data to be inserted:\n");
	scanf("%d",&data);
	head=addatbeg(head,data);
	for(int i=2;i<=n;i++){
	
		printf("enter the data to be inserted:\n");
		scanf("%d",&data);
		addatend(head,data);
	}
	return head;

}

struct node *del(struct node *head,int data){

	struct node *tmp,*p;
	if(head==NULL){
	
		printf("List is empty\n");
		return head;
	}
	if(head->info==data){
	
		tmp=head;
		head=tmp->link;
		free(tmp);
		return head;
	}
	p=head;
	while(p->link!=NULL){
	
		if(p->link->info==data){
		
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return head;
		}
	p=p->link;
	}
	printf("Element %d is not found\n",data);
}

struct node *reverse(struct node *head){

	struct node *ptr,*prev,*next;
	prev=NULL;
	ptr=head;
	while(ptr!=NULL){
	
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
	return head;

}
