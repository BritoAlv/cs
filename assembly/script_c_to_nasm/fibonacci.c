int fibonacci(int n)
{
    if ( n <= 2)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int a = fibonacci(5);
    return 0;
}