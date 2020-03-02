module L9(input clock,a,b,A,B, output D,d);
reg RA,RB,RD,Ra,Rb,Rd; 

//parameter S0=1'd6, S1=1'd2; 
always @(posedge clock)
begin
$monitor ("RA=%d", RA);
    $monitor ("RB=%d", RB);
    $monitor ("RD=%d", RD);
    $monitor ("Ra=%d", Ra);
    $monitor ("Rb=%d", Rb);
    $monitor ("Rd=%d", Rd);
RA=1'b110;RB=1'b010;Ra=1'b110;Rb=1'b010;
#5 RA<=RA+RB;
RD<=RA;
Ra=Ra+Rb;
Rb=Ra;
end
assign A=RA;
assign B=RB;
assign D=RD;
assign a=Ra;
assign b=Rb;
assign d=Rd;

endmodule
