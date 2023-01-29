with Ada.Text_IO;
procedure Lab_2_2_Book is
   bool_0: Boolean := False;
   bool_1: Boolean := False;
   bool_result : Boolean := False;
   char_input_0 : character :='0';
   char_input_1 : character := '0';
   char_input_while : character:='0';

   while_loop_bool : Boolean := True;
   procedure get_char_input(char_input : In Out character;bool : In Out boolean) is
   begin
      Ada.Text_IO.Get(char_input);
      --Ada.Text_IO.Put_Line("char_input ==  " & char_input);

      if (char_input = '1' Or char_input = 'n') then
         bool := True;
      elsif (char_input = '0' or char_input = 'y') then
         bool := False;
      else
         Ada.Text_IO.Put_Line("Input not valid setting bool_0 to 1");
         bool:= True;

      end if;

   end;

begin
   --  Insert code here.
   while (while_loop_bool = True) loop
      get_char_input(char_input_0,bool_0);
      Ada.Text_IO.Put_Line("char_input_0 == " & char_input_0 & " bool_0 == " & Boolean'Image(bool_0));
      get_char_input(char_input_1,bool_1);
      Ada.Text_IO.Put_Line("char_input_1 == " & char_input_1 & " bool_1 == " & Boolean'Image(bool_1));

      bool_result := ((bool_0 or bool_1) and (not(bool_0 and bool_1)));
      Ada.Text_IO.Put_Line("bool_result = " & boolean'image(bool_result));

      Ada.Text_IO.Put_Line("Exit out of program? (y or n) ");
      get_char_input(char_input_while,while_loop_bool);




      end loop;










end Lab_2_2_Book;--remember ada is case insensitive
