//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "graph.h"
#include "graph_shortest_path.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//#define MAX_VERTEX_NUM 8

TGraphAlgorithmForm *GraphAlgorithmForm;

static TShape *sp[MAX_VERTEX_NUM];                           //节点Shap数组
static TLabel *lb[MAX_VERTEX_NUM];                           //节点Shap上的标签数组，画板->Shap->Label
static int graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 9999 };       //存储图的矩阵结构 graph[i][i] = n:代表第i个节点到第j个节点的距离是n

static int direct = 1;                                 //默认是有向图

static int x[MAX_VERTEX_NUM], y[MAX_VERTEX_NUM];                   //存储图在屏幕的坐标位置
static int n;                                          //n:记录节点总数
static int start, end;                                 //start:设置连线时起始点的索引, end:设置连线时结束点的索引

static int i, j;
static bool input_node = false;
static int node_R = 20;

static MGraph MG;      //矩阵存储
static ALGraph ALG;    //临接链表存储

static TMemo *memo_local;

//---------------------------------------------------------------------------
int searchPoint(int X, int Y)                   //搜索给定坐标点落在图中哪个点
{
    for (i = 0; i < n; i++) {
        int d = sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
        if (d <= node_R * 1.3) {
            return i;
        }
    }
    return -1;
}

int overLap(int X, int Y)                       //搜索给定坐标点会跟哪个店重合
{
    for (i = 0; i < n; i++) {
        int d = sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
        if (d <= node_R * 3.5) {
            return i;
        }
    }
    return -1;
}

//---------------------------------------------------------------------------
int paintArrow(TImage * img, float x1, float y1, float x2, float y2)
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



void showInMemo(string s)
{
      memo_local->Lines->Append(s.c_str());
}


//---------------------------------------------------------------------------
__fastcall TGraphAlgorithmForm::TGraphAlgorithmForm(TComponent * Owner):TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::FormCreate(TObject * Sender)    //顶点间初始设置为无穷大(不通)
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
            graph[i][j] = 9999;
            MG.arcs[i][j] = 99999;
        }

}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::CreateNodeBtnClick(TObject * Sender)    //生成顶点按钮单击事件
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



