//---------------------------------------------------------------------------

#ifndef binary_searchH
#define binary_searchH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include "SearchThds.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TBinarySearchForm : public TForm
{
__published:	// IDE-managed Components
    TChart *Chart1;
    TBarSeries *BarSeries1;
    TPanel *Panel1;
    TListBox *ListBox1;
    TButton *Button1;
    TComboBox *ComboBox1;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TPanel *Panel2;
    TPanel *Panel3;
    TGroupBox *GroupBox1;
    TPanel *Panel4;
    TGroupBox *GroupBox2;
    TCheckBox *ThreeDCheckBox;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TSavePictureDialog *SavePictureDialog1;
    TBitBtn *BitBtn4;
    TBitBtn *BitBtn9;
    TBitBtn *BitBtn3;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ThreeDCheckBoxClick(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall BitBtn4Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall BitBtn9Click(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
private:	// User declarations
    void __fastcall ThreadDone(TObject *Sender);
public:		// User declarations
    __fastcall TBinarySearchForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBinarySearchForm *BinarySearchForm;
//---------------------------------------------------------------------------
#endif
