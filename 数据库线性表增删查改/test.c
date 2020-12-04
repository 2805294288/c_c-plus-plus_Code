#include "Seqlist.h"

void TeseSeqlist1()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);

    SeqListPopBack(&s,8);
	SeqListPopBack(&s,9);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 2, 3);
	SeqListInsert(&s, 3, 4);
	SeqListPrint(&s);

	SeqListErase(&s, 2);
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	SeqListFind(&s, 12);
	int point= SeqListFind(&s, 12);
	printf("%d", point);
}

int main()
{
	TeseSeqlist1();
	return 0;
}