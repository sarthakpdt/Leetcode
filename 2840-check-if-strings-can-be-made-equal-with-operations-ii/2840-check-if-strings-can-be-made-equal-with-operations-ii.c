bool checkStrings(char* s1, char* s2) {
    int n = strlen(s1);
    // 26 slots for 'a' through 'z'
    int even_team[26] = {0}; 
    int odd_team[26] = {0};

    int i = 0;
    while (s1[i] != '\0') {
        if (i % 2 == 0) {
            // Count characters at even positions
            even_team[s1[i] - 'a']++; // Add from s1
            even_team[s2[i] - 'a']--; // Subtract from s2
        } else {
            // Count characters at odd positions
            odd_team[s1[i] - 'a']++;  // Add from s1
            odd_team[s2[i] - 'a']--;  // Subtract from s2
        }
        i++;
    }

    // If your logic (swapping) would work, 
    // these counts MUST all be zero.
    int k = 0;
    while (k < 26) {
        if (even_team[k] != 0 || odd_team[k] != 0) {
            return false;
        }
        k++;
    }

    return true;
}