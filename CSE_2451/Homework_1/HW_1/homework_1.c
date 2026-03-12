// 1
int logicalShift(int x, int n){
    // Shift right logical, even though int is a signed variable. Use a maximum of 20 operations.        
    int topBit  = 0x01 << 0x1F;    
    int mask    = ~(((topBit >> n) << 0x01));  
    return (x >> n) & mask;
}

// 2
int bitParity(int x){
    // returns 1 if x contains an odd number of 0's. Use a maximum of 20 operations.
    int x1, x2, x3, x4, x5;

    x1 = x ^ (x >> 0x10);
    x2 = x1 ^ (x1 >> 0x08);
    x3 = x2 ^ (x2 >> 0x04);
    x4 = x3 ^ (x3 >> 0x02);
    x5 = x4 ^ (x4 >> 0x01);

    return (x5 & 0x01);
}

// 3
int bang(int x){
    // Compute ! x without using ! and do so in a maximum of 12 operations.
    int negX = ~x + 0x01;               
    int nonZeroSign = (x | negX) >> 0x1F; 
    return nonZeroSign + 0x01;                   
}

// 4
int isPositive(int x){
    // Is x > 0? Remember that there are really three possibilities (that x is positive, negative, or 0). Use a maximum of 8 operations.
    int sign = (x >> 0x1F) & 0x01;
    int isZero = !x;
    return !(sign | isZero);          
}

// 5
int isLessOrEqual(int x, int y){
    // Is x <= y? Remember that there are at least four possibilities based on the signs of x and y. Use a maximum of 24 operations.
    int xSign = x >> 0x1F;               
    int ySign = y >> 0x1F;                   
    int signMismatch = xSign ^ ySign;        

    int yMinusX = y + (~x + 0x01);         
    int diffSign = yMinusX >> 0x1F;       

    int xNeg_yNonNeg = signMismatch & xSign;  
    int sameSign_ok = (~signMismatch) & (~diffSign);  

    return (xNeg_yNonNeg | sameSign_ok) & 0x01;
}

// 6
int fitsBits(int x, int n){
    // Does x fit in n bits? Returns 0 if no and 1 if yes. Use a maximum of 15 operations.
    int negN = ~n + 0x01;               
    int leftCount = 0x20 + negN;          

    int restored = (x << leftCount) >> leftCount;
    int diff = restored ^ x;

    return ((diff | (~diff + 0x01)) >> 0x1F) + 0x01;
}

// 7
int divpwr2(int x, int n){
    // Compute x divided by (2 raised to the nth power). Use a maximum of 15 operations.
    int xSign = x >> 0x1F;                     
    int lowMask = (0x01 << n) + (~0x01 + 0x01); 
    int bias = xSign & lowMask;              

    return (x + bias) >> n;
}

// 8
int negate(int x){
    // Solve -x without using negation or subtraction. Use a maximum of 5 operations.
    return ~x + 0x01;
}

// 9 
int conditional(int x, int y, int z){
    // Compute the same answer as x ? y : z using a maximum of 16 operations.
    int xIsZero = ((x | (~x + 0x01)) >> 0x1F) + 0x01;   
    int mask = ~xIsZero + 0x01;                      
    return (y & ~mask) | (z & mask);
}

// 10
int tmax(){
    // Returns the most positive integer that can be stored in an int interpreted using two's complement. Use a maximum of 10 operations.
    int n = (0x0F << 0x01) + 0x01; 
    int topBit = 0x01 << n;

    return ~topBit;           
}

