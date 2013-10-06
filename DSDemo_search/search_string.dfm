object search_stringForm: Tsearch_stringForm
  Left = 217
  Top = 113
  BorderStyle = bsSingle
  Caption = #23383#31526#20018#26597#25214#19982#26367#25442
  ClientHeight = 322
  ClientWidth = 747
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Default'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 146
    Top = 0
    Width = 601
    Height = 322
    Align = alRight
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Default'
    Font.Style = []
    HideSelection = False
    Lines.Strings = (
      
        'This example demonstrates the use of Find and Replace dialogs.  ' +
        'Choose Find or Replace from the '
      'Edit menu to find and replace text in this RichEdit control.')
    ParentFont = False
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 146
    Height = 322
    Align = alClient
    TabOrder = 1
    object searchBtn: TButton
      Left = 24
      Top = 32
      Width = 97
      Height = 41
      Caption = #26597#25214
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = searchBtnClick
    end
    object replaceBtn: TButton
      Left = 24
      Top = 125
      Width = 97
      Height = 44
      Caption = #26367#25442
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = replaceBtnClick
    end
    object Button3: TButton
      Left = 24
      Top = 224
      Width = 97
      Height = 49
      Caption = #36864#20986
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
  end
  object FindDialog1: TFindDialog
    Options = [frDown, frHideUpDown]
    OnFind = Find
    Left = 440
    Top = 88
  end
  object ReplaceDialog1: TReplaceDialog
    Options = [frDown, frHideUpDown]
    OnFind = Find
    OnReplace = Replace
    Left = 376
    Top = 88
  end
end
