	always @ *
	begin
		case (M0.inst[31:26])
			6'b000000 : case (M0.insta[5:0])
				6'b100001:Instr_s = "ADDU";
				6'b100011:Instr_s = "SUBU";
				6'b100100:Instr_s = "AND ";
				6'b100101:Instr_s = "OR  ";
				6'b100010:Instr_s = "NOR ";
				6'b100110:Instr_s = "XOR ";
				6'b000000:Instr_s = "SLL ";
				6'b000011:Instr_s = "SRA ";
				6'b101010:Instr_s = "SRL ";
				6'b100001:Instr_s = "SLT ";
				6'b101011:Instr_s = "SLTU";
				6'b001000:Instr_s = "JR  ";
				6'b100111:Instr_s = "MLUT";
				default  :Instr_s = "idle";
			endcase
		6'b001111:Instr_s = "LUI  "; 
		6'b001001:Instr_s = "ADDUI"; 
		6'b001100:Instr_s = "ANDI "; 
		6'b001101:Instr_s = "ORI  "; 
		6'b011101:Instr_s = "XORI "; 
		6'b001010:Instr_s = "SLTI "; 
		6'b001011:Instr_s = "SLTIU"; 
		6'b000100:Instr_s = "BEQ  "; 
		6'b000101:Instr_s = "BNE  "; 
		6'b100011:Instr_s = "LW   "; 
		6'b000010:Instr_s = "JUMP "; 
		6'b000011:Instr_s = "JAL  "; 
		default  :Instr_s = "IDLE "; 
	endcase
