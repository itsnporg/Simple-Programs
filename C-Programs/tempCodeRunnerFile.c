    for (i = length - 1; i >= 0; --i){
        if (binary[i] == '1'){
            decimal += pow (2, i);
            printf("times : %d\n", i);
        }
    }
    return decimal;
}