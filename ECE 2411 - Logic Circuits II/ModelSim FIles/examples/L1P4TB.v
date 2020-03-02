module L1P4TB;
  wire C,E;
  reg A,B,D;

L1P4 M1(C,E,A,B,D);
  
  initial
  begin
    A = 1'b0;B = 1'b0;D = 1'b0;
    #100 A = 1'b0;B = 1'b0;D = 1'b1;
    #100 A = 1'b0;B = 1'b1;D = 1'b0;
    #100 A = 1'b0;B = 1'b1;D = 1'b1;
    #100 A = 1'b1;B = 1'b0;D = 1'b0;
    #100 A = 1'b1;B = 1'b0;D = 1'b1;
    #100 A = 1'b1;B = 1'b1;D = 1'b0;
    #100 A = 1'b1;B = 1'b1;D = 1'b1;
  end
  
  initial #800 $stop;
endmodule

