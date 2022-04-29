//=========================================================================
// Name & Email must be EXACTLY as in Gradescope roster!
// Name: Richard McGee
// Email: rmcge002@ucr.edu
// 
// Assignment name: Lab 02
// Lab section: 
// TA: 
// 
// I hereby certify that I have not received assistance on this assignment,
// or used code, from ANY outside source other than the instruction team
// (apart from what was provided in the starter file).
//
//=========================================================================

`timescale 1ns / 1ps

module floatToFixed(
  input wire clk, 
  input wire rst , 
  input wire[31:0] float, 
  input wire[4:0] fixpointpos , 
  output reg[31:0] result );

// Your  Implementation 
reg [7:0] exponent_bits;
integer last_one_mantissa;
integer last_point_before_putting_one;
reg[31:0] result_copy;
// -------------------------------------------	
// Register the results 
// -------------------------------------------

always @(*) begin
  //$write("\nfloat %b_%b_%b\n",float[31],float[30:23],float[22:0]);
	// Replace the following code with your implmentation
	//result = float;//this line was what came with the code
  
  //first find exponent 
  ////$write("\n\nAPPLES float to fixed\n");

  ////$write("\n\n30 to 23 bits = %h\n",float[30:23]);
  ////$write("\n\nexponent bits minus 127 = %h ",float[30:23] - 127);

  //mantissa 
  //float[22:0]
  
  //make sure first bit is zero if float is positive 
  //make sure first bit is 1 if float is negative
  //put mantissa into result



  //should only go mantissa length
  for (integer i = 0; i < 23; i++) begin 
    if (float[i] == 1'b1)begin 
    last_one_mantissa = i; 
    i = 100; // to stop the loop
    end //end of if 
  end //end of for loop 


  //have last_one_mantissa go up?
  for (integer x = 0; x < 23; x++) begin 
    result[x] = float[last_one_mantissa];
    last_one_mantissa += 1;
    last_point_before_putting_one = x;
    if (last_one_mantissa > 23)begin 
    x = 100; // to stop for loop 
    end

  end 
  // last_point_before_putting_one += 1; //need to go to next index to add 1 since always have 1 to add 
  // result[last_point_before_putting_one] =1'b1;

  last_point_before_putting_one += 1; 
  result[last_point_before_putting_one] = 0; //putting 0 here as placeholder

  for (integer z = last_point_before_putting_one; z < 32; z ++)begin
    result[z] = 0;
  end 


  //do the sign bit at the end
  //if float at bit 31 is 1 set result 
  //only do 2's complement opposite if sign bit is 1 
  if (float[31] == 1'b1)begin 
    result_copy = ~result;
    //result = ~result ;
    result_copy += 1;
    result = result_copy;
    result <= result;
  end
  //////$write("%h",[29:22]float);
end 
endmodule
