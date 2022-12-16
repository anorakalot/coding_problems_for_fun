with Ada.Text_IO; use Ada.Text_IO;

procedure Tic_Tac_Toe_Program is
   --input: Integer :=0; -- thjios is why there was a confl of decl error was beacuse this variable was
   --already being used for this input.
   --  X: Character := 'X';
   type X_OR_O is
     (X, O, NA);--error was here because I think that - is a special characer
   --so for now just using NA
   --type game_over is range 0 .. 1;
   type y_col_index is range 0 .. 2;
   type x_row_index is range 0 .. 2;

   type Tic_tac_toe_board is array (y_col_index, x_row_index) of X_OR_O;
   board : Tic_tac_toe_board := ((NA, NA, NA), (NA, NA, NA), (NA, NA, NA));
   input : X_OR_O            := X;
   --setting input to a x_or_o val at init fixed bug

   type GAME_STATES is (GAME_INIT,GAME_START,CHOOSE_X_O,
                       CHOOSE_MOVE,CHECK_IF_VALID_MOVE,CHECK_WIN,
                       SWITCH_PLAYER,GAME_OVER);
   game_state : GAME_STATES := GAME_INIT;
   procedure display_board is
   begin
      for y in y_col_index loop
         --Put_line("test loop!" & Integer'Image(y));
         for x in x_row_index loop
            --input        := NA;
            --above line of code does work however since
            --it turns whatever val at board(y,x) into correct
            --board (y, x) := input;

            Put (X_OR_O'Image (board (y, x)) & " ");
            --  board(y,x) := -;
            --  Tic_tac_toe_board(y,x) := -;
            --  put (Tic_tac_toe_board'Image(y,x) & " ");

            --  Put(tic_tac_toe_board);
         end loop;
         New_Line;
      end loop;

   end display_board;

begin
   --  Insert code here.
   --put main switch case finite state machine here
   display_board;



end Tic_Tac_Toe_Program;

--
--  for y in y_col_index loop
--        --Put_line("test loop!" & Integer'Image(y));
--        for x in x_row_index loop
--        Put("y " & y_col_index'Image(y) & " x " &
--                x_row_index'Image(x) & " ");
--
--        end loop;
--        New_line;
--     end loop;

-- prototype case for tic tac toe program
