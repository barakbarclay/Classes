memory[0] =   32'b00111100000000011111111111111111; //1. lui $1, 1
memory[4] =   32'b00000000000000010001010000000011; //2. sra $2, $1, 16
memory[8] =   32'b00111100000000110000000000000000; //3. lui $3, 0
memory[12] =  32'b00101000010001100011000000000000; //4. slti $6, $2, 1
memory[16] =  32'b00101000010001010010100000000000; //5. slti $5, $2, 1
memory[20] =  32'b00101000011001110011111111111111; //6. slti $7, $3, 1

