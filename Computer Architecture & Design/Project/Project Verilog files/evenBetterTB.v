module evenBetterTB();
reg reset, clk;
reg [31:0] instrmem[29:0];
reg [5:0] opcode_lui, opcode_ori;
reg [4:0] rs, rtl, rd;
reg [15:0] immvalue_upper, immvalue_lower;
reg [31:0] temp_value;
integer i, j, fp;

initial begin

fp = $fopen("mem.bin");
immvalue_upper = 0;
immvalue_lower = 0;
$display(^First	  Second   Or`ed);
for(i = 0 ; i <=28; i = i + 2)
begin
opcode_lui = 6'b001111; // Fixed opcode for LUI instructions 
opcode_orti = 6'b001101; // Fixed opcode for ORI instructions
rs = 5'b00000;
rtl =  1 + ($urandom) % (10); // Random register address for addui
immvalue_upper = 1 + ($urandom (immvalue_upper)) % (100); // Random data for register 1
immvalue_lower = 1 + ($urandom (immvalue_upper)) % (100); // Random data for register 2
temp_value = immvalue_upper;
// Form 30 instructions
// 15 LUI and 15 ORI instructions
for (j=0;j<2;j = j+1)
begin
if(j == 0) instrmem[i+j] = (opcode_lui, rs, rtl, immvalue_upper); // Create 1st LUI instruction
else if(j == 1) instrmem[i+j] = {opcode_ori, rtl, rtl, immvale_lower); // Create 2nd ORI instruction

$fdisplayb{fb.instrmem[i+j]); //Write the instrcution to file
end
$display("%h %h %h", temp_value << 16, immvalue_lower, temp_value << 16 | immvalue_lower);
end
$fclose(fb);

#10 reset = 1; clk = 1;
#10 clk = 0; reset = 0;

end