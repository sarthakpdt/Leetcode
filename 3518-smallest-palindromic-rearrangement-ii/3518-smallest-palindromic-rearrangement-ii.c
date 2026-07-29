long long comb(long long n, long long m, long long k) {
    long long res = 1;
    if (n - m < m) {
        m = n - m;
    }

    for (long long i = 1; i <= m; i++) {
        res = res * (n - i + 1) / i;
        if (res > k) {
            return k + 1;
        }
    }
    return res;
}

long long permutations(int rem, int* bucket, long long k) {
    long long ways = 1;
    for (int i = 0; i < 26; i++) {
        if (bucket[i] == 0) {
            continue;
        }

        ways *= comb(rem, bucket[i], k);
        if (ways > k) {
            break;
        }
        rem -= bucket[i];
    }
    return ways;
}

char* smallestPalindrome(char* s, long long k) {
    int len = strlen(s);
    int partition = len / 2;
    int bucket[26] = {0};

    for (int i = 0; i < partition; i++) {
        bucket[s[i] - 'a'] += 1;
    }

    char* left = (char*)malloc(partition + 1);
    int left_idx = 0;
    long long start_index = 1;

    for (int pos = 0; pos < partition; pos++) {
        for (int i = 0; i < 26; i++) {
            if (bucket[i] == 0) {
                continue;
            }

            bucket[i] -= 1;

            long long ways = permutations(partition - pos - 1, bucket, k);
            if (start_index + ways > k) {
                left[left_idx++] = i + 'a';
                break;
            }

            bucket[i] += 1;
            start_index += ways;
        }
    }
    left[left_idx] = '\0';

    if (left_idx < partition) {
        char* empty_res = (char*)malloc(1);
        empty_res[0] = '\0';
        free(left);
        return empty_res;
    }

    char* result = (char*)malloc(len + 1);
    int res_idx = 0;

    for (int i = 0; i < partition; i++) {
        result[res_idx++] = left[i];
    }

    if (len % 2 != 0) {
        result[res_idx++] = s[partition];
    }

    for (int i = partition - 1; i >= 0; i--) {
        result[res_idx++] = left[i];
    }
    result[res_idx] = '\0';

    free(left);
    return result;
}