with Ada.Text_IO;
with animal;
--with ada.strings;
with ada.strings.unbounded;
--exception is legs 1000 and height 2000
procedure Lab_6_Book is --init is name ,legs,weight,height
   var_1 : animal.creature := Animal.Init("indomitus rex",1000,3300,45);
   var_2 : animal.creature := animal.init;
begin
   Ada.Text_IO.Put_Line("legs var_1 = " & Natural'Image(animal.get_legs(var_1)));
   animal.set_legs(var_1,1200);
   ada.text_IO.put_line("legs var_1 = " & natural'Image(animal.get_legs(var_1)));
   ada.text_IO.put_line("legs var_2 = " & natural'image(animal.get_legs(var_2)));

   animal.set_height(var_2,528);
   ada.text_IO.put_line("height var_2 = " & natural'image(animal.get_height(var_2)));
   animal.set_height(var_2,5341);
   ada.text_IO.put_line("height var_2 = " & natural'image(animal.get_height(var_2)));
   Ada.text_IO.Put_Line("name of var_2 = " & Ada.Strings.unbounded.To_string(animal.get_name(var_2)));
   Ada.text_IO.Put_Line("name of var_1 = " & Ada.Strings.unbounded.To_string(animal.get_name(var_1)));


   --  Insert code here.
   null;
end Lab_6_Book;
