
module L1P4(C,E,A,B,D);
output C,E;
input A,B,D;

L1P4UDP(C,A,B);
or (E,C,D);
endmodule
