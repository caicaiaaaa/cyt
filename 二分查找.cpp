Position BinarySearch( List L, ElementType X )
{
    int low,mid,high;
    low=1;high=L->Last;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(L->Data[mid]==X)
        {
            return mid;
        }
        else if(L->Data[mid]<X)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return NotFound;
}
