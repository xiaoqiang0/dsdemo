object Form1: TForm1
  Left = 166
  Top = 83
  Width = 703
  Height = 330
  Caption = #32467#26500#20108#21449#26641
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lout: TLabel
    Left = 328
    Top = 272
    Width = 281
    Height = 25
    AutoSize = False
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object ein: TEdit
    Left = 232
    Top = 272
    Width = 89
    Height = 25
    Hint = #22359#58864#20465#35745#57502#57523'Enter'#40836
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ImeName = #12356#12421' ('#32649#30768') - '#31325#29460#57646
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnKeyUp = einKeyUp
  end
  object show: TButton
    Left = 8
    Top = 272
    Width = 217
    Height = 25
    Caption = #32467#26500#20869#23481#26174#31034
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = showClick
  end
  object sg: TStringGrid
    Left = 8
    Top = 8
    Width = 217
    Height = 257
    ColCount = 4
    DefaultColWidth = 48
    RowCount = 32
    TabOrder = 2
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object pn: TPanel
    Left = 232
    Top = 8
    Width = 457
    Height = 257
    BevelInner = bvLowered
    TabOrder = 3
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 457
      Height = 257
      Transparent = True
    end
  end
  object end: TButton
    Left = 616
    Top = 272
    Width = 73
    Height = 25
    Caption = #32467#26463
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = endClick
  end
end
