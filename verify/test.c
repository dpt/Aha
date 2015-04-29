/* test.c -- test shell for Aha! suggested solutions */

#include <limits.h>
#include <stdio.h>

/* ----------------------------------------------------------------------- */

typedef unsigned int T;
typedef T (testfn_t)(T);

/* ----------------------------------------------------------------------- */

/* reference version of our original operation */
static T reference(T x)
{
    if (x == 0)
        return 1;
    else if (x == 1)
        return 2;
    else
        return 0;
}

static T branchless1(T x)
{
    return (((x + -2) & ~x) >> 31) << x;
}

static T branchless2(T x)
{
    return (((x - 2) & ~x) >> 31) << x;
}

static T branchless3(T x)
{
    return (((x >> 1) - 1) >> 31) << x;
}

static T branchless4(T x)
{
    return ((0x80000000 - (x >> 1)) >> 31) << x;
}

/* ----------------------------------------------------------------------- */

static const struct
{
    testfn_t *branchless, *reference;
}
tests[] =
{
    { &branchless1, &reference },
    { &branchless2, &reference },
    { &branchless3, &reference },
    { &branchless4, &reference },
};

/* ----------------------------------------------------------------------- */

#define NELEMS(a) (int)(sizeof(a) / sizeof(a[0]))

int main(void)
{
    int          j;
    unsigned int i;

    for (j = 0; j < NELEMS(tests); j++)
    {
        testfn_t *fn, *ref;
        int       nfailures;

        printf("starting test %d\n", j);

        fn  = tests[j].branchless;
        ref = tests[j].reference;

        nfailures = 0;

        /* test all values from zero to UINT_MAX */
        for (i = 0; ; i++)
        {
            if (fn(i) != ref(i))
                if (++nfailures < 20) /* report first twenty failures only */
                    printf("failure at %d\n", i);

            if ((i & 0x03ffffff) == 0) /* draw 64 dots */
            {
                putc('.', stdout);
                fflush(stdout);
            }

            if (i == UINT_MAX) /* test here to prevent infinite loop */
                break;
        }
        printf("\n");

        if (nfailures == 0)
            printf("all ok!\n");
        else
            printf("saw %d failures\n", nfailures);
    }

    return 0;
}
