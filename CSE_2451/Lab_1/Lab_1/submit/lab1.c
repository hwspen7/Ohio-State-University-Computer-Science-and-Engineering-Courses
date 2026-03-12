#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int main(int argc, char * argv[]) {
  /*
   * If run as: ./lab1
   * argc = 1
   * argv = {"./lab1"}
   *
   * If run as: ./lab1 YourFirstName
   * argc = 2
   * argv = {"./lab1", "YourFirstName"}
   *
   * If run as: ./lab1 YourFirstName YourLastName
   * argc = 3
   * argv = {"./lab1", "YourFirstName", "YourLastName"}
   */ 
  srand( time(NULL));

  int r = rand()%500-500;
  printf("Hello World %d %x\n", r, r);

  printf("argc = %d, argv = {\"%s\", \"%s\", \"%s\"}\n", argc, argv[0], (argc > 1) ? argv[1] : "",
		  (argc > 2) ? argv[2] : "");

  /* use the first character of argv[1] as an unsigned char input value */
  unsigned char u8;
  if(argc < 2){
    /* default value */
    u8 = 0;
  }else{
    u8 = (unsigned char)argv[1][0];
  }

  /* unsigned int (typically 4 bytes), defined using the same input */
  unsigned int u32 = (unsigned int)u8;

  /*
   * signed int (typically 4 bytes) 
   * add a large value before assigning to force overflow
   * all variables are defined using the same input character
   */
  int s32 = (int)((unsigned int)u8 + (unsigned int)INT_MAX + 1U);

  /* === u8 formats === */
  printf("\n[u8 - unsigned char]\n");
  printf("Hex: %x\n", (unsigned int)u8);
  printf("ASCII: %c\n", u8);
  printf("Unsigned: %u\n", (unsigned int)u8);
  printf("Signed (two's complement): %d\n", (int)u8);

  /* === u32 formats === */
  printf("\n[u32 - unsigned int]\n");
  printf("Hex: %x\n", u32);
  printf("ASCII: %c\n", (unsigned char)u32);
  printf("Unsigned: %u\n", u32);
  printf("Signed (two's complement): %d\n", (int)u32);

  /* === s32 formats === */
  printf("\n[s32 - signed int]\n");
  printf("Hex: %x\n", (unsigned int)s32);
  printf("ASCII: %c\n", (unsigned char)s32);
  printf("Unsigned: %u\n", (unsigned int)s32);
  printf("Signed (two's complement): %d\n", s32);
  
  /*
   * Comparing the outputs, I noticed that printing the same variable with %x always shows the same
   * raw bit in hexadecimal form. However, when using %u and %d, the decimal results can differ because
   * signed and unsigned interpretations treat the highest bit differently. The ASCII output using %c
   * only uses the Lowest byte, so it may display a readable character or an unreadable symbol depending
   * on the value. After forcing overflow, the signed integer becomes negative, which confirms that two's
   * complement uses the highest bit as the sign bit.
   */
  
  return 0;
}
