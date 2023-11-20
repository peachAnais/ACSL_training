REM XV GIMNAZIJA
REM JUNIOR DIVISION
REM DIOPHANTUS
DIM mat$(2, 100)
FOR MONI = 1 TO 10
RJ$ = ""
K = 100000
INPUT "", A$
A$ = A$ + " "
FOR I = 1 TO LEN(A$)
        IF MID$(A$, I, 1) = "M" THEN K = I
NEXT I
FOR I = 1 TO LEN(A$) - 2
        IF ASC(MID$(A$, I + 2, 1)) < 58 THEN D$ = MID$(A$, I + 2, 1) ELSE D$ = ""
        IF MID$(A$, I, 2) = "CC" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ + "X^6": MID$(A$, I, 2) = "WW" ELSE RJ$ = RJ$ + "+" + D$ + "X^6": MID$(A$, I, 2) = "WW"
NEXT I
FOR I = 1 TO LEN(A$) - 2
        IF ASC(MID$(A$, I + 2, 1)) < 58 THEN D$ = MID$(A$, I + 2, 1) ELSE D$ = ""
        IF MID$(A$, I, 2) = "PC" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ + "X^5": MID$(A$, I, 2) = "WW" ELSE RJ$ = RJ$ + "+" + D$ + "X^5": MID$(A$, I, 2) = "WW"
NEXT I
FOR I = 1 TO LEN(A$) - 2
        IF ASC(MID$(A$, I + 2, 1)) < 58 THEN D$ = MID$(A$, I + 2, 1) ELSE D$ = ""
        IF MID$(A$, I, 2) = "PP" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ + "X^4": MID$(A$, I, 2) = "WW" ELSE RJ$ = RJ$ + "+" + D$ + "X^4": MID$(A$, I, 2) = "WW"
NEXT I
FOR I = 1 TO LEN(A$) - 1
        IF ASC(MID$(A$, I + 1, 1)) < 58 THEN D$ = MID$(A$, I + 1, 1) ELSE D$ = ""
        IF MID$(A$, I, 1) = "C" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ + "X^3" ELSE RJ$ = RJ$ + "+" + D$ + "X^3"
NEXT I
FOR I = 1 TO LEN(A$) - 1
        IF ASC(MID$(A$, I + 1, 1)) < 58 THEN D$ = MID$(A$, I + 1, 1) ELSE D$ = ""
        IF MID$(A$, I, 1) = "P" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ + "X^2" ELSE RJ$ = RJ$ + "+" + D$ + "X^2"

NEXT I
FOR I = 1 TO LEN(A$) - 1
        IF ASC(MID$(A$, I + 1, 1)) < 58 THEN D$ = MID$(A$, I + 1, 1) ELSE D$ = ""
        IF MID$(A$, I, 1) = "X" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ + "X" ELSE RJ$ = RJ$ + "+" + D$ + "X"
NEXT I
FOR I = 1 TO LEN(A$) - 1
        IF ASC(MID$(A$, I + 1, 1)) < 58 THEN D$ = MID$(A$, I + 1, 1) ELSE D$ = ""
        IF MID$(A$, I, 1) = "U" THEN IF I > K THEN RJ$ = RJ$ + "-" + D$ ELSE RJ$ = RJ$ + "+" + D$
NEXT I
IF MID$(RJ$, 1, 1) = "+" THEN RJ$ = MID$(RJ$, 2, LEN(RJ$) - 1)
PRINT RJ$
NEXT MONI


