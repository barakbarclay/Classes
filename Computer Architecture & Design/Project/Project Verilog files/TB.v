// Load Instruction Memory from Test Bench
initial begin 
	M0.Inst_Mem.memory[0] =   32'b00111100000000011111111111111111; //1. lui $1, 1
	M0.Inst_Mem.memory[4] =   32'b00000000000000010001010000000011; //2. sra $2, $1, 16
	M0.Inst_Mem.memory[8] =   32'b00111100000000110000000000000000; //3. lui $3, 0
	M0.Inst_Mem.memory[12] =  32'b00000000010000100011000000100100; //4. and $6, $2, $2
	M0.Inst_Mem.memory[16] =  32'b00000000010000110010100000100100; //5. and $5, $2, $3
	M0.Inst_Mem.memory[20] =  32'b00000000011000110011100000100100; //6. and $7, $3, $3
end

// Load Data Memory from Test Bench
// Data Memory is 32 bits wide ALUOut needs to be word aligned. memory[10] is misaligned location. 
initial begin
	M0.DM.memory[0] = 32'hDEADBEEF;
	M0.DM.memory[1] = 32'hBADDBADD;
end

reg reset, clk;
initial begin
	#5	reset = 1; clk = 0;
	#100 	reset = 0; clk = 0;
	#100 	reset = 0; clk = 0;
	forever #10 clk = ~clk;
end

//
//processor M0 (reset, clk);
