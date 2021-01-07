double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0 && nums2Size == 0)
        return 0;
    if (nums1Size == 1 && nums2Size == 0) {
        double midnumber = nums1[0];
        return midnumber;
    }
    if (nums1Size == 0 && nums2Size == 1) {
        double midnumber = nums2[0];
        return midnumber;
    }
    int size = nums1Size + nums2Size;
    int* a = (int*)malloc(sizeof(int) * size);
    int n = nums1Size + nums2Size;
    int c = nums1Size + nums2Size - 1, i = nums1Size - 1, j = nums2Size - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
            a[c--] = nums1[i--];
        else
            a[c--] = nums2[j--];
    }
    while (j >= 0)
        a[c--] = nums2[j--];
    while (i >= 0)
        a[c--] = nums1[i--];
    double midnumber = 0;
    int position = n / 2;
    if (n % 2 != 0) {
        midnumber = (double)a[position];
    }
    else
        midnumber = (double)(a[position] + a[position - 1]) / 2;
    return midnumber;
}