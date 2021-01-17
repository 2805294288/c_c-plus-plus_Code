bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    //利用一条直线斜率相同的特点。但是不可以用除法直接算斜率（斜率不存在），用乘法代替除法。
    if (coordinatesSize <= 1) {
        return true;
    }
    int high = coordinates[1][1] - coordinates[0][1];
    int length = coordinates[1][0] - coordinates[0][0];
    int high_1, length_1, grade_1, grade;
    for (int i = 1; i + 1 < coordinatesSize; i++) {
        high_1 = coordinates[i + 1][1] - coordinates[i][1];
        length_1 = coordinates[i + 1][0] - coordinates[i][0];
        int grade = high * length_1;
        int grade_1 = length * high_1;
        if (grade != grade_1)
            return false;
    }
    return true;
}