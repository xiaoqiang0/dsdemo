object Form1: TForm1
  Left = 188
  Top = 143
  Caption = #22270#31639#27861#28436#31034
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
    Left = 187
    Top = 8
    Width = 262
    Height = 53
    Caption = #26500#22270#25805#20316#38754#26495
    TabOrder = 1
    object ShortestPathBt: TButton
      Left = 98
      Top = 20
      Width = 65
      Height = 25
      Caption = #26368#20339#36335#24452
      TabOrder = 0
      OnClick = ShortestPathBtClick
    end
    object BtClearMemo: TButton
      Left = 808
      Top = 16
      Width = 83
      Height = 25
      Caption = #28165#31354#36755#20986#38754#26495
      TabOrder = 1
      OnClick = BtClearMemoClick
    end
    object CreateNodeBt: TButton
      Left = 12
      Top = 20
      Width = 74
      Height = 25
      Caption = #21019#24314#33410#28857
      TabOrder = 2
      OnClick = CreateNodeBtClick
    end
    object ResetBt: TButton
      Left = 176
      Top = 20
      Width = 75
      Height = 25
      Caption = #37325#32622#30011#26495
      TabOrder = 3
      OnClick = ResetBtClick
    end
  end
  object GraphType: TRadioGroup
    Left = 23
    Top = 8
    Width = 145
    Height = 53
    Caption = #36873#25321#22270#31867#22411
    TabOrder = 2
  end
  object RadioButtonDirect: TRadioButton
    Left = 31
    Top = 30
    Width = 57
    Height = 21
    Caption = #26377#21521#22270
    Checked = True
    TabOrder = 3
    TabStop = True
    OnClick = RadioButtonDirectClick
  end
  object RadioButtonNoDirect: TRadioButton
    Left = 94
    Top = 32
    Width = 58
    Height = 17
    Caption = #26080#21521#22270
    TabOrder = 4
    OnClick = RadioButtonNoDirectClick
  end
  object PageControl: TPageControl
    Left = 3
    Top = 67
    Width = 470
    Height = 436
    ActivePage = TabSheetDirect
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    TabWidth = 233
    object TabSheetDirect: TTabSheet
      Caption = #26377#21521#22270
      object memo: TMemo
        Left = 158
        Top = 16
        Width = 303
        Height = 366
        Color = clSilver
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object GroupBox2: TGroupBox
        Left = 3
        Top = 16
        Width = 142
        Height = 366
        Caption = #36873#25321#26377#21521#22270#31639#27861
        TabOrder = 1
        object Button1: TButton
          Left = 22
          Top = 40
          Width = 104
          Height = 25
          Caption = #22270#25628#32034'(BFS)'
          TabOrder = 0
        end
        object Button2: TButton
          Left = 22
          Top = 177
          Width = 104
          Height = 25
          Caption = #21333#28304#26368#30701#36335#24452
          TabOrder = 1
        end
        object Button3: TButton
          Left = 22
          Top = 317
          Width = 104
          Height = 25
          Caption = #25299#25169#25490#24207
          TabOrder = 2
        end
        object Button4: TButton
          Left = 22
          Top = 270
          Width = 104
          Height = 25
          Caption = #20851#38190#36335#24452
          TabOrder = 3
        end
        object Button5: TButton
          Left = 22
          Top = 131
          Width = 104
          Height = 25
          Caption = #28857#23545#28857#26368#30701#36335#24452
          TabOrder = 4
        end
        object Button6: TButton
          Left = 22
          Top = 221
          Width = 104
          Height = 25
          Caption = #20840#23616#26368#30701#36335#24452
          TabOrder = 5
        end
        object Button7: TButton
          Left = 22
          Top = 84
          Width = 104
          Height = 25
          Caption = #22270#25628#32034'(DFS)'
          TabOrder = 6
        end
      end
    end
    object TabSheetNoDirect: TTabSheet
      Caption = #26080#21521#22270
      ImageIndex = 1
    end
  end
end
