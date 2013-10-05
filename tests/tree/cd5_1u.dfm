object Form1: TForm1
  Left = 190
  Top = 172
  Width = 544
  Height = 361
  Caption = #20108#21449#26641#30340#22522#26412#24418#29366
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 296
    Width = 145
    Height = 25
    AutoSize = False
    Caption = #36755#20837#20869#23481#20540'('#25972#25968')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lout: TLabel
    Left = 224
    Top = 296
    Width = 209
    Height = 25
    AutoSize = False
    Color = clBtnHighlight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Layout = tlCenter
  end
  object ein: TEdit
    Left = 144
    Top = 296
    Width = 57
    Height = 25
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ImeName = #12356#12421' ('#32649#30768') - '#31325#29460#57646
    MaxLength = 5
    ParentFont = False
    TabOrder = 0
    OnKeyUp = einKeyUp
  end
  object pn: TPanel
    Left = 8
    Top = 8
    Width = 521
    Height = 273
    BevelInner = bvLowered
    TabOrder = 1
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 521
      Height = 273
      Transparent = True
    end
  end
  object end: TButton
    Left = 448
    Top = 296
    Width = 75
    Height = 25
    Caption = #32467'  '#26463
    TabOrder = 2
    OnClick = endClick
  end
end
