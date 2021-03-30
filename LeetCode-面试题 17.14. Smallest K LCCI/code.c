/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void AdjustDown(int *input, int n,int root)
    {
        int parent = root;
        int child = parent * 2 + 1;
        
        while(child < n)
        {
            if((child+1) <n && input[child+1] > input[child])
            {
                child++;
            }
            
            if(input[parent] < input[child])
            {
                int tmp = input[parent];
                input[parent] = input[child];
                input[child] = tmp;
                parent = child;
                child = parent * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
    
int* smallestK(int* arr, int arrSize, int k, int* returnSize){
       *returnSize = k;
       if(arrSize == 0 || k == 0)
       {
           return NULL;
       }
        int *num=(int*)malloc(sizeof(int)*k);
        for(int i=0; i<k; i++)
        {
            num[i]=arr[i];
        }
        
        for(int i=(k-2)/2; i>=0; i--)
        {
            AdjustDown(num, k, i);
        }
        
        for(int i=k; i<arrSize; i++)
        {
            if(arr[i]<num[0])
            {
                num[0]=arr[i];
                AdjustDown(num, k, 0);
            }
        }
        
        return num;
}