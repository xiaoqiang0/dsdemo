object GraphIntroduceForm: TGraphIntroduceForm
  Left = 0
  Top = 0
  Caption = #22270#20171#32461
  ClientHeight = 472
  ClientWidth = 914
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl2: TPageControl
    Left = 0
    Top = 0
    Width = 914
    Height = 472
    ActivePage = TabSheet1
    Align = alClient
    MultiLine = True
    TabOrder = 0
    TabPosition = tpBottom
    object TabSheet1: TTabSheet
      Caption = #22270#20171#32461
      ExplicitLeft = 84
      ExplicitTop = -76
      ExplicitWidth = 529
      ExplicitHeight = 280
      object RichEdit1: TRichEdit
        Left = 0
        Top = 0
        Width = 906
        Height = 446
        Align = alClient
        Alignment = taRightJustify
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitLeft = 40
        ExplicitTop = 15
        ExplicitWidth = 325
        ExplicitHeight = 262
      end
    end
    object TabSheet2: TTabSheet
      Caption = #22270#30340#36941#21382
      ImageIndex = 1
      ExplicitWidth = 385
      ExplicitHeight = 216
      object RichEdit2: TRichEdit
        Left = 0
        Top = 0
        Width = 906
        Height = 446
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEdit2')
        ParentFont = False
        TabOrder = 0
        ExplicitLeft = 384
        ExplicitTop = 200
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
    object TabSheet3: TTabSheet
      Caption = #26368#30701#36335#24452
      ImageIndex = 2
      ExplicitLeft = -12
      ExplicitTop = 68
      ExplicitWidth = 385
      ExplicitHeight = 216
      object RichEdit3: TRichEdit
        Left = 0
        Top = 0
        Width = 906
        Height = 446
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEdit3')
        ParentFont = False
        TabOrder = 0
        ExplicitHeight = 321
      end
    end
  end
end
