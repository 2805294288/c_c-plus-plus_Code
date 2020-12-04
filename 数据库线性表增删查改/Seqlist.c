#include "Seqlist.h"

void SeqListCheckCapacity(SL* ps)
{
    if (ps->size >= ps->capacity) {
        ps->capacity *= 2;
        ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
        if (ps->a == NULL) {
            printf("申请失败");
            exit(-1);
        }
    }
}
void SeqListInit(SL*ps)
{
   /* s.a = 0;
    s.size = NULL;
    s.capacity = 0;*/

    ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
    if (ps->a == NULL) {
        printf("申请失败");
        exit(-1);
    }
    ps->size = 0;
    ps->capacity = 4;
}

void SeqListPrint(SL* ps)
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

// 对数据的管理:增删查改 

//void SeqListDestory(SL* ps);

void SeqListPushBack(SL* ps, SLDateType x)
{
    assert(ps);
    if (ps->size >= ps->capacity) {
        ps->capacity *= 2;
        ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
        if (ps->a == NULL) {
            printf("申请失败");
            exit(-1);
        }
    }
    ps->a[ps->size] = x;
    ps->size++;
}
void SeqListPushFront(SL* ps, SLDateType x)
{
    assert(ps);
    void SeqListCheckCapacity(SL * ps);
    int end = ps->size - 1;
    while(end>=0){
    ps->a[end + 1] = ps->a[end];
    end--;
   }
    ps->a[0] = x;
    ps->size++;
}
void SeqListPopFront(SL* ps)
{
    assert(ps);
    int start = ps->a[0];
    while (start < ps->size - 1) {
        ps->a[start] = ps->a[start + 1];
            start++;
    }
    ps->size--;
}
void SeqListPopBack(SL* ps)
{
    assert(ps);
    ps->size--;
}
void SeqListInsert(SL* ps, size_t pos, SLDateType x) {
    assert(ps);
    void SeqListCheckCapacity(SL * ps);
    int end = ps->size;
    while (end >= pos) {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}
void SeqListErase(SL* ps, size_t pos) {
    assert(ps);
    int site = ps->a[pos];
    while (site < ps->size-1) {
        ps->a[site] = ps->a[site + 1];
        site++;
    }
    ps->size--;
}
int SeqListFind(SL* ps, SLDateType x) {
    assert(ps);
    int start = ps->a[0];
    int Long = ps->size;
    int state = 0;
     while (Long) {
         if (ps->a[start] == x) {
             return start;
             state= 1;
             break;
         }
         start++;
         Long--;
     }
     if (state == 0) {
         return -1;
     }
   
}
void SeqListDestory(SL* ps) {
    assert(ps);
    free(ps->a);
    ps->size = 0;
    ps->capacity = 0;
    ps->a = NULL;
}