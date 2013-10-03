//---------------------------------------------------------------------------
#ifndef graph_traverseH
#define graph_traverseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TGraphTraverseForm : public TForm
{
    __published:	// IDE-managed Components
        TPanel *pnl; //���ռ�
        TImage *img; //ͼ��
        TGroupBox *GroupBox1;
    TButton *CreateNodeBtn;
        TRadioGroup *GraphType;
    TRadioButton *DirectBtn;
    TRadioButton *NoDirectBtn;
    TButton *ResetBtn;
    TGroupBox *GroupBox2;
    TButton *TraverseBFSBtn;
    TButton *TraverseDFSBtn;
    TMemo *memo;
    TButton *Button4;
    TGroupBox *GroupBox3;
    TLabel *Label1;
    TComboBox *StartComboBox;
    TLabel *Label2;
    TComboBox *EndComboBox;
        void __fastcall my_print (String info);
        void __fastcall CreateNodeBtnClick(TObject *Sender);   //���ɶ��㰴ť�������

        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);    //��갴�º���
        void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);
        void __fastcall BtClearMemoClick(TObject *Sender);
        void __fastcall NoDirectBtnClick(TObject *Sender);
        void __fastcall DirectBtnClick(TObject *Sender);
        void __fastcall ResetBtnClick(TObject *Sender);
    void __fastcall TraverseDFSBtnClick(TObject *Sender);
    void __fastcall TraverseBFSBtnClick(TObject *Sender);



    private:	        // User declarations
    public:		// User declarations
        __fastcall TGraphTraverseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraphTraverseForm *GraphTraverseForm;
//---------------------------------------------------------------------------
#endif
