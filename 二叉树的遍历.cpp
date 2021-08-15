void InorderTraversal( BinTree BT )
{
    if(BT == NULL)
    {
        return;
    }
    InorderTraversal(BT->Left);
    printf("%c",BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal( BinTree BT )
{
    if(BT==NULL)
    {
        return;
    }
    printf("%c",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal( BinTree BT ){
    if(BT==NULL){
        return;
    }
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c",BT->Data);
}

void LevelorderTraversal( BinTree BT )
{
    if(BT==NULL)
    {
        return;
    }
    BinTree queue[10],a;
    int front=0,rear=0;
    queue[rear]=BT;
    rear=(rear+1)%10;
    while(rear-front)
    {
        a=queue[front];
        front=(front+1)%10;
        printf("%c",a->Data);
        if(a->Left)
        {
            queue[rear]=a->Left;
            rear = (rear+1)%10;
        }
        if(a->Right)
        {
            queue[rear]=a->Right;
            rear=(rear+1)%10;
        }
    }
}














