;
; Font8x8.a51
;

                NAME            Font8x8

                $INCLUDE        (Options.inc)

$IF (FONT8x8_Enable)

Font8x8_Code    SEGMENT         CODE AT aFONT_Table
                RSEG            Font8x8_Code

                ORG             aFONT_Table

;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 00h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 01h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 02h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 03h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 04h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 05h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 06h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 07h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 08h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 09h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 0Ah
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 0Bh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 0Ch
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 0Dh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 0Eh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 0Fh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 10h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 11h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 12h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 13h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 14h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 15h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 16h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 17h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 18h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 19h
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 1Ah
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 1Bh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 1Ch
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 1Dh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 1Eh
;               DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; 1Fh
                DB              000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h ; ' '
                DB              000h, 000h, 006h, 05Fh, 05Fh, 006h, 000h, 000h ; '!'
                DB              000h, 000h, 003h, 003h, 000h, 003h, 003h, 000h ; '"'
                DB              000h, 014h, 07Fh, 07Fh, 014h, 07Fh, 07Fh, 014h ; '#'
                DB              000h, 024h, 02Eh, 06Bh, 06Bh, 03Ah, 012h, 000h ; '$'
                DB              000h, 046h, 066h, 030h, 018h, 00Ch, 066h, 062h ; 'Percent'
                DB              000h, 030h, 07Ah, 04Fh, 05Dh, 037h, 07Ah, 048h ; '&'
                DB              000h, 004h, 007h, 003h, 000h, 000h, 000h, 000h ; '''
                DB              000h, 000h, 01Ch, 03Eh, 063h, 041h, 000h, 000h ; '('
                DB              000h, 000h, 041h, 063h, 03Eh, 01Ch, 000h, 000h ; ')'
                DB              008h, 02Ah, 03Eh, 01Ch, 01Ch, 03Eh, 01Ah, 008h ; '*'
                DB              000h, 008h, 008h, 03Eh, 03Eh, 008h, 008h, 000h ; '+'
                DB              000h, 000h, 080h, 0E0h, 060h, 000h, 000h, 000h ; ','
                DB              000h, 008h, 008h, 008h, 008h, 008h, 008h, 000h ; '-'
                DB              000h, 000h, 000h, 060h, 060h, 000h, 000h, 000h ; '.'
                DB              000h, 006h, 003h, 018h, 00Ch, 006h, 003h, 001h ; '/'
                DB              000h, 03Eh, 07Fh, 071h, 059h, 04Dh, 07Fh, 03Eh ; '0'
                DB              000h, 040h, 042h, 07Fh, 07Fh, 040h, 040h, 000h ; '1'
                DB              000h, 062h, 073h, 059h, 049h, 06Fh, 066h, 000h ; '2'
                DB              000h, 022h, 063h, 049h, 049h, 07Fh, 036h, 000h ; '3'
                DB              000h, 018h, 01Ch, 016h, 053h, 07Fh, 07Fh, 050h ; '4'
                DB              000h, 027h, 067h, 045h, 045h, 07Dh, 039h, 000h ; '5'
                DB              000h, 03Ch, 07Eh, 04Bh, 049h, 079h, 030h, 000h ; '6'
                DB              000h, 003h, 003h, 071h, 079h, 00Fh, 007h, 000h ; '7'
                DB              000h, 036h, 07Fh, 049h, 049h, 07Fh, 036h, 000h ; '8'
                DB              000h, 006h, 04Fh, 049h, 069h, 03Fh, 01Eh, 000h ; '9'
                DB              000h, 000h, 000h, 066h, 066h, 000h, 000h, 000h ; ':'
                DB              000h, 000h, 080h, 0E6h, 066h, 000h, 000h, 000h ; ';'
                DB              000h, 008h, 01Ch, 036h, 063h, 041h, 000h, 000h ; '<'
                DB              000h, 024h, 024h, 024h, 024h, 024h, 024h, 000h ; '='
                DB              000h, 000h, 041h, 063h, 036h, 01Ch, 008h, 000h ; '>'
                DB              000h, 002h, 003h, 051h, 059h, 00Fh, 006h, 000h ; '?'
                DB              000h, 03Eh, 07Fh, 041h, 05Dh, 05Dh, 01Fh, 01Eh ; '@'
                DB              000h, 07Ch, 07Eh, 013h, 013h, 07Eh, 07Ch, 000h ; 'A'
                DB              000h, 041h, 07Fh, 07Fh, 049h, 049h, 07Fh, 036h ; 'B'
                DB              000h, 01Ch, 03Eh, 063h, 041h, 041h, 063h, 022h ; 'C'
                DB              000h, 041h, 07Fh, 07Fh, 041h, 063h, 03Eh, 01Ch ; 'D'
                DB              000h, 041h, 07Fh, 07Fh, 049h, 05Dh, 041h, 063h ; 'E'
                DB              000h, 041h, 07Fh, 07Fh, 049h, 01Dh, 001h, 003h ; 'F'
                DB              000h, 01Ch, 03Eh, 063h, 041h, 051h, 073h, 072h ; 'G'
                DB              000h, 07Fh, 07Fh, 008h, 008h, 07Fh, 07Fh, 000h ; 'H'
                DB              000h, 000h, 041h, 07Fh, 07Fh, 041h, 000h, 000h ; 'I'
                DB              000h, 030h, 070h, 040h, 041h, 07Fh, 03Fh, 001h ; 'J'
                DB              000h, 041h, 07Fh, 07Fh, 008h, 01Ch, 077h, 063h ; 'K'
                DB              000h, 041h, 07Fh, 07Fh, 041h, 040h, 060h, 070h ; 'L'
                DB              000h, 07Fh, 07Fh, 00Eh, 01Ch, 00Eh, 07Fh, 07Fh ; 'M'
                DB              000h, 07Fh, 07Fh, 006h, 00Ch, 018h, 07Fh, 07Fh ; 'N'
                DB              000h, 01Ch, 03Eh, 063h, 041h, 063h, 03Eh, 01Ch ; 'O'
                DB              000h, 041h, 07Fh, 07Fh, 049h, 009h, 00Fh, 006h ; 'P'
                DB              000h, 01Eh, 03Fh, 021h, 071h, 05Fh, 05Eh, 000h ; 'Q'
                DB              000h, 041h, 07Fh, 07Fh, 009h, 019h, 07Fh, 066h ; 'R'
                DB              000h, 026h, 06Fh, 04Dh, 059h, 073h, 032h, 000h ; 'S'
                DB              000h, 003h, 041h, 07Fh, 07Fh, 041h, 003h, 000h ; 'T'
                DB              000h, 07Fh, 07Fh, 040h, 040h, 07Fh, 07Fh, 000h ; 'U'
                DB              000h, 01Fh, 03Fh, 060h, 060h, 03Fh, 01Fh, 000h ; 'V'
                DB              000h, 07Fh, 07Fh, 030h, 018h, 030h, 07Fh, 07Fh ; 'W'
                DB              000h, 063h, 077h, 01Ch, 008h, 01Ch, 077h, 063h ; 'X'
                DB              000h, 007h, 04Fh, 078h, 078h, 04Fh, 007h, 000h ; 'Y'
                DB              000h, 047h, 063h, 071h, 059h, 01Dh, 067h, 073h ; 'Z'
                DB              000h, 000h, 07Fh, 07Fh, 041h, 041h, 000h, 000h ; '['
                DB              000h, 001h, 003h, 006h, 00Ch, 018h, 030h, 060h ; '\'
                DB              000h, 000h, 041h, 041h, 07Fh, 07Fh, 000h, 000h ; ']'
                DB              000h, 008h, 00Ch, 006h, 003h, 006h, 00Ch, 008h ; '^'
                DB              080h, 080h, 080h, 080h, 080h, 080h, 080h, 080h ; '_'
                DB              000h, 000h, 000h, 003h, 007h, 004h, 000h, 000h ; '`'
                DB              000h, 020h, 074h, 054h, 054h, 03Ch, 078h, 040h ; 'a'
                DB              000h, 041h, 07Fh, 03Fh, 048h, 048h, 078h, 030h ; 'b'
                DB              000h, 038h, 07Ch, 044h, 044h, 06Ch, 028h, 000h ; 'c'
                DB              000h, 030h, 078h, 048h, 049h, 03Fh, 07Fh, 040h ; 'd'
                DB              000h, 038h, 07Ch, 054h, 054h, 05Ch, 018h, 000h ; 'e'
                DB              000h, 048h, 07Eh, 07Fh, 049h, 003h, 002h, 000h ; 'f'
                DB              000h, 098h, 0BCh, 0A4h, 0A4h, 0F8h, 07Ch, 004h ; 'g'
                DB              000h, 041h, 07Fh, 07Fh, 008h, 004h, 07Ch, 078h ; 'h'
                DB              000h, 000h, 044h, 07Dh, 07Dh, 040h, 000h, 000h ; 'i'
                DB              000h, 060h, 0E0h, 080h, 080h, 0FDh, 07Dh, 000h ; 'j'
                DB              000h, 041h, 07Fh, 07Fh, 010h, 038h, 06Ch, 044h ; 'k'
                DB              000h, 000h, 041h, 07Fh, 07Fh, 040h, 000h, 000h ; 'l'
                DB              000h, 07Ch, 07Ch, 018h, 038h, 01Ch, 07Ch, 078h ; 'm'
                DB              000h, 07Ch, 07Ch, 004h, 004h, 07Ch, 078h, 000h ; 'n'
                DB              000h, 038h, 07Ch, 044h, 044h, 07Ch, 038h, 000h ; 'o'
                DB              000h, 084h, 0FCh, 0F8h, 0A4h, 024h, 03Ch, 018h ; 'p'
                DB              000h, 018h, 03Ch, 024h, 0A4h, 0F8h, 0FCh, 084h ; 'q'
                DB              000h, 044h, 07Ch, 078h, 04Ch, 004h, 01Ch, 018h ; 'r'
                DB              000h, 048h, 05Ch, 054h, 054h, 074h, 024h, 000h ; 's'
                DB              000h, 000h, 004h, 03Eh, 07Fh, 044h, 024h, 000h ; 't'
                DB              000h, 03Ch, 07Ch, 040h, 040h, 03Ch, 07Ch, 040h ; 'u'
                DB              000h, 01Ch, 03Ch, 060h, 060h, 03Ch, 01Ch, 000h ; 'v'
                DB              000h, 03Ch, 07Ch, 070h, 038h, 070h, 07Ch, 03Ch ; 'w'
                DB              000h, 044h, 06Ch, 038h, 010h, 038h, 06Ch, 044h ; 'x'
                DB              000h, 09Ch, 0BCh, 0A0h, 0A0h, 0FCh, 07Ch, 000h ; 'y'
                DB              000h, 04Ch, 064h, 074h, 05Ch, 04Ch, 064h, 000h ; 'z'
                DB              000h, 008h, 008h, 03Eh, 077h, 041h, 041h, 000h ; '{'
                DB              000h, 000h, 000h, 077h, 077h, 000h, 000h, 000h ; '|'
                DB              000h, 041h, 041h, 077h, 03Eh, 008h, 008h, 000h ; '}'
                DB              000h, 002h, 003h, 001h, 003h, 002h, 003h, 001h ; '~'
                DB              0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh ; ' '
$ENDIF
                END
