with Ada.Text_IO;

procedure Lab_3_3_Book is
   --counter_val : Positive :=1;--don;t need this since I can just use

begin
   for x in 1 .. 10000 loop
      if (((x rem 3) = 0) or ((x rem 13)=0) or ((x rem 23)=0)) then
      Ada.Text_IO.Put_Line(Integer'Image(x) & " ");
      end if;

      end loop;
   --  Insert code here.
   null;
end Lab_3_3_Book;
