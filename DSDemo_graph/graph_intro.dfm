object GraphIntroduceForm: TGraphIntroduceForm
  Left = 0
  Top = 0
  Caption = #22270#20171#32461
  ClientHeight = 485
  ClientWidth = 894
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl2: TPageControl
    Left = 0
    Top = 0
    Width = 894
    Height = 485
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    MultiLine = True
    ParentFont = False
    TabOrder = 0
    TabPosition = tpBottom
    object TabSheet1: TTabSheet
      Caption = #22270#20171#32461
      object RichEdit1: TRichEdit
        Left = 0
        Top = 0
        Width = 886
        Height = 449
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
      end
    end
    object TabSheet2: TTabSheet
      Caption = #22270#30340#36941#21382
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object RichEdit2: TRichEdit
        Left = 0
        Top = 0
        Width = 886
        Height = 449
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEdit2')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = #26368#23567#29983#25104#26641
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object RichEdit4: TRichEdit
        Left = 0
        Top = 0
        Width = 886
        Height = 449
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEdit4')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = #26368#30701#36335#24452
      ImageIndex = 2
      object RichEdit3: TRichEdit
        Left = 0
        Top = 0
        Width = 886
        Height = 449
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEdit3')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
