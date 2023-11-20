REM Junior Division
REM XV Gimnazija
CLS
DIM rj(5000, 2)
DIM i AS INTEGER
DIM a AS DOUBLE
FOR i = 1 TO 5
        f = 0
        PRINT : PRINT "Input #"; LTRIM$(RTRIM$(STR$(i))); ":";
        INPUT "", a
        s$ = LTRIM$(RTRIM$(STR$(a)))
        k = (10 ^ ((LEN(s$) / 2) - 1)) + 1
        br = 0
        FOR j = k TO ((k - 1) * 10) / 2
                IF a MOD j = 0 THEN br = br + 1: rj(br, 1) = j: rj(br, 2) = a / j
        NEXT
        FOR j = 1 TO br
                o$ = LTRIM$(RTRIM$(STR$(rj(j, 1)))) + LTRIM$(RTRIM$(STR$(rj(j, 2))))
                FOR x = 1 TO LEN(s$)
                       m$ = MID$(s$, x, 1)
                       FOR y = 1 TO LEN(o$)
                              IF MID$(o$, y, 1) = m$ THEN GOTO dalje
                       NEXT
                       GOTO opet
dalje:
               NEXT
               IF f >= 1 THEN PRINT " and ";
               PRINT LTRIM$(RTRIM$(STR$(rj(j, 1)))); ","; LTRIM$(RTRIM$(STR$(rj(j, 2))));
               f = f + 1
opet:    
                
        NEXT
        IF f = 0 THEN PRINT "NONE"
NEXT
END

