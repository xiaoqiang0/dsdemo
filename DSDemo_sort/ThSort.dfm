object ThreadSortForm: TThreadSortForm
  Left = 229
  Top = 129
  BorderStyle = bsDialog
  Caption = #32447#31243#25490#24207#28436#31034
  ClientHeight = 502
  ClientWidth = 1207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 24
    Width = 244
    Height = 369
  end
  object Bevel3: TBevel
    Left = 511
    Top = 24
    Width = 250
    Height = 370
  end
  object Bevel2: TBevel
    Left = 258
    Top = 24
    Width = 247
    Height = 369
  end
  object BubbleSortBox: TPaintBox
    Left = 8
    Top = 24
    Width = 244
    Height = 369
    OnPaint = BubbleSortBoxPaint
  end
  object SelectionSortBox: TPaintBox
    Left = 258
    Top = 24
    Width = 247
    Height = 369
    OnPaint = SelectionSortBoxPaint
  end
  object QuickSortBox: TPaintBox
    Left = 511
    Top = 24
    Width = 250
    Height = 370
    OnPaint = QuickSortBoxPaint
  end
  object Label1: TLabel
    Left = 96
    Top = 5
    Width = 73
    Height = 13
    AutoSize = False
    Caption = #20882#27873#25490#24207
  end
  object Label2: TLabel
    Left = 338
    Top = 5
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #36873#25321#25490#24207
  end
  object Label3: TLabel
    Left = 629
    Top = 8
    Width = 86
    Height = 13
    AutoSize = False
    Caption = #24555#36895#25490#24207
  end
  object Label4: TLabel
    Left = 8
    Top = 421
    Width = 90
    Height = 16
    AutoSize = False
    Caption = #25490#24207#25968#25454#22823#23567':'
  end
  object StartBtn: TButton
    Left = 8
    Top = 443
    Width = 145
    Height = 25
    Caption = #24320#22987#25490#24207
    TabOrder = 0
    OnClick = StartBtnClick
  end
  object Chart1: TChart
    Left = 767
    Top = 64
    Width = 432
    Height = 329
    Legend.Alignment = laTop
    Legend.Font.Brush.Gradient.EndColor = clGray
    Legend.Font.Emboss.Color = 8421440
    Legend.Font.InterCharSize = 2
    Legend.Font.Shadow.Color = 8421440
    Legend.Font.Shadow.Transparency = 52
    Legend.GlobalTransparency = 2
    Legend.Symbol.Pen.Color = 201326592
    Legend.Symbol.Pen.Width = 3
    Legend.Symbol.Pen.SmallSpace = 1
    Legend.TextStyle = ltsPlain
    Legend.Title.Alignment = taCenter
    Title.Font.Height = -16
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      ' '#25490#24207#32467#26524#22270#26631#32479#35745)
    BottomAxis.ExactDateTime = False
    BottomAxis.LabelsFormat.TextAlignment = taCenter
    BottomAxis.LabelsSeparation = 0
    BottomAxis.Title.Caption = #25968#25454#22823#23567
    DepthAxis.LabelsFormat.TextAlignment = taCenter
    DepthTopAxis.LabelsFormat.TextAlignment = taCenter
    LeftAxis.Grid.SmallSpace = 1
    LeftAxis.Grid.Visible = False
    LeftAxis.LabelsFormat.TextAlignment = taCenter
    LeftAxis.LabelsOnAxis = False
    LeftAxis.Title.Angle = 0
    LeftAxis.Title.Caption = '10'#27627#31186
    LeftAxis.Title.Pen.Color = 1040187392
    LeftAxis.Title.Pen.Width = 7
    LeftAxis.TitleSize = 19
    RightAxis.LabelsFormat.TextAlignment = taCenter
    TopAxis.LabelsFormat.TextAlignment = taCenter
    View3D = False
    Zoom.Pen.Mode = pmNotXor
    TabOrder = 1
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 6
    object Bubble_Series: TFastLineSeries
      Marks.Visible = False
      SeriesColor = clTeal
      Title = 'Bubble Sort'
      LinePen.Color = clTeal
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      object TeeFunction2: TAverageTeeFunction
        CalcByValue = False
      end
    end
    object Select_Series: TFastLineSeries
      Marks.Visible = False
      SeriesColor = clRed
      Title = 'Select Sort'
      LinePen.Color = clRed
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      object TeeFunction3: TAverageTeeFunction
        CalcByValue = False
      end
    end
    object Quick_Series: TFastLineSeries
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'Quick Sort'
      LinePen.Color = clBlue
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object ComboBox1: TComboBox
    Left = 104
    Top = 416
    Width = 49
    Height = 21
    DropDownCount = 0
    TabOrder = 2
    Text = '256'
    OnChange = ComboBox1Change
  end
  object saveChartBtn: TButton
    Left = 1096
    Top = 33
    Width = 75
    Height = 25
    Caption = #20445#23384#22270#34920
    TabOrder = 3
    OnClick = saveChartBtnClick
  end
  object Button1: TButton
    Left = 175
    Top = 443
    Width = 138
    Height = 25
    Caption = #33258#21160#25191#34892
    TabOrder = 4
    OnClick = Button1Click
  end
  object SaveDialog1: TSaveDialog
    Left = 1040
    Top = 24
  end
end
