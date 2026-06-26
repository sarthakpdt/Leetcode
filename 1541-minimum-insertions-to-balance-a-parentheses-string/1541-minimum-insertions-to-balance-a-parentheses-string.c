int minInsertions(char* s) {
    int insertions = 0;
    int needed_rights = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            if (needed_rights % 2 != 0) {
                insertions++;
                needed_rights--;
            }
            needed_rights += 2;
        } 
        else {
            needed_rights--;
            if (needed_rights < 0) {
                insertions++;
                needed_rights += 2;
            }
        }
    }

    return insertions + needed_rights;
}