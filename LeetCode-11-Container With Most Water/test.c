int maxArea(int* height, int heightSize) {
    //用C语言暴力解法会超时，理解双指针以后就很快只需要最多遍历一次。
    int capacity = 0;
    int maxcapacity = 0;
    int head = 0, tail = heightSize - 1;
    while (head != tail) {
        if (height[head] < height[tail]) {
            capacity = height[head] * (tail - head);
            head++;
        }
        else {
            capacity = height[tail] * (tail - head);
            tail--;
        }
        if (capacity > maxcapacity) {
            maxcapacity = capacity;
        }
    }
    return maxcapacity;
}