void __fastcall TGraphAlgorithmForm::imgMouseDown(TObject * Sender, //鼠标按下事件,记录起始点的位置
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    if (CreateNodeBtn->Enabled == true && input_node == true) {
        if (n < MAX_VERTEX_NUM) {    //限制最多输入MAX_VERTEX_NUM个节点
            int tmp = overLap(X, Y);
            char data = 'A' + n;
            if (tmp != -1) {
                ShowMessage("与节点:" + IntToStr(tmp) + "相邻太近");
                return;
            }
            sp[n] = new TShape(this);    //建立新结点控件
            sp[n]->Parent = pnl;    //设置新结点控件属性
            sp[n]->Enabled = false;
            sp[n]->Left = X - node_R;    //圆形的直径是15的圆
            sp[n]->Top = Y - node_R;
            sp[n]->Height = 2 * node_R;
            sp[n]->Width = 2 * node_R;
            TColor color[MAX_VERTEX_NUM] = {
                clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua,
                clTeal, clWebRoyalBlue
            };
            sp[n]->Brush->Color = color[n];    //设置填充颜色
            sp[n]->Shape = stEllipse;    //控件的类型是椭圆，C++builder 中没有圆只有椭圆，高度宽度相等即为圆
            lb[n] = new TLabel(pnl);    //建立新结点标签
            lb[n]->Parent = pnl;    //设置新结点控件属性
            lb[n]->Caption = data;    //节点的显示内容即节点的下标
            lb[n]->Transparent = true;    //标签透明
            lb[n]->Left = X - 5;    //设置标签的位置
            lb[n]->Top = Y - 5;
            x[n] = X;
            y[n] = Y;        //存储新顶点坐标，圆的中心
            n++;
            MGraph_Add_Node(&MG);
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


void __fastcall TGraphAlgorithmForm::imgMouseUp(TObject * Sender,
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    int dist = 0;

    end = searchPoint(X, Y);
    if (start != -1 && end != -1 && start != end) {
        dist = StrToInt(InputBox("节点距离", "请输入节点距离: ", "5"));    //默认值5
        img->Canvas->MoveTo(x[start], y[start]);
        img->Canvas->LineTo(x[end], y[end]);
	    img->Canvas->TextOut((x[start] + x[end]) / 2, (y[start] + y[end]) / 2, dist);

        //如果是有向图画箭头
        if (direct == 1) {
            paintArrow(img, x[start], y[start], x[end], y[end]);
            graph[start][end] = dist;    //有向图
            MGraph_Add_Arc(&MG, start, end, dist);
        } else {
            //无向图是对称矩阵
            graph[start][end] = graph[end][start] = dist;
            MGraph_Add_Arc(&MG, start, end, dist);
            MGraph_Add_Arc(&MG, end, start, dist);
        }
    }

    start = -1;
    end = -1;            //reset
}
void __fastcall TGraphAlgorithmForm::my_print (String info)
{
     memo->Lines->Add(info);
}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::ShortestPathBtnClick(TObject * Sender)    //最短路径求解事件
{
    bool vst[MAX_VERTEX_NUM] = { false };     //访问辅助数组
    int dte[MAX_VERTEX_NUM] = { 0 };          //单源最短路径算法存储最短路径dte[i] = x 代表从节点0到节点i的最短路径是x
    int target = -1;

    if (n == 0) {
        ShowMessage("图还未创建,请创建完图后再进行操作");
        return;
    }

    do {
        target = StrToInt(InputBox("最佳路径设定框", 
                          "请输入目的顶点 0 ~" + IntToStr(n - 1), ""));
    } while (target >= n || target < 0);           //控制输入范围

    ShortestPathBtn->Enabled = false;
    int edg = 1, min = 9999, vtx;                  //edg、min、vtx分别表示始边,最小边,顶点
    vst[0] = true;                                 //从顶点0（原点）开始计算路径

    for (i = 1; i < n; i++)                        //记录相邻原点的路经值
        dte[i] = graph[0][i];

    while (edg < n - 1)                            //最短路径解决方法
    {
        edg++;                                     //边线计数器加1
        min = 9999;                                //设定比较基值
        for (i = 1; i < n; i++) {
            if (vst[i] == false && min > dte[i])   //没有访问过的相邻接定点
            {
                vtx = i;                           //将访问的对象
                min = dte[i];                      //最短路径值已经改变
            }
        }
        vst[vtx] = true;                           //访问设置
        for (i = 1; i < n; i++) {
            if (vst[i] == false && dte[vtx] + graph[vtx][i] < dte[i])    //新路径总长如果小于目前最短路径
                dte[i] = dte[vtx] + graph[vtx][i];    //更新当前最短路径记录
        }
    }

    memo->Lines->Add("从原点到第 " + IntToStr(target) + " 点最佳路径为" +
            IntToStr(dte[target]));
}



void __fastcall TGraphAlgorithmForm::BtClearMemoClick(TObject * Sender)
{
    memo->Clear();
}

//---------------------------------------------------------------------------


void __fastcall TGraphAlgorithmForm::DirectBtnClick(TObject * Sender)
{
    direct = 1;
    TopologicalSortBtn->Enabled = true;
    CircleCheckBtn->Enabled = true;
    CriticalPathBtn->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TGraphAlgorithmForm::NoDirectBtnClick(TObject * Sender)
{
    direct = 0;
    TopologicalSortBtn->Enabled = false;
    CircleCheckBtn->Enabled = false;
    CriticalPathBtn->Enabled = false;
}

//---------------------------------------------------------------------------



void __fastcall TGraphAlgorithmForm::ResetBtnClick(TObject * Sender)
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
    for (i = 0; i < n; i++) {
        delete sp[i];
        delete lb[i];
    }

    n = 0;
    CreateNodeBtn->Enabled = true;
    CreateNodeBtn->Caption = "输入节点";
}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::FloydBtnClick(TObject *Sender)
{

     memo->Lines->Add("=====Floyd 最短路径求解结果如下=====");
     ShortestPath_FLOYD(&MG);
}
//---------------------------------------------------------------------------

void __fastcall TGraphAlgorithmForm::DijBtnClick(TObject *Sender)
{
   memo->Lines->Add("=====Dijkstra 最短路径求解结果如下=====");
   for (i = 0; i < MG.vexnum; i++)
       ShortestPath_DIJ(&MG, i);
}
//---------------------------------------------------------------------------





