int main () {
    int a;
    int b;
    int c;
    int d;
    int arr[5];
    int e[6][7];

// ID LHS
    // LHS = CONSTANT
    a = 1;

    // LHS = ID
    a = a;

    // LHS = ARRAY[CONSTANT]
    a = arr[1];

    // LHS = ARRAY[ID]
    a = arr[a];

    // LHS = ARRAY[MATH]
    a = arr[a+1];

    // LHS = MATH
    a = a + 1;
    // LHS = 2D
    a = e[3][4];
// ARRAY[] LHS
    // LHS = CONSTANT
    arr[1] = 1;
    arr[a] = 1;
    arr[a+2] = 1;
    arr[2+2] = 1;
    arr[a+a] = 1;

    // LHS = ID
    arr[1] = a;
    arr[a] = a;
    arr[a+2] = a;
    arr[2+2] = a;
    arr[a+a] = a;

    // LHS = ARRAY[CONSTANT]
    arr[1] = arr[1];
    arr[a] = arr[1];
    arr[a+2] = arr[1];
    arr[2+2] = arr[1];
    arr[a+a] = arr[1];

    // LHS = ARRAY[ID]
    arr[1] = arr[a];
    arr[a] = arr[a];
    arr[a+2] = arr[a];
    arr[2+2] = arr[a];
    arr[a+a] = arr[a];

    // LHS = ARRAY[MATH]
    arr[1] = arr[a+1];
    arr[a] = arr[a+1];
    arr[a+2] = arr[a+1];
    arr[2+2] = arr[a+1];
    arr[a+a] = arr[a+1];

    // LHS = MATH
    arr[1] = a + 1;
    arr[a] = a + 1;
    arr[a+2] = a + 1;
    arr[2+2] = a + 1;
    arr[a+a] = a + 1;

    // LHS = 2D
    arr[1] = e[3][4];
    arr[a] = e[3][4];
    arr[a+2] = e[3][4];
    arr[2+2] = e[3][4];
    arr[a+a] = e[3][4];
    /*
*/
    //e[a][a] = e[b][b] + e[c][c] * e[d][d];
    //e[a][b] = 0;
    //e[a][b] = c;
    return 0;
}
