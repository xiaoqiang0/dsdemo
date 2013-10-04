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
//---------------------------------------------------------------------------
class TBinarySearchForm : public TForm
{
__published:	// IDE-managed Components
    TButton *Button2;
    TRadioGroup *RadioGroup1;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TChart *Chart1;
    TBarSeries *BarSeries1;
    TPanel *Panel1;
    TListBox *ListBox1;
    TButton *Button1;
    TLabel *Label1;
    TComboBox *ComboBox1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TBinarySearchForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBinarySearchForm *BinarySearchForm;
//---------------------------------------------------------------------------
#endif
