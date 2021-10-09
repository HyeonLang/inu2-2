#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { //�� ���� element
	int id; //id
	int arrival_time; //�����ð�
	int service_time; //���� �ð�
	int vip;          //vip ����
	int prime_num;    //�Ҽ� ����
} element;

typedef struct QueueNode { //�� ť ��� 
	element data;         //�� ���� data
	struct QueueNode* link; //��� ��ũ
} QueueNode;

typedef struct {   //ť Adt ����
	QueueNode* front, * rear;
} LinkedQueueType;

//�ʱ�ȭ �Լ�
void init_queue(LinkedQueueType* q) {
	q->front = q->rear = 0;   //front�� rear�� NULL���� ���� (����)
}


//������� ���� �Լ�(ť�� ����ִ°�?)
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);  //front ���� > ����
}


//�� ���� �Լ�
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