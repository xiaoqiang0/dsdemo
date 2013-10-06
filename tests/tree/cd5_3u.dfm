object Form1: TForm1
  Left = 240
  Top = 111
  Caption = #20108#21449#26641#30340#22522#26412#25805#20316
  ClientHeight = 476
  ClientWidth = 1171
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 1
    Top = 0
    Width = 920
    Height = 481
    Align = alCustom
    TabOrder = 0
    object pn: TPanel
      Left = 1
      Top = 1
      Width = 918
      Height = 414
      Align = alClient
      BevelInner = bvLowered
      Color = clTeal
      TabOrder = 0
      ExplicitLeft = -275
      ExplicitTop = -222
      ExplicitWidth = 1012
      ExplicitHeight = 535
      object img: TImage
        Left = 2
        Top = 2
        Width = 914
        Height = 410
        Align = alClient
        Transparent = True
        ExplicitLeft = 162
        ExplicitTop = 140
        ExplicitWidth = 1008
        ExplicitHeight = 531
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 415
      Width = 918
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
      ExplicitLeft = -135
      ExplicitTop = 387
      ExplicitWidth = 1223
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
        OnKeyPress = einKeyPress
      end
      object Button2: TButton
        Left = 216
        Top = 24
        Width = 73
        Height = 25
        Caption = #26597#25214
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button5: TButton
        Left = 304
        Top = 24
        Width = 73
        Height = 25
        Caption = #32467#26463
        TabOrder = 2
        OnClick = Button5Click
      end
      object Button3: TButton
        Left = 128
        Top = 24
        Width = 73
        Height = 25
        Caption = #21152#20837
        TabOrder = 3
        OnClick = Button3Click
      end
    end
  end
  object Panel2: TPanel
    Left = 927
    Top = 0
    Width = 244
    Height = 476
    Align = alRight
    TabOrder = 1
    ExplicitLeft = 919
    ExplicitTop = -136
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 72
      Height = 13
      Caption = #36755#20986#20449#24687#26174#31034
    end
    object Memo1: TMemo
      Left = 1
      Top = 43
      Width = 242
      Height = 432
      Align = alBottom
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
    end
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 24
    Top = 32
  end
end
