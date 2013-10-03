//---------------------------------------------------------------------------

#ifndef binary_searchH
#define binary_searchH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TBinarySearchForm : public TForm
{
__published:	// IDE-managed Components
    TListBox *ListBox1;
    TListBox *ListBox2;
    TButton *Button2;
    TButton *Button1;
private:	// User declarations
public:		// User declarations
    __fastcall TBinarySearchForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBinarySearchForm *BinarySearchForm;
//---------------------------------------------------------------------------
#endif
