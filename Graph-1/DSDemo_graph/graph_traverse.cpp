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

static TShape *sp[MAX_VERTEX_NUM];                           //节点Shap数组
static TLabel *lb[MAX_VERTEX_NUM];                           //节点Shap上的标签数组，画板->Shap->Label

static int direct = 0;                                       //默认是有向图
static int N;                                                //n:记录节点总数
static int start, end;                                       //start:设置连线时起始点的索引, end:设置连线时结束点的索引
static int i, j;
static bool input_node = false;
static int node_R = 20;

static MGraph MG;      //矩阵存储
static ALGraph ALG;    //临接链表存储

static TMemo *memo_local;

//---------------------------------------------------------------------------
static int searchPoint(int x, int y)                   //搜索给定坐标点落在图中哪个点
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

static int overLap(int x, int y)                       //搜索给定坐标点会跟哪个店重合
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

    //自左到右，或自右到左
    if (dy == 0) {
        int flag = (x2 - x1) > 0 ? 1 : -1;
        Ox = x2 - 2 * node_R * flag;
        Oy = y2;
        O1x = Ox;
        O1y = y2 + node_R / 3;
        O2x = Ox;
        O2y = y2 - node_R / 3;
    }
    //自下而上或自上而下
    if (dx == 0) {
        int flag = (y2 - y1) > 0 ? 1 : -1;
        Ox = x2;
        Oy = y2 - 2 * node_R * flag;
        O1x = Ox + node_R / 3;
        O1y = Oy;
        O2x = Ox - node_R / 3;
        O2y = Oy;
    }
    //左下角-->右上角方向
    if (x2 - x1 > 0 && y2 - y1 < 0) {
        Ox = x2 - 2 * node_R * dx / d;
        Oy = y2 + 2 * node_R * dy / d;
        O1x = Ox + node_R / 3 * dy / d;
        O1y = Oy + node_R / 3 * dx / d;
        O2x = Ox - node_R / 3 * dy / d;
        O2y = Oy - node_R / 3 * dx / d;
    }
    //右上角-->左下角方向
    if (x2 - x1 < 0 && y2 - y1 > 0) {
        Ox = x2 + 2 * node_R * dx / d;
        Oy = y2 - 2 * node_R * dy / d;
        O1x = Ox - node_R / 3 * dy / d;
        O1y = Oy - node_R / 3 * dx / d;
        O2x = Ox + node_R / 3 * dy / d;
        O2y = Oy + node_R / 3 * dx / d;
    }
    //左上角-->右下角方向
    if (x2 - x1 > 0 && y2 - y1 > 0) {
        Ox = x2 - 2 * node_R * dx / d;
        Oy = y2 - 2 * node_R * dy / d;
        O1x = Ox + node_R / 3 * dy / d;
        O1y = Oy - node_R / 3 * dx / d;
        O2x = Ox - node_R / 3 * dy / d;
        O2y = Oy + node_R / 3 * dx / d;
    }
    //右下角-->左上角方向
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
void __fastcall TGraphTraverseForm::FormCreate(TObject * Sender)    //顶点间初始设置为无穷大(不通)
{
    memo_local = memo;

    //邻接矩阵
    MG.vexnum = 0;
    MG.arcnum = 0;
    MG.print = showInMemo;
    //邻接表
    ALG.vexnum = 0;
    ALG.arcnum = 0;
    ALG.print = showInMemo;

    for (i = 0; i < MAX_VERTEX_NUM; i++)
        for (j = 0; j < MAX_VERTEX_NUM; j++) {
            MG.arcs[i][j] = 99999;
        }
}

//---------------------------------------------------------------------------
void __fastcall TGraphTraverseForm::CreateNodeBtnClick(TObject * Sender)    //生成顶点按钮单击事件
{

    pnl->Enabled = true;                            //启动画板功能
    if (input_node == false) {
        memo->Lines->Add("请用鼠标点击创建图的节点");
        CreateNodeBtn->Caption = "结束输入";
        input_node = true;
        img->Canvas->MoveTo(0, 0);
        img->Canvas->LineTo(0, 0);
    } else {
        memo->Lines->Add("创建节点结束，可以用鼠标拖拽创建图的边线");
        CreateNodeBtn->Caption = "输入节点";
        input_node = false;
        pnl->Cursor = crArrow;
        img->Visible = true;
        //CreateNodeBtn->Enabled = false;
    }
}



