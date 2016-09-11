;
; Timer.a51
;
; This file defines the Timer interrupt ISRs, and some useful functions.
;

                NAME            Timer

                $INCLUDE        (TCON.inc)
                $INCLUDE        (PSW.inc)

                PUBLIC          InitTimer

                PUBLIC          Timer0ISR
                PUBLIC          Timer1ISR

                EXTERN          CODE(Timer1Hook)

;===============================================================================

Timer           SEGMENT         CODE
                RSEG            Timer

InitTimer:
                RET

;-------------------------------------------------------------------------------

                USING           3

Timer0ISR:
                PUSH            PSW
                PUSH            ACC
                PUSH            DPH
                PUSH            DPL

                ORL             PSW, #mRS1+mRS0   ; Bank 3

                CALL            Timer1Hook

                POP             DPL
                POP             DPH
                POP             ACC
                POP             PSW
                RETI

;-------------------------------------------------------------------------------

                USING           2

Timer1ISR:
                RETI

                END
