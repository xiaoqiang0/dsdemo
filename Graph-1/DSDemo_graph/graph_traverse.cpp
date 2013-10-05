//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "graph.h"
#include "graph_traverse.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//#define MAX_VERTEX_NUM 8

TGraphTraverseForm *GraphTraverseForm;

static TShape *sp[MAX_VERTEX_NUM];                           //�ڵ�Shap����
static TLabel *lb[MAX_VERTEX_NUM];                           //�ڵ�Shap�ϵı�ǩ���飬����->Shap->Label

static int direct = 0;                                       //Ĭ��������ͼ
static int N;                                                //n:��¼�ڵ�����
static int start, end;                                       //start:��������ʱ��ʼ�������, end:��������ʱ�����������
static int i, j;
static bool input_node = false;
static int node_R = 20;

static MGraph MG;      //����洢
static ALGraph ALG;    //�ٽ�����洢

static TMemo *memo_local;

//---------------------------------------------------------------------------
static int searchPoint(int x, int y)                   //�����������������ͼ���ĸ���
{
    for (i = 0; i < N; i++) {
        int d = sqrt((x - ALG.vertics[i].x) * (x - ALG.vertics[i].x) + \
                (y - ALG.vertics[i].y) * (y - ALG.vertics[i].y));
        if (d <= node_R * 1.3) {
            return i;
        }
    }
    return -1;
}

static int overLap(int x, int y)                       //����������������ĸ����غ�
{
    for (i = 0; i < N; i++) {
        int d = sqrt((x - ALG.vertics[i].x) * (x - ALG.vertics[i].x) + \
                (y - ALG.vertics[i].y) * (y - ALG.vertics[i].y));
        if (d <= node_R * 3.5) {
            return i;
        }
    }
    return -1;
}

//---------------------------------------------------------------------------
static int paintArrow(TImage * img, float x1, float y1, float x2, float y2)
{
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float d, Ox, Oy, O1x, O1y, O2x, O2y;
    float k1, k2;
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    //�����ң������ҵ���
    if (dy == 0) {
        int flag = (x2 - x1) > 0 ? 1 : -1;
        Ox = x2 - 2 * node_R * flag;
        Oy = y2;
        O1x = Ox;
        O1y = y2 + node_R / 3;
        O2x = Ox;
        O2y = y2 - node_R / 3;
    }
    //���¶��ϻ����϶���
    if (dx == 0) {
        int flag = (y2 - y1) > 0 ? 1 : -1;
        Ox = x2;
        Oy = y2 - 2 * node_R * flag;
        O1x = Ox + node_R / 3;
        O1y = Oy;
        O2x = Ox - node_R / 3;
        O2y = Oy;
    }
    //���½�-->���ϽǷ���
    if (x2 - x1 > 0 && y2 - y1 < 0) {
        Ox = x2 - 2 * node_R * dx / d;
        Oy = y2 + 2 * node_R * dy / d;
        O1x = Ox + node_R / 3 * dy / d;
        O1y = Oy + node_R / 3 * dx / d;
        O2x = Ox - node_R / 3 * dy / d;
        O2y = Oy - node_R / 3 * dx / d;
    }
    //���Ͻ�-->���½Ƿ���
    if (x2 - x1 < 0 && y2 - y1 > 0) {
        Ox = x2 + 2 * node_R * dx / d;
        Oy = y2 - 2 * node_R * dy / d;
        O1x = Ox - node_R / 3 * dy / d;
        O1y = Oy - node_R / 3 * dx / d;
        O2x = Ox + node_R / 3 * dy / d;
        O2y = Oy + node_R / 3 * dx / d;
    }
    //���Ͻ�-->���½Ƿ���
    if (x2 - x1 > 0 && y2 - y1 > 0) {
        Ox = x2 - 2 * node_R * dx / d;
        Oy = y2 - 2 * node_R * dy / d;
        O1x = Ox + node_R / 3 * dy / d;
        O1y = Oy - node_R / 3 * dx / d;
        O2x = Ox - node_R / 3 * dy / d;
        O2y = Oy + node_R / 3 * dx / d;
    }
    //���½�-->���ϽǷ���
    if (x2 - x1 < 0 && y2 - y1 < 0) {
        Ox = x2 + 2 * node_R * dx / d;
        Oy = y2 + 2 * node_R * dy / d;
        O1x = Ox - node_R / 3 * dy / d;
        O1y = Oy + node_R / 3 * dx / d;
        O2x = Ox + node_R / 3 * dy / d;
        O2y = Oy - node_R / 3 * dx / d;
    }

    float dst_x = (Ox + x2) / 2;
    float dst_y = (Oy + y2) / 2;

    img->Canvas->MoveTo(ceil(O1x), ceil(O1y));
    img->Canvas->LineTo(floor(dst_x), floor(dst_y));
    img->Canvas->LineTo(floor(O2x), floor(O2y));
}



