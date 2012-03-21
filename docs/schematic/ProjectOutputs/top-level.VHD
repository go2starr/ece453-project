------------------------------------------------------------
-- VHDL topMINUSlevel
-- 2012 2 24 11 49 10
-- Created By "DXP VHDL Generator"
-- "Copyright (c) 2002-2004 Altium Limited"
------------------------------------------------------------

------------------------------------------------------------
-- VHDL topMINUSlevel
------------------------------------------------------------

Library IEEE;
Use     IEEE.std_logic_1164.all;

Entity topMINUSlevel Is
  attribute MacroCell : boolean;

End topMINUSlevel;
------------------------------------------------------------

------------------------------------------------------------
architecture structure of topMINUSlevel is
   Component X_3MINUSaxis_Ac_meter                           -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        SPI : inout STD_LOGIC                                -- ObjectKind=Pin|PrimaryId=*-SPI
      );
   End Component;

   Component X_38kHz_Encoder                                 -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        UNDEFINED : in STD_LOGIC                             -- ObjectKind=Pin|PrimaryId=*-
      );
   End Component;

   Component X_38kHz_Decoder_Receiver                        -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        RX_DAT : inout STD_LOGIC                             -- ObjectKind=Pin|PrimaryId=*-RX_DAT
      );
   End Component;

   Component X_38kHz_Encoder_Transmitter                     -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        TX_DAT : inout STD_LOGIC                             -- ObjectKind=Pin|PrimaryId=*-TX_DAT
      );
   End Component;

   Component ACC_PORT                                        -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        FROM_RX_Breadboard_PCB : in  STD_LOGIC;              -- ObjectKind=Pin|PrimaryId=*-FROM_RX (Breadboard/PCB)
        RX_DAT                 : out STD_LOGIC;              -- ObjectKind=Pin|PrimaryId=*-RX_DAT
        TO_TX_Breadboard_PCB   : out STD_LOGIC;              -- ObjectKind=Pin|PrimaryId=*-TO_TX (Breadboard/PCB)
        TX_DAT                 : in  STD_LOGIC               -- ObjectKind=Pin|PrimaryId=*-TX_DAT
      );
   End Component;

   Component ARM                                             -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        ADDRESS : out   STD_LOGIC;                           -- ObjectKind=Pin|PrimaryId=*-ADDRESS
        DATA    : inout STD_LOGIC                            -- ObjectKind=Pin|PrimaryId=*-DATA
      );
   End Component;

   Component FPGA                                            -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        ADDRESS : in    STD_LOGIC;                           -- ObjectKind=Pin|PrimaryId=*-ADDRESS
        DATA    : inout STD_LOGIC;                           -- ObjectKind=Pin|PrimaryId=*-DATA
        RX      : in    STD_LOGIC;                           -- ObjectKind=Pin|PrimaryId=*-RX
        TX      : out   STD_LOGIC                            -- ObjectKind=Pin|PrimaryId=*-TX
      );
   End Component;

   Component IR_Receiver                                     -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        RX_DAT : out STD_LOGIC                               -- ObjectKind=Pin|PrimaryId=*-RX DAT
      );
   End Component;

   Component IR_Xmitter                                      -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        TX_DAT : in STD_LOGIC                                -- ObjectKind=Pin|PrimaryId=*-TX DAT
      );
   End Component;

   Component PS3_Controller                                  -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        miniUSB : inout STD_LOGIC                            -- ObjectKind=Pin|PrimaryId=*-miniUSB
      );
   End Component;

   Component uC                                              -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        X_9  : inout STD_LOGIC;                              -- ObjectKind=Pin|PrimaryId=*-9
        X_10 : inout STD_LOGIC                               -- ObjectKind=Pin|PrimaryId=*-10
      );
   End Component;

   Component USB_Controller                                  -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        ADDRESS      : in    STD_LOGIC;                      -- ObjectKind=Pin|PrimaryId=*-ADDRESS
        DATA         : inout STD_LOGIC;                      -- ObjectKind=Pin|PrimaryId=*-DATA
        USB_internal : inout STD_LOGIC                       -- ObjectKind=Pin|PrimaryId=*-USB_internal
      );
   End Component;

   Component USB_Port                                        -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      port
      (
        USB              : inout STD_LOGIC;                  -- ObjectKind=Pin|PrimaryId=*-USB
        USBMINUSinternal : inout STD_LOGIC                   -- ObjectKind=Pin|PrimaryId=*-USB-internal
      );
   End Component;


    Signal NamedIOSignal_DATA : STD_LOGIC;
    Signal NamedIOSignal_miniUSB : STD_LOGIC;
    Signal NamedIOSignal_USB : STD_LOGIC;
    Signal NamedIOSignal_USB_internal : STD_LOGIC;
    Signal NamedIOSignal_USBMINUSinternal : STD_LOGIC;
    Signal PinSignal_ADDRESS : STD_LOGIC; -- ObjectKind=Net|PrimaryId=Net*_ADDRESS
    Signal PinSignal_RX_DAT  : STD_LOGIC; -- ObjectKind=Net|PrimaryId=Net*_RX
    Signal PinSignal_TX      : STD_LOGIC; -- ObjectKind=Net|PrimaryId=Net*_TX

begin
    X : X_38kHz_Decoder_Receiver                             -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : IR_Xmitter                                           -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : X_38kHz_Encoder                                      -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : X_38kHz_Encoder_Transmitter                          -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : X_3MINUSaxis_Ac_meter                                -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : uC                                                   -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : IR_Receiver                                          -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
;

    X : FPGA                                                 -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      Port Map
      (
        ADDRESS => PinSignal_ADDRESS,                        -- ObjectKind=Pin|PrimaryId=*-ADDRESS
        DATA    => NamedIOSignal_DATA,                       -- ObjectKind=Pin|PrimaryId=*-DATA
        RX      => PinSignal_RX_DAT,                         -- ObjectKind=Pin|PrimaryId=*-RX
        TX      => PinSignal_TX                              -- ObjectKind=Pin|PrimaryId=*-TX
      );

    X : ACC_PORT                                             -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      Port Map
      (
        RX_DAT => PinSignal_RX_DAT,                          -- ObjectKind=Pin|PrimaryId=*-RX_DAT
        TX_DAT => PinSignal_TX                               -- ObjectKind=Pin|PrimaryId=*-TX_DAT
      );

    X : ARM                                                  -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      Port Map
      (
        ADDRESS => PinSignal_ADDRESS,                        -- ObjectKind=Pin|PrimaryId=*-ADDRESS
        DATA    => NamedIOSignal_DATA                        -- ObjectKind=Pin|PrimaryId=*-DATA
      );

    X : USB_Controller                                       -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      Port Map
      (
        DATA         => NamedIOSignal_DATA,                  -- ObjectKind=Pin|PrimaryId=*-DATA
        USB_internal => NamedIOSignal_USB_internal           -- ObjectKind=Pin|PrimaryId=*-USB_internal
      );

    X : USB_Port                                             -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      Port Map
      (
        USB              => NamedIOSignal_USB,               -- ObjectKind=Pin|PrimaryId=*-USB
        USBMINUSinternal => NamedIOSignal_USBMINUSinternal   -- ObjectKind=Pin|PrimaryId=*-USB-internal
      );

    X : PS3_Controller                                       -- ObjectKind=Part|PrimaryId=*|SecondaryId=1
      Port Map
      (
        miniUSB => NamedIOSignal_miniUSB                     -- ObjectKind=Pin|PrimaryId=*-miniUSB
      );

end structure;
------------------------------------------------------------

