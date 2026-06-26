int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    int *p = (int *)malloc(2000 * sizeof(int)); 
    int count = 0;

    for (int i = 0; ; i++) {
        double pow_x = pow(x, i);
        if (pow_x >= bound) {
            break;
        }

        for (int j = 0; ; j++) {
            double sum = pow_x + pow(y, j);
            
            if (sum <= bound) {
                bool isDuplicate = false;
                for (int k = 0; k < count; k++) {
                    if (p[k] == (int)sum) {
                        isDuplicate = true;
                        break;
                    }
                }
                
                if (!isDuplicate) {
                    p[count] = (int)sum;
                    count++;
                }
            } else {
                break;
            }
            
            if (y == 1) {
                break;
            }
        }
        
        if (x == 1) {
            break;
        }
    }

    *returnSize = count;
    return p;
}