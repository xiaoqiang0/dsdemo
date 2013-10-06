//---------------------------------------------------------------------------
#ifndef graph_MSTH
#define graph_MSTH
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
class TGraphMSTForm : public TForm
{
    __published:	// IDE-managed Components
        TPanel *pnl; //���ռ�
        TImage *img; //ͼ��
        TGroupBox *GroupBox1;
    TButton *CreateNodeBtn;
    TButton *ResetBtn;
    TGroupBox *GroupBox2;
    TButton *PrimBtn;
    TButton *KruskalBtn;
    TMemo *memo;
    TPanel *Panel1;
    TPanel *Panel2;
        void __fastcall my_print (String info);
        void __fastcall CreateNodeBtnClick(TObject *Sender);   //���ɶ��㰴ť�������

        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);    //��갴�º���
        void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);
        void __fastcall BtClearMemoClick(TObject *Sender);
        void __fastcall ResetBtnClick(TObject *Sender);
    void __fastcall KruskalBtnClick(TObject *Sender);
    void __fastcall PrimBtnClick(TObject *Sender);



    private:	        // User declarations
    public:		// User declarations
        __fastcall TGraphMSTForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraphMSTForm *GraphMSTForm;
//---------------------------------------------------------------------------
#endif
