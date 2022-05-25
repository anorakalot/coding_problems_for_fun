//=========================================================================
// Name & Email must be EXACTLY as in Gradescope roster!
// Name: Richard McGee
// Email: rmcge002@ucr.edu
// 
// Assignment name: Lab 01
// Lab section: 
// TA: 
// 
// I hereby certify that I have not received assistance on this assignment,
// or used code, from ANY outside source other than the instruction team
// (apart from what was provided in the starter file).
//
//=========================================================================

`timescale 1ns / 1ps

//  Constant definitions 

module myalu # ( parameter NUMBITS = 16 ) (
    input wire clk, 
    input wire reset ,  
    input  wire[NUMBITS-1:0] A, 
    input  wire[NUMBITS-1:0] B, 
    input wire [2:0]opcode, 
    output reg [NUMBITS-1:0] result,  
    output reg carryout ,
    output reg overflow , 
    output reg zero  );
// ------------------------------
// Insert your solution below
// ------------------------------ 
always @* begin 
//   case(address)
 //    0 : $display ("It is 11:40PM");
 //    1 : $display ("I am feeling sleepy");
 //    2 : $display  ("Let me skip this tutorial");
 //    default : $display  ("Need to complete");
//    endcase

 case (opcode)
// //unsigned add 
// if (opcode == 3'b000)begin 
    3'b000  : {carryout,result} = $unsigned(A)+$unsigned(B); 
//         {carryout,result = A+B;

        // result =  [NUMBITS-1:0]temp_result;
        // carryout = [NUMBITS];
     //end          
// //signed add    
    3'b001  :  result = $signed(A)+$signed(B); 
//     // if (a >= 0 && b >= 0 && result <0) begin 
//     //     overflow = 1;

//     // end 
//     // else if (a<0 && b  < 0 && result >=0)begin 
//     //     overflow = 1;
//     // end

// // //unsigned sub  
    3'b010  : {carryout,result} = $unsigned(A) - $unsigned(B);
// // //signed sub 
    3'b011  : result = $signed(A)- $signed(B);
// // //bit-wise And 
    3'b100  : result = A & B; 
// // //bit-wise OR
     3'b101  : result = A | B; 
// // //bit-wise XOR 
     3'b110  : result = A ^ B;
// // //divide a by 2
     3'b111  : result = A >> 1;



     //default : $display("APPLES");
    endcase 
if (result == 0)begin 
    zero = 1;
    end 
else begin 
    zero = 0;
    end 
if (opcode == 3'b000)begin //unsigned add

    overflow = 0;

    end //for 3'b000

if (opcode == 3'b010)begin //unsgined sub

    overflow = 0;

    end //for 3'b010 
if (opcode ==3'b001)begin //signed add
    if ($signed(A) >= 0 && $signed(B) >= 0 && $signed(result) <0) begin 
        overflow = 1;

    end 
    else if ($signed(A)<0 && $signed(B)  < 0 && $signed(result) >=0)begin 
        overflow = 1;
    end
    else begin 
    overflow = 0;
    end 

    carryout = 0;

    end

if (opcode ==3'b011)begin //signed sub
    if ($signed(A) >= 0 && $signed(B) <  0 && $signed(result) <0) begin 
        overflow = 1;

    end 
    else if ($signed(A)<0 && $signed(B)  >= 0 && $signed(result) >=0)begin 
        overflow = 1;
    end
    else begin 
        overflow = 0;
    end 
    carryout = 0;
    end

if (opcode == 3'b100 || opcode == 3'b101 || opcode == 3'b110 || opcode ==3'b111)begin 
    carryout = 0;
    overflow = 0;
end 

// if (overflow != 1'b0 && overflow != 1'b1)begin 
//     overflow = 1'b1;
//     end 


    end//this is the end of the always begin  


 endmodule


// //=========================================================================
// // Name & Email must be EXACTLY as in Gradescope roster!
// // Name: Richard McGee
// // Email: rmcge002@ucr.edu
// // 
// // Assignment name: Lab 01
// // Lab section: 
// // TA: 
// // 
// // I hereby certify that I have not received assistance on this assignment,
// // or used code, from ANY outside source other than the instruction team
// // (apart from what was provided in the starter file).
// //
// //=========================================================================

// `timescale 1ns / 1ps

// module myalu_tb;
//     parameter NUMBITS = 8;

//     // Inputs
//     reg clk;
//     reg reset;
//     reg [NUMBITS-1:0] A;
//     reg [NUMBITS-1:0] B;
//     reg [2:0] opcode;

//     // Outputs
//     wire [NUMBITS-1:0] result;
//     reg [NUMBITS-1:0] R;
//     wire carryout;
//     wire overflow;
//     wire zero;

//     // -------------------------------------------------------
//     // Instantiate the Unit Under Test (UUT)
//     // -------------------------------------------------------
//     myalu #(.NUMBITS(NUMBITS)) uut (
//         .clk(clk),
//         .reset(reset) ,  
//         .A(A), 
//         .B(B), 
//         .opcode(opcode), 
//         .result(result), 
//         .carryout(carryout), 
//         .overflow(overflow), 
//         .zero(zero)
//     );

