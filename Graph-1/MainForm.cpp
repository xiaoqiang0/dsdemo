//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "graph_alg_u.h"
#include "graph_intro_u.h"
#include "SortThds.h"
#include "ThSort.h"
#include "search_string.h"
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
void __fastcall Tdsdemo_MainForm::N7Click(TObject *Sender)
{
     //调用图算法
     GraphAlgorithmForm->ShowModal();
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

     main_StatusBar->Panels->Items[1]->Text = FormatDateTime("yyyy 年 mm 月dd 日 hh:mm:ss", datetime);
     main_StatusBar->Panels->Items[0]->Text = "xyz";
//     main_StatusBar->Panels->Items[0]->Text = FloatToStr(datetime.Val * 100000);
}
//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::N6Click(TObject *Sender)
{
     //
     graph_intro_frm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::FormResize(TObject *Sender)
{

     //DateToStr
     //Image
     main_StatusBar->Panels->Items[0]->Width = dsdemo_MainForm->Width - 200;
     main_StatusBar->Panels->Items[1]->Width = 200;
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N18Click(TObject *Sender)
{
     ThreadSortForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::ToolButton1Click(TObject *Sender)
{
    ThreadSortForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N21Click(TObject *Sender)
{
     search_stringForm->ShowModal();
}
//---------------------------------------------------------------------------

