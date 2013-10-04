//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <random>
#include "binary_search.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBinarySearchForm *BinarySearchForm;
typedef int DataType;

TSearchArrary x;
static int c = 1;
//---------------------------------------------------------------------------
__fastcall TBinarySearchForm::TBinarySearchForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void scramble(int n)
{       int i, j;
        int t;
        for (i = n-1; i > 0; i--) {
                j = rand() % (i + 1);
                t = x[i]; x[i] = x[j]; x[j] = t;
        }
}

void __fastcall TBinarySearchForm::Button1Click(TObject *Sender)
{
                for (int i = 0; i < array_size; i++){
                        x[i] = i;
                }
                scramble(array_size);
                for (int i = 0; i < array_size; i++){
                        ListBox1->Items->Add(x[i]);
                }
                BitBtn9->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TBinarySearchForm::ThreadDone(TObject * obj)
{

    TColor color[8] = {
        clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua,
        clTeal, clWebRoyalBlue
    };
    TSearchThread * thread = (TSearchThread * )obj;
    //ShowMessage(IntToStr(thread->count));
    BarSeries1->AddXY(c*3, thread->count, thread->SearchName, color[c % 8]);
    c++;
}
void __fastcall TBinarySearchForm::ThreeDCheckBoxClick(TObject *Sender)
{
     Chart1->View3D = ThreeDCheckBox->Checked ;
}
//---------------------------------------------------------------------------

void __fastcall TBinarySearchForm::BitBtn2Click(TObject *Sender)
{
  BitBtn1->Enabled=false;
  BitBtn2->Enabled=false;
  Chart1->ZoomPercent(85);
  BitBtn1->Enabled=true;
  BitBtn2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TBinarySearchForm::BitBtn1Click(TObject *Sender)
{
  BitBtn1->Enabled=false;
  BitBtn2->Enabled=false;
  Chart1->ZoomPercent(115);
  BitBtn1->Enabled=true;
  BitBtn2->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TBinarySearchForm::BitBtn4Click(TObject *Sender)
{

     if(SavePictureDialog1->Execute()){
         if (FileExists(SavePictureDialog1->FileName))
            DeleteFile(SavePictureDialog1->FileName);
         Chart1->SaveToBitmapFile(SavePictureDialog1->FileName);
     }
}
//---------------------------------------------------------------------------

void __fastcall TBinarySearchForm::FormShow(TObject *Sender)
{
     BarSeries1->Clear();
     BitBtn9->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TBinarySearchForm::BitBtn9Click(TObject *Sender)
{
    c = 1;
    BarSeries1->Clear();

    if (CheckBox1->Checked == true) {
        TSequentialSearchThread *ssearch= new TSequentialSearchThread(x, "顺序查找");
        ssearch->OnTerminate = ThreadDone;
    }

    if (CheckBox2->Checked == true) {
        TBinarySearchThread  *bsearch= new TBinarySearchThread(x, "二分查找");
        bsearch->OnTerminate = ThreadDone;
    }

    if (CheckBox3->Checked == true) {
        TBinarySearchThread_opt *bsearch_opt= new TBinarySearchThread_opt(x, "二分查找优化");
        bsearch_opt->OnTerminate = ThreadDone;
    }
}
//---------------------------------------------------------------------------


