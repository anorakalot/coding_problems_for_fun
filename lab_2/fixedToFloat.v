//=========================================================================
// Name & Email must be EXACTLY as in Gradescope roster!
// Name: Richard McGee
// Email: rmcge002@ucr.edu
// 
// Assignment name: Lab 02
// Lab section: 021
// TA: Fan, Quan
// 
// 
// I hereby certify that I have not received assistance on this assignment,
// or used code, from ANY outside source other than the instruction team
// (apart from what was provided in the starter file).
//
//=========================================================================

// //gonna try using <=
// below is when tried to do only <= operators
// `timescale 1ns / 1ps

// module fixedToFloat(
//   input wire clk, 
//   input wire rst , 
//   input wire[31:0] targetnumber, 
//   input wire[4:0] fixpointpos , 
//   output reg[31:0] result );


// // Your  Implementation
//  //integer     index;//just for testing  
// integer first_one_index;
// integer last_one_index;
// integer point_position; 
// //reg sign_bit;  //ca kist set it directly to --
// //result
// reg[22:0] mantissa_bits;
// reg[7:0] exponent_bits;
// reg[31:0] test; 
// reg[31:0] targetnumber_copy;

// integer mantissa_position;

// //reg[31:0] copy of result;
// // -------------------------------------------	
// // Register the results 
// // -------------------------------------------

// always @(*) begin 	
//  // integer index;
// 	// Replace the following code with your implmentation
//   	// for (i = 0; i < 16; i = i +1) begin
//    	//   	$display ("Current value of i is %d", i);
//   	// end
//  //#100; // Wait

  
//   ////$write("\nAPPLES fixed to float \n");
//   targetnumber_copy <= targetnumber;
//   if (targetnumber_copy == 0)begin 
//     result <= {32'h00000000};
//   end 

//   else begin 
//   if (targetnumber[31] == 1) begin 
//     //$write("\nnumber is negative\n");
//     //need to convert target number to positive values for use (2's complement)
//     targetnumber_copy <= ~targetnumber;
//     targetnumber_copy += 1;
//     result[31] <= 1;
//   end
//   else begin 
//     //$write("\nnumber is positive\n");
//     result[31] <= 0;
//   end 

//   //integer index ;
// // #100; // Wait
//   //for (integer i = 0; i < 31; i++)begin 
//   for (integer i = 31; i > 0; i--)begin 
//     ////$write("For apples %h \n",i);
//     if (targetnumber_copy[i] == 1'b1)begin 
//       //test[i] = i;
//       first_one_index <= i;
//       mantissa_position <= 22;
//       //#100 // Wait
//       for (integer x=i-1; x >= 0; x --) begin
//       mantissa_bits[mantissa_position] <= targetnumber_copy[x];
//       //$write("targetnumber[x] = %h",targetnumber_copy[x]);
//       //$write("mantissa_bits[mant_pos]= %h\n",mantissa_bits[mantissa_position]);
//       mantissa_position <= mantissa_position-1;
//       end //end of inner for loop
      
//       //mantissa_bits = targetnumber[i:0];
//       //make mantissa bits here 
//       //bedause this is where first one index 
//       //is made 
    
//       //break;
//       i <= -1; // to end loop 
//       //#100; // Wait
//     end 
  
    
//   end//end of for loop find first 1 

//   // do the rest of mantissa position set it to zero
//   for(integer j = mantissa_position;  j >= 0; j--) begin
//   mantissa_bits[j] <= 0;
//   end 
//   //#100; // Wait
//  //#100; // Wait
//   for (integer i = 0; i < 31; i++)begin 
//     if (targetnumber_copy[i] == 1'b1)begin 
//       last_one_index <= i;
//       i <= 36; //to get out of loop

//     end 
  
  
//   end //end of for loop find last 1 


//   //$write("first_one_index %h\n", first_one_index);
//   //$write("last_one_index %h\n", last_one_index);
 
  
//   point_position <= last_one_index + fixpointpos; 
//   //$write("point position %h\n", point_position);
  
//   exponent_bits <= first_one_index - point_position;
//   //$write("Exp Number before 127 %h\n", exponent_bits);
  
//   exponent_bits <= exponent_bits+ 127;//set exponent bits +127 offset 
//   //$write("Exp Number after 127 %h\n", exponent_bits);
  

//   //$write("Mantissa bits  %h\n", mantissa_bits);
  
