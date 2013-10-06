object GraphMSTForm: TGraphMSTForm
  Left = 188
  Top = 143
  Caption = #26368#23567#29983#25104#26641
  ClientHeight = 504
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
    Left = 321
    Top = 0
    Width = 779
    Height = 504
    Cursor = crCross
    Hint = #31243#12558#38548#30038#31734#29916#36299
    Align = alClient
    BevelInner = bvLowered
    BevelOuter = bvLowered
    Enabled = False
    TabOrder = 0
    ExplicitLeft = 479
    ExplicitTop = 8
    ExplicitWidth = 615
    ExplicitHeight = 495
    object img: TImage
      Left = 2
      Top = 2
      Width = 775
      Height = 500
      Align = alClient
      Transparent = True
      OnMouseDown = imgMouseDown
      OnMouseUp = imgMouseUp
      ExplicitLeft = -162
      ExplicitTop = -448
      ExplicitWidth = 617
      ExplicitHeight = 497
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 321
    Height = 504
    Align = alLeft
    TabOrder = 1
    ExplicitTop = 4
    object memo: TMemo
      Left = 1
      Top = 49
      Width = 319
      Height = 454
      Align = alClient
      Color = clSilver
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 0
      ExplicitLeft = 18
      ExplicitTop = 235
      ExplicitWidth = 303
      ExplicitHeight = 284
    end
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 319
      Height = 48
      Align = alTop
      TabOrder = 1
      object GroupBox1: TGroupBox
        Left = 1
        Top = 1
        Width = 139
        Height = 46
        Align = alLeft
        Caption = #26500#22270#25805#20316#38754#26495
        TabOrder = 0
        ExplicitLeft = -1
        ExplicitTop = 10
        ExplicitHeight = 53
        object CreateNodeBtn: TButton
          Left = 6
          Top = 20
          Width = 64
          Height = 25
          Caption = #21019#24314#33410#28857
          TabOrder = 0
          OnClick = CreateNodeBtnClick
        end
        object ResetBtn: TButton
          Left = 75
          Top = 20
          Width = 61
          Height = 25
          Caption = #37325#32622#30011#26495
          TabOrder = 1
          OnClick = ResetBtnClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 157
        Top = 1
        Width = 161
        Height = 46
        Align = alRight
        Caption = #26368#23567#29983#25104#26641#31639#27861
        TabOrder = 1
        ExplicitLeft = 146
        ExplicitTop = 10
        ExplicitHeight = 53
        object PrimBtn: TButton
          Left = 8
          Top = 19
          Width = 66
          Height = 23
          Caption = 'Prim '#31639#27861
          TabOrder = 0
          OnClick = PrimBtnClick
        end
        object KruskalBtn: TButton
          Left = 82
          Top = 19
          Width = 71
          Height = 23
          Caption = 'Kruskal '#31639#27861
          TabOrder = 1
          OnClick = KruskalBtnClick
        end
      end
    end
  end
end
