// 2 bit up/down counter

module L7(input dir,clock,reset);
reg[1:0]state; //state is neither an input or output and must not be declated in module line

parameter S0=2'b00, s1=2'b01, S2=2'b10, s3=2'b11; //assigns values of S0-S3 prior to the always statement
always @(posedge clock or negedge reset)
if(reset==0) state <=s0; //non-blocking syntax used here
else case (state)
S0: if(dir) state=S1; else state=s3;
S1: if(dir) state=s2; else state=S0;
S2: if(dir) state=S3; else state=S1;
S3: if(dir) state=s0; else state=S2;
endcase

endmodule
