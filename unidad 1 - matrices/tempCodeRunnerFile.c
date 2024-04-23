    const int matrixA[4][3] = {
            {1, 2, 3},
            {6, 7, 8},
            {11, 12, 13},
            {16, 17, 18},
        };

    const int matrizB[3][2] = {
            {1, 2},
            {6, 7},
            {11, 12},
    };
   
    int mat[4][2]; 
    
    multiplyMatrices(matrixA, 4, 3, matrizB, 3, 2, mat);
    
    showMatrix(mat, 4, 2);

    return 0;
}