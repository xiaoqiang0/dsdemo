//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "graph_shortest_path.h"
#include "graph_intro.h"
#include "SortThds.h"
#include "ThSort.h"
#include "search_string.h"
#include "graph_traverse.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tdsdemo_MainForm *dsdemo_MainForm;
//---------------------------------------------------------------------------
__fastcall Tdsdemo_MainForm::Tdsdemo_MainForm(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::N2Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::date_TimerTimer(TObject *Sender)
{
     TDateTime datetime = Now();
     unsigned short hour, min, sec, msec;

     main_StatusBar->Panels->Items[1]->Text = FormatDateTime("yyyy 年 mm 月dd 日 hh:mm:ss", datetime);
     datetime.DecodeTime(&hour, &min, &sec, &msec) ;
     main_StatusBar->Panels->Items[0]->Text = IntToStr(sec * 1000 + msec);
     //FloatToStr(CompToDouble(TimeStampToMSecs(DateTimeToTimeStamp(datetime))));
}

//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::N6Click(TObject *Sender)
{

     GraphIntroduceForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::N22Click(TObject *Sender)
{
     GraphTraverseForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N7Click(TObject *Sender)
{
     //调用图算法
     GraphAlgorithmForm->ShowModal();
}

//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::FormResize(TObject *Sender)
{

     main_StatusBar->Panels->Items[0]->Width = dsdemo_MainForm->Width - 200;
     main_StatusBar->Panels->Items[1]->Width = 200;
     welcomeLabel->Left = dsdemo_MainForm->Width/2 - welcomeLabel->Width / 2;
     welcomeLabel->Top = dsdemo_MainForm->Height/4 ;
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N18Click(TObject *Sender)
{
     ThreadSortForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::SortCompareTBtnClick(TObject *Sender)
{
    ThreadSortForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N21Click(TObject *Sender)
{
     search_stringForm->ShowModal();
}
//---------------------------------------------------------------------------







