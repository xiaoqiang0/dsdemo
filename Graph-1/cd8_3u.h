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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *pnl; //���ռ�
    TImage *img; //ͼ��
    TGroupBox *GroupBox1;
    TGroupBox *gb;//���������ı���
	TButton *ct;//���ɶ��㰴ť
	TButton *ph;//���·����ť
    TBitBtn *pct;
    TBitBtn *del;
    TBitBtn *cle;
    TBevel *Bevel1;
    TImage *img1;
	void __fastcall ctClick(TObject *Sender);   //���ɶ��㰴ť�������
	void __fastcall phClick(TObject *Sender);   //���·����ť�������
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
			TShiftState Shift, int X, int Y);    //��갴�º���
	void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
			TShiftState Shift, int X, int Y);    //��굯����

	//���º���ʽ���幦�ܰ�ť����������¼�����
    void __fastcall cleClick(TObject *Sender);
    void __fastcall pctClick(TObject *Sender);
    void __fastcall delClick(TObject *Sender);
    void __fastcall img1MouseDown(TObject *Sender, TMouseButton Button,
            TShiftState Shift, int X, int Y);
    void __fastcall img1MouseMove(TObject *Sender, TShiftState Shift,
            int X, int Y);
    void __fastcall img1MouseUp(TObject *Sender, TMouseButton Button,
            TShiftState Shift, int X, int Y);


    private:	        // User declarations
    public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
