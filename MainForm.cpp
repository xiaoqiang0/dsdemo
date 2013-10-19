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
#include "ds_flash.h"
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
    AnsiString weeks [] = {"������", "����һ", "���ڶ�","������", "������",
                           "������", "������"};

    main_StatusBar->Panels->Items[1]->Text = \
                 FormatDateTime("yyyy �� mm ��dd �� hh:mm:ss     ", datetime) +\
                 weeks[DayOfWeek (datetime) - 1];
    datetime.DecodeTime(&hour, &min, &sec, &msec) ;
    main_StatusBar->Panels->Items[0]->Text = "��³ʦ��ѧԺ �����ϵ";
    //FloatToStr(CompToDouble(TimeStampToMSecs(DateTimeToTimeStamp(datetime))));
}

//---------------------------------------------------------------------------
void __fastcall Tdsdemo_MainForm::FormResize(TObject *Sender)
{

    main_StatusBar->Panels->Items[0]->Width = dsdemo_MainForm->Width - 260;
    main_StatusBar->Panels->Items[1]->Width = 260;
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


void __fastcall Tdsdemo_MainForm::FormCreate(TObject *Sender)
{
     AppPath = ExtractFileDir (Application->ExeName);
	 TSearchRec sr;

     imgidx = 0;
	//����ͼƬ�ļ�
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


void __fastcall Tdsdemo_MainForm::Image1DblClick(TObject *Sender)
{
     Image1->Picture->LoadFromFile(AppPath + "\\data\\" + flist[(imgidx++) % flist.size()]);
}
//---------------------------------------------------------------------------


void __fastcall Tdsdemo_MainForm::arrayinsert_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "��������������", "\\DSDemo_list\\arrayinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::arrayfind_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "����������Ҳ���", "\\DSDemo_list\\arrayfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::arraydelete_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "��������ɾ������", "\\DSDemo_list\\arraydelete.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::disarrayinsert_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "��������������", "\\DSDemo_list\\disarrayinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::disarrayfind_ActionExecute(TObject *Sender)
{
      ShowFlashDemo(this, "����������Ҳ���", "\\DSDemo_list\\disarrayfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::disarraydelete_ActionExecute(TObject *Sender)
{
      ShowFlashDemo(this, "��������ɾ������", "\\DSDemo_list\\disarraydelete.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::listinsert_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "������Ĳ������", "\\DSDemo_list\\listinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::listfind_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "������Ĳ��Ҳ���", "\\DSDemo_list\\listfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::listdelete_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "�������ɾ������", "\\DSDemo_list\\listdelete.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::dlistinsert_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "˫������Ĳ������", "\\DSDemo_list\\dlistinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::dlistfind_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "˫������Ĳ��Ҳ���", "\\DSDemo_list\\dlistfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::dlistdelete_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "˫�������ɾ������", "\\DSDemo_list\\dlistdelete.swf");
}
//---------------------------------------------------------------------------


void __fastcall Tdsdemo_MainForm::stackarray_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "ջ�������ʾ", "\\DSDemo_stack\\stackarray.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::stacklist_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "ջ�������ʾ", "\\DSDemo_stack\\stacklink.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::stackfunc_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "ջ�Ĳ���", "\\DSDemo_stack\\stackfunc.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuearray_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "���е������ʾ", "\\DSDemo_queue\\queuearray.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuelist_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "���е������ʾ", "\\DSDemo_queue\\queuelink.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuelinkinsert_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "���еĲ���", "\\DSDemo_queue\\queuelinkinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuelinkdel_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "���е�ɾ��", "\\DSDemo_queue\\queuelinkdel.swf");
}
//---------------------------------------------------------------------------


