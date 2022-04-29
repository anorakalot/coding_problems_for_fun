//=========================================================================
// Name & Email must be EXACTLY as in Gradescope roster!
// Name: Richard McGee
// Email: rmcge002@ucr.edu
// 
// Assignment name: 
// Lab section: 
// TA: 
// 
// I hereby certify that I have not received assistance on this assignment,
// or used code, from ANY outside source other than the instruction team
// (apart from what was provided in the starter file).
//
//=========================================================================

`timescale 1ns / 1ps

module fixedToFloat(
  input wire clk, 
  input wire rst , 
  input wire[31:0] targetnumber, 
  input wire[4:0] fixpointpos , 
  output reg[31:0] result );


// Your  Implementation
 //integer     index;//just for testing  
integer first_one_index;
integer last_one_index;
integer point_position; 
//reg sign_bit;  //ca kist set it directly to --
//result
reg[22:0] mantissa_bits;
reg[7:0] exponent_bits;
reg[31:0] test; 
reg[31:0] targetnumber_copy;

integer mantissa_position;

//reg[31:0] copy of result;
// -------------------------------------------	
// Register the results 
// -------------------------------------------

always @(*) begin 	
 // integer index;
	// Replace the following code with your implmentation
  	// for (i = 0; i < 16; i = i +1) begin
   	//   	$display ("Current value of i is %d", i);
  	// end
 //#100; // Wait
  ////$write("\nAPPLES fixed to float \n");
  targetnumber_copy = targetnumber;
  if (targetnumber[31] == 1) begin 
    //$write("\nnumber is negative\n");
    //need to convert target number to positive values for use (2's complement)
    targetnumber_copy = ~targetnumber;
    targetnumber_copy += 1;
    result[31] = 1;
  end
  else begin 
    //$write("\nnumber is positive\n");
    result[31] = 0;
  end 

  //integer index ;
// #100; // Wait
  //for (integer i = 0; i < 31; i++)begin 
  for (integer i = 31; i > 0; i--)begin 
    ////$write("For apples %h \n",i);
    if (targetnumber_copy[i] == 1'b1)begin 
      //test[i] = i;
      first_one_index = i;
      mantissa_position = 22;
      for (integer x=i-1; x >= 0; x --) begin
      mantissa_bits[mantissa_position] = targetnumber_copy[x];
      //$write("targetnumber[x] = %h",targetnumber_copy[x]);
      //$write("mantissa_bits[mant_pos]= %h\n",mantissa_bits[mantissa_position]);
      mantissa_position -=1;
      end //end of inner for loop
      //mantissa_bits = targetnumber[i:0];
      //make mantissa bits here 
      //bedause this is where first one index 
      //is made 
    
      //break;
      i = -1; // to end loop 
    end 
  
    
  end//end of for loop find first 1 

  // do the rest of mantissa position set it to zero
  for(integer j = mantissa_position;  j >= 0; j--) begin
  mantissa_bits[j] = 0;
  end 
 //#100; // Wait
  for (integer i = 0; i < 31; i++)begin 
    if (targetnumber_copy[i] == 1'b1)begin 
      last_one_index = i;
      i = 36; //to get out of loop

    end 
  
  
  end //end of for loop find last 1 


  //$write("first_one_index %h\n", first_one_index);
  //$write("last_one_index %h\n", last_one_index);
 
  
  point_position = last_one_index + fixpointpos; 
  //$write("point position %h\n", point_position);
  
  exponent_bits = first_one_index - point_position;
  //$write("Exp Number before 127 %h\n", exponent_bits);
  
  exponent_bits += 127;//set exponent bits +127 offset 
  //$write("Exp Number after 127 %h\n", exponent_bits);
  

  //$write("Mantissa bits  %h\n", mantissa_bits);
  
  //mantissa_bits = targetnumber[first_one_index-1:0];
  result[30:23] = exponent_bits; 
  result[22:0] = mantissa_bits;
 //#100; // Wait
  $write("\nfixpointpos %b\n ",fixpointpos);
  $write("targetnumber %b\n",targetnumber);
  $write("targetnumber_copy %b\n",targetnumber);
  $write("result %b_%b_%b\n",result[31],result[30:23],result[22:0]);
  
  result <= result;
  result = result;
  //result = targetnumber;line of code that came with starter 

end 
endmodule