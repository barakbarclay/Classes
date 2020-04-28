module L9TB;
  reg clock,A,B,a,b;
  wire D,d;

L9 M1(clock,A,B,a,b,D,d);
  
  initial
  begin
    $monitor ("RA=%d", A);
    $monitor ("RB=%d", B);
    $monitor ("RA=%d", D);
    $monitor ("Ra=%d", a);
    $monitor ("RA=%d", b);
    $monitor ("RA=%d", D);
    clock = 1'b0;A=1'd6;B=1'd2;a=1'd6;b=1'd2;
    #5 clock = 1'b1;
  end
  
  initial #20 $stop;
  
endmodule
