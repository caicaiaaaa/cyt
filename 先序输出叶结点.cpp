void PreorderPrintLeaves( BinTree BT )
{
    if(BT!=NULL)
    {
        if(BT->Left==NULL&&BT->Right==NULL)
            printf("%c",BT->Data);
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}