void __fastcall TGraphTraverseForm::imgMouseDown(TObject * Sender, //鼠标按下事件,记录起始点的位置
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    if (input_node == true) {
        if (N < MAX_VERTEX_NUM) {    //限制最多输入MAX_VERTEX_NUM个节点
            int tmp = overLap(X, Y);
            char data = 'A' + N;
            if (tmp != -1) {
                ShowMessage("与节点:" + IntToStr(tmp) + "相邻太近");
                return;
            }
            sp[N] = new TShape(this);    //建立新结点控件
            sp[N]->Parent = pnl;    //设置新结点控件属性
            sp[N]->Enabled = false;
            sp[N]->Left = X - node_R;    //圆形的直径是15的圆
            sp[N]->Top = Y - node_R;
            sp[N]->Height = 2 * node_R;
            sp[N]->Width = 2 * node_R;
            TColor color[MAX_VERTEX_NUM] = {
                clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua,
                clTeal, clWebRoyalBlue
            };
            sp[N]->Brush->Color = color[N];    //设置填充颜色
            sp[N]->Shape = stEllipse;    //控件的类型是椭圆，C++builder 中没有圆只有椭圆，高度宽度相等即为圆
            lb[N] = new TLabel(pnl);    //建立新结点标签
            lb[N]->Parent = pnl;    //设置新结点控件属性
            lb[N]->Caption = data;    //节点的显示内容即节点的下标
            lb[N]->Transparent = true;    //标签透明
            lb[N]->Left = X - 5;    //设置标签的位置
            lb[N]->Top = Y - 5;
            N++;
            ALGraph_Add_Node(&ALG, X, Y);
            StartComboBox->Items->Add(ALG.vertics[ALG.vexnum - 1].data.data);
            EndComboBox->Items->Add(ALG.vertics[ALG.vexnum - 1].data.data);
        }
        //顶点计数器加1
        return;
    }
    start = searchPoint(X, Y);

    //ShowMessage("请输入 0 ~ "+);
}


void __fastcall TGraphTraverseForm::imgMouseUp(TObject * Sender,
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    int dist = 0;

    end = searchPoint(X, Y);
    if (start != -1 && end != -1 && start != end) {
        dist = StrToInt(InputBox("节点距离", "请输入节点距离: ", "5"));    //默认值5
        img->Canvas->MoveTo(ALG.vertics[start].x, ALG.vertics[start].y);
        img->Canvas->LineTo(ALG.vertics[end].x, ALG.vertics[end].y);
        img->Canvas->TextOut((ALG.vertics[start].x + ALG.vertics[end].x) / 2, (ALG.vertics[start].y + ALG.vertics[end].y) / 2, dist);

        //如果是有向图画箭头
        if (direct == 1) {
            paintArrow(img, ALG.vertics[start].x, ALG.vertics[start].y, ALG.vertics[end].x, ALG.vertics[end].y);
            ALGraph_Add_Arc(&ALG, start, end, dist);
            MGraph_Add_Arc(&MG, start, end, dist);
        } else {
            //无向图是对称矩阵
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
            img->Canvas->Pixels[i][j] = clWhite;    //将范围内的画板变白
    img->Canvas->MoveTo(0,0);
    img->Canvas->LineTo(0,0);

    //释放标签和圆形
    for (i = 0; i < N; i++) {
        delete sp[i];
        delete lb[i];
    }

    N = 0;
    CreateNodeBtn->Enabled = true;
    CreateNodeBtn->Caption = "输入节点";
}

//---------------------------------------------------------------------------

void __fastcall TGraphTraverseForm::TraverseDFSBtnClick(TObject *Sender)
{
     memo->Lines->Add("=====DFS 图遍历结果如下=====");
     DFSTraverse(&ALG);
}
//---------------------------------------------------------------------------

void __fastcall TGraphTraverseForm::TraverseBFSBtnClick(TObject *Sender)
{
 memo->Lines->Add("=====BFS 图遍历结果如下=====");
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
        ShowMessage("从" + StartComboBox->Text + "到" + EndComboBox->Text + "没有路径");
}
//---------------------------------------------------------------------------

