with Ada.Text_IO;
with Ada.Strings.Unbounded; use Ada.strings.Unbounded;
with Ada.Strings.Fixed;

procedure Lab_2_3_Book is
   test_string_0 : String(1 .. 63,1..13);--seems I can't start range with 0 (which it shouldn't since i should be
                                   --able to start index at any range I though but for now just have it start at 1
                                   --63 is total width of the thing to print
   test_string_1 : String(1 .. 63) := (others => '#');
   test_string_2 : String(1 .. 63) := (1=> '#',2=>'#',62=>'#',63=>'#',others=>' ');
   --test_string_1 : String:="APPLES";
begin
   --  Insert code here.
   --test_string_0 := test_string_1; this won't work
   --Ada.Strings.Fixed.Move(test_string_1,test_string_0);
   --Ada.Text_IO.Put_Line(test_string_0);
   Ada.Text_IO.Put_Line(test_string_1);
   Ada.Text_IO.Put_Line(test_string_2);
   null;
end Lab_2_3_Book;