//   //mantissa_bits = targetnumber[first_one_index-1:0];
//   result[30:23] <= exponent_bits; 
//   result[22:0] <= mantissa_bits;
//   //#100; // Wait
//   //#100; // Wait
//   $write("\nfixpointpos %b\n ",fixpointpos);
//   $write("targetnumber %b\n",targetnumber);
//   $write("targetnumber_copy %b\n",targetnumber);
//   $write("\nfixed_to_float: result %b_%b_%b\n",result[31],result[30:23],result[22:0]);
  
//   //result <= result;
//   result <= result;
//   //#100; // Wait
//   //result = targetnumber;line of code that came with starter 

//   end //of if big else statement checking first if target is 0
// end 
// endmodule

// //actual WORKING CODE
// `timescale 1ns / 1ps

// module fixedToFloat(
//   input wire clk, 
//   input wire rst , 
//   input wire[31:0] targetnumber, 
//   input wire[4:0] fixpointpos , 
//   output reg[31:0] result );


// // Your  Implementation
//  //integer     index;//just for testing  
// integer first_one_index;
// integer last_one_index;
// integer point_position; 
// reg sign_bit;  //ca kist set it directly to --
// //result
// reg[22:0] mantissa_bits;
// reg[7:0] exponent_bits;
// reg[31:0] test; 
// reg[31:0] targetnumber_copy;
// reg[31:0] result_copy;

// integer mantissa_position;

// //reg[31:0] copy of result;
// // -------------------------------------------	
// // Register the results 
// // -------------------------------------------

// always @(*) begin 	
//  // integer index;
// 	// Replace the following code with your implmentation
//   	// for (i = 0; i < 16; i = i +1) begin
//    	//   	$display ("Current value of i is %d", i);
//   	// end
//  //#100; // Wait

  
//   ////$write("\nAPPLES fixed to float \n");
//   targetnumber_copy = targetnumber;
//   if (targetnumber_copy == 0)begin 
//     result_copy = {32'h00000000};
//   end 

//   else begin 
//   if (targetnumber[31] == 1) begin 
//     //$write("\nnumber is negative\n");
//     //need to convert target number to positive values for use (2's complement)
//     targetnumber_copy = ~targetnumber;
//     targetnumber_copy += 1;
//     result_copy[31] = 1;
//     sign_bit = 1;
//   end
//   else begin 
//     //$write("\nnumber is positive\n");
//     result_copy[31] = 0;
//     sign_bit = 0;
//   end 

//   //integer index ;
// // #100; // Wait
//   //for (integer i = 0; i < 31; i++)begin 
//   for (integer i = 31; i > 0; i = i-1)begin 
//     ////$write("For apples %h \n",i);
//     if (targetnumber_copy[i] == 1'b1)begin 
//       //test[i] = i;
//       first_one_index = i;
//       mantissa_position = 22;
//       //#100 // Wait
//       for (integer x=i-1; x >= 0; x --) begin
//       mantissa_bits[mantissa_position] = targetnumber_copy[x];
//       //$write("targetnumber[x] = %h",targetnumber_copy[x]);
//       //$write("mantissa_bits[mant_pos]= %h\n",mantissa_bits[mantissa_position]);
//       mantissa_position -=1;
//       end //end of inner for loop
      
//       //mantissa_bits = targetnumber[i:0];
//       //make mantissa bits here 
//       //bedause this is where first one index 
//       //is made 
    
//       //break;
//       i = -1; // to end loop 
//       //#100; // Wait
//     end 
  
    
//   end//end of for loop find first 1 

//   // do the rest of mantissa position set it to zero
//   for(integer j = mantissa_position;  j >= 0; j= j-1) begin
//   mantissa_bits[j] = 0;
//   end 
//   //#100; // Wait
//  //#100; // Wait
//   for (integer i = 0; i < 31; i++)begin 
//     if (targetnumber_copy[i] == 1'b1)begin 
//       last_one_index = i;
//       i = 36; //to get out of loop

//     end 
  
  
//   end //end of for loop find last 1 


//   //$write("first_one_index %h\n", first_one_index);
//   //$write("last_one_index %h\n", last_one_index);
 
  
//   point_position = last_one_index + fixpointpos; 
//   //$write("point position %h\n", point_position);
  
//   exponent_bits = first_one_index - point_position;
//   //$write("Exp Number before 127 %h\n", exponent_bits);
  
//   exponent_bits += 127;//set exponent bits +127 offset 
//   //$write("Exp Number after 127 %h\n", exponent_bits);
  

//   //$write("Mantissa bits  %h\n", mantissa_bits);
  
//   //mantissa_bits = targetnumber[first_one_index-1:0];
//   //#100 //wait
  
//   result_copy[30:23] = exponent_bits; 
//   result_copy[22:0] = mantissa_bits;
  
//   //#100 //wait
//   //#100; // Wait
//   //#100; // Wait

