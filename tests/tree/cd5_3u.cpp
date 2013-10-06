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

class node        //结点类
{
   public:
      int data;
      node* left;                                //左子树指针
      node* right;                               //右子树指针
      node():data(0),left(NULL),right(NULL){}    //结点构建时的设置
      getdata(){return data;}                     //取得结点内容
};

class bntree                           	//二叉树类
{
   public:
      void insert(int da,int *lv,int *d)           //安插一个新结点的函数
      {
         node* newnode=new node;           //产生新结点
         newnode->data=da;
         if(root==NULL)           //如果二叉树为空，建立根结点
            root=newnode;
         else
         {
            node* P=root;
            node* F;
            while(1)                          //自动循环直到return为止
            {
               *d=(*d)+1;                   //用指针传递函数间的d值
               F=P;
               if(da < (P->data))           //新加入的值小于目前结点值
               {
                  *lv=(*lv)*2;              //用指针传递函数间的lv值
                  P=P->left;
                  if(P==NULL)         //若此结点无数据,新值设置在此并跳出循环
                  {
                     F->left=newnode;
                     return ;
                  }
               }
               else                      //新加入的值小于当前结点值
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
      int find(int k,int l)               //搜寻树中结点位置的函数
      {
         node* P=root;
         while(P->getdata()!=k)            //当前结点数据不等于搜寻值时运行
         {
            if(k<P->data)                //当搜寻值小于当前数据时往左子结点移动
            {
               P=P->left;
               l=l*2;
            }
            else
            {
               P=P->right;
               l=l*2+1;
            }
            if(P==NULL)                   //找不到要搜寻的结点返回0
               return 0;
         }
         return l;                      //返回搜索成功的结点位置
      }
      void droot(){clear(root);}        //用连续调用递归的方式清除所有结点
      void clear(node* T)               //清除二叉树结点
      {
         if(T!=NULL)
         {
            clear(T->left);       //不断调用清除函数以寻找端点
            clear(T->right);      //清除该端的叶子结点
            delete T;
         }
      }
   private:
      node* root;
};
bntree tree;              //新建立一个bntree类别,名称为tree
int dat,l,timer=0;
int i;
TShape *sp[32];  //为取得运行时所构建的对象,所以将其声明为数组以便索引
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void create(int lv,int d,int da)      //构建窗体显示控件的函数
{
   static int p[16];

   TColor color[5]={clWhite,clYellow,clLime,clBlue,clRed};
   sp[lv]=new TShape(Form1);        //构建的结点控件形体
   sp[lv]->Parent=Form1->pn;
   sp[lv]->Height=20;
   sp[lv]->Width=30;

   TLabel *lb;                  //构建结点控件内容表示
   lb=new TLabel(Form1);
   lb->Parent=Form1->pn;
   lb->Height=20;
   lb->Width=30;
   lb->Transparent=true;
   lb->Caption=IntToStr(da);

   sp[lv]->Top=20+d*35;
   lb->Top=24+d*35;

   if(d==0)                   //取得结点左端座标
   {
      sp[lv]->Left=175;
      lb->Left=185;
   }
   else
   {
      sp[lv]->Left=175-d*40+(d*80/(pow(2,d)-1)*(lv-(pow(2,d))));
      lb->Left=185-d*40+(d*80/(pow(2,d)-1)*(lv-(pow(2,d))));

      Form1->img->Canvas->MoveTo(p[lv/2],35+(d-1)*35);      //构建结点连接线段
      Form1->img->Canvas->LineTo((sp[lv]->Left)+15,(sp[lv]->Top)+15);
   }

   sp[lv]->Shape=stEllipse;
   sp[lv]->Brush->Color=color[d];         //结点颜色根据所在层而变化

   if(lv<16)
      p[lv]=(sp[lv]->Left)+15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)   	//增加新结点
{
   int lv=1,d=0;                          //设置深度及位置的初始值
   dat=StrToInt(ein->Text);
   tree.insert(dat,&lv,&d);    //调用安插新结点的函数
   ein->Text="";
   if(d<5)
      create(lv,d,dat);        //调用生成窗体显示控件的函数
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)     //关闭程序并清除结点
{
   tree.droot();
   Close();
}
//---------------------------------------------------------------------------
void fnode(int l)
{
   sp[l]->Shape=stRoundRect;            //将找到的结点形状改为圆角方形
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)       //搜寻二叉树结点
{
   int key;
   l=1;
   key=StrToInt(ein->Text);
   l=tree.find(key,l);                //调用搜索函数,并将值返回给l
            //函数返回一个值可直接传递,若欲返回两个以上则可用适当的变量或指针
   if(l==0)
      ShowMessage("找不到"+IntToStr(key)+" 这个数");
   else
   {
      fnode(l);           //将找到的结点变形
      timer=1;           //使找到的结点闪烁
   }
   ein->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//熟悉计数器的使用有助于动画及效果的表现
   static int t=0;
   if(timer==1)
   {
      if(t%2==0)                       //锁定结点使其闪烁
         sp[l]->Visible=false;
      else
         sp[l]->Visible=true;
      t++;
      if(t>20)                          //结束计数器并将形状还原
      {
        timer=0;                          //还原搜寻结果变化
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

