#include "test.h"

SListNode* BuySListNode(SlistDateType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL) {
		printf("ÉêÇëÇ°Ê§°Ü");
		exit(-1);
	}
	NewNode->val = x;
	NewNode->next = NULL;

	return NewNode;
}
void SListPushBack(SListNode** pphead, SlistDateType x)
{
	if (*pphead == NULL) {
		SListNode* NewNode = BuySListNode(x);
		*pphead = NewNode;
	}
	else {
		SListNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		SListNode* NewNode = BuySListNode(x);
		tail->next = NewNode;
	}
}

SListNode* reverseList(SListNode** pphead)
{
	SListNode* p, * pre = NULL;
	SListNode* cur = *pphead;
	while (cur) {
		p = cur->next;
		cur->next = pre;
		pre =cur;
		cur = p;
	}
	return pre;
}

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}