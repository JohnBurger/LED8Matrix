;
; Timer1.a51
;
; This file defines the Timer1 symbols and some useful functions.
; Those functions are actually defined in Timer.inc - to commonalise the code.
;

                NAME            Timer1

                $INCLUDE        (Options.inc)

$IF (TIMER1_Enable)

T               LIT             '1'               ; Timer1

                SFR   rTL1  =   08Bh
                SFR   rTH1  =   08Dh

                $INCLUDE        (Timer.inc)
;===============================================================================
$ENDIF
                END
