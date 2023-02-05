with Ada.Text_IO;
with Ada.Strings.Fixed;
with Ada.Strings.Bounded;
with Ada.Numerics.Discrete_Random;

procedure Lab_3_2_Book is
   subtype Vals is positive range 1..100;
   package Random100 is new Ada.Numerics.Discrete_Random
     (Result_Subtype => Vals);
   gen : Random100.Generator;
   generatednum : Vals :=1;

   temp_string : string(1..4);
   --temp_string : Bounded_string(10);
   last : Natural :=0;
   --val : Integer :=0;
   char_val : character := ' ';
   string_val : string(1..4);
  -- string_val : Bounded_string(10);


   while_bool : Boolean := True;

   get_rid_of_newline_bug_char : Character := ' ';
   first_iter : Boolean := True;

begin

   while while_bool loop
      Ada.Text_IO.New_line;
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

      --string_val := Ada.Text_IO.get_line;--(temp_string,last);
      --Ada.Text_IO.put(temp_string);
      --Ada.Text_IO.put(last);
      --string_val := temp_string(1..last);

      --Ada.Text_IO.Get(get_rid_of_newline_bug_char);
      --temp_string := Ada.Text_IO.Get_Line;
      --if (first_iter = False)then

      Ada.Text_IO.Put_Line("Exit? yes or no");
      Ada.Text_IO.Get(char_val);
      Ada.Text_IO.skip_line;--put this ehre since found online that sometime newline char stuk in input buffer
                            --after things like get I don't have get so I dont' know why it sometimes skips get_line but at least I know it
                            -- works with this since it keeps it from skipping get_line below with a random newline being in the input buffer

         --end if;
      --Ada.Text_IO.get_line(temp_string,last);
      --Ada.Text_IO.Put_Line(" temp_string = " & temp_string);
      --Ada.Text_IO.Put_Line("last = " & natural'image(last));

      --char_val := character'value(temp_string(1..last));
      --string_val := temp_string(1..last);--bug on this line
      --Ada.strings.fixed.move(temp_string,string_val);

      --Ada.Text_IO.Put_Line("string_val = " & string_val);

      if (char_val = 'y') then
      --if string_val = "yes0" then --or string_val = "y" or string_val = "Yes0" then
         Ada.Text_IO.Put_Line("Inside of if");
         while_bool := False;
         end if;
      --Ada.Text_IO.Put_Line("char_val " & character'image(char_val));
      --val := Integer'Value(temp_string(1..last));
      --Ada.Text_IO.Put_Line("val = " & Integer'Image(val));

      --if (first_iter = True) then
        -- first_iter := False;
        -- end if;
        Ada.Text_IO.PUt_Line("while_bool = " & boolean'image(while_bool));
   end loop;
   null;
end Lab_3_2_Book;