//       initial begin 
    
//      clk = 0; reset = 1; #50; 
//      clk = 1; reset = 1; #50; 
//      clk = 0; reset = 0; #50; 
//      clk = 1; reset = 0; #50; 
         
//      forever begin 
//         clk = ~clk; #50; 
//      end 
     
//     end 
    
//     integer totalTests = 0;
//     integer failedTests = 0;
//     initial begin // Test suite
//         // Reset
//         @(negedge reset); // Wait for reset to be released (from another initial block)
//         @(posedge clk); // Wait for first clock out of reset 
//         #10; // Wait 

//         // Additional test cases
//         // ---------------------------------------------
//         // Testing unsigned additions 
//         // --------------------------------------------- 
//         $write("Test Group 1: Testing unsigned additions ... \n");
//         opcode = 3'b000; 
//         totalTests = totalTests + 1;
//         $write("\tTest Case 1.1: Unsigned Add ... ");
//         A = 8'hFF;
//         B = 8'h01;
//         R = 8'h00; 
//         #100; // Wait 
//         if (R != result || zero != 1'b1 || carryout != 1'b1) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
//         #10; // Wait 
        
// 		// Add more tests here
//         opcode = 3'b000; 
//         totalTests = totalTests + 1;
//         $write("\tTest Case 1.2: Unsigned Add ... ");
//         A = 8'h81;
//         B = 8'h28;
//         R = 8'hA9; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 || carryout != 1'b0) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
//         #10; // Wait 
        
//         // ---------------------------------------------
//         // Testing unsigned subs 
//         // --------------------------------------------- 
//         $write("Test Group 2: Testing unsigned subs ...\n");
//         opcode = 3'b010; 
//         totalTests = totalTests + 1;
//         $write("\tTest Case 2.1: Unsigned Sub ... ");
//         A = 8'h91;
//         B = 8'h28;
//         R = 8'h69; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 || carryout != 1'b0) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
//         #10; // Wait 
// 		// Add more tests here

//         // ---------------------------------------------
//         // Testing signed adds 
//         // --------------------------------------------- 
//         $write("Test Group 3: Testing signed adds ...\n");
//         opcode = 3'b001; 
        
//         totalTests = totalTests + 1;
//         $write("\tTest Case 3.1: Signed adds ... ");
//         A = 8'h61;
//         B = 8'h12;
//         R = 8'h73; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 ) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
//         #10; // Wait 
// 		// Add more tests here

//         // ---------------------------------------------
//         // Testing signed subs 
//         // --------------------------------------------- 
//         $write("Test Group 4: Testing signed subs ...\n");
//         opcode = 3'b011; 
                
// 		// Add more tests here
//         totalTests = totalTests + 1;
//         $write("\tTest Case 4.1: Signed subs ... ");
//         A = 8'h61;
//         B = 8'h12;
//         R = 8'h01; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 ) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
//         #10; // Wait 
//         // ---------------------------------------------
//         // Testing ANDS 
//         // --------------------------------------------- 
//         $write("Test Group 5: Testing ANDs ...\n");
//         opcode = 3'b100; 
//         totalTests = totalTests + 1;
//         $write("\tTest Case 5.1: ANDS ... ");
//         A = 8'hD9;
//         B = 8'h61;
//         R = 8'h41; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 ) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
//         #10; // Wait 
                


//         // ----------------------------------------
//         // ORs 
//         // ---------------------------------------- 
//         $write("Test Group 6: Testing ORs ...\n");
//         opcode = 3'b101; 
        
// 		// Add more tests here
//         totalTests = totalTests + 1;
//         $write("\tTest Case 6.1: OR ... ");
//         A = 8'hD9;
//         B = 8'h61;
//         R = 8'hFB; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 ) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end

//         #10; // Wait 
//         // ----------------------------------------
//         // XORs 
//         // ---------------------------------------- 
//         $write("Test Group 7: Testing XORs ...\n");
//         opcode = 3'b110; 
        
// 		// Add more tests here
//         totalTests = totalTests + 1;
//         $write("\tTest Case 7.1: XOR ... ");
//         A = 8'hD9;
//         B = 8'h61;
//         R = 8'hB8; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 ) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end

//         // ----------------------------------------
//         // Div 2 
//         // ----------------------------------------
//         $write("Test Group 8: Testing DIV 2 ...\n");
//         opcode = 3'b111; 

//         totalTests = totalTests + 1;
//         $write("\tTest Case 8.1: DIV 2 ... ");
//         A = 8'h60;
//         //B = 8'h61;
//         R = 8'h30; 
//         #100; // Wait 
//         if (R != result || zero != 1'b0 ) begin
//             $write("failed\n");
//             failedTests = failedTests + 1;
//         end else begin
//             $write("passed\n");
//         end
        
// 		// Add more tests here

//         // -------------------------------------------------------
//         // End testing
//         // -------------------------------------------------------
//         $write("\n-------------------------------------------------------");
//         $write("\nTesting complete\nPassed %0d / %0d tests", totalTests-failedTests,totalTests);
//         $write("\n-------------------------------------------------------");
//     end
// endmodule
