object BinarySearchForm: TBinarySearchForm
  Left = 0
  Top = 0
  Align = alCustom
  Caption = #20108#20998#26597#25214' & '#39034#24207#26597#25214
  ClientHeight = 311
  ClientWidth = 856
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 146
    Top = 0
    Width = 97
    Height = 311
    Align = alRight
    Caption = #36873#25321#26597#25214#26041#27861
    TabOrder = 1
    ExplicitTop = 32
    ExplicitHeight = 279
  end
  object RadioButton1: TRadioButton
    Left = 160
    Top = 60
    Width = 77
    Height = 17
    Caption = #20108#20998#26597#25214
    Checked = True
    TabOrder = 2
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 160
    Top = 115
    Width = 77
    Height = 17
    Caption = #39034#24207#26597#25214
    TabOrder = 3
  end
  object Button2: TButton
    Left = 152
    Top = 175
    Width = 85
    Height = 25
    Caption = #26597#25214
    TabOrder = 0
  end
  object Chart1: TChart
    Left = 243
    Top = 0
    Width = 613
    Height = 311
    BackWall.Brush.Style = bsClear
    Foot.Font.Height = -12
    Foot.Frame.Color = clScrollBar
    Title.Frame.Color = clWhite
    Title.Text.Strings = (
      #20108#20998#26597#25214#21644#32447#24615#39034#24207#26597#25214#27604#36739)
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.DateTimeFormat = 'MM/dd/yy'
    BottomAxis.Grid.Color = clScrollBar
    BottomAxis.LabelsFormat.TextAlignment = taCenter
    BottomAxis.Ticks.Visible = False
    BottomAxis.Title.Caption = #19981#21516#26597#25214#31639#27861
    Chart3DPercent = 35
    DepthAxis.LabelsFormat.TextAlignment = taCenter
    DepthTopAxis.LabelsFormat.TextAlignment = taCenter
    LeftAxis.Grid.Color = clScrollBar
    LeftAxis.LabelsFormat.TextAlignment = taCenter
    LeftAxis.Title.Caption = #24179#22343#27604#36739#27425#25968
    LeftAxis.Title.Pen.Width = 5
    LeftAxis.Title.Pen.SmallSpace = 1
    LeftAxis.Title.RoundSize = 18
    LeftAxis.Title.ShapeStyle = fosRoundRectangle
    LeftAxis.TitleSize = 34
    RightAxis.Grid.Color = clScrollBar
    RightAxis.LabelsFormat.TextAlignment = taCenter
    TopAxis.Grid.Color = clScrollBar
    TopAxis.LabelsFormat.TextAlignment = taCenter
    View3DOptions.OrthoAngle = 55
    View3DOptions.Zoom = 102
    Zoom.Pen.Mode = pmNotXor
    Align = alRight
    TabOrder = 4
    ExplicitLeft = 283
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      26
      15
      26)
    ColorPaletteIndex = 13
    object BarSeries1: TBarSeries
      ColorEachPoint = True
      Marks.Visible = True
      SeriesColor = clRed
      XValues.DateTime = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      Left = 15
      Top = 52
      Data = {
        010300000000000000000000000000000000207C40000000000000F03F000000
        0000087B4000000000000008400000000000307B40}
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 146
    Height = 311
    Align = alClient
    TabOrder = 5
    ExplicitWidth = 223
    ExplicitHeight = 314
    object Label1: TLabel
      Left = 2
      Top = 6
      Width = 48
      Height = 13
      Caption = #25968#25454#20010#25968':'
    end
    object ListBox1: TListBox
      Left = 1
      Top = 50
      Width = 144
      Height = 260
      Align = alBottom
      ItemHeight = 13
      TabOrder = 0
      ExplicitLeft = 2
      ExplicitTop = 60
    end
    object Button1: TButton
      Left = 64
      Top = 6
      Width = 76
      Height = 38
      Caption = #29983#25104#25968#25454
      TabOrder = 1
      OnClick = Button1Click
    end
    object ComboBox1: TComboBox
      Left = 1
      Top = 22
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '10000'
    end
  end
end
