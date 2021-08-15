Stack CreateStack(int MaxSize)
{
    Stack s = (Stack)malloc(sizeof(Stack));
    s->Data = (ElementType *)malloc(sizeof(ElementType)*MaxSize);
    s->MaxSize = MaxSize;
    s->Top1 = -1;
    s->Top = MaxSize;
    return s;
}

bool Push(Stack S, ElementType X, int Tag)
{
    if(S->Top-s->Top==1)
    {
        printf("Stack Full\n");
        return false;
    }
    if(Tag==1)
    S->Data[++]
}
