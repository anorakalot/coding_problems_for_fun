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

// //USE THIS ONE BELOW 
// `timescale 1ns / 1ps

module fixedFloatConversion_tb;
    // Inputs
    reg clk; 
    reg rst; 
    reg [31:0] targetnumber;
    reg [4:0] fixpointpos;
    reg  opcode; 
    
    wire [31:0] resultnumber;
    reg [31:0] R;
    
    // ---------------------------------------------------
    // Instantiate the Unit Under Test (UUT)
    // --------------------------------------------------- 
    fixedFloatConversion uut (
        .clk( clk ) , 
        .rst(rst) ,         
        .targetnumber(targetnumber), 
        .fixpointpos(fixpointpos),
        .opcode(opcode) , 
        .result(resultnumber)
    );

    initial begin 
        clk = 0; rst = 1; #50; 
        clk = 1; rst = 1; #50; 
        clk = 0; rst = 0; #50; 
        clk = 1; rst = 0; #50; 
        forever begin 
            clk = ~clk; #50; 
        end 
    end
     
    integer failedTests = 0;
    integer totalTests = 0;
    initial begin
        // Reset
        @(negedge rst); // Wait for reset to be released (from another initial block)
        @(posedge clk); // Wait for first clock out of reset 
        #10; // Wait 

        fixpointpos = 4'b0000;
        targetnumber = { 32'h0 }; 
        R = { 32'h0 }; 
        //think got them mixed up fixed to floatig
        //$write("\nthink got them mixed up fixed to floating\n" );
        // -------------------------------------------------------
        // Test group 1: Floating point to fixed point
        // -------------------------------------------------------
        $display("Test Group 1: Testing Floating point to fixed point... ");
        opcode = 1'b0; 

        $write("\tTest Case 1.1: Convert 25.25 (011001.01,2=>0 10000011 1001010..)...");
        totalTests = totalTests + 1;
        // Set inputs
        fixpointpos = 4'b0010;
        targetnumber = { {24'h000000}, {8'b011001_01}  }; 
        R = 32'b0_10000011_10010100000000000000000;
        #100; // Wait
        $write("\nresultnumber_in_tb %h \n",resultnumber);
        $write("\nresultnumber_in_tb  %b_%b_%b \n",resultnumber[31],resultnumber[30:23],resultnumber[22:0]);
        if (R != resultnumber) begin
            $display("failed: Expected: %b, got %b", R, resultnumber); 
            failedTests = failedTests + 1;
        end else begin
            $display("passed"); 
        end


        // -------------------------------------------------------
        // Put your tests here
        // -------------------------------------------------------     
        //NEED TO FINISH WRITING THIS NEW TEST         
		$write("\tTest Case 1.2: Convert 0 (000000.00,0=>0 00000000 0000000..)...");
        totalTests = totalTests + 1;
        // Set inputs
        fixpointpos = 4'b0010;
        targetnumber = { {24'h000000}, {8'b000000_00}  }; 
        R = 32'b0_00000000_00000000000000000000000;
        #100; // Wait
        $write("\nresultnumber_in_tb %h \n",resultnumber);
        $write("\nresultnumber_in_tb  %b_%b_%b \n",resultnumber[31],resultnumber[30:23],resultnumber[22:0]);
        if (R != resultnumber) begin
            $display("failed: Expected: %b, got %b", R, resultnumber); 
            failedTests = failedTests + 1;
        end else begin
            $display("passed"); 
        end

        $write("\tTest Case 1.3: Convert 8.25 (1000.01,0=>0 10000010 00001)");
        totalTests = totalTests + 1;
        // Set inputs
        fixpointpos = 4'b0010;
        targetnumber = { {24'h000000}, {8'b001000_01}  }; 
        R = 32'b0_10000010_00001000000000000000000;
        #100; // Wait
        $write("\nresultnumber_in_tb %h \n",resultnumber);
        $write("\nresultnumber_in_tb  %b_%b_%b \n",resultnumber[31],resultnumber[30:23],resultnumber[22:0]);
        if (R != resultnumber) begin
            $display("failed: Expected: %b, got %b", R, resultnumber); 
            failedTests = failedTests + 1;
        end else begin
            $display("passed"); 
        end

        
        //think got them mixed up floating to fixed 
        //$write("\nthink got them mixed up floating to fixed\n" );
        // -------------------------------------------------------
        // Test group 2: Fixed point to floating point
        // -------------------------------------------------------
        $display("Test Group 2: Testing Fixed point to floating point... ");
        opcode = 1'b1; 

        $write("\tTest Case 2.1: 25.25 (0 10000011 1001010,2=>011001.01)..."); 
        totalTests = totalTests + 1;
        opcode = 1'b1; 
        fixpointpos = 4'b0010;
        targetnumber = 32'b0_10000011_10010100000000000000000;
        R = { {24'h000000}, {8'b011001_01}  };  
        #100; 
        $write("\nresultnumber_in_tb %h \n",resultnumber);
        $write("\nresultnumber_in_tb  %b_%b_%b \n",resultnumber[31],resultnumber[30:23],resultnumber[22:0]);
        if ( R != resultnumber || resultnumber === 32'bz) begin
            $display("failed: Expected: %b, got %b", R, resultnumber);
            failedTests = failedTests + 1;
        end else begin
            $display("passed");
        end



        $write("\tTest Case 2.1: 0 (0 00000000 0000000,2=>000000.00)..."); 
        totalTests = totalTests + 1;
        opcode = 1'b1; 
        fixpointpos = 4'b0010;
        targetnumber = 32'b0_00000000_00000000000000000000000;
        R = { {24'h000000}, {8'b000000_00}  };  
        #100; 
        $write("\nresultnumber_in_tb %h \n",resultnumber);
        $write("\nresultnumber_in_tb  %b_%b_%b \n",resultnumber[31],resultnumber[30:23],resultnumber[22:0]);
        if ( R != resultnumber || resultnumber === 32'bz) begin
            $display("failed: Expected: %b, got %b", R, resultnumber);
            failedTests = failedTests + 1;
        end else begin
            $display("passed");
        end

        
            
        // -------------------------------------------------------
        // Put your tests here
        // -------------------------------------------------------            
		  
        // --------------------------------------------------------------
        // End testing
        // --------------------------------------------------------------
        $write("\n--------------------------------------------------------------");
        $write("\nTesting complete\nPassed %0d / %0d tests",totalTests-failedTests,totalTests);
        $write("\n--------------------------------------------------------------\n");
        $finish();
    end
endmodule

