Var num, min, max, key, quest: integer;

begin
  max := 0;

  readln(quest);
  
  if quest > 100 then
      begin
        writeln('> 100');
      
        exit;
      end;
  
   for key := 0 to quest do
    begin
      readln(num);
      
      if num > 300 then
          begin
            writeln('> 300');
            
            exit;
          end;  
      
      min := num;
      
      if (min > max) and (min mod 5 = 0)then
          begin
            max := min;
          end;
    end;     
          
  writeln('num: ' + max);
  
end.