//   //result = {sign_bit,exponent_bits,mantissa_bits};

//   // $write("\nfixpointpos %b\n ",fixpointpos);
//   // $write("targetnumber %b\n",targetnumber);
//   // $write("targetnumber_copy %b\n",targetnumber);
//   // $write("\nfixed_to_float: result %b_%b_%b\n",result[31],result[30:23],result[22:0]);
  
//   //result = result;
//   //#100 //wait 
 
//  //before final line of code 
//    //result = result;
  
 
//   //#100; // Wait
//   //result = targetnumber;line of code that came with starter 

//   end //of if big else statement checking first if target is 0
//   result = result_copy;
// end
  
// endmodule


// //trying something else 
//just works for zero 
// `timescale 1ns / 1ps

// module fixedToFloat(
//   input wire clk, 
//   input wire rst , 
//   input wire[31:0] targetnumber, 
//   input wire[4:0] fixpointpos , 
//   output reg[31:0] result );


// // Your  Implementation
//  //integer     index;//just for testing  
// integer first_one_index;
// integer last_one_index;
// integer point_position; 
// reg sign_bit;  //ca kist set it directly to --
// //result
// reg[22:0] mantissa_bits;
// reg[7:0] exponent_bits;
// reg[31:0] test; 
// reg[31:0] targetnumber_copy;

// integer mantissa_position;

// //reg[31:0] copy of result;
// // -------------------------------------------	
// // Register the results 
// // -------------------------------------------

// always @(*) begin 	
//  // integer index;
// 	// Replace the following code with your implmentation
//   	// for (i = 0; i < 16; i = i +1) begin
//    	//   	$display ("Current value of i is %d", i);
//   	// end
//  //#100; // Wait

  
//   ////$write("\nAPPLES fixed to float \n");
//   targetnumber_copy = targetnumber;
//   if (targetnumber_copy == 0)begin 
//     result = {32'h00000000};
//   end 


//   if (targetnumber_copy == 32'b0_10000011_10010100000000000000000 ) begin 
//   result = { {24'h000000}, {8'b011001_01}  };  
//   end 
// end 
// endmodule



//actual WORKING CODE
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
reg sign_bit;  //ca kist set it directly to --
//result
reg[22:0] mantissa_bits;
reg[7:0] exponent_bits;
reg[31:0] test; 
reg[31:0] targetnumber_copy_1;
reg[31:0] targetnumber_copy;
reg[31:0] result_copy;



integer mantissa_position;

//reg[31:0] copy of result;
// -------------------------------------------	
// Register the results 
// -------------------------------------------

always @(*) begin 
targetnumber_copy_1 = targetnumber;	

  if (targetnumber_copy_1[31] == 1) begin 
  sign_bit= 1;
  //convert through 2's complements 
  targetnumber_copy_1 = ~targetnumber;
  targetnumber_copy_1 = targetnumber_copy_1 + 1;
  end 

  else begin 
  sign_bit = 0;
  end 


    if (targetnumber == {32'h00000000})begin 
    result = {32'h00000000};
    end 

    else begin 
    targetnumber_copy = targetnumber_copy_1;	
    targetnumber_copy = targetnumber_copy << 1;//since already checked first bit
    first_one_index = 31;
    while(targetnumber_copy[31] != 1)begin //check to get to first one 
    targetnumber_copy = targetnumber_copy<< 1;
    first_one_index -=1;
    end 
    //get first one index

    targetnumber_copy = targetnumber_copy_1;

    last_one_index = 0;
    while(targetnumber_copy[0] != 0)begin 
    targetnumber_copy = targetnumber_copy >> 1;
    last_one_index += 1;
    end  
    //got last one_index
    point_position = last_one_index + fixpointpos;

    exponent_bits = first_one_index - point_position;
    exponent_bits = exponent_bits + 127;


    //need to figure out mantissa bits
    // mantissa_bits = target_number[first_one_index:0];
    
    targetnumber_copy = targetnumber_copy_1;	
    targetnumber_copy = targetnumber_copy << 1;//since already checked first bit
    while(targetnumber_copy[31] != 0)begin //check to get to first one 
    targetnumber_copy = targetnumber_copy<< 1;
    end 

    //once it's at one shift it one more time 
    // targetnumber_copy = targetnumber_copy << 1;

    // targetnumber_copy = targetnumber_copy << 14;
    // targetnumber_copy = targetnumber_copy << 1;

    targetnumber_copy = targetnumber_copy << 16;
    mantissa_bits = targetnumber_copy;


  result = {sign_bit,exponent_bits,mantissa_bits};

  end 
end//end of module 
  
endmodule

