#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { //고객 정보 element
	int id; //id
	int arrival_time; //도착시간
	int service_time; //서비스 시간
	int vip;          //vip 여부
	int prime_num;    //소수 여부
} element;

typedef struct QueueNode { //고객 큐 노드 
	element data;         //고객 정보 data
	struct QueueNode* link; //노드 링크
} QueueNode;

typedef struct {   //큐 Adt 구현
	QueueNode* front, * rear;
} LinkedQueueType;

//초기화 함수
void init_queue(LinkedQueueType* q) {
	q->front = q->rear = 0;   //front와 rear을 NULL으로 맞춤 (공백)
}


//공백상태 검출 함수(큐가 비어있는가?)
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);  //front 공백 > 리턴
}


//앞 삽입 함수
void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;

	if (is_empty(q))
	{
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp; 
		q->rear = temp;
	}
}