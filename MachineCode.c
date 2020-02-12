#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// %x = in hex code for printf()
typedef struct rFormat{
	char opcode[8];
	char rs[5];
	char rt[5];
	char rd[5];
	char shamt[5];
	char funct[6];
	int i; 
}RFormat;

void printFormat(RFormat *instruct){
	
}

int getOpval(char* opcode){
	if (strcmp(opcode, "add") == 0)
		return 0x312;	
    if (strcmp(opcode, "addu") == 0) 
		return 0x312;
    if (strcmp(opcode, "and") == 0) 
		return 0x312;
    if (strcmp(opcode, "break") == 0) 
		return 0x000;
    if (strcmp(opcode, "div") == 0) 
		return 0x120;
    if (strcmp(opcode, "divu") == 0) 
		return 0x120;
    if (strcmp(opcode, "jalr") == 0) 
		return 0x310;
    if (strcmp(opcode, "jr") == 0) 
		return 0x100;
    if (strcmp(opcode, "mfhi") == 0) 
		return 0x300;
    if (strcmp(opcode, "mflo") == 0) 
		return 0x300;
    if (strcmp(opcode, "mthi") == 0) 
		return 0x100;
    if (strcmp(opcode, "mtlo") == 0) 
		return 0x100;
    if (strcmp(opcode, "mult") == 0) 
		return 0x120;
    if (strcmp(opcode, "multu") == 0) 
		return 0x120;
    if (strcmp(opcode, "nor")== 0) 
		return 0x312;
    if (strcmp(opcode, "or") == 0) 
		return 0x312;
    if (strcmp(opcode, "sll") == 0) 
		return 0x324;
    if (strcmp(opcode, "sllv") == 0) 
		return 0x321;
    if (strcmp(opcode, "slt") == 0) 
		return 0x312;
    if (strcmp(opcode, "sltu") == 0) 
		return 0x312;
    if (strcmp(opcode, "sra") == 0) 
		return 0x324;
    if (strcmp(opcode, "srav") == 0) 
		return 0x321;
    if (strcmp(opcode, "srl") == 0) 
		return 0x324;
    if (strcmp(opcode, "srlv") == 0) 
		return 0x321;
    if (strcmp(opcode, "sub") == 0) 
		return 0x312;
    if (strcmp(opcode, "subu") == 0) 
		return 0x312;
    if (strcmp(opcode, "syscall") == 0) 
		return 0x000;
    if (strcmp(opcode, "xor") == 0) 
		return 0x312;
    return 1;
}

void scanInput(RFormat *instruct){
	scanf("%s", instruct->opcode);

	const char c[2] = ",";
	char regsisters[32];
	char *pnt;
	int mask =  0xf00;

	scanf("%[^\n]", regsisters);

	pnt = strtok(regsisters, c);

	for(int i = 0; i < 3; i++){
		int opval = (mask & getOpval(instruct->opcode)) >> (2-i) * 4;
		if(opval == 1){
			sscanf(pnt, "%s", instruct->rs);
		}else if(opval == 2){
			sscanf(pnt, "%s", instruct->rt);
		}else if(opval == 3){
			sscanf(pnt, "%s", instruct->rd);
		}else if(opval == 4){
			sscanf(pnt, "%d", &(instruct->i));
		}
		pnt = strtok(NULL, c);
		mask = mask >> 4; 
	}
}

int main(void){	
	RFormat* instruction;
	printf("Enter an R-format instruction:\n");
	// initializing object
	instruction->i = 0;
	for(int i = 0; i < 2; i++){
		if(i == 0){
			instruction->rs[i] = '0';
			instruction->rt[i] = '0';
			instruction->rd[i] = '0';
		}else{
			instruction->rs[i] = 0;
			instruction->rt[i] = 0;
			instruction->rd[i] = 0;		
		}
	}
	scanInput(instruction);
	printFormat(instruction);
	return 0;
}
// test instruction
// add $t0 $t1 $t2

// R-Format instructions
/*	Operation	opcode: 	Fucnt:
	add			0			20
	addu		0			21
	and			0			24
	jr			0			08
	nor			0			27
	or			0			25
	slt			0			2a
	sltu		0			2b
	sll			0			00
	srl			0			02
	sub			0			22
	subu		0			23
	div			0			1a
	divu		0			1b
	mfhi		0			10
	mflo		0			12
	mfcO		0			0
	mult		0			18
	multu		0			19
	sra			0			3
*/
// Register values
/* 
	$zero	0
	$at		1
	$v0		2
	$v1		3
	$a0		4
	$a1		5
	$a2		6
	$a3		7
	$t0		8
	$t1		9
	$t2		10
	$t3		11
	$t4		12
	$t5		13
	$t6		14
	$t7		15
	$s0		16
	$s1		17
	$s2		18
	$s3		19
	$s4		20
	$s5		21
	$s6		22
	$s7		23
	$t8		24
	$t9		25
	$k0		26
	$k1		27
	$gp		28
	$sp		29
	$fp		30
	$ra		31
*/