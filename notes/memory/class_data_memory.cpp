#include <inttypes.h>
#include <stdio.h>

//          /* 1. use a union */
//          union u {
//              double d;
//              unsigned char c[sizeof(double)];
//          };
//          union u tmp;
//          size_t i;
//          tmp.d = d;
//          for (i = 0; i < sizeof(double); ++i)
//              printf("%02x\n", tmp.c[i]);
//          
//          /* 2. memcpy */
//          unsigned char data[sizeof d];
//          size_t i;
//          memcpy(data, &d, sizeof d);
//          for (i = 0; i < sizeof d; ++i)
//              printf("%02x\n", data[i]);
//          
//          /* 3. Use a pointer to an unsigned char to examine the bytes */
//          unsigned char *p = (unsigned char *)&d;
//          size_t i;
//          for (i = 0; i < sizeof d; ++i)
//              printf("%02x\n", p[i]);

#define DUMPVARHEX(_var, _type) dumpHex((void*)&_var, sizeof(_type), #_var);

void dumpHex(void* _ptr, uint32_t _size, char* _name)
{
    uintptr_t;
    printf("<Variable> %s \n", _name);
    unsigned char* p = (unsigned char*)_ptr;
    uint32_t lr = _size % 16 == 0 ? 16 : _size % 16;
    uint32_t rr = 0 == (_size % 16) ? _size / 16 : _size / 16 + 1;
    for (uint32_t ii = 0; ii < rr; ++ii)
    {
        for (uint32_t jj = 0; jj < (ii == (_size / 16) ? lr : 16); ++jj)
        {
            printf("%02x%c", p[jj + 16 * ii], 0 == (jj + 1) % 4 ? '|' : ' ');
        }
        printf("\n");
    }
}

class A
{
public:
    A() { a = 1; b = 2; c = (uint32_t*)3; }
    virtual ~A() = default;
    uint32_t a;
    uint8_t  b;
    uint32_t* c;
};

class B : public A
{
public:
    B() { d = 4; }
    uint8_t  d;
};

int main(int argc, char** argv)
{
    A a = A();
    DUMPVARHEX(a, A);
    uint32_t a_size = sizeof(A);
    B b = B();
    DUMPVARHEX(b, B);
    uint32_t b_size = sizeof(B);

    printf("OK\n");
    return 1;
}