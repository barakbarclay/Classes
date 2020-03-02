module  Part1 (A,B,C,F);
  output	F;
  input		A,B,C;
  wire		w1,w2;

  or		G1 (w1,A,B);
  or		G2 (w2,B,C);
  and		G3 (F,w1,w2);
endmodule