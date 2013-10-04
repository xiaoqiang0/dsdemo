#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "SearchThds.h"
int array_size = ARRAY_SIZE;
/* TSearchThread */
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TSearchThread::TSearchThread(TSearchArrary &SearchArray, AnsiString SearchType)
: TThread(false)
{
    FSize = array_size;
    SearchName = SearchType;
    for(int i=0; i<FSize; ++i) {
        FSearchArray[i] = SearchArray[i];
    }
    FreeOnTerminate = true;
}

void __fastcall TSearchThread::Search(TSearchArrary &A)
{}

void __fastcall TSearchThread::Execute()
{
    TThread::NameThreadForDebugging((AnsiString)ClassName());
    Search(FSearchArray);
}

/*二分查找算法*/
__fastcall TBinarySearchThread::TBinarySearchThread(TSearchArrary &SearchArray, AnsiString SearchType)
:TSearchThread(SearchArray,SearchType)
{

}

void __fastcall TBinarySearchThread::swap(int i, int j)
{
    int t = FSearchArray[i];
    FSearchArray[i] = FSearchArray[j];
    FSearchArray[j] = t;
}
void __fastcall TBinarySearchThread::qsort(int l, int u)
{
    int i, j;
    int t;
    int *x = FSearchArray;
    if (l >= u)
        return;
    t = x[l];
    i = l;
    j = u+1;
    for (;;) {
        do {i++; sort_count++;} while (i <= u && x[i] < t);
        do {j--; sort_count++;} while (x[j] > t);
        if (i > j)
            break;
        swap(i, j);
    }
    swap(l, j);
    qsort(l, j-1);
    qsort(j+1, u);
}

void __fastcall TBinarySearchThread::Search(TSearchArrary &A)
{
    int i, t;
    int l, u, m;
    sort_count = 0;
    count = 0;
    qsort(0, FSize-1);
    for (i = 0; i < FSize; i++) {
        t = FSearchArray[i];
        l = 0;
        u = FSize-1;
        for (;;) {
            if (l > u)
                break;
            m = (l + u) / 2;
            if (FSearchArray[m] < t){
                count += 1;
                l = m+1;
            } else if (FSearchArray[m] == t){
                count += 2;
                break;
            } else { /* x[m] > t */
                count += 2;
                u = m-1;
            }
        }
    }
    count = (count + sort_count )  / FSize ;
}
//顺序查找
__fastcall TSequentialSearchThread::TSequentialSearchThread(TSearchArrary &SearchArray, AnsiString SearchType)
:TSearchThread(SearchArray,SearchType)
{

}
void __fastcall TSequentialSearchThread::Search(TSearchArrary &A)
{
    count = 0;
    int *x = FSearchArray;
    for (int i = 0; i < FSize; i++) {
        int t = x[i];
        for (i = 0; i < FSize; i++){
            count ++;
            if (x[i] == t)
                break;
        }
    }
    count = count / FSize;

}

//二分优化查找
__fastcall TBinarySearchThread_opt::TBinarySearchThread_opt(TSearchArrary &SearchArray, AnsiString SearchType)
    :TBinarySearchThread(SearchArray,SearchType)
{}


void __fastcall TBinarySearchThread_opt::Search(TSearchArrary &A)
{
    int i, t;
    int l, u, m;
    int *x = FSearchArray;
    sort_count = 0;
    count = 0;
    qsort(0, FSize-1);
    for (i = 0; i < FSize; i++) {
        t = x[i];
        l = -1;
        u = FSize;
        while (l+1 != u) {
            count++;
            m = (l + u) / 2;
            if (x[m] < t)
                l = m;
            else
                u = m;
        }
        //if (u >= n || x[u] != t)
        //    return -1;
    }
    count = (count + sort_count )  / FSize ;
}
