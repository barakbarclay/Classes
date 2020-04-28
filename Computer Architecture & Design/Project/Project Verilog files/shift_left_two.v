// Performs the shift left 2 on signex before giving the value to the Branch Adder module. 
module shift_left_two (
input[31:0] signex,
output[31:0] Boff);
assign Boff = signex << 2;
endmodule