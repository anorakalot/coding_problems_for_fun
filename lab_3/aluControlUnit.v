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

module aluControlUnit (
    input  wire [1:0] alu_op, 
    input  wire [5:0] instruction_5_0, 
    output wire [3:0] alu_out
    );
    //have reg here too to assign output wire too 
    //outside of always begin sequential block
    reg [3:0] alu_out_reg;
// ------------------------------
// Insert your solution below
// ------------------------------ 
always @* begin 

    casex ({alu_op,instruction_5_0})
    // 2'b00 , 6'bxxxxxx : alu_out_reg = 4'b0010; 
    // 2'bx1 , 6'bxxxxxx : alu_out_reg = 4'b0110; 
    // 2'b1x , 6'bxx0000 : alu_out_reg = 4'b0010; 
    // 2'b1x , 6'bxx0010 : alu_out_reg = 4'b0110; 
    // 2'b1x , 6'bxx0100 : alu_out_reg = 4'b0000; 
    // 2'b1x , 6'bxx0101 : alu_out_reg = 4'b0001; 
    // 2'b1x , 6'bxx1010 : alu_out_reg = 4'b0111; 
    // 2'b1x , 6'bxx0111 : alu_out_reg = 4'b1100; 
    // 2'b01 , 6'bxxxxxx : alu_out_reg = 4'b0


    // 2'b00 , 6'bxxxxxx : alu_out_reg = 4'b0010; //lw
    // 2'b00 , 6'bxxxxxx : alu_out_reg = 4'b0010;//sw   
    // 2'b01 , 6'bxxxxxx : alu_out_reg = 4'b0110; //beq 
    // 2'b10 , 6'b100000 : alu_out_reg = 4'b0010; //r add
    // 2'b10 , 6'b100010 : alu_out_reg = 4'b0110; //r sub
    // 2'b10 , 6'b100100 : alu_out_reg = 4'b0000; //r and
    // 2'b10 , 6'b100101 : alu_out_reg = 4'b0001; //r or  
    // 2'b10 , 6'b100111 : alu_out_reg = 4'b1100; //r nor
    // 2'b10 , 6'b101010 : alu_out_reg = 4'b0111; //r set on less

//changed based on gradescope grader 
    8'b00xxxxxx : alu_out_reg = 4'b0010; //lw
    8'b00xxxxxx : alu_out_reg = 4'b0010;//sw   
    8'b01xxxxxx : alu_out_reg = 4'b0110; //beq 
    8'b10100000 : alu_out_reg = 4'b0010; //r add
    8'b10100010 : alu_out_reg = 4'b0110; //r sub
    8'b10100100 : alu_out_reg = 4'b0000; //r and
    8'b10100101 : alu_out_reg = 4'b0001; //r or  
    8'b10100111 : alu_out_reg = 4'b1100; //r nor
    8'b10101010 : alu_out_reg = 4'b0111; //r set on less


    endcase 



end 

    assign alu_out = alu_out_reg;
endmodule
