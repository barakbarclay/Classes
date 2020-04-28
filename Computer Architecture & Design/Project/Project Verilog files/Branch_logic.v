// Assigns Branchsel a value based on Branch, bne, and zero. 
module Branch_logic(
input Branch, bne, zero,
output Branchsel);
assign Branchsel = (Branch & zero) | (bne & ~zero);
endmodule