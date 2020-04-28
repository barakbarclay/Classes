module L10TB;
  wire Q2,Q1,Q0;
  wire [2:0]State,Highway,Gravel;
  reg TRAFFIC,clock,reset;

L10 M1(Q2,Q1,Q0,State,Highway,Gravel,TRAFFIC,clock,reset);
  
  initial
  begin
    $monitor ("State=%b%b%b   Highway=%b   Gravel=%b", Q2,Q1,Q0,Highway,Gravel);
    TRAFFIC = 1'b0;clock = 1'b0;reset = 1'b0;
    #5 TRAFFIC = 1'b0;clock = 1'b0;reset = 1'b1;
    #5 TRAFFIC = 1'b0;clock = 1'b1;reset = 1'b1;
    #10 TRAFFIC = 1'b0;clock = 1'b0;reset = 1'b1;
    #10 TRAFFIC = 1'b1;clock = 1'b1;reset = 1'b1;
    #10 TRAFFIC = 1'b1;clock = 1'b0;reset = 1'b1;
    #10 TRAFFIC = 1'b1;clock = 1'b1;reset = 1'b1;
    #10 TRAFFIC = 1'b1;clock = 1'b0;reset = 1'b1;
    #10 TRAFFIC = 1'b1;clock = 1'b1;reset = 1'b1;
    #10 TRAFFIC = 1'b1;clock = 1'b0;reset = 1'b1;
    forever begin
    #10 TRAFFIC = 1'b0;clock = 1'b1;reset = 1'b1;
    #10 TRAFFIC = 1'b0;clock = 1'b0;reset = 1'b1;
    end 
  end
  
  initial #200 $stop;
  
endmodule