static void showInMemo(string s)
{
    memo_local->Lines->Append(s.c_str());
}


//---------------------------------------------------------------------------
__fastcall TGraphTraverseForm::TGraphTraverseForm(TComponent * Owner):TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TGraphTraverseForm::FormCreate(TObject * Sender)    //������ʼ����Ϊ�����(��ͨ)
{
    memo_local = memo;

    //�ڽӾ���
    MG.vexnum = 0;
    MG.arcnum = 0;
    MG.print = showInMemo;
    //�ڽӱ�
    ALG.vexnum = 0;
    ALG.arcnum = 0;
    ALG.print = showInMemo;

    for (i = 0; i < MAX_VERTEX_NUM; i++)
        for (j = 0; j < MAX_VERTEX_NUM; j++) {
            MG.arcs[i][j] = 99999;
        }
}

//---------------------------------------------------------------------------
void __fastcall TGraphTraverseForm::CreateNodeBtnClick(TObject * Sender)    //���ɶ��㰴ť�����¼�
{

    pnl->Enabled = true;                            //�������幦��
    if (input_node == false) {
        memo->Lines->Add("�������������ͼ�Ľڵ�");
        CreateNodeBtn->Caption = "��������";
        input_node = true;
        img->Canvas->MoveTo(0, 0);
        img->Canvas->LineTo(0, 0);
    } else {
        memo->Lines->Add("�����ڵ�����������������ק����ͼ�ı���");
        CreateNodeBtn->Caption = "����ڵ�";
        input_node = false;
        pnl->Cursor = crArrow;
        img->Visible = true;
        //CreateNodeBtn->Enabled = false;
    }
}



void __fastcall TGraphTraverseForm::imgMouseDown(TObject * Sender, //��갴���¼�,��¼��ʼ���λ��
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    if (input_node == true) {
        if (N < MAX_VERTEX_NUM) {    //�����������MAX_VERTEX_NUM���ڵ�
            int tmp = overLap(X, Y);
            char data = 'A' + N;
            if (tmp != -1) {
                ShowMessage("��ڵ�:" + IntToStr(tmp) + "����̫��");
                return;
            }
            sp[N] = new TShape(this);    //�����½��ؼ�
            sp[N]->Parent = pnl;    //�����½��ؼ�����
            sp[N]->Enabled = false;
            sp[N]->Left = X - node_R;    //Բ�ε�ֱ����15��Բ
            sp[N]->Top = Y - node_R;
            sp[N]->Height = 2 * node_R;
            sp[N]->Width = 2 * node_R;
            TColor color[MAX_VERTEX_NUM] = {
                clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua,
                clTeal, clWebRoyalBlue
            };
            sp[N]->Brush->Color = color[N];    //���������ɫ
            sp[N]->Shape = stEllipse;    //�ؼ�����������Բ��C++builder ��û��Բֻ����Բ���߶ȿ����ȼ�ΪԲ
            lb[N] = new TLabel(pnl);    //�����½���ǩ
            lb[N]->Parent = pnl;    //�����½��ؼ�����
            lb[N]->Caption = data;    //�ڵ����ʾ���ݼ��ڵ���±�
            lb[N]->Transparent = true;    //��ǩ͸��
            lb[N]->Left = X - 5;    //���ñ�ǩ��λ��
            lb[N]->Top = Y - 5;
            N++;
            ALGraph_Add_Node(&ALG, X, Y);
            StartComboBox->Items->Add(ALG.vertics[ALG.vexnum - 1].data.data);
            EndComboBox->Items->Add(ALG.vertics[ALG.vexnum - 1].data.data);
        }
        //�����������1
        return;
    }
    start = searchPoint(X, Y);

    //ShowMessage("������ 0 ~ "+);
}


