object BiTreeForm: TBiTreeForm
  Left = 240
  Top = 111
  Caption = #20108#21449#26641#30340#22522#26412#25805#20316
  ClientHeight = 558
  ClientWidth = 1045
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 801
    Height = 558
    Align = alClient
    TabOrder = 0
    ExplicitHeight = 560
    object pn: TPanel
      Left = 1
      Top = 1
      Width = 799
      Height = 481
      Align = alClient
      BevelInner = bvLowered
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 0
      ExplicitHeight = 471
      object img: TImage
        Left = 2
        Top = 2
        Width = 795
        Height = 477
        Align = alClient
        Transparent = True
        ExplicitLeft = 0
        ExplicitTop = -2
        ExplicitHeight = 407
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 482
      Width = 799
      Height = 75
      Align = alBottom
      BiDiMode = bdLeftToRight
      Caption = #25805#20316#38754#26495
      Color = clOlive
      ParentBiDiMode = False
      ParentColor = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      object Panel3: TPanel
        Left = 560
        Top = 15
        Width = 237
        Height = 58
        Align = alRight
        TabOrder = 0
        object Button1: TButton
          Left = 160
          Top = 2
          Width = 73
          Height = 24
          Caption = #21518#24207#36941#21382
          TabOrder = 0
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 81
          Top = 2
          Width = 73
          Height = 24
          Caption = #20013#24207#36941#21382
          TabOrder = 1
        end
        object Button3: TButton
          Left = 2
          Top = 2
          Width = 73
          Height = 24
          Caption = #21069#24207#36941#21382
          TabOrder = 2
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 2
          Top = 31
          Width = 73
          Height = 25
          Caption = #26641#30340#28145#24230
          TabOrder = 3
        end
        object Button6: TButton
          Left = 81
          Top = 31
          Width = 73
          Height = 25
          Caption = #32467#26463
          TabOrder = 4
          OnClick = Button1Click
        end
        object Button5: TButton
          Left = 160
          Top = 31
          Width = 73
          Height = 25
          Caption = #32467#26463
          TabOrder = 5
          OnClick = Button1Click
        end
      end
      object Panel4: TPanel
        Left = 2
        Top = 15
        Width = 423
        Height = 58
        Align = alLeft
        TabOrder = 1
        ExplicitHeight = 70
        object BitBtn1: TBitBtn
          Left = 327
          Top = 1
          Width = 95
          Height = 56
          Align = alRight
          Caption = #21019#24314#20108#21449#26641
          TabOrder = 0
          OnClick = BitBtn1Click
          ExplicitHeight = 68
        end
        object PageControl1: TPageControl
          Left = 1
          Top = 1
          Width = 312
          Height = 56
          ActivePage = 数组线性序列
          Align = alLeft
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Verdana'
          Font.Style = []
          MultiLine = True
          ParentFont = False
          TabOrder = 1
          ExplicitTop = 0
          ExplicitHeight = 68
          object TabSheet1: TTabSheet
            Caption = #21069#24207#21644#20013#24207#24207#21015'  '
            ExplicitWidth = 312
            ExplicitHeight = 42
            object InOrderEdit: TEdit
              Left = 159
              Top = 1
              Width = 142
              Height = 25
              AutoSize = False
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Verdana'
              Font.Style = []
              ImeName = #20013#25991' ('#31616#20307') - '#24494#36719#25340#38899
              ParentFont = False
              TabOrder = 0
              Text = 'BDAEFC'
            end
            object PreOrderEdit: TEdit
              Left = 3
              Top = 1
              Width = 150
              Height = 25
              AutoSize = False
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Verdana'
              Font.Style = []
              ImeName = #20013#25991' ('#31616#20307') - '#24494#36719#25340#38899
              ParentFont = False
              TabOrder = 1
              Text = 'ABDCEF'
            end
          end
          object 树的广义表: TTabSheet
            Caption = '   '#26641#30340#24191#20041#34920'   '
            ImageIndex = 1
            ExplicitWidth = 312
            ExplicitHeight = 40
            object TableEdit: TEdit
              Left = 3
              Top = 1
              Width = 298
              Height = 26
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Verdana'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              Text = 'A(B(,C),D(E(F,G),H))'
            end
          end
          object 数组线性序列: TTabSheet
            Caption = #25968#32452#32447#24615#24207#21015'    '
            ImageIndex = 2
            ExplicitHeight = 25
            object TreeArrayEdit: TEdit
              Left = 0
              Top = 1
              Width = 301
              Height = 26
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Verdana'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              Text = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
            end
          end
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 801
    Top = 0
    Width = 244
    Height = 558
    Align = alRight
    TabOrder = 1
    ExplicitHeight = 560
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 242
      Height = 17
      Align = alTop
      Caption = #36755#20986#20449#24687#26174#31034
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Memo1: TMemo
      Left = 1
      Top = 18
      Width = 242
      Height = 539
      Align = alClient
      TabOrder = 0
      ExplicitTop = 14
      ExplicitHeight = 545
    end
  end
  object Timer1: TTimer
    Interval = 500
    Left = 24
    Top = 32
  end
end
