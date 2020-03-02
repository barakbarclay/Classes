module L10(output Q2,Q1,Q0, output [2:0]State,Highway,Gravel, input TRAFFIC,clock,reset);
reg[2:0]state; 
assign Q2=state[2];
assign Q1=state[1];
assign Q0=state[0];
assign State[2]=state[2];
assign State[1]=state[1];
assign State[0]=state[0];
assign Highway[2]=Q2||(Q1&&Q0);
assign Highway[1]=(!Q2&&!Q1&&Q0)||(!Q2&&Q1&&!Q0);
assign Highway[0]=!Q2&&!Q1&&!Q0;
assign Gravel[2]=(!Q2&&!Q1)||(!Q2&&!Q0);
assign Gravel[0]=(!Q2&&Q1&&Q0)||(Q2&&!Q1);
assign Gravel[1]=Q2&&Q1;
parameter S0=3'b000, S1=3'b001, S2=3'b010, S3=3'b011, S4=3'b100, S5=3'b101, S6=3'b110, S7=3'b111;
always @(posedge clock or negedge reset)
if(reset==0) state <=S0; 
else case (state)
S0: if(TRAFFIC) state=S1;
S0: if(!TRAFFIC) state=S0;
S1: if(1) state=S2;
S2: if(1) state=S3;
S3: if(1) state=S4;
S4: if(1) state=S5;
S5: if(1) state=S6;
S6: if(1) state=S7;
S7: if(1) state=S0;
endcase
endmodule
