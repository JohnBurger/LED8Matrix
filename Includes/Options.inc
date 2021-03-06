;
; Options.inc
; This file defines which way the code should operate:
; * Which modules to Enable
; * How different BOARDs work - and the resultant constants
; * How different UPDATEs work - and the resultant constants
;

$IF  (NOT OPTIONS_INC)
$SET (OPTIONS_INC)

                $INCLUDE        (John.inc)

; Need to select which CPU.
CPU_STC12       EQU             12
CPU_STC89       EQU             89
CPU_Demo        EQU             CPU_STC89 ; Which demo board is in use
;CPU            EQU             CPU_STC12 ; Example

; Need to select a Clock Frequency. To avoid 32-bit arithmetic, it's factored
Clock_11059200  EQU             21600   ; 11.0592 MHz in 512 Hz steps
Clock_33177600  EQU             64800   ; 33.1776 MHz in 512 Hz steps
;Clock_Freq     EQU             Clock_33177600 ; Example

$SET (EYES_Enable)
;$SET (INT0_Enable)             ; Set to enable Externel Int 0 code
;$SET (INT1_Enable)             ; Set to enable External Int 1 code
$SET (TIMER0_Enable)            ; Set to enable Timer0 code
;$SET (TIMER1_Enable)           ; Set to enable Timer1 code
;$SET (TIMER2_Enable)           ; Set to enable Timer2 code
;$SET (SERIAL_Enable)           ; Set to enable all Serial code
;$SET (BAUD_Enable)             ; Set to enable Baud Rate Generator
;$SET (UART_Enable)             ; Set to enable UART code
;$SET (UART2_Enable)            ; Set to enable UART2 code
;   $SET (UART2_Alt)            ; Set to move UART2 to alternate pins
;$SET (ADC_Enable)              ; Set to enable Analog-digital converter code
;$SET (LVD_Enable)              ; Set to enable Low-Voltage Detect code
;$SET (PCA_Enable)              ; Set to enable Programmable Counter code
;$SET (SPI_Enable)              ; Set to enable Serial Peripheral Interface code
$SET (FLASH_Enable)             ; Set to enable Flash memory code

;$SET (DIGIPOT_Enable)          ; Set to enable DigiPot code
$SET (LED8X8_Enable)            ; Set to enable LED 8x8 matrix code

$SET (FONT7x6_Enable)           ; Set to enable font programming
;$SET (FONT8x8_Enable)          ; Set to enable font programming

aFONT_Table     EQU             00500h

; Different interrups have different priorities
INT_Priority_0  EQU             00b     ; Lowest priority
INT_Priority_1  EQU             01b
INT_Priority_2  EQU             10b
INT_Priority_3  EQU             11b     ; Highest priority
;TIMER0_Priority EQU             INT_Priority_3 ; Examples
;TIMER1_Priority EQU             INT_Priority_0
;UART_Priority   EQU             INT_Priority_2
;UART2_Priority  EQU             INT_Priority_2

; The two Timers can be in different Modes - but if Timer0 is in Timer_Mode_8,
; then so will Timer1! (If only Timer1 is, then it is disabled.)
TIMER_Mode_13   EQU             00b    ; 13-bit timer/counter
TIMER_Mode_16   EQU             01b    ; 16-bit timer/counter
TIMER_Mode_8_Auto EQU           10b    ; 8-bit timer/counter, auto-reloaded
TIMER_Mode_8    EQU             11b    ; 2x8_bit timer/counters
TIMER_Mode_Mask EQU             11b    ; Mask for just Mode value
TIMER_Mode_x12  EQU             10000000b ; Mask to indicate x12 mode
;TIMER0_Mode    EQU             TIMER_Mode_x12+TIMER_Mode_8_Auto ; Example
;TIMER1_Mode    EQU             TIMER_Mode_16

