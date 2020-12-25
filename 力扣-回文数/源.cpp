bool isPalindrome(int x) {
    long long newnumber = 0;
    int number = x;
    if (x < 0) {
        return false;
    }
    else {
        while (x) {
            newnumber = newnumber * 10 + x % 10;
            x = x / 10;
        }
        if (newnumber == number) {
            return true;
        }
        else
            return false;
    }
    return 0;
}