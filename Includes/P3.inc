;
; P3.inc
;
; This file defines I/O Port P3 and its Configuration ports P3M0 and P3M1
;

$IF  (NOT P3_INC)
$SET (P3_INC)

                SFR     pP3   = 0B0h

                SFR     rP3M0 = 0B2h
                SFR     rP3M1 = 0B1h

$ENDIF ; P3_INC
