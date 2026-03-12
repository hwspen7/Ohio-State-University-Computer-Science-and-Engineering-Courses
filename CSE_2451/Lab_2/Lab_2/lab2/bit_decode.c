#include <stdio.h>

/* Reads the 4-bit key and builds the 8-bit key */
unsigned char create_key(void);
/* Rotates the value right by 1 bit */
unsigned char rotate_right(unsigned char value);
/* Rotates the value left by 1 bit */
unsigned char rotate_left(unsigned char value);

/*
     * Spencer Qin
     * This program decodes a bit stream cipher. It asks the user for a 4-bit key, turns
     * it into an 8-bit key, and then reads the encrypted hex values one at a time. For each
     * value, it undoes the bit rotation, uses XOR with the key to get the original character,
     * and prints the decoded message.
     * */
int main(void)
{
    unsigned char key;
    unsigned char cipher;
    unsigned char decoded;
    unsigned int hex_value;
    char separator;
    int count;

    /* Get the key from the user */
    key = create_key();

    /* Ask for the encoded message */
    printf("Enter encoded text: ");

    /* Keep track of character position */
    count = 0;

    /* Read one hex value at a time */
    while (scanf("%2x", &hex_value) == 1)
    {
	/* Store the hex value as one byte */
        cipher = (unsigned char)hex_value;

	/* Undo the alternating rotation */
	if (count % 2 == 0)
	{
	    cipher = rotate_right(cipher);
	}
	else
	{
	    cipher = rotate_left(cipher);
	}

	/* Decode the character using XOR */
	decoded = cipher ^ key;

	/* Print each character right away */
	putchar(decoded);

	/* Read the space or newline after the hex value */
	separator = getchar();

	/* If it is newline, this was the last value */
	if (separator == '\n')
	{
	    putchar('\n');
	    break;
	}

	/* Move on to the next character */
	count++;
    }
    return 0;
}

/* Reads 4 bits from the user and turns them into an 8-bit key */
unsigned char create_key(void)
{
    unsigned char key;
    char digit;
    int i;

    /* Start with an empty key */
    key = 0;
    printf("Enter 4-bit key: ");
    
    /* Read and process each bit right away */
    for (i = 0; i < 4; i++)
    {
        digit = getchar();

	/* Shift left to make room for the next bit */
	key = key << 1;

	/* If the digit is 1, set the last bit to 1 */
	if (digit == '1')
	{
	    key = key | 1;
	}
    }
    /* Remove the newline after the key */
    getchar();

    /* Copy the 4-bit pattern to make an 8-bit key */
    key = (key << 4) | key;

    return key;
}

/* Rotate the byte right by 1 bit */
unsigned char rotate_right(unsigned char value)
{
    return ((value >> 1) | (value << 7)) & 0xFF;
}

/* Rotate the byte left by 1 bit */
unsigned char rotate_left(unsigned char value)
{
    return ((value << 1) | (value >> 7)) & 0xFF;
}


