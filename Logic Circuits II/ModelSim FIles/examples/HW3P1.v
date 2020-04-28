
module Exmpl_3(A, B, C, D, F, G); // Line 1: A "-" cannot be used in module declaration. A ";" is neeeded after ")". See side note.
input A, B, C; output D, F, G; // Line 2: Omit "s", put a ";" after "C" and "F", and lowercase "O". See side note.
//output B // Line 3: Omit line b/c "B" is already an input. ";" would be needed after "B" if this line was used.
and g1(D, A, B); // Line 4: The output should be listed first.
not (G, A); // Line 5: A ";" is neeeded after ")" instead of a ",". Not gate should have only 2 ports.
or (F, B, C); // Line 6: "OR" should be lowercase. "B" should have a "," instead of a ";" after it.
endmodule // Line 7: Omit ";".
//Side note: If only above commented corrections are done, "D" would be the output for two different gates. Although
//	     it will complle, the simulation doesn't seem to like it and gives "D" a red line instead of a green one.
//	     This can be fixed many ways. I choose to add another output "G" to use for the not gate instead of "D".