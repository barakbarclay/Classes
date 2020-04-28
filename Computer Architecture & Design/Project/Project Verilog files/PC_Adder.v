// Increases the PC by 4.
module PC_adder(
input [31:0] PC,
output [31:0] PCplus4);
assign PCplus4 = PC + 4;
endmoduleC