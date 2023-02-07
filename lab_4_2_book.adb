with Ada.Text_IO;
with Ada.Strings.Unbounded;

procedure Lab_4_2_Book is
   unb_str_0 : Ada.Strings.Unbounded.Unbounded_string;
   return_bool_val : Boolean;
   function palindrome_or_not
     (unb_str_inp : in out Ada.Strings.Unbounded.Unbounded_String) return Boolean is
      --have 2 indexes (one at beginning and one at back) check is each has same values
      index_0 : Integer :=1;--assume ada index starts at 1 if not specified
      index_1 : Integer := Ada.Strings.Unbounded.Length(unb_str_inp);
      --str : String(1..100);
   begin

      --str := Ada.Strings.Unbounded.To_String(unb_str_inp);
      --above  fails since str is not the same length as unb_str_inp with the current input "racecar"
      --Ada.Text_IO.Put_Line("str'length " & str'Length);--bug
      --Ada.Text_IO.Put_Line("unb_str_inp'Length " & unb_str_inp'Length);
      --Ada.Text_IO.Put_Line("length of unb_str_inp = " & Ada.Strings.Unbounded.length(unb_str_inp));
      Ada.Text_IO.Put_Line("unb_str_inp'Length " & Integer'Image(Ada.Strings.Unbounded.Length(unb_str_inp)));
      --Ada.Text_IO.Put_Line("unb_str_inp[index_0] " & unb_str_inp(index_0));
      --Ada.Text_IO.Put_Line("str " &   str(1));
      Ada.Text_IO.Put_Line("element(unb_str_inp,1) " & Ada.Strings.Unbounded.element(unb_str_inp,index_0));
      Ada.Text_IO.Put_Line("element(unb_str_inp,index_1) " & Ada.Strings.Unbounded.element(unb_str_inp,index_1));

      while (index_0 < index_1) loop
         if ( Ada.Strings.Unbounded.element(unb_str_inp,index_0) /= Ada.Strings.Unbounded.element(unb_str_inp,index_1))then
            return False;
         else
            --if equal to each other
            index_0 := index_0 + 1;
            index_1 := index_1 -1;
         end if;

         end loop;
      return True;--placeholder
   end palindrome_or_not;

begin
   unb_str_0 := Ada.Strings.Unbounded.To_Unbounded_String("noon");--racecar,youtube (check for non palindrome)
   return_bool_val := palindrome_or_not(unb_str_0);
   Ada.Text_IO.Put_Line("return_bool_val = " & Boolean'Image(return_bool_val));
   --null;
end Lab_4_2_Book;
