object GraphMSTForm: TGraphMSTForm
  Left = 188
  Top = 143
  Caption = #26368#23567#29983#25104#26641
  ClientHeight = 511
  ClientWidth = 1100
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
  object pnl: TPanel
    Left = 479
    Top = 8
    Width = 615
    Height = 495
    Cursor = crCross
    Hint = #31243#12558#38548#30038#31734#29916#36299
    BevelInner = bvLowered
    BevelOuter = bvLowered
    Enabled = False
    TabOrder = 0
    object img: TImage
      Left = 0
      Top = 0
      Width = 617
      Height = 497
      Transparent = True
      OnMouseDown = imgMouseDown
      OnMouseUp = imgMouseUp
    end
  end
  object GroupBox1: TGroupBox
    Left = 304
    Top = 8
    Width = 169
    Height = 53
    Caption = #26500#22270#25805#20316#38754#26495
    TabOrder = 4
    object CreateNodeBtn: TButton
      Left = 3
      Top = 20
      Width = 74
      Height = 25
      Caption = #21019#24314#33410#28857
      TabOrder = 0
      OnClick = CreateNodeBtnClick
    end
    object ResetBtn: TButton
      Left = 83
      Top = 20
      Width = 75
      Height = 25
      Caption = #37325#32622#30011#26495
      TabOrder = 1
      OnClick = ResetBtnClick
    end
  end
  object GraphType: TRadioGroup
    Left = 15
    Top = 8
    Width = 137
    Height = 53
    Caption = #36873#25321#22270#31867#22411
    TabOrder = 1
  end
  object DirectBtn: TRadioButton
    Left = 84
    Top = 30
    Width = 61
    Height = 21
    Caption = #26377#21521#22270
    TabOrder = 2
    OnClick = DirectBtnClick
  end
  object NoDirectBtn: TRadioButton
    Left = 20
    Top = 32
    Width = 62
    Height = 17
    Caption = #26080#21521#22270
    Checked = True
    Ctl3D = True
    ParentCtl3D = False
    TabOrder = 3
    TabStop = True
    OnClick = NoDirectBtnClick
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 80
    Width = 156
    Height = 129
    Caption = #26368#23567#29983#25104#26641#31639#27861
    TabOrder = 5
    object PrimBtn: TButton
      Left = 3
      Top = 34
      Width = 138
      Height = 26
      Caption = #29983#25104#26368#23567#29983#25104#26641'(Prim)'
      TabOrder = 0
      OnClick = PrimBtnClick
    end
    object KruskalBtn: TButton
      Left = 4
      Top = 86
      Width = 139
      Height = 26
      Caption = #29983#25104#26368#23567#29983#25104#26641'(Kruskal )'
      TabOrder = 1
      OnClick = KruskalBtnClick
    end
  end
  object memo: TMemo
    Left = 170
    Top = 80
    Width = 303
    Height = 402
    Color = clSilver
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 6
  end
end
