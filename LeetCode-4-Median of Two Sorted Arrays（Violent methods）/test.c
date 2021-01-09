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
     int n=0;
     for(int i=0;i<nums1Size;i++){
         a[n++]=nums1[i];
     }
     for(int j=0;j<nums2Size;j++){
         a[n++]=nums2[j];
     } 
     for(int i=0;i<n-1;i++){
         for(int j=0;j<n-i-1;j++){
             if(a[j]>a[j+1]){
                 int temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
             }
         }
     } 
     double midnumber = 0;
     int position = n / 2;
     if (n % 2 != 0) {
         midnumber = (double)a[position];
     }
     else
         midnumber = (double)(a[position] + a[position - 1]) / 2;
     return midnumber;
}