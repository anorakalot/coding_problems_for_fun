with Ada.Text_IO;
with Ada.Strings;
with Ada.Strings.Bounded;
with Ada.Strings.Fixed;
with Ada.Numerics.Discrete_Random;
procedure Lab_5_Book is
   last : Natural;
   string_inp : String(1..50 ) := (others => ' ');--this is good since it keeps all other charcaters
   --as blanks in the beginning so only the typed out string inp shows
   random_int_val : Integer;
   random_float_val : Float;
   low_int_range : Integer;
   high_int_range : integer;

   type company_rec is record
      --first_name : Ada.Strings.Bounded.Bounded_String(1..50);
      first_name : String(1..50) := (others => ' ');
      --first_name : Ada.Strings.Bounded.bounded_string;
      last_name : String(1..50) := (others => ' ');
      title : String(1..50) := (others => ' '); -- iniitalizing with all whitespace is good
      salary : Integer;
      vac_hours : Integer;
      sick_time : Integer;
      num_of_years_in : Integer;

   end record;

   type comp_rec_array is array (1..2) of company_rec;

   my_comp_rec_array : comp_rec_array;
   --my_comp_rec : company_rec;

   --type name_array is array (1..10) of string(1..50);
   --my_name_array : name_array := (1=>"apples" , others => " ");
   function make_custom_string_w_size (func_str_inp : in out String; last_func_inp : in out Natural ) return String is
      --string constraint not allowed infunction parameter declaration
      new_str : String (1..last_func_inp);
   begin


      Ada.Strings.Fixed.Move(func_str_inp (func_str_inp'First..last_func_inp), new_str);--1..last_func_inp
      Ada.Text_IO.Put_Line("New_str = " & new_str);


   --return "Apples";
     return new_str;


   end make_custom_string_w_size;

   procedure check_int_ranges (low_range : in out Integer; high_range : in out Integer) is
      temp_int : integer;
   begin
      if (low_range > high_range) then
         low_range := temp_int;
         low_range := high_range;
         high_range := temp_int;
      elsif(low_range = high_range) then
         high_range := high_range +10;
         end if;


   end check_int_ranges;

   function return_random_int_val (low_range : in Integer; high_range : in Integer ) return integer is
      check_int_ranges(low_range,high_range);
      subtype vals is Integer range low_range .. high_range;
      package random_int_val is new Ada.Numerics.Discrete_random(Result_Subtype => Vals);
       Gen : random_int_val.Generator  ;
   begin
         random_int_val.reset(Gen=>Gen);
         return random_int_val.random(Gen=>gen);

   end return_random_int_val;





     --start of main function below
begin
   --  Insert code here.

   for i in 1..2 loop
      Ada.Text_IO.Put_Line("first_name for employee " & Integer'Image(i));
      Ada.Text_IO.Get_line(string_inp,last);
      Ada.Text_IO.Put_Line(Natural'Image(last));
      --have a function that returns a string with exact length
      --declare
        -- new_str := String(1..last);
      --begin
        -- new_str := make_custom_string_w_size(string_inp,last);

      --end
        --maybe change above later to make it all a function that sets first name directly
        --actually above might not work since I set thte size of the strings itself in the record as 1..50 already lol
      --new_str := make_custom_string_w_size(string_inp,last);
      --my_comp_rec_array(i).first_name := string_inp;
      my_comp_rec_array(i).first_name := string_inp;


      string_inp := (others => ' ');

      Ada.Text_IO.Put_Line("last_name for employee " & Integer'Image(i));
      Ada.Text_IO.Get_line(string_inp,last);
      Ada.Text_IO.Put_Line(Natural'Image(last));
      my_comp_rec_array(i).last_name := string_inp;
      --my_comp_rec(i).last_name := string_inp;

      string_inp := (others => ' ');

      Ada.Text_IO.Put_Line(my_comp_rec_array(i).first_name);
      Ada.Text_IO.Put_Line(my_comp_rec_array(i).last_name);
      --Ada.Text_IO.Put_Line(Integer'Image(my_comp_rec_array(i).first_name'Last));

      --input rest of variables here
      Ada.Text_IO.Put_Line("Input low range for salary employee " & Integer'Image(i));
      Ada.Text_IO.Get_Line(string_inp,last);
      low_int_range := Integer'Value(string_inp(1..last));
      Ada.Text_IO.Put_Line(Integer'Image(low_int_range));

      Ada.Text_IO.Put_Line("Input high range for salary employee " & Integer'Image(i));
      Ada.Text_IO.Get_Line(string_inp,last);
      high_int_range := Integer'Value(string_inp(1..last));
      Ada.Text_IO.Put_Line(Integer'Image(high_int_range));



      random_int_val := return_random_int_val(low_int_range,high_int_range);
      Ada.Text_IO.Put_Line("Random_val " & Integer'Image(random_int_val));

   end loop;

   --Ada.Text_IO.Get_Line(string_inp,last);

   --my_comp_rec_array(1).first_name := string_inp;
   --string_inp := (others => ' ');


   --Ada.Text_IO.Get_Line(my_comp_rec.first_name,last);
   --Ada.Text_IO.Put_Line(my_comp_rec.first_name);
   --Ada.Text_IO.Put_Line(Natural'Image(last));

   null;
end Lab_5_Book;
