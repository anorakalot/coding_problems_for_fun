with Ada.Text_IO;
with Ada.Strings.Fixed;
with Ada.Numerics.Discrete_Random;

procedure Lab_3_2_Book is
   subtype Vals is positive range 1..100;
   package Random100 is new Ada.Numerics.Discrete_Random
     (Result_Subtype => Vals);
   gen : Random100.Generator;
   generatednum : Vals :=1;

   temp_string : string(1..4);
   last : Natural :=0;
   --val : Integer :=0;
   --char_val : character := ' ';
   string_val : string(1..4);

   while_bool : Boolean := True;


begin
   while while_bool loop

      random100.reset(gen=>gen);
      generatednum := random100.random(gen=>gen);
      Ada.Text_IO.Put_Line("generated_num = " & Vals'Image(generatednum));
   --  Insert code here.

      case generatednum is
         when 1..9 =>
            Ada.Text_IO.Put_line("in 0-9 range");

         when 10..19=>
            Ada.Text_IO.Put_Line("in 10's range");
         when 20..29=>
            Ada.Text_IO.Put_Line("in 20's range");
         when 30..39=>
            Ada.Text_IO.Put_Line("in 30's range");
         when 40..49=>
            Ada.Text_IO.Put_Line("in 40's range");
         when 50..59=>
            Ada.Text_IO.Put_Line("in 50's range");
         when 60..69=>
            Ada.Text_IO.Put_Line("in 60's range");
         when 70..79=>
            Ada.Text_IO.Put_Line("in 70's range");
         when 80..89=>
            Ada.Text_IO.Put_Line("in 80's range");
         when 90..99=>
            Ada.Text_IO.Put_Line("in 90's range");
         when 100=>
            Ada.Text_IO.Put_Line("is 100!");
      end case;


      Ada.Text_IO.get_line(temp_string,last);

      Ada.Text_IO.Put_Line(" temp_string = " & temp_string);
      Ada.Text_IO.Put_Line("last = " & natural'image(last));
      --char_val := character'value(temp_string(1..last));
      string_val := temp_string(1..last);--bug on this line

      Ada.Text_IO.Put_Line("string_val = " & string_val);
      --Ada.Text_IO.Put_Line("char_val " & character'image(char_val));
      --val := Integer'Value(temp_string(1..last));
      --Ada.Text_IO.Put_Line("val = " & Integer'Image(val));


   end loop;
   null;
end Lab_3_2_Book;
