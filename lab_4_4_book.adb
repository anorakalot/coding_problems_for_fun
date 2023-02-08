-- declare_block.adb:
with Ada.Text_IO;
procedure lab_4_4_book is
   Counter : Natural := 0;

   procedure declare_proc is
      Bool : boolean := True;
   begin
      counter := 3;
      Ada.Text_io.Put_Line ("inside delcare " & Natural'image(counter));
      Ada.Text_io.put_line( "bool = " & boolean'image(bool));


   end declare_proc;


begin
   Ada.Text_IO.Put_Line
     ("Right before the declare: " & Natural'Image (Counter));

   declare_proc;

   --Ada.Text_IO.Put_Line("The boolean after declare: " &
   -- Natural'Image(Bool));
   Ada.Text_IO.Put_Line
     ("Right after the declare: " & Natural'Image (Counter));--this changes with declare proc since it's a global variable
end lab_4_4_book;