void __fastcall TGraphTraverseForm::imgMouseUp(TObject * Sender,
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    int dist = 0;

    end = searchPoint(X, Y);
    if (start != -1 && end != -1 && start != end) {
        dist = StrToInt(InputBox("�ڵ����", "������ڵ����: ", "5"));    //Ĭ��ֵ5
        img->Canvas->MoveTo(ALG.vertics[start].x, ALG.vertics[start].y);
        img->Canvas->LineTo(ALG.vertics[end].x, ALG.vertics[end].y);
        img->Canvas->TextOut((ALG.vertics[start].x + ALG.vertics[end].x) / 2, (ALG.vertics[start].y + ALG.vertics[end].y) / 2, dist);

        //���������ͼ����ͷ
        if (direct == 1) {
            paintArrow(img, ALG.vertics[start].x, ALG.vertics[start].y, ALG.vertics[end].x, ALG.vertics[end].y);
            ALGraph_Add_Arc(&ALG, start, end, dist);
            MGraph_Add_Arc(&MG, start, end, dist);
        } else {
            //����ͼ�ǶԳƾ���
            ALGraph_Add_Arc(&ALG, start, end, dist);
            ALGraph_Add_Arc(&ALG, end, start, dist);

            MGraph_Add_Arc(&MG, start, end, dist);
            MGraph_Add_Arc(&MG, end, start, dist);
        }
    }

    start = -1;
    end = -1;            //reset
}
void __fastcall TGraphTraverseForm::my_print (String info)
{
    memo->Lines->Add(info);
}


void __fastcall TGraphTraverseForm::BtClearMemoClick(TObject * Sender)
{
    memo->Clear();
}

//---------------------------------------------------------------------------


void __fastcall TGraphTraverseForm::DirectBtnClick(TObject * Sender)
{
    direct = 1;
}

//---------------------------------------------------------------------------

void __fastcall TGraphTraverseForm::NoDirectBtnClick(TObject * Sender)
{
    direct = 0;
}

//---------------------------------------------------------------------------


void __fastcall TGraphTraverseForm::ResetBtnClick(TObject * Sender)
{
    int i;
    //    TColor original_color =  img->Canvas->Brush->Color;
    //    img->Canvas->Brush->Color = clWhite;
    //    img->Canvas->Rectangle(0, 0, img->Width, img->Height);
    //    img->Canvas->Brush->Color =  original_color;
    //    img->Repaint();
    for (i = 0; i < img->Width; i++)
        for (j = 0; j < img->Height; j++)
            img->Canvas->Pixels[i][j] = clWhite;    //����Χ�ڵĻ�����
    img->Canvas->MoveTo(0,0);
    img->Canvas->LineTo(0,0);

    //�ͷű�ǩ��Բ��
    for (i = 0; i < N; i++) {
        delete sp[i];
        delete lb[i];
    }

    N = 0;
    CreateNodeBtn->Enabled = true;
    CreateNodeBtn->Caption = "����ڵ�";
}

//---------------------------------------------------------------------------

void __fastcall TGraphTraverseForm::TraverseDFSBtnClick(TObject *Sender)
{
     memo->Lines->Add("=====DFS ͼ�����������=====");
     DFSTraverse(&ALG);
}
//---------------------------------------------------------------------------

void __fastcall TGraphTraverseForm::TraverseBFSBtnClick(TObject *Sender)
{
 memo->Lines->Add("=====BFS ͼ�����������=====");
 BFSTraverse(&ALG);
}
//---------------------------------------------------------------------------
void __fastcall TGraphTraverseForm::Button4Click(TObject *Sender)
{
     VertexType start, end;
     int start_idx, end_idx;

     start.data = StartComboBox->Text[1];

     end.data   = EndComboBox->Text[1];

     start_idx = ALGraph_LocateVertex(&ALG, start);
     end_idx = ALGraph_LocateVertex(&ALG, end);
     if (! ALGraph_exist_path_DFS(&ALG, start_idx, end_idx))
        ShowMessage("��" + StartComboBox->Text + "��" + EndComboBox->Text + "û��·��");
}
//---------------------------------------------------------------------------

