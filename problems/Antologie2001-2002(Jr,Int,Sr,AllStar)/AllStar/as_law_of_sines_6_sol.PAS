{LAW OF SINES -WRITTEN BY WOBURN CI}
uses crt;

function sin(a : extended) : extended;
begin
  sin := system.sin(a * pi/180);
end;

function req(a, b : extended) : boolean;
begin
  req := abs(a - b) < 0.01;
end;

var
  z, y, actual : array[1..3,1..2] of extended;
  i, j : word;
  a, b, c, d : byte;
  yused : boolean;
  s : string;
  written : boolean;

function checktri : boolean;
var
  a, b, c : extended;
  i : byte;
begin
  a := -1;
  for i := 1 to 3 do
    if (z[i,1] <> 0) and (z[i,2] <> 0) then begin
      if a = -1 then a := z[i,1] / sin(z[i,2])
      else if not req(a, z[i,1] / sin(z[i,2])) then begin
        checktri := false;
        exit;
      end;
    end;
  if (z[1,2] <> 0) and (z[2,2]<>0) and (z[3,2] <> 0) then begin
    if abs(z[1,2] + z[2,2] + z[3,2] - 180) > 1 then begin
      checktri := false;
      exit;
    end;
  end;
  checktri := true;
end;

procedure getnext;
var
  i, j, k, l, m,n : byte;
begin
  for i := 1 to 2 do
    for j := i + 1 to 3 do begin
      m := 0;
      for n := 1 to 2 do begin
        if z[i,n] = 0 then begin
          k := i;
          l := n;
          inc(m);
        end;
        if z[j,n] = 0 then begin
          k := j;
          l := n;
          inc(m);
        end;
      end;
      if m = 1 then begin
        a := i + j - k;
        c := k;
        d := l;
        exit;
      end;
    end;
{  write('ERROR'); }
end;

var
 tc : byte;
 f : text;

label goend,goend2,1;
begin
clrscr;
assign(f, 'acsl6.in');
reset(f);
for tc := 1 to 10 do begin
  s := '';
  yused := false;
  for i := 1 to 3 do
    for j := 1 to 2 do read(f,z[i, j]);
  actual := z;
  repeat
   if (z[1,2]=0)and(z[2,2]<>0)and(z[3,2]<>0) then z[1,2]:=180-z[2,2]-z[3,2];
   if (z[1,2]<>0)and(z[2,2]=0)and(z[3,2]<>0) then z[2,2]:=180-z[1,2]-z[3,2];
   if (z[1,2]<>0)and(z[2,2]<>0)and(z[3,2]=0) then z[3,2]:=180-z[1,2]-z[2,2];
   if not checktri then goto goend;
   getnext;
   if d = 1 then begin { side }
     z[c,d] := z[a,1] / sin(z[a,2]) * sin(z[c,2]);
   end else begin
     z[c,d] := sin(z[a,2]) / z[a,1] * z[c,1];
     if z[c,d] > 1 then goto goend;
     z[c,d] := 180 / pi * arctan(z[c,d] / sqrt(1 - sqr(z[c,d])));
     if 180 - z[c,d] + z[a,2] < 180 then begin
       y := z;
       y[c,d] := 180 - y[c,d];
       yused := true;
     end;
   end;

   for i := 1 to 3 do
     if (z[i,1] = 0) or (z[i,2] = 0) then goto 1;
   break;
1:
  until false;

  written := false;

  if checktri then begin
    for i := 1 to 3 do begin
      if actual[i,2] = 0 then begin
        if written then write(',');
        write(chr(64 + i), '=',z[i,2]:0:2);
        written := true;
      end;
    end;
      s := '1';
  end;

  if yused then begin
    z := y;
   if (z[1,2]=0)and(z[2,2]<>0)and(z[3,2]<>0) then z[1,2]:=180-z[2,2]-z[3,2];
   if (z[1,2]<>0)and(z[2,2]=0)and(z[3,2]<>0) then z[2,2]:=180-z[1,2]-z[3,2];
   if (z[1,2]<>0)and(z[2,2]<>0)and(z[3,2]=0) then z[3,2]:=180-z[1,2]-z[2,2];
   if not checktri then begin
     if s = '1' then begin
       writeln;
       goto goend2;
     end
     else goto goend;
   end;
    for i := 1 to 3 do begin
      if actual[i,2] = 0 then begin
        if written then write(',');
        write(chr(64 + i) + s, '=',z[i,2]:0:2);
        written := true;
      end;
    end;
   writeln;
  end else if s = '1' then writeln;
  goto goend2;
goend:
  writeln('Not a triangle');
goend2:
end;
  readln;
  close(f);

end.