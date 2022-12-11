with Ada.Text_IO; use Ada.Text_IO;

procedure Tic_Tac_Toe_Program is
   input: Integer :=0;
   --  X: Character := 'X';

   type X_OR_O is (X,O);
   type y_col_index is range 0 .. 2;
   type x_row_index is range 0 .. 2;

   type Tic_tac_toe_board is array (y_col_index,x_row_index) of X_OR_O;

begin
   --  Insert code here.
   for y in y_col_index loop
      --Put_line("test loop!" & Integer'Image(y));
      for x in x_row_index loop
      Put("y " & y_col_index'Image(y) & " x " &
              x_row_index'Image(x) & " ");

      end loop;
      New_line;
      end loop;
   --  /Put_Line ("hello world");


end Tic_Tac_Toe_Program;
