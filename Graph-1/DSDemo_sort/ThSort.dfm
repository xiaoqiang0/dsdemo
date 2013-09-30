object ThreadSortForm: TThreadSortForm
  Left = 229
  Top = 129
  BorderStyle = bsDialog
  Caption = #32447#31243#25490#24207#28436#31034
  ClientHeight = 471
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
    Width = 264
    Height = 369
  end
  object Bevel3: TBevel
    Left = 546
    Top = 24
    Width = 264
    Height = 370
  end
  object Bevel2: TBevel
    Left = 278
    Top = 24
    Width = 262
    Height = 369
  end
  object BubbleSortBox: TPaintBox
    Left = 8
    Top = 24
    Width = 264
    Height = 369
    OnPaint = BubbleSortBoxPaint
  end
  object SelectionSortBox: TPaintBox
    Left = 278
    Top = 24
    Width = 262
    Height = 369
    OnPaint = SelectionSortBoxPaint
  end
  object QuickSortBox: TPaintBox
    Left = 546
    Top = 24
    Width = 264
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
    Left = 358
    Top = 5
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #36873#25321#25490#24207
  end
  object Label3: TLabel
    Left = 664
    Top = 8
    Width = 86
    Height = 13
    AutoSize = False
    Caption = #24555#36895#25490#24207
  end
  object Label4: TLabel
    Left = 8
    Top = 421
    Width = 66
    Height = 13
    Caption = #25490#24207#25968#25454
  end
  object StartBtn: TButton
    Left = 159
    Top = 416
    Width = 75
    Height = 25
    Caption = #24320#22987#25490#24207
    TabOrder = 0
    OnClick = StartBtnClick
  end
  object Chart1: TChart
    Left = 816
    Top = 24
    Width = 385
    Height = 369
    Legend.GlobalTransparency = 2
    Legend.Visible = False
    Title.Text.Strings = (
      ' '#25490#24207#32467#26524#22270#26631#32479#35745)
    BottomAxis.ExactDateTime = False
    BottomAxis.LabelsFormat.TextAlignment = taCenter
    BottomAxis.LabelsSeparation = 0
    DepthAxis.LabelsFormat.TextAlignment = taCenter
    DepthTopAxis.LabelsFormat.TextAlignment = taCenter
    LeftAxis.Grid.SmallSpace = 1
    LeftAxis.LabelsFormat.TextAlignment = taCenter
    RightAxis.LabelsFormat.TextAlignment = taCenter
    TopAxis.LabelsFormat.TextAlignment = taCenter
    View3D = False
    Zoom.Pen.Mode = pmNotXor
    TabOrder = 1
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 6
    object Series1: TFastLineSeries
      Marks.Visible = False
      SeriesColor = clTeal
      LinePen.Color = clTeal
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      object TeeFunction2: TAverageTeeFunction
        CalcByValue = False
      end
    end
    object Series2: TFastLineSeries
      Marks.Visible = False
      SeriesColor = clBlue
      LinePen.Color = clBlue
      LinePen.SmallSpace = 1
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      object TeeFunction1: TCustomTeeFunction
        CalcByValue = False
        Period = 1.000000000000000000
        NumPoints = 100
      end
    end
    object Series3: TFastLineSeries
      Marks.Visible = False
      SeriesColor = clRed
      LinePen.Color = clRed
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      object TeeFunction3: TAverageTeeFunction
        CalcByValue = False
      end
    end
  end
  object Button1: TButton
    Left = 262
    Top = 416
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 80
    Top = 418
    Width = 49
    Height = 21
    TabOrder = 3
    Text = '256'
    Items.Strings = (
      '64'
      '128'
      '192'
      '256'
      '320'
      '384'
      '448'
      '512')
  end
end
