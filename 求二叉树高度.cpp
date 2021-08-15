int GetHeight(BinTree BT)
{
    int cnt = 0;
    if(BT)
    {
        int l,r;
        l = GetHeight(BT->Left);
        r = GetHeight(BT->Right);
        if(l>r)
            cnt = l+1;
        else
            cnt = r+1;
    }
    return cnt;
}
