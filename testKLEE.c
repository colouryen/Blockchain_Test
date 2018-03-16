int outputArr(int n)
{
    int a[5] = {5, 0, 3, 1, 7};
    n = n % 5;
    return a[a[n]];
}

int main()
{
    int n;
    klee_make_symbolic(&n, sizeof(n), "int var n");

    return outputArr(n);
}
