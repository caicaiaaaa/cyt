List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
Position Find( List L, ElementType X )
{
    L =L->Next;
    while(L)
    {
        if(L->Data == X)
            return L;
        L=L->Next;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P )
{
    List p = (List)malloc(sizeof(List));
    p->Data = X;
    p->Next = NULL;
    List t = L;
    while(t)
    {
        if(t->Next==P)
        {
            p->Next = P;
            t->Next = p;
            return true;
        }
        t = t->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}
bool Delete( List L, Position P )
{
    if(L ==P)
    {
        L = L->Next;
        return true;
    }
    while(L)
    {
        if(L->Next == P)
        {
            L->Next =P->Next;
            return true;
        }
        L =L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}
