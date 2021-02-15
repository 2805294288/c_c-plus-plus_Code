//很简单的将字符串j作为目标，将字符串j中的每个字符与s中的字符进行遍历匹配。
int numJewelsInStones(char* jewels, char* stones) {
    int k = 0;
    int count = 0;
    int Long = strlen(stones);
    while (jewels[k]) {
        for (int i = 0; i < Long; i++) {
            if (jewels[k] == stones[i]) {
                count++;
            }
        }
        k++;
    }
    return count;
}