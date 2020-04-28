module PC (input clk, reset,
input[31:0] newPC,
output reg[31:0] PC);
always @(posedge clk or posedge reset)
begin

if (reset == 1)
PC<= 0; // or whereever the first instruction is
else
PC<= newPC;
end
endmodule

module PC_adder(
input [31:0] PC,
output [31:0] PCplus4);
assign PCplus4 = PC + 4;
endmodule

module Instruction_Memory (
input [31:0] PC,
output reg [31:0] inst);
// reg [7:0] memory[199:0];
reg[31:0] memory[199:0];

initial begin
memory[0] =   32'b00111100000000011111111111111111; //1. lui $1, 1
memory[4] =   32'b00000000000000010001010000000011; //2. sra $2, $1, 16
memory[8] =   32'b00000000000000100001110000000000; //3. sll $3, $2, 16
memory[12] =  32'b00000000000000110010011000000010; //4. srl $4, $3, 24
memory[16] =  32'b00100100000001010000000000001111; //5. addui $5, $0, 17
memory[20] =  32'b00000000100001010011000000100011; //6.  subu $6, $4, $5
memory[24] =  32'b00000000110001000011100000100001; //7.  addu $7, $6, $4
memory[28] =  32'b00000000111001100100000000100100; //8.  and  $8, $7, $6
memory[32] =  32'b00000000111001100100100000100110; //9.  xor  $9, $7, $6
memory[36] =  32'b00000000001010010101000000101010; //10. slt  $10, $1, $9
memory[40] =  32'b00010101010000000000000000000010; //11. bne  $10, $0, xxx,
// next instruction is 52 = PC+4 + 8                      

memory[52] =  32'b00000000111010010101100000100101; //12  or  $11, $7, $9
memory[56] =  32'b00001100000000000000000000010010; //13  jal XXXX
// I'll jump C0 72 = 1001000
memory[72] =  32'b00110001011011000000000000001010; //14. andi $12, $11, 1010
memory[76] =  32'b00000011111000000000000000001000; //15. jr $31 
// next instruction is 60 [56+4] from $31
memory[60] =  32'b00001000000000000000000000010100; //16. j zzzz
// next instruction is 80 = 1010000
memory[80] =  32'b10001101100011010000000000000000; //17. lw  $13, 0($12)
memory[84] =  32'b00111001101011100000000000001110; //18. xori $14, $13, 1110
memory[88] =  32'b00110101101011110000000000001110; //19. ori  $15, $13, 1110
memory[92] =  32'b00000000001010011000000000101011; //20. sltu $16, $1, $9
memory[96] =  32'b00101000001100010000000000000000; //21. slti $17, $1, 0
memory[100] = 32'b00101100001100100000000000000000; //22. sltui $18, s1, 0
memory[104] = 32'b00010010000100100000000000000010; //23. beq $16,$18, yyyy
// next instruction is +12 (4+8)
memory[116] = 32'b10101101100010110000000000000100; //24. sw $11, 4(12)
end           


always @ (PC)
//inst = {memory[PC],memory[PC+1],memory[PC+2],memory[PC+3]);
inst = memory[PC];
endmodule



module thirtytwo_bit_mux(input select,
input[31:0] zero_value, one_value,
output reg [31:0] out_value);

always @ (select, zero_value, one_value)
begin
if (select ==0) out_value = zero_value;
if (select ==1) out_value = one_value;
end
endmodule