; This is the rate of the Baud Rate Timer. It's factored down to avoid 32 bits
BAUD_x1         EQU             08000h ; Mask to flag to NOT use x12
BAUD_75         EQU             BAUD_x1 + 75
BAUD_150        EQU             BAUD_x1 + 150
BAUD_300        EQU             BAUD_x1 + 300
BAUD_600        EQU             BAUD_x1 + 600
BAUD_1200       EQU                75 ;   1,200 baud in 16 Hz steps
BAUD_2400       EQU               150 ;   2,400 baud in 16 Hz steps
BAUD_4800       EQU               300 ;   4,800 baud in 16 Hz steps
BAUD_9600       EQU               600 ;   9,600 baud in 16 Hz steps
BAUD_19200      EQU              1200 ;  19,200 baud in 16 Hz steps
BAUD_38400      EQU              2400 ;  38,400 baud in 16 Hz steps
BAUD_57600      EQU              3600 ;  57,600 baud in 16 Hz steps
BAUD_115200     EQU              7200 ; 115,200 baud in 16 Hz steps
BAUD_230400     EQU             14400 ; 230,400 baud in 16 Hz steps
BAUD_345600     EQU             21600 ; 345,600 baud in 16 Hz steps
;BAUD_Rate      EQU             BAUD_115200 ; Example

UART_Mode_x2     EQU            10000000b ; Mask to double UART baud rate (not 000b)
UART_Mode_BRG    EQU            01000000b ; Mask to use BRG, not Timer1  (not UART2)
UART_Mode_8Shift EQU                 000b
UART_Mode_8Var   EQU                 010b
UART_Mode_9Shift EQU                 100b
UART_Mode_9Var   EQU                 110b
UART_Mode_Frame  EQU                 001b ; Mask to enable Frame Error Checking
UART_Mode_Mask   EQU                0111b ; Mask for just Mode value
;UART_Mode       EQU            UART_Mode_BRG+UART_Mode_8Var ; Examples
;UART2_Mode      EQU            UART_Mode_x2+UART_Mode_8Var+UART_Mode_Frame

; * A "cycle" is a single 'count' downwards of the LED value(s) - one PWM cycle:
;   - This is embodied in a single interrupt - whatever the interrupt does.
; * A "count" is either a decrement or a shift right:
;   - A decrement means that the full 256-count (16+ million colours) can be
;     shown. However, this won't PWM well.
;   - A shift right means that there are only really 9 possible values, with
;     ever-greater ranges for larger and larger numbers. Logarithmic, in fact!
;     Note that the test isn't zero/non-zero, it's whether the bottom bit is 1.
;     That allows for better modulation of the LED.
; * A "frame" is an update of the entire matrix:
;   - For persistence of vision, there have to be many Frames Per Second (FPS).
;   - Depending on colour depth (bits per colour(LED): 1/2/4/5/8), that could be
;     1, 4, 16, 32 or 256 cycles (interrupts) per LED per frame (grouped as
;     configured).
FPS_Rate_Row    EQU             8
FPS_Rate_Colour EQU             8*3
FPS_Rate_Pixel  EQU             8*8
FPS_Rate_LED    EQU             8*8*3

nFPS            EQU             25 ; Frames Per Second. Sets the interrupt rate.
nCycles         EQU             16 ; Number of cycles per Frame
ScrollDelay     EQU             4  ; Number of Frames per Scroll

