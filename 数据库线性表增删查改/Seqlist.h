#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity; // unsigned int
}SL;
void SeqListInit(SL*ps);
void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListCheckCapacity(SL* ps);
void SeqListPopFront(SL* ps);
void SeqListInsert(SL* ps, size_t pos, SLDateType x);
void SeqListErase(SL* ps, size_t pos);
int SeqListFind(SL* ps, SLDateType x);
void SeqListDestory(SL* ps);
