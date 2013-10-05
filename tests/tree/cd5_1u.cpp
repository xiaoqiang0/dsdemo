//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>                      //ʹ��math����
#include "cd5_1u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int tree[32]={0};                  //�򵥵�������������,������ƺ�ɱ����״�ṹ
int a=1,i,l;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void create(int lv,int d,int i)          //���ӻ��½��Ĺ�������������ʱ����
{
   static int p[16];            //��̬������������p��������¼��Ӧ���߶εĶ˵�

   TShape *sp;                  //�����µ�Spape�ؼ�sp���趨������ֵ
   TColor color[5]={clWhite,clYellow,clLime,clBlue,clRed};      //���ý������ɫ
   sp=new TShape(Form1);
   sp->Parent=Form1->pn;     //�����¿ؼ������ڻ�����
   sp->Height=30;
   sp->Width=30;
   sp->Shape=stCircle;
   sp->Brush->Color=color[d];

   TLabel *lb;                 //���������µ�Label�ؼ�lb������������ֵ
   lb=new TLabel(Form1);
   lb->Parent=Form1->pn;
   lb->Height=20;
   lb->Width=30;
   lb->Transparent=true;         //����LabelΪ͸�����ڻ�����ֻ������
   lb->Caption=IntToStr(i);

   sp->Top=20+d*50;             //�趨�ؼ����ֵĶ���ֵ
   lb->Top=28+d*50;

   if(d==0)                    //���ÿؼ����ֵ����ֵ��ע��dΪ�¿ؼ����
   {
      sp->Left=245;          //���Ǹ��������
      lb->Left=255;
   }
   else
   {
      sp->Left=245-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));     //��pow()��η�
      lb->Left=255-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));      //lvΪ���λ��

      Form1->Image1->Canvas->MoveTo(p[lv/2],35+(d-1)*50);         //�߶��������
      Form1->Image1->Canvas->LineTo((sp->Left)+15,(sp->Top)+15);  //�߶��յ�����
   }

   Form1->lout->Caption="�� "+IntToStr(a)+" ������ֵ("+IntToStr(tree[lv])+"),"+
                         "λ�ڵ� "+IntToStr(d+1)+" ��";         //��������ȼ�1Ϊ����

   if(lv<16)
      p[lv]=(sp->Left)+15;             //���������λ�ü�¼��p����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::einKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   int d=0;                              //��ȳ�ʼֵ��Ϊ0
   if(Key==13)
   {
      i=StrToInt(ein->Text);
      l=1;                               //�����λ��Ϊ1(��������)
      if(a>1)
      {
         while(tree[l]!=0)              //�и�����ſɰ����ӽ��λַ
         {
            if(i<tree[l])               //�µ�����ֵ�Ƚ�С
            {
               l=l*2;                   //λ������������
               d++;                     //��ȼ�1
            }
            else                        //�µ�����ֵ�Ƚϴ�
            {
               l=l*2+1;                 //λ������������1��
               d++;
            }
         }
      }
      tree[l]=i;                       //����ֵ�������ض�����λ����
      if(d>=5)
         lout->Caption="�������ֵ���ڵ����֮��";
      else
         create(l,d,i);    //���ù���������ʾ�ؼ��ĺ���������λ��,��ȼ�����
      ein->Text="";
      a++;                 //����������1
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::endClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

