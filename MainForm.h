//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ImgList.hpp>
#include <VCLTee.TeeDraw3D.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>

#include <vector>
using namespace std;
//---------------------------------------------------------------------------
class Tdsdemo_MainForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *xit1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TStatusBar *main_StatusBar;
    TTimer *date_Timer;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *N11;
    TMenuItem *N13;
    TMenuItem *N14;
    TToolBar *ToolBar1;
    TToolButton *SortCompareTBtn;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TImage *Image1;
    TImageList *ToolbarImageList;
    TMenuItem *N15;
    TMenuItem *N16;
    TMenuItem *N17;
    TMenuItem *N18;
    TMenuItem *N19;
    TMenuItem *N21;
    TLabel *welcomeLabel;
    TTimer *Timer1;
    TMenuItem *N22;
    TMenuItem *N23;
    TMenuItem *N24;
    TMenuItem *N20;
    TToolButton *ToolButton1;
    TActionList *ActionList1;
    TAction *tree_BiTree_Action;
    TAction *graph_MST_Action;
    TAction *graph_shortest_path_Action;
    TAction *graph_traverse_Action;
    TAction *search_BinarySearch_Action;
    TAction *sort_compare_Action;
    TToolButton *ToolButton5;
    TPopupMenu *PopupMenu1;
    TMenuItem *N25;
    TMenuItem *N26;
    TAction *arrayinsert_Action;
    TAction *arrayfind_Action;
    TAction *arraydelete_Action;
    TAction *disarrayinsert_Action;
    TAction *disarrayfind_Action;
    TAction *disarraydelete_Action;
    TMenuItem *N27;
    TMenuItem *N28;
    TMenuItem *N29;
    TMenuItem *N30;
    TMenuItem *N31;
    TMenuItem *N32;
    TMenuItem *N33;
    TMenuItem *N34;
    TMenuItem *N35;
    TAction *listinsert_Action;
    TAction *listfind_Action;
    TAction *listdelete_Action;
    TAction *dlistinsert_Action;
    TAction *dlistfind_Action;
    TAction *dlistdelete_Action;
    TMenuItem *N36;
    TMenuItem *N37;
    TMenuItem *N38;
    TMenuItem *N39;
    TMenuItem *N40;
    TMenuItem *N41;
    TAction *stackarray_Action;
    TAction *stacklist_Action;
    TAction *stackfunc_Action;
    TAction *queuearray_Action;
    TAction *queuelist_Action;
    TAction *queuelinkinsert_Action;
    TMenuItem *N42;
    TMenuItem *N43;
    TMenuItem *N44;
    TAction *queuelinkdel_Action;
    TMenuItem *N12;
    TMenuItem *N45;
    TMenuItem *N46;
    TMenuItem *N47;
    void __fastcall N2Click(TObject *Sender);
    void __fastcall date_TimerTimer(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall N21Click(TObject *Sender);
    void __fastcall tree_BiTree_ActionExecute(TObject *Sender);
    void __fastcall graph_MST_ActionExecute(TObject *Sender);
    void __fastcall graph_traverse_ActionExecute(TObject *Sender);
    void __fastcall graph_shortest_path_ActionExecute(TObject *Sender);
    void __fastcall search_BinarySearch_ActionExecute(TObject *Sender);
    void __fastcall sort_compare_ActionExecute(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall N25Click(TObject *Sender);
    void __fastcall Image1DblClick(TObject *Sender);
    void __fastcall arrayinsert_ActionExecute(TObject *Sender);
    void __fastcall arrayfind_ActionExecute(TObject *Sender);
    void __fastcall arraydelete_ActionExecute(TObject *Sender);
    void __fastcall disarrayinsert_ActionExecute(TObject *Sender);
    void __fastcall disarrayfind_ActionExecute(TObject *Sender);
    void __fastcall disarraydelete_ActionExecute(TObject *Sender);
    void __fastcall listinsert_ActionExecute(TObject *Sender);
    void __fastcall listfind_ActionExecute(TObject *Sender);
    void __fastcall listdelete_ActionExecute(TObject *Sender);
    void __fastcall dlistinsert_ActionExecute(TObject *Sender);
    void __fastcall dlistfind_ActionExecute(TObject *Sender);
    void __fastcall dlistdelete_ActionExecute(TObject *Sender);
    void __fastcall stackarray_ActionExecute(TObject *Sender);
    void __fastcall stacklist_ActionExecute(TObject *Sender);
    void __fastcall stackfunc_ActionExecute(TObject *Sender);
    void __fastcall queuearray_ActionExecute(TObject *Sender);
    void __fastcall queuelist_ActionExecute(TObject *Sender);
    void __fastcall queuelinkinsert_ActionExecute(TObject *Sender);
    void __fastcall queuelinkdel_ActionExecute(TObject *Sender);

private:	// User declarations
    AnsiString AppPath;
    vector <AnsiString> flist;
    int imgidx;
public:		// User declarations
    __fastcall Tdsdemo_MainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdsdemo_MainForm *dsdemo_MainForm;
//---------------------------------------------------------------------------
#endif
