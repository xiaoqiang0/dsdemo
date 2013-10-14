//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "cd5_3u.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TBiTreeForm *BiTreeForm;
static TMemo *memo_local;
static TImage *img_local;
static TColor color[8] = {
    clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua,
    clTeal, clWebRoyalBlue
};

int flag = 1;

//---------------------------------------------------------------------------
__fastcall TBiTreeForm::TBiTreeForm(TComponent * Owner)
:TForm(Owner)
{
    T = NULL;
    memo_local = Memo1;
    img_local = img;
}

int TBiTreeForm::get_pos_x(BiTree T)
{
    if (T->parent == T)
	return width * pow(0.5, T->depth);

    if (T->parent->left == T)
	return get_pos_x(T->parent) - width * pow(0.5, T->depth);
    else
	return get_pos_x(T->parent) + width * pow(0.5, T->depth);
}

int TBiTreeForm::get_pos_y(BiTree T)
{
    return T->depth * height / (max_depth + 1);
}
//TBiTreeForm::
void traverse_visit(void *data)
{
  BiTree T;
  T = (BiTree) data;
  memo_local->Lines->Add(T->data);
}

//TBiTreeForm::
void note_leaf(void *data)
{
  BiTree T;
  T = (BiTree) data;
  if (T->left || T->right) {
       return;
  }
    //Clear first
    img_local->Canvas->Brush->Color = clWhite;
    img_local->Canvas->Ellipse(T->x - 20, T->y - 15, T->x + 20, T->y + 15);
    //img_local->Canvas->TextOut(T->x - 3, T->y - 5, T->data);

    //Paint Node
    img_local->Canvas->Brush->Color = clBlack;
    img_local->Canvas->Brush->Style = bsFDiagonal;
    img_local->Canvas->Ellipse(T->x - 20, T->y - 15, T->x + 20, T->y + 15);
    img_local->Canvas->TextOut(T->x - 3, T->y - 5, T->data);
    img_local->Canvas->Brush->Style = bsSolid;
}
void TBiTreeForm::PaintTree(BiTree T)
{
    if (!T)
	return;

    if (T->parent == T)
	T->depth = 1;
    else
	T->depth = T->parent->depth + 1;

    T->x = get_pos_x(T);
    T->y = get_pos_y(T);

    //Paint Line
    img->Canvas->MoveTo(T->parent->x, T->parent->y);
    img->Canvas->LineTo(T->x, T->y);

    //Paint Node
    img->Canvas->Brush->Color = color[T->depth % 8];
    img->Canvas->Ellipse(T->x - 20, T->y - 15, T->x + 20, T->y + 15);
    img->Canvas->TextOut(T->x - 3, T->y - 5, T->data);
    //Paint parent Node to overwrite line
    img->Canvas->Brush->Color = color[T->parent->depth % 8];
    img->Canvas->Ellipse(T->parent->x - 20, T->parent->y - 15,
			 T->parent->x + 20, T->parent->y + 15);
    img->Canvas->TextOut(T->parent->x - 3, T->parent->y - 5,
			 T->parent->data);

    PaintTree(T->left);
    PaintTree(T->right);
}

void TBiTreeForm::RepaintTree()
{
    width = img->Width;
    height = img->Height;
    max_depth = getDepth(T);
    PaintTree(T);

}
void TBiTreeForm::ClearImage()
{
    img->Canvas->Pen->Color = clWhite;	//将画笔颜色设为白色
    img->Canvas->Pen->Width = img->Height * 2;	//设置画笔宽度为8
    img->Canvas->MoveTo(0, 0);
    img->Canvas->LineTo(img->Width, 0);
    img->Canvas->Pen->Color = clBlack;
    img->Canvas->Pen->Width = 1;
}

void __fastcall TBiTreeForm::FormCreate(TObject * Sender)
{
    char pre[] = "ABDCEF";
    char in[]  = "BDAEFC";
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE";
    //T = CTree(pre, 0, 5, in, 0, 5);
//    T = CreateBiTreeFromArray(s, 0);
}

//---------------------------------------------------------------------------
void __fastcall TBiTreeForm::FormResize(TObject * Sender)
{
    ClearImage();
    RepaintTree();
    if (flag == 1) {
        flag = 0;
        WindowState = wsNormal;
    }
}

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
void __fastcall TBiTreeForm::FormDestroy(TObject *Sender)
{
     freeBiTree(T);
}
//---------------------------------------------------------------------------



void __fastcall TBiTreeForm::BitBtn1Click(TObject *Sender)
{
    AnsiString pre = PreOrderEdit->Text;
    AnsiString ino = InOrderEdit->Text;
    AnsiString table = TableEdit->Text;
    AnsiString txt = TreeArrayEdit->Text;
    freeBiTree(T);
    switch (PageControl1->TabIndex) {
        case 0:
            T = CTree(pre.c_str(), 0, 5, ino.c_str(), 0, 5);
            break;
        case 1:
            T = createBiTree(table.c_str());
            break;
        case 2:
            T = CreateBiTreeFromArray(txt.c_str(), 0);
            break;

    }

    ClearImage();
    RepaintTree();
}

void __fastcall TBiTreeForm::Button3Click(TObject *Sender)
{
     memo_local->Lines->Add("前序遍历结果如下:");
     PreOrderTraverse(T, traverse_visit);
}
//---------------------------------------------------------------------------


void __fastcall TBiTreeForm::Button2Click(TObject *Sender)
{
     memo_local->Lines->Add("中序遍历结果如下:");
     InOrderTraverse_recurse(T, traverse_visit);
}
//---------------------------------------------------------------------------
void __fastcall TBiTreeForm::Button1Click(TObject * Sender)
{
     memo_local->Lines->Add("后序遍历结果如下:");
     PostOrderTraverse(T, traverse_visit);
}
void __fastcall TBiTreeForm::Button5Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------



void __fastcall TBiTreeForm::Button4Click(TObject *Sender)
{
    memo_local->Lines->Add("树的深度是:" + IntToStr(getDepth(T)));
}
//---------------------------------------------------------------------------

void __fastcall TBiTreeForm::Button6Click(TObject *Sender)
{
//
PreOrderTraverse(T, note_leaf);
}
//---------------------------------------------------------------------------


