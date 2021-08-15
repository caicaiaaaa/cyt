BinTree Delete( BinTree BST, ElementType X )
{
    if(BST == NULL)
    {
        printf("Not Found\n");
        return BST;
    }
    else if(BST->Data == X)
    {
        if(BST->Left!=NULL &&BST->Right!=NULL)
        {
            BinTree p = FindMax(BST->Left);
            p->Right = BST->Right;
            p = BST->Left;
            free(BST);
            return p;
        }
        else if(BST->Left!=NULL && BST->Right == NULL)
        {
            BinTree p = BST->Left;
            free(BST);
            return p;
        }
        else if(BST->Right!=NULL && BST->Left == NULL)
        {
            BinTree p = BST->Right;
            free(BST);
            return p;
        }
        else if((BST->Left!=NULL)&&(BST->Right == NULL))
        {
            BinTree p =BST;
            free(P);
            return NULL;
        }
    }
    else if(X < BST->Data)
    {
        BST->Left = Delete(BST->Left,X);
        return BST;
    }
    else if(X>BST->Data)
    {
        BST->Right = Delete(BST->Right,X);
        return BST;
    }
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(BST == NULL)
    {
        BST = (BinTree)malloc(sizeof(Position));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else if(X > BST->Data)
        BST->Right = Insert(BST->Right,X);
    else if(X<BST->Data)
        BST->Left = Insert(BST->Left,X);
    return BST;
}





























