with Ada.Text_IO; use Ada.Text_IO;
--with Ada.Enumeration_IO; use Ada.Enumeration_IO;

procedure Tic_Tac_Toe_Program is
   --input: Integer :=0; -- thjios is why there was a confl of decl error was beacuse this variable was
   --already being used for this input.
   --  X: Character := 'X';
   char_input : Character :='X';
   int_input : Integer := 0;
   type X_OR_O is
     (X, O, NA);--error was here because I think that - is a special characer
   --so for now just using NA
   --type game_over is range 0 .. 1;
   type y_col_index is range 0 .. 2;
   type x_row_index is range 0 .. 2;

   y_input : y_col_index := 0;
   x_input : x_row_index := 0;

   type Tic_tac_toe_board is array (y_col_index, x_row_index) of X_OR_O;
   board : Tic_tac_toe_board := ((NA, NA, NA), (NA, NA, NA), (NA, NA, NA));
   input : X_OR_O            := X;
   check_win_cond_var : X_OR_O;
   --setting input to a x_or_o val at init fixed bug

   type GAME_STATES is (GAME_INIT,GAME_START,CHOOSE_X_O,
                       CHOOSE_MOVE,CHECK_IF_VALID_MOVE,CHECK_WIN,
                       SWITCH_PLAYER,GAME_OVER);
   game_state : GAME_STATES := GAME_INIT;
   type valid_bool is range 0 .. 1;
   valid_move_bool : valid_bool :=0;
   valid_win_bool : valid_bool := 0;
   valid_row_win_bool : valid_bool := 0;
   valid_col_win_bool : valid_bool := 0;
   valid_row_check_bool : valid_bool :=0;
   valid_col_check_bool : valid_bool :=0;
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
   case game_state is --transitions
      when GAME_INIT =>
         game_state := GAME_START;
      when GAME_START =>
         game_state := CHOOSE_X_O;
      when CHOOSE_X_O=>
         game_state := CHOOSE_MOVE;
      when CHOOSE_MOVE=>
         game_state := CHECK_IF_VALID_MOVE;
      when CHECK_IF_VALID_MOVE =>
         if valid_move_bool = 0 then
            game_state := CHOOSE_MOVE; --goes back to choose another move
         elsif valid_move_bool = 1 then
            game_state := CHECK_WIN;
         else
            Put_Line("ERROR IN CHECK_IF_VALID_MOVE");
         end if ;
      when CHECK_WIN=>
         if valid_win_bool = 0 then
            game_state := SWITCH_PLAYER;
         elsif valid_win_bool = 1 then
            game_state := GAME_OVER;
         else
            Put_Line("Error in CHECK_WIN");
         end if;
      when SWITCH_PLAYER=>
         game_state := CHOOSE_MOVE;
      when GAME_OVER=>
         --nothing should just stay in GAME_OVER
         game_state := GAME_OVER;--might need to change this looping back to game over state
         --  end case
   end case;

   case game_state is --actions
      when GAME_INIT =>
         Put_Line("Game_init");
      when GAME_START =>
         Put_Line("Game Start");
      when CHOOSE_X_O=>
         Put_Line("Choose X or O ");
         --Get(input);
         Get(char_input);
         input := X_OR_O'Val(char_input);
         Put_Line("You chose " & X_OR_O'Image(input));
      when CHOOSE_MOVE=>
         display_board;
         Put_Line("Enter Y_input (note 0 is top and 2 is bottom for 2d array)");
         Get(y_input);
         Put_Line("Enter x_input ");
         Get(x_input);
         Put_Line("y== " & y_col_index'Image ( y_input) & "x == " & x_col_index'Image(x_input));

      when CHECK_IF_VALID_MOVE =>
         --in here need to check if current input either x or o has already
         --taken a spot in the tic tac toe board
          if board(y_input,x_input) /= NA then
             Put_Line("input is valid!");
             valid_move_bool := 1;--so it transitions to the next state correctly
             --Now to actuall put input onto the board
             Put_Line("putting input onto the board!");
             board(y_input,x_input) := input;
             display_board;
          else
             Put_Line("input is NOT valid!");
             valid_move_bool := 0;--this needs to be zero
          end if;


      when CHECK_WIN=>
         --check_win_cond_var := board(0,0);
         --probably best to do this in a algorithmic way since
         -- if I need to scale up I can do it easier with this method
         Put_Line ("checking row win condition");
         valid_win_bool := 0;
         valid_row_win_bool :=0;
         for y in y_col_index loop
            valid_row_check_bool := 1;
            valid_row_win_bool := 1;
            check_win_cond_var := board(y,0);
            if (check_win_cond_var = NA) then
               valid_row_check_bool :=0;--if first value is NA then this row automatically isn't valid
               end if;
            --set it to the first element of x at a y value to check if they are all the same
            --actually this might now work since if a value is NA and they are all NA then it would mistangly make it so
            for x in x_col_index loop
               if (valid_row_check_bool = 1) and (board(y,x) /= check_win_cond_var) then
                  valid_row_win_bool := 0;
               end if;
            end loop;
            if valid_row_win_bool = 1 then
               valid_win_bool :=1;
            end if;

         end loop;

         --think there might be a logic issue with valid_win_bool above
      when SWITCH_PLAYER=>
         if (input = X) then
            input := O;
         elsif (input = O) then
            input := X;
         end if;
      when GAME_OVER=>
         Put_Line("Game_Over!");
   end case;


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
