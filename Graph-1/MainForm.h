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
    TMenuItem *N12;
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
    TMenuItem *N20;
    TMenuItem *N21;
    TLabel *welcomeLabel;
    TTimer *Timer1;
    TMenuItem *N22;
    TMenuItem *N23;
    void __fastcall N7Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall date_TimerTimer(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall N18Click(TObject *Sender);
    void __fastcall SortCompareTBtnClick(TObject *Sender);
    void __fastcall N21Click(TObject *Sender);
    void __fastcall N22Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tdsdemo_MainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdsdemo_MainForm *dsdemo_MainForm;
//---------------------------------------------------------------------------
#endif
