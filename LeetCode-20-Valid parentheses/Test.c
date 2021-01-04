//动态栈(数组）（可动态增容）
typedef char STDataType;
typedef struct Stack
{
    STDataType* a;
    int  top;//栈顶下标
    int  capacity;
}Stack;

// 初始化栈 
void StackInit(Stack* ps);
// 入栈 
void StackPush(Stack* ps, STDataType data);
// 出栈 
void StackPop(Stack* ps);
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);

//栈的初始化
void StackInit(Stack* ps)
{
    ps->a = malloc(sizeof(STDataType) * 4);
    ps->top = 0;
    ps->capacity = 4;
}
//入栈
void StackPush(Stack* ps, STDataType data)
{
    assert(ps);
    if (ps->top == ps->capacity) {
        ps->capacity *= 2;
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity);
        if (tmp == NULL) {
            printf("申请失败！");
            exit(-1);
        }
        else
            ps->a = tmp;
    }
    ps->a[ps->top] = data;
    ps->top++;
}

// 出栈 
void StackPop(Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    --ps->top;
}
//获取栈中个数
int StackSize(Stack* ps)
{
    assert(ps);
    return ps->top;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
    assert(ps);
    if (ps->top == 0)
        return 1;
    else
        return 0;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}

bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    bool ret;
    while (*s != '\0')
    {
        if (*s == '(' || *s == '{' || *s == '[') {
            StackPush(&st, *s);
            ++s;
        }
        else
        {
            if (StackEmpty(&st)) {
                ret = false;
                break;
            }
            char Top = StackTop(&st);
            if (*s == ')' && Top != '(') {
                ret = false;
                break;
            }
            if (*s == '}' && Top != '{') {
                ret = false;
                break;
            }
            if (*s == ']' && Top != '[') {
                ret = false;
                break;
            }
            StackPop(&st);
            ++s;
        }
    }
    if (*s == '\0')
        ret = StackEmpty(&st);
    StackDestroy(&st);

    return ret;
}