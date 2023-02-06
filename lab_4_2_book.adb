with Ada.Text_IO;
with Ada.Strings.Unbounded;

procedure Lab_4_2_Book is

   function palindrome_or_not
     (unb_str_inp : in out Ada.Strings.Unbounded.Unbounded_String) return Boolean is
      --have 2 indexes (one at beginning and one at back) check is each has same values
      index_0 : Integer :=0;
      str : String(1..100);
   begin

      str := Ada.Strings.Unbounded.To_String(unb_str_inp);
      Ada.Text_IO.Put_Line("str'length " & str'Length);
      --Ada.Text_IO.Put_Line("unb_str_inp'Length " & unb_str_inp'Length);


      return True;--placeholder
   end palindrome_or_not;

begin
   --  Insert code here.
   null;
end Lab_4_2_Book;
