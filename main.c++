#include <cstdio>
#include <cstdint>

#include "foo.inline.c++"

int main()
{
    int x = 123, y = 239;
    int d = foo<int>(x, y);
    int64_t lld = foo<int64_t>(x, y);

    printf("x=%d, y=%d, d=%d, lld=%lld\n", x, y, d, lld);

    return 0;
}
