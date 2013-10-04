//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <random>
#include "binary_search.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBinarySearchForm *BinarySearchForm;
#define MAXN 10000

typedef int DataType;

DataType x[MAXN];
int n = MAXN;

//---------------------------------------------------------------------------
__fastcall TBinarySearchForm::TBinarySearchForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBinarySearchForm::Button1Click(TObject *Sender)
{
                for (int i = 0; i < n; i++){
                        x[i] = i;
                        ListBox1->Items->Add(x[i]);
                }

}
//---------------------------------------------------------------------------

