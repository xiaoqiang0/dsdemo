object BiTreeForm: TBiTreeForm
  Left = 240
  Top = 111
  Caption = #20108#21449#26641#30340#22522#26412#25805#20316
  ClientHeight = 560
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
    Height = 560
    Align = alClient
    TabOrder = 0
    object pn: TPanel
      Left = 1
      Top = 1
      Width = 799
      Height = 471
      Align = alClient
      BevelInner = bvLowered
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 0
      object img: TImage
        Left = 2
        Top = 2
        Width = 795
        Height = 467
        Align = alClient
        Transparent = True
        ExplicitLeft = 0
        ExplicitTop = -2
        ExplicitHeight = 407
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 472
      Width = 799
      Height = 87
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
        Left = 544
        Top = 15
        Width = 253
        Height = 70
        Align = alRight
        TabOrder = 0
        object Button1: TButton
          Left = 56
          Top = 45
          Width = 73
          Height = 24
          Caption = #21518#24207#36941#21382
          TabOrder = 0
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 56
          Top = 24
          Width = 73
          Height = 22
          Caption = #20013#24207#36941#21382
          TabOrder = 1
        end
        object Button3: TButton
          Left = 56
          Top = 1
          Width = 73
          Height = 24
          Caption = #21069#24207#36941#21382
          TabOrder = 2
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 136
          Top = 1
          Width = 73
          Height = 25
          Caption = #26641#30340#28145#24230
          TabOrder = 3
        end
        object Button6: TButton
          Left = 135
          Top = 45
          Width = 73
          Height = 24
          Caption = #32467#26463
          TabOrder = 4
          OnClick = Button1Click
        end
      end
      object PageControl1: TPageControl
        Left = 2
        Top = 15
        Width = 299
        Height = 70
        ActivePage = 数组线性序列
        Align = alLeft
        MultiLine = True
        TabOrder = 1
        object TabSheet1: TTabSheet
          Caption = '  '#21069#24207#21644#20013#24207#24207#21015'  '
          object InOrderEdit: TEdit
            Left = 126
            Top = 9
            Width = 112
            Height = 25
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ImeName = #20013#25991' ('#31616#20307') - '#24494#36719#25340#38899
            ParentFont = False
            TabOrder = 0
            Text = 'BDAEFC'
          end
          object PreOrderEdit: TEdit
            Left = 4
            Top = 9
            Width = 109
            Height = 25
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
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
          object TableEdit: TEdit
            Left = 6
            Top = 13
            Width = 217
            Height = 21
            TabOrder = 0
            Text = 'A(B(,C),D(E(F,G),H))'
          end
        end
        object 数组线性序列: TTabSheet
          Caption = #25968#32452#32447#24615#24207#21015'    '
          ImageIndex = 2
          object TreeArrayEdit: TEdit
            Left = 3
            Top = 13
            Width = 231
            Height = 21
            TabOrder = 0
            Text = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
          end
        end
      end
      object BitBtn1: TBitBtn
        Left = 328
        Top = 40
        Width = 75
        Height = 25
        Caption = #21019#24314#20108#21449#26641
        TabOrder = 2
        OnClick = BitBtn1Click
      end
    end
  end
  object Panel2: TPanel
    Left = 801
    Top = 0
    Width = 244
    Height = 560
    Align = alRight
    TabOrder = 1
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 242
      Height = 13
      Align = alTop
      Caption = #36755#20986#20449#24687#26174#31034
      ExplicitWidth = 72
    end
    object Memo1: TMemo
      Left = 1
      Top = 14
      Width = 242
      Height = 545
      Align = alClient
      TabOrder = 0
    end
  end
  object Timer1: TTimer
    Interval = 500
    Left = 24
    Top = 32
  end
end
