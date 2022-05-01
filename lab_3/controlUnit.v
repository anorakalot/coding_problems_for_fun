//=========================================================================
// Name & Email must be EXACTLY as in Gradescope roster!
// Name: 
// Email: 
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

module controlUnit  (
    input  wire [5:0] instr_op, 
    output wire       reg_dst,   
    output wire       branch,     
    output wire       mem_read,  
    output wire       mem_to_reg,
    output wire [1:0] alu_op,        
    output wire       mem_write, 
    output wire       alu_src,    
    output wire       reg_write
    );

// ------------------------------
// Insert your solution below
// ------------------------------ 
//case (instr_op)
reg[8:0] control_signals;
reg[1:0] alu_op_reg;
always @* begin 
    // if (instr_op == 6'b000000)begin 
    // assign reg_dst =0;
    //assign works best when outside always begin end
    // end 
    
    case (instr_op)
    //r-format
    6'b000000 : control_signals = 9'b100100010;
    //lw
    6'b100011 : control_signals = 9'b011110000;
    //sw 
    6'b101011 : control_signals = 9'bx1x001000;

    //beg 
    6'b000100 : control_signals = 9'bx0x000101;
    //imm
    //gonna assume for imm instructions that it's the same as 
    //r type except for alusrc is 1 since it's 0 for r-type
    6'b001000 : control_signals = 9'b110100010;
    endcase 
    alu_op_reg = control_signals[1:0];
    //endcase 
    //always @(*)  begin 
    //not sure if need above line 
//  case (instr_op)
// // //unsigned add 
// // if (opcode == 3'b000)begin 
//     6'b000000  : assign reg_write = 1'b0; 
//         {carryout,result = A+B;

        // result =  [NUMBITS-1:0]temp_result;
        // carryout = [NUMBITS];
     //end          
// //signed add    



     //default : $display("APPLES");
    //endcase 

    // case (instr_op)
    //     6'b000000    : reg_dst = 1'b1;
    //     // alu_src = 0;
    //     // mem_to_reg = 0;
    //     // reg_write = 1;
    //     // mem_read = 0;
    //     // mem_write = 0;
    //     // branch  = 0;
    //     // alu_op = 2'b10;
    //     //end 

    //     // 6'b100011    : begin 
    //     // reg_dist = 0;
    //     // alu_src = 1;
    //     // mem_to_reg = 1;
    //     // reg_write = 1;
    //     // mem_read = 1;
    //     // mem_write = 0;
    //     // branch  = 0;
    //     // alu_op = 2'b00;
    //     // end 
        

    // endcase 


    end
//assign wire values after always begin end block 
//since it causes error if done in conditional 
//that has to bee in always begin end block
    assign reg_dst = control_signals[8];
    assign alu_src = control_signals[7];
    assign mem_to_reg = control_signals[6];
    assign reg_write = control_signals[5];
    assign mem_read = control_signals[4];
    assign mem_write = control_signals[3];
    assign branch = control_signals[2];
    assign alu_op[1] = control_signals[1];
    assign alu_op[0] = control_signals[0];

endmodule
