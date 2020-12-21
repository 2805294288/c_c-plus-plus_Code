#include "test.h"

int main()
{
	SListNode* PList = NULL;

	SListPushBack(&PList, 1);
	SListPushBack(&PList, 2);
	SListPushBack(&PList, 3);
	SListPushBack(&PList, 4);
	SListPrint(PList);

	SListNode* pre=reverseList(&PList);
	SListPrint(pre);
}
