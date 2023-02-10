with Ada.Text_IO;
with Ada.Strings;
with Ada.Strings.Bounded;
procedure Lab_5_Book is
   last : Natural;
   string_inp : String(1..50 ) := (others => ' ');
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
   my_comp_rec : company_rec;

   --type name_array is array (1..10) of string(1..50);
   --my_name_array : name_array := (1=>"apples" , others => " ");

begin
   --  Insert code here.

   for i in 1..2 loop
      Ada.Text_IO.Put_Line("first_name of employee ");
      Ada.Text_IO.Get_line(string_inp,last);
      my_comp_rec_array(i).first_name := string_inp;

      string_inp := (others => ' ');

      Ada.Text_IO.Put_Line("last_name of employee ");
      Ada.Text_IO.Get_line(string_inp,last);
      my_comp_rec_array(i).last_name := string_inp;

      Ada.Text_IO.Put_Line(my_comp_rec_array(i).first_name & ' ' & my_comp_rec_array(i).last_name);
      Ada.Text_IO.Put_Line(Integer'Image(my_comp_rec_array(i).first_name'Last));


   end loop;

   Ada.Text_IO.Get_Line(string_inp,last);

   my_comp_rec_array(1).first_name := string_inp;
   string_inp := (others => ' ');


   Ada.Text_IO.Get_Line(my_comp_rec.first_name,last);
   Ada.Text_IO.Put_Line(my_comp_rec.first_name);
   Ada.Text_IO.Put_Line(Natural'Image(last));

   null;
end Lab_5_Book;
