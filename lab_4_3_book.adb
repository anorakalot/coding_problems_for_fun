
with Ada.Text_IO;
with Ada.Strings.Unbounded;

procedure Lab_4_3_Book is

   unb_str_0 : Ada.Strings.Unbounded.Unbounded_string;
   return_bool_val : Boolean;
    index_0 : Integer :=1;--assume ada index starts at 1 if not specified
   index_1 : Integer;-- := Ada.Strings.Unbounded.Length(unb_str_inp);

   function palindrome_or_not
     (unb_str_inp : in out Ada.Strings.Unbounded.Unbounded_String; index_0 : in out Integer; index_1 : in out Integer) return Boolean is
      --have 2 indexes (one at beginning and one at back) check is each has same values

      --str : String(1..100);
   begin

      Ada.Text_IO.Put_Line("unb_str_inp'Length " & Integer'Image(Ada.Strings.Unbounded.Length(unb_str_inp)));
      Ada.Text_IO.Put_Line("element(unb_str_inp,1) " & Ada.Strings.Unbounded.element(unb_str_inp,index_0));
      Ada.Text_IO.Put_Line("element(unb_str_inp,index_1) " & Ada.Strings.Unbounded.element(unb_str_inp,index_1));


      if (index_0 < index_1) then -- base case

         return True;


      elsif ( Ada.Strings.Unbounded.element(unb_str_inp,index_0) /= Ada.Strings.Unbounded.element(unb_str_inp,index_1))then
            return False;

      else
            --if equal to each other
            index_0 := index_0 + 1;
            index_1 := index_1 -1;
            return_bool_val := palindrome_or_not(unb_str_inp,index_0,index_1);
      end if;

   end palindrome_or_not;

begin--youtube gives wrong answer
   Ada.Text_IO.PUt_Line("Start of 4_3");
   unb_str_0 := Ada.Strings.Unbounded.To_Unbounded_String("youtube");--racecar,youtube (check for non palindrome),noon
   index_1 := Ada.Strings.Unbounded.Length(unb_str_0);
   return_bool_val := palindrome_or_not(unb_str_0,index_0,index_1);
   Ada.Text_IO.Put_Line("return_bool_val = " & Boolean'Image(return_bool_val));
   --null;
end Lab_4_3_Book;
