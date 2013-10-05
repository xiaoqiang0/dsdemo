//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "cd5_2u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct tree                          //����һ�ṹ����,���ƾͽ�tree
{
   int data;                         //��Ž������
   int left;                         //����������λ��
   int right;                        //����������λ��
};
typedef struct tree node;            //�����µ����ṹ
node t[31];                          //����ṹ����t
int i,idx,p,d,lv=1;
int dat=0,ts=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)     //����ʼʱ���е��¼�
{
   for(i=0;i<31;i++)                                        //���ýṹ�����ĳ�ʼֵ
   {
      t[i].data=0;                                            //���ݳ�ʼֵ��Ϊ0
      t[i].left=-1;                                           //��������ʼֵ��Ϊ-1
      t[i].right=-1;                                          //��������ʼֵ��Ϊ-1
   }
   sg->Cells[0][0]=" �ڵ���";
   sg->Cells[1][0]=" ����ֵ";
   sg->Cells[2][0]=" ����ֵ";
   sg->Cells[3][0]=" ����ֵ";
}
//---------------------------------------------------------------------------
void create(int lv,int d,int da)            //�������ؼ���������
{
   static int p[16];                   //�����������
   TShape *sp;                         //�����̳����
   TColor color[5]={clTeal,clPurple,clLime,clBlue,clBackground};
   sp=new TShape(Form1);                //�����¿ؼ�
   sp->Parent=Form1->pn;                 //���ÿؼ����ֵ����
   sp->Height=30;
   sp->Width=30;
   sp->Hint="����ֵΪ"+IntToStr(ts);    //��������ֵ��ʼֵΪ0,tsΪ�������
   sp->ShowHint=true;

   TLabel *lb;
   lb=new TLabel(Form1);
   lb->Parent=Form1->pn;
   lb->Height=20;
   lb->Width=30;
   lb->Transparent=true;                //��ǩ����ɫ��Ϊ͸��
   lb->Caption=IntToStr(da);

   sp->Top=20+d*50;                     //���ý�㶥������
   lb->Top=28+d*50;

   if(d==0)                             //ȡ�ý���������ֵ
   {
      sp->Left=210;
      lb->Left=220;
   }
   else
   {
      sp->Left=210-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));
      lb->Left=220-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));

      Form1->Image1->Canvas->MoveTo(p[lv/2],35+(d-1)*50);
      Form1->Image1->Canvas->LineTo((sp->Left)+15,(sp->Top)+15);
   }

   Form1->lout->Caption="�� "+IntToStr(ts+1)+" ������ֵ( "+IntToStr(da)+" ) ,"+
                         "λ�ڵ� "+IntToStr(d+1)+" ��";

   sp->Shape=stCircle;
   sp->Brush->Color=color[d];

   if(lv<16)
      p[lv]=(sp->Left)+15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::einKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)                       //�����¼�
{
   if(Key==13)
   {
      dat=StrToInt(ein->Text);
      p=0;
      if(ts==0)
         t[0].data=dat;                  //�����
      else
      {
         idx=0;
         d=0;
         lv=1;
         t[ts].data=dat;                 //����������
         while(p==0)                     //��ָ���ж�ֵpΪ0ʱִ��
         {
            if(dat < t[idx].data)        //�����ֵС��������������ִ��
            {
               if(t[idx].left!=-1)       //������������������
                  idx=t[idx].left;       //������ֵ����������,����ѭ��
               else                      //���������������
                  p=-1;                  //������ֵ����������,����ѭ��

               lv*=2;                    //���ӽ��λ��
            }
            else
            {
               if(t[idx].right != -1)    //������������������
                  idx=t[idx].right;      //������������������,����ѭ��
               else
                  p=1;

               lv=lv*2+1;             //���ӽ��λ��
            }
            d++;                      //��ȼ�1
         }

         if(p==1)                     //�����������������λ��
            t[idx].right=ts;
         else
            t[idx].left=ts;
      }
      if(d>=5)
         lout->Caption="�½ڵ�λ�ڵ����֮��~";
      else
         create(lv,d,dat);       //���ô���ؼ���������

      ein->Text="";
      ts++;                      //����������ۼ�
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::showClick(TObject *Sender)  //�����ʾ�������¼�
{
   for(i=0;i<ts;i++)
   {
      sg->Cells[0][i+1]="����ֵ"+IntToStr(i);
      sg->Cells[1][i+1]=t[i].left;
      sg->Cells[2][i+1]=t[i].data;
      sg->Cells[3][i+1]=t[i].right;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::endClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

