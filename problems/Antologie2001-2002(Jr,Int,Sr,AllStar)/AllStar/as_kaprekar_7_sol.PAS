{ Sean Henderson, Woburn CI }
{ ACSL All-Star Senior 5    }
{ Problem 7 - Kaprekar      }

program kaprekar;

uses crt;

const
  hexchars : string = '0123456789ABCDEF';

var
  inp : text;
  subt, qt, lencyc : longint;
  q, l : array[0..120] of longint;
  done : boolean;

procedure push(n : longint);
begin
  qt := (qt + 1) mod 121;
  q[qt] := n;
  l[qt] := subt;
end;

procedure search(n : longint);
var
  i : byte;
begin
  for i := 0 to 120 do begin
    if (q[i] > 0) then begin
      if (q[i] = n) then begin
        done := true;
        lencyc := subt - l[i];
      end;
    end;
  end;
  if (n = 0) then done := true;
end;

procedure inhex(n : longint; var s : string);
begin
  s := '';
  while (n <> 0) do begin
    s := hexchars[n mod 16 + 1] + s;
    n := n div 16;
  end;
end;

procedure base10(var n : longint; s : string);
var
  i : byte;
  p16 : longint;
begin
  p16 := 1;
  n := 0;
  for i := length(s) downto 1 do begin
    n := n + (pos(s[i], hexchars) - 1) * p16;
    p16 := p16 * 16;
  end;
end;

procedure sort(var s, n1, n2 : string);
var
  i, j : byte;
  c : char;
begin
  n1 := '';
  n2 := '';
  for i := 1 to length(s) do begin
    for j := i + 1 to length(s) do begin
      if (s[i] > s[j]) then begin
        c := s[i];
        s[i] := s[j];
        s[j] := c;
      end;
    end;
    n1 := n1 + s[i];
    n2 := s[i] + n2;
  end;
end;

var
  i : longint;
  s, n1, n2 : string;
  n1d, n2d, t : longint;

begin
  clrscr;
  assign(inp, 'acsl7.in'); reset(inp);
  for i := 1 to 10 do begin
    readln(inp, s);
    if (s = '0') then begin
      writeln('ZERO, 0');
      continue;
    end;
    done := false;
    subt := 0;
    qt := 0;
    fillchar(q, sizeof(q), 0);
    fillchar(l, sizeof(l), 0);
    while not(done) do begin
      sort(s, n1, n2);
      base10(n1d, n1);
      base10(n2d, n2);
      inc(subt);
      t := abs(n2d - n1d);
      search(t);
      inhex(t, s);
      if not done then push(t);
    end;
    if (t = 0) then writeln('ZERO, ', subt)
    else if (lencyc = 1) then writeln('CONSTANT, ', s)
    else writeln('CYCLE, ', lencyc);
  end;
  close(inp);
  readln;
end.