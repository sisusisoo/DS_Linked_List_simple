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

//일단 사용안함.
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
		error("리스트가 비었습니다.");
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
		error("리스트가 비었습니다.");
	}
	removed = pre->link;//전에 노드가 가르키는 곳의 주소 즉 전의것 pre가 가리키는 다음 노드 
	pre->link = removed->link;
	free(removed);
	return head;
	
}

void print_list(Listnode* head) {
	printf("List: ");
	for (Listnode* p = head->link; p != NULL;p=p->link) {//head 의 data 말고 head가 가리키는 곳의 data를 넣어야함

		printf("%d->", p->data);

	}
	printf("\n");
}
//pre를 찾기 
Listnode * finding(Listnode *head,int index) { //pre를 반환해야함 
	int i ;
	Listnode* f= (Listnode*)malloc(sizeof(Listnode));
	Listnode* p;
	for (p = head,i=0; p != NULL; p = p->link,i++) {//fidning함수는 포인터가 null값 될때까지만 간다
		move++;
		if (index == -1) {//-1인경우는SELECT에서 미리 처리해놓음
			return f;
		}
		else if (index==i) {
			return p;

		}
		f = p;//for 마지막에 전 node저장용 

		/*
		else if (index==1) {//여기 고침 1치면 pre니까 0을 반환하려고 
			
			f = p;
			return f;
		}
		*/
		// 링크무브
	

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

		
		//inputVal이 필요한가?
		if (inputPos-1 > countNode(head)) {//입력한 위치보다 마지막 위치가 뒤이면  아무것도 안들어가있는 상태 : -1
			printf("the last index is %d. Insert at the end of the list\n", countNode(head));
			t = finding(head,countNode(head)+1);
			insert(head, t, inputVal);
			//t = finding(head, inputPos);//move 처리용
		}
		else {
			t = finding(head, inputPos+1);
			insert(head, t, inputVal);
		}
	
		
		printf("Move along the Link: %d \n", move-1);//finding에 넣어야하나 ..
		//insert();
		break;



	case 2:
		printf("Enter the position :");
		scanf_s("%d", &inputPos);
		t = finding(head, inputPos);//pos에 0넣으면 head 반환  /  1넣으면 0번째 반환해야하는데 1번째 반환  /
		//오류 수정용 

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