; There are five ways to update the individual RGB pixels (some with options):
; 0) Each cycle, update the whole frame.
;    * There aren't enough individual I/Os for that - there'd need to be 192!
;    * And, the LED Matrix isn't designed that way.
;    * There would need to be FPS*Cycle interrupts per second:
;      - Assuming 25 FPS and 256 cycles, that's 6,400 interrupts per second;
;      - Assuming 25 FPS and 8 cycles, that's 200 interrupts per second.
; 1) Each cycle, update one whole row (All the colours of each pixel).
;    * This would have up to 24 LEDs lit at once.
;      Given a 120mA chip maximum (not forgetting that the anode is shared!),
;      with a per-pin 20 mA, each LED can use a maximum of 0.833 mA.
;    * There needs to be FPS*Cycle*8 interrupts per second:
;      - Assuming 25 FPS and 256 cycles, that's 51,200 interrupts per second!
;      - Assuming 25 FPS and 8 cycles, that's 1,600 interrupts per second.
; 2) Each cycle, update one colour in each row (All the Blues, Greens or Reds).
;    * This would have up to 8 LEDs lit at once.
;      Given a 120mA chip maximum (not forgetting that the anode is shared!),
;      with a per-pin 20 mA, each LED can use a maximum of 2.5 mA.
;    * There needs to be FPS*Cycle*8*3 interrupts per second.
;      - Assuming 25 FPS and 256 cycles, that's 153,600 interrupts per second!
;      - Assuming 25 FPS and 8 cycles, that's  4,800 interrupts per second.
;    * Note that either:
;      a) Each colour in one row is updated before the next row is started;
;      b) Each colour in all rows is updated before the next colour is started.
; 3) Each cycle, update one pixel in each row (Its Blue, Green and Red).
;    * This would have up to 3 LEDs lit at once.
;      Given a 120mA chip maximum (not forgetting that the anode is shared!),
;      with a per-pin 20 mA, each LED can use a maximum of 6.66 mA.
;    * There needs to be FPS*Cycle*8*8 interrupts per second.
;      - Assuming 25 FP5 and 256 cycles, that's 409,600 interrupts per second!
;      - Assuming 25 FPS and 8 cycles, that's 12,800 interrupts per second.
; 4) Each cycle, update one LED in each row.
;    * This would have up to 1 LED lit at once.
;      Given a 120mA chip maximum with a per-pin 20 mA, each LED can use a
;      maximum of 20 mA.
;    * There needs to be FPS*Cycle*8*8*3 interrupts per second.
;      - Assuming 25 FPS and 256 cycles, that's 1,228,800 interrupts per second!
;      - Assuming 25 FPS and 8 cycles, that's 38,400 interrupts per second.
;    * Note that either:
;      a) Each colour in one pixel is updated before the next pixel is started;
;      b) Each colour in one row of pixels is updated before the next row is
;         started;
;      c) One colour in all the pixels is updated before the next colour is
;         started.

