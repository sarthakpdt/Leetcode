bool isPalindrome(int x) {
    int a=0;
    long b=0;
    int num=x;
    while (x>0){
        a=x%10;
        b=b*10+a;
        x=x/10;
    }
    if (num==b){
        return true;
    }
    else{
        return false;
    }
}