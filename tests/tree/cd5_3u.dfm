object Form1: TForm1
  Left = 240
  Top = 111
  Width = 428
  Height = 334
  Caption = #20108#21449#26641#30340#22522#26412#25805#20316
  Color = clOlive
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 232
    Width = 401
    Height = 65
    BiDiMode = bdLeftToRight
    Caption = #25805#20316#38754#26495
    Color = clOlive
    ParentBiDiMode = False
    ParentColor = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
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
  object TPanel
    Left = 8
    Top = 8
    Width = 401
    Height = 217
    BevelInner = bvLowered
    Color = clMenu
    TabOrder = 1
    object pn: TPanel
      Left = 8
      Top = 8
      Width = 385
      Height = 201
      BevelInner = bvLowered
      Color = clTeal
      TabOrder = 0
      object img: TImage
        Left = 0
        Top = 0
        Width = 385
        Height = 201
        Transparent = True
      end
    end
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 24
    Top = 32
  end
end
