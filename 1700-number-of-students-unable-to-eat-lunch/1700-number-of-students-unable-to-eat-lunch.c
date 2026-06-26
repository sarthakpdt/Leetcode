int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count0 = 0, count1 = 0;
    
    // Count the number of students preferring each type
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) {
            count0++;
        } else {
            count1++;
        }
    }
    
    // Process each sandwich in order
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            if (count0 > 0) {
                count0--;
            } else {
                break; // No more students want this sandwich type
            }
        } else {
            if (count1 > 0) {
                count1--;
            } else {
                break; // No more students want this sandwich type
            }
        }
    }
    
    // Remaining students can't eat
    return count0 + count1;
}
