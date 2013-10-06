//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "cd5_3u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
class bntree;

class node        //�����
{
   public:
      int data;
      node* left;                                //������ָ��
      node* right;                               //������ָ��
      node():data(0),left(NULL),right(NULL){}    //��㹹��ʱ������
      getdata(){return data;}                     //ȡ�ý������
};

class bntree                           	//��������
{
   public:
      void insert(int da,int *lv,int *d)           //����һ���½��ĺ���
      {
         node* newnode=new node;           //�����½��
         newnode->data=da;
         if(root==NULL)           //���������Ϊ�գ����������
            root=newnode;
         else
         {
            node* P=root;
            node* F;
            while(1)                          //�Զ�ѭ��ֱ��returnΪֹ
            {
               *d=(*d)+1;                   //��ָ�봫�ݺ������dֵ
               F=P;
               if(da < (P->data))           //�¼����ֵС��Ŀǰ���ֵ
               {
                  *lv=(*lv)*2;              //��ָ�봫�ݺ������lvֵ
                  P=P->left;
                  if(P==NULL)         //���˽��������,��ֵ�����ڴ˲�����ѭ��
                  {
                     F->left=newnode;
                     return ;
                  }
               }
               else                      //�¼����ֵС�ڵ�ǰ���ֵ
               {
                  *lv=(*lv)*2+1;
                  P=P->right;
                  if(P==NULL)
                  {
                     F->right=newnode;
                     return ;
                  }
               }
            }
         }
      }
      int find(int k,int l)               //��Ѱ���н��λ�õĺ���
      {
         node* P=root;
         while(P->getdata()!=k)            //��ǰ������ݲ�������Ѱֵʱ����
         {
            if(k<P->data)                //����ѰֵС�ڵ�ǰ����ʱ�����ӽ���ƶ�
            {
               P=P->left;
               l=l*2;
            }
            else
            {
               P=P->right;
               l=l*2+1;
            }
            if(P==NULL)                   //�Ҳ���Ҫ��Ѱ�Ľ�㷵��0
               return 0;
         }
         return l;                      //���������ɹ��Ľ��λ��
      }
      void droot(){clear(root);}        //���������õݹ�ķ�ʽ������н��
      void clear(node* T)               //������������
      {
         if(T!=NULL)
         {
            clear(T->left);       //���ϵ������������Ѱ�Ҷ˵�
            clear(T->right);      //����ö˵�Ҷ�ӽ��
            delete T;
         }
      }
   private:
      node* root;
};
bntree tree;              //�½���һ��bntree���,����Ϊtree
int dat,l,timer=0;
int i;
TShape *sp[32];  //Ϊȡ������ʱ�������Ķ���,���Խ�������Ϊ�����Ա�����
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void create(int lv,int d,int da)      //����������ʾ�ؼ��ĺ���
{
   static int p[16];

   TColor color[5]={clWhite,clYellow,clLime,clBlue,clRed};
   sp[lv]=new TShape(Form1);        //�����Ľ��ؼ�����
   sp[lv]->Parent=Form1->pn;
   sp[lv]->Height=20;
   sp[lv]->Width=30;

   TLabel *lb;                  //�������ؼ����ݱ�ʾ
   lb=new TLabel(Form1);
   lb->Parent=Form1->pn;
   lb->Height=20;
   lb->Width=30;
   lb->Transparent=true;
   lb->Caption=IntToStr(da);

   sp[lv]->Top=20+d*35;
   lb->Top=24+d*35;

   if(d==0)                   //ȡ�ý���������
   {
      sp[lv]->Left=175;
      lb->Left=185;
   }
   else
   {
      sp[lv]->Left=175-d*40+(d*80/(pow(2,d)-1)*(lv-(pow(2,d))));
      lb->Left=185-d*40+(d*80/(pow(2,d)-1)*(lv-(pow(2,d))));

      Form1->img->Canvas->MoveTo(p[lv/2],35+(d-1)*35);      //������������߶�
      Form1->img->Canvas->LineTo((sp[lv]->Left)+15,(sp[lv]->Top)+15);
   }

   sp[lv]->Shape=stEllipse;
   sp[lv]->Brush->Color=color[d];         //�����ɫ�������ڲ���仯

   if(lv<16)
      p[lv]=(sp[lv]->Left)+15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)   	//�����½��
{
   int lv=1,d=0;                          //������ȼ�λ�õĳ�ʼֵ
   dat=StrToInt(ein->Text);
   tree.insert(dat,&lv,&d);    //���ð����½��ĺ���
   ein->Text="";
   if(d<5)
      create(lv,d,dat);        //�������ɴ�����ʾ�ؼ��ĺ���
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)     //�رճ���������
{
   tree.droot();
   Close();
}
//---------------------------------------------------------------------------
void fnode(int l)
{
   sp[l]->Shape=stRoundRect;            //���ҵ��Ľ����״��ΪԲ�Ƿ���
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)       //��Ѱ���������
{
   int key;
   l=1;
   key=StrToInt(ein->Text);
   l=tree.find(key,l);                //������������,����ֵ���ظ�l
            //��������һ��ֵ��ֱ�Ӵ���,����������������������ʵ��ı�����ָ��
   if(l==0)
      ShowMessage("�Ҳ���"+IntToStr(key)+" �����");
   else
   {
      fnode(l);           //���ҵ��Ľ�����
      timer=1;           //ʹ�ҵ��Ľ����˸
   }
   ein->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//��Ϥ��������ʹ�������ڶ�����Ч���ı���
   static int t=0;
   if(timer==1)
   {
      if(t%2==0)                       //�������ʹ����˸
         sp[l]->Visible=false;
      else
         sp[l]->Visible=true;
      t++;
      if(t>20)                          //����������������״��ԭ
      {
        timer=0;                          //��ԭ��Ѱ����仯
        sp[l]->Shape=stEllipse;
        t=0;
      }
   }
}
//---------------------------------------------------------------------------







void __fastcall TForm1::einKeyPress(TObject *Sender, System::WideChar &Key)
{
     if (Key == 13) {
           Button3->Click();
     }
}
//---------------------------------------------------------------------------

