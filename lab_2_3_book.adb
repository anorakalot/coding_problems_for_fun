with Ada.Text_IO;
with Ada.Strings.Unbounded; use Ada.strings.Unbounded;
with Ada.Strings.Fixed;

procedure Lab_2_3_Book is
   type comb_string is array (1..13) of String(1..63);
   empty_string : String(1..63) := (others=> ' ');
   total_string : comb_string := (others=> empty_string);
   --test_string_0 : String(1 .. 63);--seems I can't start range with 0 (which it shouldn't since i should be
                                   --able to start index at any range I though but for now just have it start at 1
                                   --63 is total width of the thing to print
                                   --to have a 2d string will have to make an array for it

   uniq_string_0 : String(1 .. 63) := (others => '#');
   uniq_string_1 : String(1 .. 63) := (1..2=> '#',62..63=>'#',others=>' ');
   uniq_string_2 : String(1 .. 63) := (1..2 =>'#',9..19 =>'0',23..31=>'0',36..46=>'0',62..63=>'#',others=>' ');
   uniq_string_3 : String(1 .. 63) := (1..2 =>'#',9..10 =>'0',18..19=>'0',23..24=>'0',31..32=>'0'
                                       ,36..37=>'0', 45..46=>'0',62..63=>'#',others=>' ');
   uniq_string_4 : String(1 .. 63) := (1..2 =>'#',9..19=>'0',23..24=>'0',31..32=>'0'
                                       ,36..46=>'0',62..63=>'#',others=>' ');
   uniq_string_5 : String(1 .. 63) := (1..2 =>'#',9..10 =>'0',18..19=>'0',23..31=>'0'
                                       ,36..37=>'0', 45..46=>'0',62..63=>'#',others=>' ');
   --test_string_1 : String(1 .. 63) := (others => '#');
   --test_string_2 : String(1 .. 63) := (1=> '#',2=>'#',62=>'#',63=>'#',others=>' ');
   --test_string_1 : String:="APPLES";

begin
   total_string(1) := uniq_string_0;
   total_string(2) := uniq_string_0;
   total_string(3) := uniq_string_1;
   total_string(4) := uniq_string_2;
   total_string(5) := uniq_string_3;
   total_string(6) := uniq_string_3;
   total_string(7) := uniq_string_4;
   total_string(8) := uniq_string_3;
   total_string(9) := uniq_string_3;
   total_string(10) := uniq_string_5;
   total_string(11) := uniq_string_1;
   total_string(12) := uniq_string_0;
   total_string(13) := uniq_string_0;

     for x in 1..13 loop
      Ada.Text_IO.Put_Line(total_string(x));

      end loop;
   --Ada.Text_IO.Put_Line(total_string(1));
   --  Insert code here.
   --test_string_0 := test_string_1; this won't work
   --Ada.Strings.Fixed.Move(test_string_1,test_string_0);
   --Ada.Text_IO.Put_Line(test_string_0);
   --Ada.Text_IO.Put_Line(test_string_1);
   --Ada.Text_IO.Put_Line(test_string_2);
   null;
end Lab_2_3_Book;
