//=========================================================================
// Name & Email must be EXACTLY as in Gradescope roster!
// Name: Richard McGee
// Email: rmcge002@ucr.edu
// 
// Assignment name: Lab 02
// Lab section: 021
// TA: Fan, Quan
// 
// I hereby certify that I have not received assistance on this assignment,
// or used code, from ANY outside source other than the instruction team
// (apart from what was provided in the starter file).
//
//=========================================================================
// `timescale 1ns / 1ps
// below is when tried to do only <= operators
// module floatToFixed(
//   input wire clk, 
//   input wire rst , 
//   input wire[31:0] float, 
//   input wire[4:0] fixpointpos , 
//   output reg[31:0] result );

// // Your  Implementation 
// reg [7:0] exponent_bits;
// integer last_one_mantissa;
// integer last_point_before_putting_one;
// reg[31:0] result_copy;
// // -------------------------------------------	
// // Register the results 
// // -------------------------------------------

// always @(*) begin
//   //$write("\nfloat %b_%b_%b\n",float[31],float[30:23],float[22:0]);
// 	// Replace the following code with your implmentation
// 	//result = float;//this line was what came with the code
  
//   //first find exponent 
//   ////$write("\n\nAPPLES float to fixed\n");

//   ////$write("\n\n30 to 23 bits = %h\n",float[30:23]);
//   ////$write("\n\nexponent bits minus 127 = %h ",float[30:23] - 127);

//   //mantissa 
//   //float[22:0]
  
//   //make sure first bit is zero if float is positive 
//   //make sure first bit is 1 if float is negative
//   //put mantissa into result

//   if (float == 0)begin 
//   result <=  {32'h00000000};

//   end 

//   else begin 
//   //should only go mantissa length
//   for (integer i = 0; i < 23; i++) begin 
//     if (float[i] == 1'b1)begin 
//     last_one_mantissa <= i; 
//     i <= 100; // to stop the loop
//     end //end of if 
//   end //end of for loop 

// //#100; // Wait
//   //have last_one_mantissa go up?
//   for (integer x = 0; x < 23; x++) begin 
//     result[x] <= float[last_one_mantissa];
//     last_one_mantissa += 1;
//     last_point_before_putting_one <= x;
//     if (last_one_mantissa > 23)begin 
//     x <= 100; // to stop for loop 
//     end

//   end 
//   // last_point_before_putting_one += 1; //need to go to next index to add 1 since always have 1 to add 
//   // result[last_point_before_putting_one] =1'b1;

//   last_point_before_putting_one <= last_point_before_putting_one + 1; 
//   result[last_point_before_putting_one] <= 0; //putting 0 here as placeholder

//   for (integer z = last_point_before_putting_one; z < 32; z ++)begin
//     result[z] <= 0;
//   end 

// //#100; // Wait
//   //do the sign bit at the end
//   //if float at bit 31 is 1 set result 
//   //only do 2's complement opposite if sign bit is 1 
//   if (float[31] == 1'b1)begin 
//     result_copy <= ~result;
//     //result = ~result ;
//     result_copy += 1;
//     result <= result_copy;
//     //result <= result;
//   $write("\nfloat_to_fixed: result %b_%b_%b\n",result[31],result[30:23],result[22:0]);
  
//   end

//   end // end of else zero case
//   //#100; // Wait
//   //////$write("%h",[29:22]float);
// end 
// endmodule


// //ACTUAL WORKING CODE 
// `timescale 1ns / 1ps

// module floatToFixed(
//   input wire clk, 
//   input wire rst , 
//   input wire[31:0] float, 
//   input wire[4:0] fixpointpos , 
//   output reg[31:0] result );

// // Your  Implementation 
// reg [7:0] exponent_bits;
// integer last_one_mantissa;
// integer last_point_before_putting_one;
// reg[31:0] result_copy;
// // -------------------------------------------	
// // Register the results 
// // -------------------------------------------

// always @(*) begin
//   //$write("\nfloat %b_%b_%b\n",float[31],float[30:23],float[22:0]);
// 	// Replace the following code with your implmentation
// 	//result = float;//this line was what came with the code
  
//   //first find exponent 
//   ////$write("\n\nAPPLES float to fixed\n");

//   ////$write("\n\n30 to 23 bits = %h\n",float[30:23]);
//   ////$write("\n\nexponent bits minus 127 = %h ",float[30:23] - 127);

//   //mantissa 
//   //float[22:0]
  
//   //make sure first bit is zero if float is positive 
//   //make sure first bit is 1 if float is negative
//   //put mantissa into result

//   if (float == 0)begin 
//   result =  {32'h00000000};

//   end 

//   else begin 
//   //should only go mantissa length
//   for (integer i = 0; i < 23; i++) begin 
//     if (float[i] == 1'b1)begin 
//     last_one_mantissa = i; 
//     i = 100; // to stop the loop
//     end //end of if 
//   end //end of for loop 

// //#100; // Wait
//   //have last_one_mantissa go up?
//   for (integer x = 0; x < 23; x++) begin 
//     result[x] = float[last_one_mantissa];
//     last_one_mantissa += 1;
//     last_point_before_putting_one = x;
//     if (last_one_mantissa > 23)begin 
//     x = 100; // to stop for loop 
//     end

//   end 
//   // last_point_before_putting_one += 1; //need to go to next index to add 1 since always have 1 to add 
//   // result[last_point_before_putting_one] =1'b1;

//   last_point_before_putting_one += 1; 
//   result[last_point_before_putting_one] = 0; //putting 0 here as placeholder

//   for (integer z = last_point_before_putting_one; z < 32; z ++)begin
//     result[z] = 0;
//   end 

// //#100; // Wait
//   //do the sign bit at the end
//   //if float at bit 31 is 1 set result 
//   //only do 2's complement opposite if sign bit is 1 
//   if (float[31] == 1'b1)begin 

//     // result_copy = ~result;
//     // //result = ~result ;
//     // result_copy += 1;
//     // result = result_copy;

//     result = ~result ; 
//     result = result + 1;

//     //result <= result;
//   //$write("\nfloat_to_fixed: result %b_%b_%b\n",result[31],result[30:23],result[22:0]);
  
//   end

//   end // end of else zero case
//   //#100; // Wait
//   //////$write("%h",[29:22]float);
// end 
// endmodule


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
reg[31:0] float_copy; 
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

  // if (float == 0)begin 
  // result =  {32'h00000000};

  // end 

  if (float == 0)begin 
  result = {32'h00000000};
  end 

  else begin 
  //result[]
  result_copy = float[22:0];
  result_copy[23] = 1'b1;


  while (result_copy[0] != 1)begin 
  result_copy = result_copy >> 1;
  end 

  //if sign bit is 1 change to negative 2's complement
  if (float[31] == 1'b1)begin 
  result = ~result_copy;
  result = result + 1; 

  end 
  else begin 
  result= result_copy;

  end 

  end//end of big zero else

  // last_one_index = 0;
  // while(targetnumber_copy[0] != 0)begin 
  // targetnumber_copy = targetnumber_copy >> 1;
  // last_one_index += 1;
  // end  
  //#100; // Wait
  //////$write("%h",[29:22]float);
end 
endmodule

