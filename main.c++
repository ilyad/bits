#include <cstdio>
#include <cstdint>

#include "foo.inline.c++"

int main()
{
    int x = 123, y = 239;
    int d = foo<int>(x, y);
    int64_t lld = foo<int64_t>(x, y);

    printf("foo: x=%d, y=%d, d=%d, lld=%lld\n", x, y, d, lld);

    d = bar<int>(x, y);
    lld = bar<int64_t>(x, y);

    printf("bar: x=%d, y=%d, d=%d, lld=%lld\n", x, y, d, lld);

    x = 70000, y = -8000;
    d = muh<int>(x, y);
    lld = muh<int64_t>(x, y);

    printf("muh: x=%d, y=%d, d=%d, lld=%lld\n", x, y, d, lld);

    return 0;
}
