//---------------------------------------------------------------------------
#ifndef cd8_3uH
#define cd8_3uH
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
class TForm1 : public TForm
{
    __published:	// IDE-managed Components
        TPanel *pnl; //���ռ�
        TImage *img; //ͼ��
        TGroupBox *GroupBox1;
        TButton *CreateNodeBt;
        TButton *ShortestPathBt;
        TRadioGroup *GraphType;
        TRadioButton *DirectBt;
        TRadioButton *NoDirectBt;
        TMemo *memo;
        TPageControl *PageControl;
        TTabSheet *TabSheetDirect;
        TTabSheet *TabSheetNoDirect;
        TButton *ResetBt;
        TGroupBox *GroupBox2;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        void __fastcall CreateNodeBtClick(TObject *Sender);   //���ɶ��㰴ť�������
        void __fastcall ShortestPathBtClick(TObject *Sender);   //���·����ť�������
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);    //��갴�º���
        void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);
        void __fastcall BtClearMemoClick(TObject *Sender);
        void __fastcall NoDirectBtClick(TObject *Sender);
        void __fastcall DirectBtClick(TObject *Sender);
        void __fastcall ResetBtClick(TObject *Sender);
    void __fastcall PageControlChange(TObject *Sender);



    private:	        // User declarations
    public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
