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
#include "binary_search.h"
#include "graph_MST.h"
#include "tree_BiTree.h"
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
void __fastcall Tdsdemo_MainForm::FormResize(TObject *Sender)
{

    main_StatusBar->Panels->Items[0]->Width = dsdemo_MainForm->Width - 200;
    main_StatusBar->Panels->Items[1]->Width = 200;
    welcomeLabel->Left = dsdemo_MainForm->Width/2 - welcomeLabel->Width / 2;
    welcomeLabel->Top = dsdemo_MainForm->Height/4 ;
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N6Click(TObject *Sender)
{

    GraphIntroduceForm->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tdsdemo_MainForm::N21Click(TObject *Sender)
{
    search_stringForm->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tdsdemo_MainForm::tree_BiTree_ActionExecute(TObject *Sender)
{
    BiTreeForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::graph_MST_ActionExecute(TObject *Sender)
{
    GraphMSTForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::graph_traverse_ActionExecute(TObject *Sender)
{
    GraphTraverseForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::graph_shortest_path_ActionExecute(TObject *Sender)

{
    GraphAlgorithmForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::search_BinarySearch_ActionExecute(TObject *Sender)

{
    BinarySearchForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::sort_compare_ActionExecute(TObject *Sender)
{
    ThreadSortForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::Image1Click(TObject *Sender)
{
     Image1->Picture->LoadFromFile(AppPath + "\\data\\" + flist[(imgidx++) % flist.size()]);
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::FormCreate(TObject *Sender)
{
     AppPath = ExtractFileDir (Application->ExeName);
	 TSearchRec sr;

     imgidx = 0;
	//查找图片文件
	if (FindFirst(AppPath+"\\data\\*.jpg", faAnyFile, sr) == 0) {
		do {
                flist.push_back(sr.Name);
		} while (FindNext(sr) == 0);
		FindClose(sr);
	}
    Image1->Picture->LoadFromFile(AppPath + "\\data\\" + flist[imgidx++]);
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::N25Click(TObject *Sender)
{
      Image1->Picture->LoadFromFile(AppPath + "\\data\\" + flist[(imgidx++) % flist.size()]);
}
//---------------------------------------------------------------------------

