#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
int move = 0;


typedef struct Listnode {
	element data;
	struct Listnode* link;
}Listnode;


void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;
}

//�ϴ� ������.
Listnode* insert_first(Listnode *head, int value) {
	Listnode* p = (Listnode*)malloc(sizeof(Listnode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

Listnode* insert(Listnode* head, Listnode* pre, element value) {


	Listnode* p = (Listnode*)malloc(sizeof(Listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;

}


Listnode* delete_first(Listnode* head) {

	Listnode* removed;
	if (head == NULL) {
		error("����Ʈ�� ������ϴ�.");
		return NULL;
	}
	removed = head;
	head = removed->link;
	free(removed);
	return head;

}

Listnode* delete(Listnode* head, Listnode* pre) {
	Listnode* removed;
	if (head == NULL) {
		error("����Ʈ�� ������ϴ�.");
	}
	removed = pre->link;//���� ��尡 ����Ű�� ���� �ּ� �� ���ǰ� pre�� ����Ű�� ���� ��� 
	pre->link = removed->link;
	free(removed);
	return head;
	
}

void print_list(Listnode* head) {
	printf("List: ");
	for (Listnode* p = head->link; p != NULL;p=p->link) {//head �� data ���� head�� ����Ű�� ���� data�� �־����

		printf("%d->", p->data);

	}
	printf("\n");
}
//pre�� ã�� 
Listnode * finding(Listnode *head,int index) { //pre�� ��ȯ�ؾ��� 
	int i ;
	Listnode* f= (Listnode*)malloc(sizeof(Listnode));
	Listnode* p;
	for (p = head,i=0; p != NULL; p = p->link,i++) {//fidning�Լ��� �����Ͱ� null�� �ɶ������� ����
		move++;
		if (index == -1) {//-1�ΰ���SELECT���� �̸� ó���س���
			return f;
		}
		else if (index==i) {
			return p;

		}
		f = p;//for �������� �� node����� 

		/*
		else if (index==1) {//���� ��ħ 1ġ�� pre�ϱ� 0�� ��ȯ�Ϸ��� 
			
			f = p;
			return f;
		}
		*/
		// ��ũ����
	

	}
	return f;
	
	
}

int countNode(Listnode *head) {
	int count = -1;
	Listnode* p=head;
	while (p->link !=NULL) {

	
		p = p->link;
		count++;
	}
	return count;
}


void select(Listnode *head,int inputSel) {
	int inputPos;
	int inputVal;
	Listnode *t;
	switch (inputSel) {
	case 1:
		printf("enter the number and position:");
		
		scanf_s("%d %d", &inputVal,&inputPos);

		
		//inputVal�� �ʿ��Ѱ�?
		if (inputPos-1 > countNode(head)) {//�Է��� ��ġ���� ������ ��ġ�� ���̸�  �ƹ��͵� �ȵ��ִ� ���� : -1
			printf("the last index is %d. Insert at the end of the list\n", countNode(head));
			t = finding(head,countNode(head)+1);
			insert(head, t, inputVal);
			//t = finding(head, inputPos);//move ó����
		}
		else {
			t = finding(head, inputPos+1);
			insert(head, t, inputVal);
		}
	
		
		printf("Move along the Link: %d \n", move-1);//finding�� �־���ϳ� ..
		//insert();
		break;



	case 2:
		printf("Enter the position :");
		scanf_s("%d", &inputPos);
		t = finding(head, inputPos);//pos�� 0������ head ��ȯ  /  1������ 0��° ��ȯ�ؾ��ϴµ� 1��° ��ȯ  /
		//���� ������ 

		delete(head,t);
		printf("Move along the Link: %d\n ", move-1);


		break;
	case 3:
		print_list(head);
		break;
	case 4:
		exit(1);
		break;
	}
}

int main(void)
	{
	
		Listnode* head;
		head = (Listnode*)malloc(sizeof(Listnode));
		head->link = NULL;//****************
		
		int exit = 1;
		int inputSel;

		while (exit) {
			move = 0;
			
			printf("(1) Insert\n");
			printf("(2) Delet\n");
			printf("(3) Print\n");
			printf("(4) Exit\n");
			printf("Enter the menu:");
			scanf_s("%d", &inputSel);
			if (inputSel < 5 && inputSel>0) {
				select(head, inputSel);
			}
			else {

				printf("not correct number! try again\n");
			}



		}
		
	}