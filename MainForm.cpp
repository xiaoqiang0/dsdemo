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
    AnsiString weeks [] = {"星期日", "星期一", "星期二","星期三", "星期四",
                           "星期五", "星期六"};

    main_StatusBar->Panels->Items[1]->Text = \
                 FormatDateTime("yyyy 年 mm 月dd 日 hh:mm:ss     ", datetime) +\
                 weeks[DayOfWeek (datetime) - 1];
    datetime.DecodeTime(&hour, &min, &sec, &msec) ;
    main_StatusBar->Panels->Items[0]->Text = "齐鲁师范学院 计算机系";
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


void __fastcall Tdsdemo_MainForm::Image1DblClick(TObject *Sender)
{
     Image1->Picture->LoadFromFile(AppPath + "\\data\\" + flist[(imgidx++) % flist.size()]);
}
//---------------------------------------------------------------------------


void __fastcall Tdsdemo_MainForm::arrayinsert_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "有序数组插入操作", "\\DSDemo_list\\arrayinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::arrayfind_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "有序数组查找操作", "\\DSDemo_list\\arrayfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::arraydelete_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "有序数组删除操作", "\\DSDemo_list\\arraydelete.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::disarrayinsert_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "无序数组插入操作", "\\DSDemo_list\\disarrayinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::disarrayfind_ActionExecute(TObject *Sender)
{
      ShowFlashDemo(this, "无序数组查找操作", "\\DSDemo_list\\disarrayfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::disarraydelete_ActionExecute(TObject *Sender)
{
      ShowFlashDemo(this, "无序数组删除操作", "\\DSDemo_list\\disarraydelete.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::listinsert_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "单链表的插入操作", "\\DSDemo_list\\listinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::listfind_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "单链表的查找操作", "\\DSDemo_list\\listfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::listdelete_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "单链表的删除操作", "\\DSDemo_list\\listdelete.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::dlistinsert_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "双向链表的插入操作", "\\DSDemo_list\\dlistinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::dlistfind_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "双向链表的查找操作", "\\DSDemo_list\\dlistfind.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::dlistdelete_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "双向链表的删除操作", "\\DSDemo_list\\dlistdelete.swf");
}
//---------------------------------------------------------------------------


void __fastcall Tdsdemo_MainForm::stackarray_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "栈的数组表示", "\\DSDemo_stack\\stackarray.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::stacklist_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "栈的链表表示", "\\DSDemo_stack\\stacklink.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::stackfunc_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "栈的操作", "\\DSDemo_stack\\stackfunc.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuearray_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "队列的数组表示", "\\DSDemo_queue\\queuearray.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuelist_ActionExecute(TObject *Sender)
{
     ShowFlashDemo(this, "队列的链表表示", "\\DSDemo_queue\\queuelink.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuelinkinsert_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "队列的插入", "\\DSDemo_queue\\queuelinkinsert.swf");
}
//---------------------------------------------------------------------------

void __fastcall Tdsdemo_MainForm::queuelinkdel_ActionExecute(TObject *Sender)
{
    ShowFlashDemo(this, "队列的删除", "\\DSDemo_queue\\queuelinkdel.swf");
}
//---------------------------------------------------------------------------


