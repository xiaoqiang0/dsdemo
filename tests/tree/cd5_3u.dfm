object BiTreeForm: TBiTreeForm
  Left = 240
  Top = 111
  Caption = #20108#21449#26641#30340#22522#26412#25805#20316
  ClientHeight = 478
  ClientWidth = 1045
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 801
    Height = 478
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 821
    ExplicitHeight = 476
    object pn: TPanel
      Left = 1
      Top = 1
      Width = 799
      Height = 411
      Align = alClient
      BevelInner = bvLowered
      Color = clTeal
      TabOrder = 0
      ExplicitWidth = 819
      ExplicitHeight = 409
      object img: TImage
        Left = 2
        Top = 2
        Width = 795
        Height = 407
        Align = alClient
        Transparent = True
        ExplicitLeft = 0
        ExplicitTop = -2
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 412
      Width = 799
      Height = 65
      Align = alBottom
      BiDiMode = bdLeftToRight
      Caption = #25805#20316#38754#26495
      Color = clOlive
      ParentBiDiMode = False
      ParentColor = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      ExplicitLeft = -3
      ExplicitTop = 421
      ExplicitWidth = 804
      object ein: TEdit
        Left = 16
        Top = 24
        Width = 73
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
      end
      object Button2: TButton
        Left = 207
        Top = 24
        Width = 73
        Height = 25
        Caption = #26597#25214
        TabOrder = 1
      end
      object Button5: TButton
        Left = 304
        Top = 24
        Width = 73
        Height = 25
        Caption = #32467#26463
        TabOrder = 2
      end
      object Button3: TButton
        Left = 128
        Top = 24
        Width = 73
        Height = 25
        Caption = #21152#20837
        TabOrder = 3
      end
      object Button1: TButton
        Left = 392
        Top = 24
        Width = 73
        Height = 25
        Caption = #32467#26463
        TabOrder = 4
        OnClick = Button1Click
      end
      object StatusBar1: TStatusBar
        Left = 2
        Top = 44
        Width = 795
        Height = 19
        Panels = <
          item
            Width = 50
          end>
        ExplicitLeft = -22
      end
    end
  end
  object Panel2: TPanel
    Left = 801
    Top = 0
    Width = 244
    Height = 478
    Align = alRight
    TabOrder = 1
    ExplicitLeft = 821
    ExplicitHeight = 476
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
      Height = 463
      Align = alClient
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
      ExplicitLeft = 3
      ExplicitHeight = 468
    end
  end
  object Timer1: TTimer
    Interval = 500
    Left = 24
    Top = 32
  end
end