module jump_calc (input[3:0] PCbits,
input[25:0] instbits,
output [31:0] JumpAdrs);
assign JumpAdrs = {PCbits, instbits, 2'b00};
endmodule

module main_control (input[5:0] inst,
output reg[3:0] ALUOp,
output reg ALUSrc, RegDst, RegWrite, MemWrite, MemtoReg,
MemRead, Branch, bne, Jump, jal, ui);

always @ (inst)
begin
case (inst)
6'b000000: // R—type instruction
begin
ALUOp=4'b0010; ALUSrc=0; RegDst=1; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=0;
end
6'b001111: // lui instruction
begin
./*>ALUOp=4'b0011; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=0;
end
6'b001001: // addui instruction
begin
ALUOp=4'b0000; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=1;
end
6'b001100: // andi instruction
begin
ALUOp=4'b0101; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=1;
end

6'b001101: // ori instruction
begin
ALUOp=4'b0110; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=1;
end
6'b001110: // xori instruction
begin
ALUOp=4'b0111; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=1;
end
6'b001010: // slti instruction
begin
ALUOp=4'b0100; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=0;
end
6'b001011: // sltiu instruction
begin
ALUOp=4'b1001; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=1;
end
6'b000100: // beg instruction
begin
ALUOp=4'b0001; ALUSrc=0; RegDst=0; RegWrite=0; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=1; bne=0; Jump=0; jal=0; ui=0;
end
6'b000101: // bne instruction
begin
ALUOp=4'b0001; ALUSrc=0; RegDst=0; RegWrite=0; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=1; Jump=0; jal=0; ui=0;
end
6'b100011: // lu instruction
begin
ALUOp=4'b0000; ALUSrc=1; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=1; MemRead=1; Branch=0; bne=0; Jump=0; jal=0; ui=0;
end

6'b101011: // sw instruction
begin
ALUOp=4'b0000; ALUSrc=1; RegDst=0; RegWrite=0; MemWrite=1;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=0;
end
6'b000010: // j instruction
begin
ALUOp=4'b0000; ALUSrc=0; RegDst=0; RegWrite=0; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=1; jal=0; ui=0;
end
6'b000011: // jal instruction
begin
ALUOp=4'b0000; ALUSrc=0; RegDst=0; RegWrite=1; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=1; jal=1; ui=0;
end
default:
begin
ALUOp=4'b0000; ALUSrc=0; RegDst=0; RegWrite=0; MemWrite=0;
MemtoReg=0; MemRead=0; Branch=0; bne=0; Jump=0; jal=0; ui=0;
end
endcase
end
endmodule

module five_bit_mux(input select,
input[4:0] zero_value, one_value,
output reg [4:0] out_value);

always @ (select, zero_value, one_value)
begin
if (select == 0) out_value=zero_value;
if (select == 1) out_value= one_value;
end
endmodule


module registers(input RegWrite, clk,
input[4:0] reg1ad, reg2ad, writead,
input[31:0] data_in, output wire [31:0] reg1data, reg2data);

reg[31:0] register[31:0];
initial begin register[0] = 0; end // $zero
assign regldata = register[reg1ad]; // read
assign reg2data = register[reg2ad]; // write
always @ (posedge clk)
begin
if (RegWrite== 1) register[writead] <= data_in;

end
endmodule




module sign_extend(
input ui,
input[15:0] inst,
output reg [31:0] signex);

always @ (ui, inst)
begin
if (ui == 1) signex = {16'b0000000000000000, inst};
else begin
if (inst[15] == 1) signex={16'b1111111111111111, inst};
if (inst[15] == 0) signex={16'b0000000000000000, inst};
end
end
endmodule

module shift_left_two (
input[31:0] signex,
output[31:0] Boff);
assign Boff = signex << 2;
endmodule


module branch_add (
input[31:0] PCplus4, Boff,
output[31:0] BAout);
assign BAout = PCplus4 + Boff;
endmodule

module Branch_logic(
input Branch, bne, zero,
output Branchsel);
assign Branchsel = (Branch & zero) | (bne & ~zero);
endmodule



module ALU (
input[31:0] reg1data, ALU2,
input[3:0] ALUfunc,
input[4:0] shamt,
output reg [31:0] ALUOut,
output reg zero, overflow);
reg[5:0] i;
always @ (*)
begin
case (ALUfunc)
4'b0010: ALUOut = reg1data + ALU2; // add, addui, lw, sw
4'b0110: ALUOut = reg1data - ALU2; // sub, bne,beq
4'b0000: ALUOut = reg1data & ALU2; // and, andi
4'b0001: ALUOut = reg1data | ALU2; // or , ori
4'b1001: ALUOut = reg1data ^ ALU2; // xor, xori
4'b1010: ALUOut = ALU2 << shamt; //   sll  slci
4'b1100: ALUOut = ALU2 >> shamt; //   srl
4'b0111: begin                   //   slt,— SIGNED #5

if (reg1data[31] == ALU2[31])
begin
if (reg1data < ALU2) ALUOut =1;
else ALUOut = 0;
end
else
begin
if (reg1data > ALU2) ALUOut =1;
else ALUOut = 0;
end
end

4'b1101: ALUOut = ALU2 << 16; // lui
4'b1110: begin // sltu, sltui - UNSIGNED #s
if (reg1data < ALU2) ALUOut = 1;
else ALUOut = 0;
end
4'b1011: begin // sra
ALUOut=ALU2;
for (i=0; i<=31; i=i+1)
begin
if (i < shamt) ALUOut = {ALUOut[31],ALUOut[31:1]};
end
end
default: ALUOut = 0;
endcase
if (ALUOut == 0) zero = 1; else zero = 0;
end
endmodule




module ALU_Control(
input[3:0] ALUOp,
input[5:0] funct,
output reg jr,
output reg[3:0] ALUfunc);
always @ (ALUOp, funct, ALUfunc)
begin
jr = 0; // default
case (ALUOp)
4'b0010: // R—typ& instructions
begin
case (funct) // look at function code
6'b100001: ALUfunc = 4'b0010; // addu
6'b100011: ALUfunc = 4'b0110; // subu
6'b100100: ALUfunc = 4'b0000; // and
6'b100101: ALUfunc = 4'b0001; // or
6'b100110: ALUfunc = 4'b1001; // xor
6'b000000: ALUfunc = 4'b1010; // sll
6'b000011: ALUfunc = 4'b1011; // sra
6'b000010: ALUfunc = 4'b1100; // srl
6'b101010: ALUfunc = 4'b0111; // slt
6'b101011: ALUfunc = 4'b1110; // sltu
6'b001000: begin ALUfunc = 4'b0010; jr = 1; end // jr
endcase
end
4'b0011: ALUfunc = 4'b1101; //lui - sll 16
4'b0000: ALUfunc = 4'b0010; //addui, lw, sw - add
4'b0101: ALUfunc = 4'b0000; //andi - AND
4'b0110: ALUfunc = 4'b0001; //ori
4'b0111: ALUfunc = 4'b1001; //xori
4'b0100: ALUfunc = 4'b0111; //slti - SIGNED Slt
4'b0001: ALUfunc = 4'b0110; //beq, bne - subtract
4'b1001: ALUfunc = 4'b1110; //sltui - subtract & set bit
endcase
end
endmodule



module Data_Memory (
input clk, MemRead, MemWrite,
input [31:0] ALUOut, reg2data,
output reg [31:0] memout);
reg [31:0] memory[199:0];
initial begin
memory[8] = 32'b11110000111100001111000011110000;
memory[10] = 32'b00000000000000000000000000000101;
end
always @ (ALUOut, MemRead)
begin
if (MemRead == 1) memout = memory[ALUOut];
end
always @(posedge clk)
begin
if (MemWrite ==1) memory[ALUOut] <= reg2data;
end
endmodule


module processor(
input reset, clk);
wire[3:0] ALUOp;
wire[3:0] ALUfunc;
wire[4:0] regad, Rmuxout, ra;
wire[31:0] PC, PCplus4, newPC, inst, JumpAdrs,
Mmuxout, regin, signex, Boff, ALU2,
BAOut, BMuxout, JMuxout, memout,
ALUOut, reg2data, reg1data;
wire RegWrite;


assign ra = 5'b11111;

PC PCmod (clk, reset, newPC, PC);

PC_adder PC_adder (PC, PCplus4);

Instruction_Memory Inst_Mem (PC, inst);

thirtytwo_bit_mux jal_mux (.select(jal), .zero_value(Mmuxout),
.one_value(PCplus4), .out_value(regin));

five_bit_mux regdesc1(.select(RegDst), .zero_value(inst[20:16]),
.one_value(inst[15:11]), .out_value(Rmuxout));

five_bit_mux regdest2(.select(jal), .zero_value(Rmuxout),
.one_value(ra), .out_value(regad));

registers tegisters(RegWrite, clk, inst[25:21], inst[20:16], regad,
regin, reg1data, reg2data);

jump_calc j_calc (PCplus4[31:28],inst[25:0],JumpAdrs);

main_control main_control (inst[31:26], ALUOp, ALUSrc, RegDst,
RegWrite, MemWrite, MemtoReg, MemRead,
Branch, bne, Jump, jal, ui);

sign_extend sign_ex (ui, inst[15:0], signex);

shift_left_two SL2 (signex, Boff);

branch_add Branch_add (PCplus4, Boff, BAOut);

thirtytwo_bit_mux ALUSrcMux (.select(ALUSrc), .zero_value(reg2data),
.one_value(signex), .out_value(ALU2));

ALU ALU (reg1data, ALU2, ALUfunc, inst[10:6], ALUOut, zero, overflow);

ALU_Control ALU_cont (ALUOp, inst[5:0], jr, ALUfunc);

Branch_logic BL (Branch, bne, zero, Branchsel);

thirtytwo_bit_mux Bmux (.select(Branchsel), .zero_value(PCplus4),
.one_value(BAOut), .out_value(BMuxout));

thirtytwo_bit_mux Jmux (.select(Jump), .zero_value(BMuxout),
.one_value(JumpAdrs), .out_value(JMuxout));

thirtytwo_bit_mux JRmux (.select(jr), .zero_value(JMuxout),
.one_value(reg1data), .out_value(newPC));

Data_Memory DM (clk, MemRead, Memwrite, ALUOut, reg2data, memout);

thirtytwo_bit_mux  Mmux (.select(MemtoReg), .zero_value(ALUOut),
.one_value(memout), .out_value(Mmuxout));

endmodule


module test;
reg reset, clk;
initial begin
#5 reset = 1; clk = 1;
#10 clk = 0; reset = 0;
forever #10 clk = ~clk;
end
processor H0 (reset, clk);
endmodule

































































