// 2 bit up/down counter testbench

module L7TB;
  wire A,B;
  wire [1:0]State;
  reg dir,clock,reset;

L7 M1(A,B,State,dir,clock,reset);
  
  initial
  begin
    $monitor ("AB=%b%b", A,B);
    dir = 1'b1;clock = 1'b0;reset = 1'b0;
    #5 dir = 1'b1;clock = 1'b0;reset = 1'b1;
    forever begin
    #25 dir = 1'b1;clock = 1'b1;reset = 1'b1;
    #25 dir = 1'b1;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b1;clock = 1'b1;reset = 1'b1;
    #25 dir = 1'b1;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b1;clock = 1'b1;reset = 1'b1;
    #25 dir = 1'b1;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b1;clock = 1'b1;reset = 1'b1;

    #25 dir = 1'b0;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b1;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b1;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b1;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b0;reset = 1'b1;
    #25 dir = 1'b0;clock = 1'b1;reset = 1'b1;

    #25 dir = 1'b1;clock = 1'b0;reset = 1'b1;
    end
  end
  
  initial #800 $stop; //change # to length of above
  
endmodule
