//---------------------------------------------------------------------------
#ifndef ThSortH
#define ThSortH


//---------------------------------------------------------------------------
#include <Windows.hpp>
#include <Messages.hpp>
#include <SysUtils.hpp>
#include <Variants.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include "SortThds.h"
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Data.DB.hpp>
#include <VCLTee.TeeData.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeeFunci.hpp>


//---------------------------------------------------------------------------
 class TThreadSortForm: public TForm
{
__published:	// IDE-managed Components
	TPaintBox *BubbleSortBox;
	TPaintBox *SelectionSortBox;
	TPaintBox *QuickSortBox;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TButton *StartBtn;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
    TChart *Chart1;
    TFastLineSeries *Bubble_Series;
    TAverageTeeFunction *TeeFunction2;
    TFastLineSeries *Select_Series;
    TAverageTeeFunction *TeeFunction3;
    TComboBox *ComboBox1;
    TLabel *Label4;
    TFastLineSeries *Quick_Series;
    TButton *saveChartBtn;
    TSaveDialog *SaveDialog1;
	void __fastcall StartBtnClick(TObject *Sender);
	void __fastcall BubbleSortBoxPaint(TObject *Sender);
	void __fastcall SelectionSortBoxPaint(TObject *Sender);
	void __fastcall QuickSortBoxPaint(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall saveChartBtnClick(TObject *Sender);
private: // User declarations
	int ThreadsRunning;
	void __fastcall RandomizeArrays();
	void __fastcall ThreadDone(TObject *Sender);
public:  // User declarations
	void __fastcall PaintArray(TPaintBox *Box, TSortArray &A, TColor color);
	__fastcall TThreadSortForm(TComponent *AOwner);
};

//---------------------------------------------------------------------------
extern PACKAGE   TThreadSortForm *ThreadSortForm;
extern int N;
//---------------------------------------------------------------------------

#endif