; The representation of the different modes is expressed in bits as follows:
; * There are three bits: Row, Pixel and LED;
;   * If the Row bit is set, then the whole Row changes (one or all colours);
;   * If neither the Pixel or LED bit is set, then all three colours change;
;   * If the Pixel bit is set, then the Pixel, not Colour, changes per cycle;
;   * If the LED bit is set, then the Colour is changed before the Row is.
;
; The bits are as follows:
; ROW : PIXEL : LED | Interpretation                                    (# LEDs)
;-----+-------+-----+-----------------------------------------------------------
;  0  :   0   :  0  | One Pixel changes per cycle (BGR0.0,BGR0.1,)           (3)
;  0  :   0   :  1  | One Colour changes per cycle (B0.0,G0.0,R0.0,B0.1,)    (1)
;  0  :   1   :  0  | One LED changes per cycle (B0.0,B0.1,..,B1.0,B1.1,)    (1)
;  0  :   1   :  1  | One LED changes per cycle (B0.0,B0.1,..,G0.0,G0.1,)    (1)
;  1  :   0   :  0  | One whole Row changes per cycle (BGR0.01234567,)     (8*3)
;  1  :   0   :  1  | One Colour each Row changes per cycle (B0.0-7,G0.0-7,) (8)
;  1  :   1   :  0  | One Colour per Row changes per cycle (B0.0-7,B1.0-7,)  (8)
;  1  :   1   :  1  | One Frame changes per cycle (not possible!)         (192!)

UPDATE_Pixel      EQU           000b    ; BGR0.0,BGR0.1,BGR0.2,...           (3)
UPDATE_LED_Pixel  EQU           001b    ; B0.0,G0.0,R0.0,...                 (1)
UPDATE_LED_Colour EQU           010b    ; B0.0,B0.1,...,B1.0,B1.1,...        (1)
UPDATE_LED_Row    EQU           011b    ; B0.0,B0.1,...,G0.0,G0.1,...        (1)
UPDATE_Row_Pixel  EQU           100b    ; BGR0.01234567,...                 (24)
UPDATE_Row_LED    EQU           101b    ; B0.01234567,G0.01234567,...        (8)
UPDATE_Row_Colour EQU           110b    ; B0.01234567,B1.01234567,...        (8)
UPDATE_Row_Frame  EQU           111b    ;                                 (192!)
UPDATE_Row_Last   EQU           UPDATE_Row_Frame

; There are three boards:
; * BOARD_PLCC40 has no LED Matrix, and one single DigiPot cascade;
; * BOARD_DigiPot has digital potentiometers;
; * BOARD_Resistor has fixed resistors.
; Other than the obvious, the differences are:
; * For testing purposes, spare Ports on the PLCC40 version are used for LEDs;
; * For board layout reasons, Cathodes and Anodes are on different I/O ports;
; * The different boards use different CPU clocks.
BOARD_PLCC40    EQU             0
BOARD_DigiPot   EQU             1
BOARD_Resistor  EQU             2

BOARD           EQU             BOARD_PLCC40
TIMER0_Mode     EQU             TIMER_Mode_8_Auto
TIMER0_Priority EQU             INT_Priority_3
BAUD_Rate       EQU             BAUD_115200

IF     (BOARD=BOARD_PLCC40)
;  $SET     (SERIAL_Enable)
;  SERIAL       LIT             'UART2'
;  $SET     (BAUD_Enable)
;  $SET     (UART2_Enable)
;  $SET     (UART2_Alt)
;  $SET     (DIGIPOT_Enable)
   CPU               EQU        CPU_STC12
   Clock_Freq        EQU        Clock_11059200
;  {SERIAL}_Priority EQU        INT_Priority_2
;  UART2_Mode        EQU        UART_Mode_8Var
ELSEIF (BOARD=BOARD_DigiPot)
;  $SET     (SERIAL_Enable)
;  SERIAL       LIT             'UART2'
;  $SET     (BAUD_Enable)
;  $SET     (UART2_Enable)
;  $SET     (UART2_Alt)
   $SET     (DIGIPOT_Enable)
   CPU               EQU        CPU_STC12
   Clock_Freq        EQU        Clock_33177600
;  {SERIAL}_Priority EQU        INT_Priority_2
;  UART2_Mode        EQU        UART_Mode_8Var
ELSEIF (BOARD=BOARD_Resistor)
;  $SET     (SERIAL_Enable)
;  SERIAL       LIT             'UART'
;  $SET     (BAUD_Enable)
;  $SET     (UART_Enable)
   CPU               EQU        CPU_Demo
   Clock_Freq        EQU        Clock_11059200
;  {SERIAL}_Priority EQU        INT_Priority_2
;  UART_Mode         EQU        UART_Mode_BRG + UART_Mode_8Var
ELSE
   __ERROR__       "BOARD unknown!"
ENDIF

IF     (CPU=CPU_STC12)
CPU_Freq        EQU             Clock_Freq
ELSEIF (CPU=CPU_STC89)
CPU_Freq        EQU             Clock_Freq/6      ; Assumes 6T has been enabled
ELSE
__ERROR__ "CPU unknown!"
ENDIF

$IF (EYES_Enable)

                $INCLUDE        (P4.inc)

IF     (CPU=CPU_STC12)
DefineBit       LeftEye,  pP4, 5
DefineBit       RightEye, pP4, 4

Eye_Init        MACRO
                ORL             rP4SW, #(mALEP45 + mNAP44)
;               ORL             pP4, #(mLeftEye + mRightEye)
;               ANL             rP4M1, #NOT (mLeftEye + mRightEye)
                ORL             rP4M0, #    (mLeftEye + mRightEye)
                ENDM

Eye_Close       MACRO           Which ; LeftEye or RightEye
                SETB            Which
                ENDM

Eye_Open        MACRO           Which ; LeftEye or RightEye
                CLR             Which
                ENDM

Eye_Wink        MACRO           Which ; LeftEye or RightEye
                CPL             Which
                ENDM
ELSEIF (CPU=CPU_STC89)
Eye_Init        MACRO
                ENDM

Eye_Close       MACRO           Which
                ENDM

Eye_Open        MACRO           Which
                ENDM

Eye_Wink        MACRO           Which
                ENDM
ELSE
__ERROR__ "CPU unknown!"
ENDIF
$ENDIF

$ENDIF ; OPTIONS_INC
