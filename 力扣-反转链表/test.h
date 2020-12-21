#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SlistDateType;

typedef struct ListNode {
	SlistDateType val;
	struct ListNode* next;
}SListNode;
void SListPrint(SListNode* phead);

SListNode* BuySListNode(SlistDateType x);
void SListPushBack(SListNode** pphead, SlistDateType x);

SListNode* reverseList(SListNode** pphead);

