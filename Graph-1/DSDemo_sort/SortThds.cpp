
//---------------------------------------------------------------------------

// This software is Copyright (c) 2011 Embarcadero Technologies, Inc. 
// You may only use this software if you are an authorized licensee
// of Delphi, C++Builder or RAD Studio (Embarcadero Products).
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "SortThds.h"
int N = ARRAY_SIZE;

//---------------------------------------------------------------------------
void __fastcall PaintLine(TPaintBox *Box, int i, int len)
{
    int n = N;
    int h = Box->Height;
    int w = Box->Width;

    float y = h * 1.0 / n;
    float x = w * 1.0 / n;
    Box->Canvas->MoveTo(1, int(i * y)+1);
    Box->Canvas->LineTo(int(len * x)+1, int(i * y)+1);

}


//---------------------------------------------------------------------------

int ASize(TSortArray &A)

{
    printf("%d\n", N);
    return N;

}


/* TSortThread */

//---------------------------------------------------------------------------

void __fastcall TSortThread::Sort(TSortArray &)

{

}


//---------------------------------------------------------------------------

    __fastcall TSortThread::TSortThread(TPaintBox *Box, TSortArray &SortArray)
: TThread(false)
{
    FBox = Box;
    FSize = N;
    for(int i=0; i<FSize; ++i) {
        FSortArray[i] = SortArray[i];
    }
    FreeOnTerminate = true;
}

/* Since DoVisualSwap uses a VCL component (i.e., the TPaintBox) it should never
   be called directly by this thread.  DoVisualSwap should be called by passing
   it to the Synchronize method which causes DoVisualSwap to be executed by the
   main VCL thread, avoiding multi-thread conflicts. See VisualSwap for an
   example of calling Synchronize. */
//---------------------------------------------------------------------------

void __fastcall TSortThread::DoVisualSwap()
{
    FBox->Canvas->Pen->Color = clBtnFace;
    PaintLine(FBox, FI, FA);
    PaintLine(FBox, FJ, FB);
    FBox->Canvas->Pen->Color = clRed;
    PaintLine(FBox, FI, FB);
    PaintLine(FBox, FJ, FA);
}

/* VisusalSwap is a wrapper on DoVisualSwap making it easier to use.  The
   parameters are copied to instance variables so they are accessable
   by the main VCL thread when it executes DoVisualSwap */
//---------------------------------------------------------------------------

void __fastcall TSortThread::VisualSwap(int a, int b, int i, int j)
{
    FA = a;
    FB = b;
    FI = i;
    FJ = j;
    Synchronize(DoVisualSwap);
}

/* The Execute method is called when the thread starts */
//---------------------------------------------------------------------------

void __fastcall TSortThread::Execute()
{
    TThread::NameThreadForDebugging((AnsiString)ClassName());
    Sort(FSortArray);
}

/* TBubbleSort */
//---------------------------------------------------------------------------

__fastcall TBubbleSort::TBubbleSort(TPaintBox *Box, TSortArray &SortArray)

:TSortThread(Box,SortArray)

{

}


//---------------------------------------------------------------------------

void __fastcall TBubbleSort::Sort(TSortArray &A)
{
    for(int i = N-1; i > 0; --i)
        for(int j = 0; j < N - 1; ++j)
            if( A[j] > A[j + 1] )

            {
                VisualSwap(A[j], A[j + 1], j, j + 1);
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
                if( Terminated ) return;
            }
}

/* TSelectionSort */
//---------------------------------------------------------------------------

__fastcall TSelectionSort::TSelectionSort(TPaintBox *Box, TSortArray &SortArray)

:TSortThread(Box,SortArray)

{

}


//---------------------------------------------------------------------------

void __fastcall TSelectionSort::Sort(TSortArray &A)
{
    for(int i = 0; i < N - 2; i++)
        for(int j = N - 1; j > i + 1; j--)
            if( A[i] > A[j] )

            {
                VisualSwap(A[i], A[j], i, j);
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
                if( Terminated ) return;
            }
}

/* TQuickSort */
//---------------------------------------------------------------------------

__fastcall TQuickSort::TQuickSort(TPaintBox *Box, TSortArray &SortArray)

:TSortThread(Box,SortArray)

{

}


//---------------------------------------------------------------------------

void __fastcall TQuickSort::QuickSort(TSortArray &A, int iLo, int iHi)
{
    int Lo = iLo;
    int Hi = iHi;
    int Mid = A[(Lo + Hi) / 2];
    do {

        while( A[Lo] < Mid ) Lo++;
        while( A[Hi] > Mid ) Hi--;
        if( Lo <= Hi )

        {
            VisualSwap(A[Lo], A[Hi], Lo, Hi);
            int t = A[Lo];
            A[Lo] = A[Hi];
            A[Hi] = t;
            Lo++;
            Hi--;
        }
    } while(Lo <= Hi);
    if( Hi > iLo ) QuickSort(A, iLo, Hi);
    if( Lo < iHi ) QuickSort(A, Lo, iHi);
    if( Terminated ) return;
}

//---------------------------------------------------------------------------
void __fastcall TQuickSort::Sort(TSortArray &A)
{

    QuickSort(A, 0, N-1);

}

