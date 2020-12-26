int compare(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return (*pa) - (*pb);
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int i, j;
    int count = 0;
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    for (i = 0; i < gSize; i++)
    {
        for (j = 0; j < sSize; j++)
        {
            if (g[i] <= s[j])
            {
                count += 1;
                s[j] = 0;
                break;
            }
        }
    }
    return count;
}
