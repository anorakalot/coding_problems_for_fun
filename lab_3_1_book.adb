with Ada.Text_IO;
with Ada.Numerics.Discrete_Random;

procedure Lab_3_1_Book is
-- this is how you would make an integer input to the
-- command line.

   TempString : String (1 .. 3);
   Last       : Natural := 0;
   Value      : Integer := 0;

--Ada.Text_IO.Get_Line(TempString, Last);
--Value := Integer'Value(TempString(1 .. Last));

-- this is how you would generate a random integer within a
-- specific range.
   subtype Vals is Positive range 1 .. 5;
   package Random100 is new Ada.Numerics.Discrete_Random
     (Result_Subtype => Vals);
   Gen          : Random100.Generator;
   GeneratedNum : Vals := 1;

   --misc variables
   Score : Integer := 5;
   not_right_guess : Boolean := True;
begin
   --randon number gen
   Random100.Reset (Gen => Gen);
   GeneratedNum := Random100.Random (Gen => Gen);
   Ada.Text_IO.Put_Line("generated_num = " & Vals'Image(generatedNum));
   --above line is for debugging pruposes only to amek sure game works properely

   if (generatednum > 5 or generatednum < 0) then--i fixedd bug just red vals range above from 1..10 to 1..5
      Ada.Text_IO.Put_Line("Generation error not in correct range , setting to default val ");
      GeneratedNum := 5;
      end if;

   Ada.Text_IO.Put_Line("Generated num is between 1-5 Guess with fewer mistakes to get a higher score");

   while not_right_guess loop
      --  taking in integer input
      Ada.Text_IO.Get_Line (TempString, Last);
      Value := Integer'Value (TempString (1 .. Last));

      if (value = generatednum) then
         Ada.Text_IO.Put_Line("guessed right! generatednum was " & Vals'Image(generatednum) & " Score is " & Integer'Image(score));
         not_right_guess := False;
      else
         Ada.Text_IO.Put_Line("Not right guess! Try again!");
         score := score - 1;
         end if;
      end loop;
   null;
end Lab_3_1_Book;
