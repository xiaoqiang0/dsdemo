//---------------------------------------------------------------------------
// Copyright (c) 1995-2010 Embarcadero Technologies, Inc.

// You may only use this software if you are an authorized licensee
// of Delphi, C++Builder or RAD Studio (Embarcadero Products).
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ThSort.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TThreadSortForm *ThreadSortForm;

bool ArraysRandom;
TSortArray BubbleSortArray;
TSortArray SelectionSortArray;
TSortArray QuickSortArray;
extern int N;
/* TThreadSortForm */
//---------------------------------------------------------------------------
TDateTime start_time;



__fastcall TThreadSortForm::TThreadSortForm(TComponent *AOwner)

:TForm(AOwner)

{

}


//---------------------------------------------------------------------------

void __fastcall TThreadSortForm::PaintArray(TPaintBox *Box, TSortArray &A, TColor color)
{
    Box->Canvas->Pen->Color = color;
    for(int i = 0; i < N - 1; ++i)
        PaintLine(Box, i, A[i]);
}

//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::BubbleSortBoxPaint(TObject *)
{
    PaintArray(BubbleSortBox, BubbleSortArray, clGreen);
}

//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::SelectionSortBoxPaint(TObject *)
{
    PaintArray(SelectionSortBox, SelectionSortArray, clRed);
}

//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::QuickSortBoxPaint(TObject *)
{
    PaintArray(QuickSortBox, QuickSortArray, clBlue);
}

//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::FormCreate(TObject *)
{
    RandomizeArrays();
    ComboBox1->Items->Clear();
    for (int i = 32; i <= 512; i = i + 48) {
         ComboBox1->Items->Add(IntToStr(i));
    }
    ComboBox1->ItemIndex = ComboBox1->GetCount() / 2;
}

//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::StartBtnClick(TObject *)
{
    RandomizeArrays();
    ThreadsRunning = 3;
    start_time = Now();

    TSelectionSort *SelectionSort = new TSelectionSort(SelectionSortBox, SelectionSortArray, clRed);
    SelectionSort->OnTerminate = ThreadDone;
    TBubbleSort *BubbleSort = new TBubbleSort(BubbleSortBox, BubbleSortArray, clGreen);
    BubbleSort->OnTerminate = ThreadDone;
    TQuickSort *QuickSort = new TQuickSort(QuickSortBox, QuickSortArray, clBlue);
    QuickSort->OnTerminate = ThreadDone;
    StartBtn->Enabled = false;
}

//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::RandomizeArrays()
{
    if( ! ArraysRandom ) {
        Randomize();
        for(int i = 0; i < ASize(BubbleSortArray); ++i) {
            BubbleSortArray[i] = Random(N - 1);
            SelectionSortArray[i] = BubbleSortArray[i];
            QuickSortArray[i] = BubbleSortArray[i];
        }
        ArraysRandom = true;
        Repaint();
    }
}

static long int get_msec(unsigned short hour, unsigned short min, unsigned short sec, unsigned short msec)
{
       return msec + sec * 1000 + min * 1000 * 60 + hour * 1000 * 60 * 60;
}
//---------------------------------------------------------------------------
void __fastcall TThreadSortForm::ThreadDone(TObject *)
{
    TDateTime end_time = Now();
    unsigned short hour, min, sec, msec;
    long int start_msec = 0;
    long int end_msec =  0;
    start_time.DecodeTime(&hour, &min, &sec, &msec);
    start_msec = get_msec(hour, min, sec, msec);
    end_time.DecodeTime(&hour, &min, &sec, &msec);
    end_msec = get_msec(hour, min, sec, msec);

    switch (ThreadsRunning) {
        case 1:
            Bubble_Series->AddXY(N, (end_msec - start_msec) / 10.0);
            break;
        case 2:
            Select_Series->AddXY(N, (end_msec - start_msec) / 10.0);
            break;
        case 3:
            Quick_Series->AddXY(N, (end_msec - start_msec) / 10.0);
            break;
        default:
            ;
    }
    ThreadsRunning--;
    if( ThreadsRunning == 0 ) {

        StartBtn->Enabled = true;
        ArraysRandom = false;
    }

}

void __fastcall TThreadSortForm::ComboBox1Change(TObject *Sender)
{
    N = StrToInt(ComboBox1->Text);
    ArraysRandom = false;
    RandomizeArrays();
}
//---------------------------------------------------------------------------

void __fastcall TThreadSortForm::saveChartBtnClick(TObject *Sender)
{
     if(SaveDialog1->Execute()){
         if (FileExists(SaveDialog1->FileName))
            DeleteFile(SaveDialog1->FileName);
         Chart1->SaveToBitmapFile(SaveDialog1->FileName);
     }
}
//---------------------------------------------------------------------------


void __fastcall TThreadSortForm::Button1Click(TObject *Sender)
{
/*     //
     ComboBox1->DropDownCount;
     for (int i = 0; i < ComboBox1->GetCount(); i++) {
         ComboBox1->ItemIndex = i;
         ComboBox1->OnChange(ComboBox1);
         StartBtn->Click();
         StartBtn->Enabled = False;
         while (1) {

         if (StartBtn->Enabled == True) {
             break;
             Sleep(1000);
         }
          Sleep(1000);
         }

         Sleep(2000);
         if (i == 3)
           break;

     }
*/
}
//---------------------------------------------------------------------------

