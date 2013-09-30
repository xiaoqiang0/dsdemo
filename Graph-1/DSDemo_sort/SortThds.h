//---------------------------------------------------------------------------
#ifndef SortThdsH
#define SortThdsH


//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Graphics.hpp>
#include <ExtCtrls.hpp>

#define ARRAY_SIZE 512
typedef int TSortArray[ARRAY_SIZE];

//---------------------------------------------------------------------------

 class TSortThread: public TThread
{
__published:	// IDE-managed Components
private: // User declarations
	TPaintBox *FBox;
	TSortArray FSortArray;
	int FSize;

	int FA; int FB; int FI; int FJ;
	void __fastcall DoVisualSwap();
protected:  // User declarations
	void __fastcall Execute();
	void __fastcall VisualSwap(int A, int B, int I, int J);
	virtual void __fastcall Sort(TSortArray &A);
public:  // User declarations
    TColor LColor;
	__fastcall TSortThread(TPaintBox *Box, TSortArray &SortArray, TColor color);
};
//---------------------------------------------------------------------------


/* TBubbleSort */
//---------------------------------------------------------------------------

 class TBubbleSort: public TSortThread
{
__published:	// IDE-managed Components
protected:  // User declarations
	void __fastcall Sort( TSortArray &A);
public:
	__fastcall TBubbleSort(TPaintBox *Box,  TSortArray &SortArray, TColor color);
};
//---------------------------------------------------------------------------


/* TSelectionSort */
//---------------------------------------------------------------------------

 class TSelectionSort: public TSortThread
{
__published:	// IDE-managed Components
protected:  // User declarations
	void __fastcall Sort( TSortArray &A);
public:
	__fastcall TSelectionSort(TPaintBox *Box,  TSortArray &SortArray, TColor color);
};
//---------------------------------------------------------------------------


/* TQuickSort */
//---------------------------------------------------------------------------

 class TQuickSort: public TSortThread
{
__published:	// IDE-managed Components
protected:  // User declarations
	void __fastcall Sort( TSortArray &A);
	void __fastcall QuickSort(TSortArray &A, int iLo, int iHi);
public:
	__fastcall TQuickSort(TPaintBox *Box,  TSortArray &SortArray, TColor color);
};
//---------------------------------------------------------------------------


extern PACKAGE void __fastcall PaintLine(TPaintBox *Box, int I, int Len);
extern PACKAGE int ASize(TSortArray &A);
extern int N;

#endif

