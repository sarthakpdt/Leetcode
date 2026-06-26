bool checkRecord(char* s) {
    int count = 0;
    int count2 = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            count++;
            count2 = 0; 
        } else if (s[i] == 'L') {
            count2++;
        } else {
            count2 = 0; 
        }
        if (count>1 || count2>2) {
            return false;
        }
    }
    
    return true;
}
