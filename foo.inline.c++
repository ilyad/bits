template <class integer_t, int b>
struct worker_t
{
    static void foo(const integer_t x, const integer_t y, integer_t &m, integer_t &c, integer_t &a)
    {
        worker_t<integer_t, b/2>::foo(x, y, m, c, a);
        worker_t<integer_t, b/2>::foo(x, y, m, c, a);
    }
    static void muh(const integer_t x, integer_t &y, integer_t &m, integer_t &c, integer_t &a)
    {
        worker_t<integer_t, b/2>::muh(x, y, m, c, a);
        worker_t<integer_t, b/2>::muh(x, y, m, c, a);
    }
};

template <class integer_t>
struct worker_t<integer_t, 1>
{
    static void foo(const integer_t x, const integer_t y, integer_t &m, integer_t &c, integer_t &a)
    {
        a |= (c ^ x ^ y) & m;
        c = (x & y) | (x & c) | (y & c);
        c &= m;
        c <<= 1;
        m <<= 1;
    }
    static void muh(const integer_t x, integer_t &y, integer_t &m, integer_t &c, integer_t &a)
    {
        integer_t z = (m&x) ? y : 0;
        integer_t aa = c ^ a ^ z;
        c = (a & z) | (a & c) | (z & c);
        a = aa;
        c <<= 1;
        m <<= 1;
        y <<= 1;
    }
};

template<class integer_t> integer_t foo(integer_t x, integer_t y)
{
    integer_t m=1, c=0, a=0;
    worker_t<integer_t, 8*sizeof(integer_t)>::foo(x, y, m, c, a);
    return a;
}

template<class integer_t> integer_t bar(integer_t x, integer_t y)
{
    integer_t m=1, c=1, a=0;
    worker_t<integer_t, 8*sizeof(integer_t)>::foo(x, ~y, m, c, a);
    return a;
}

template<class integer_t> integer_t muh(integer_t x, integer_t y)
{
    integer_t m=1, c=0, a=0;
    worker_t<integer_t, 8*sizeof(integer_t)>::muh(x, y, m, c, a);
    return a;
}
