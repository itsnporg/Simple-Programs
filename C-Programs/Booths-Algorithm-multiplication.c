#include <stdio.h>
void add();
void rshiftop();
void subtract();
int a_real[4] = {0, 0, 0, 0}, a[4] = {0, 0, 0, 0}, q[4] = {0, 0, 1, 1}, q1 = 0, m[4] = {0, 1, 1, 1}, m_real[4] = {0, 1, 1, 1}; 
//q and m(m_real) can be taken as input for multiplication

int main()
{
    int count = 0;
    // printf("%d\n", q[3]);
    // printf("%d\n", q1);
    // for (int i = 0; i < 4; i++)
    while (count != 4)

    {
        if (q[3] == q1)
        {

            // printf("11 and 00\n");
            rshiftop();
            count++;
        }
        else if (q[3] == 1 && q1 == 0)
        {
            // printf("-1 0\n");
            subtract();
            count++;
        }
        else
        {
            // printf("-0 1\n");
            add();
            count++;
        }
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d", a[i]);
    // }
    for(int i=0;i<4;i++)
    {
      printf("%d",a_real[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", q[i]);
    }
    printf("\n%d", count);
}
void add()
{
    int copya[4];
    // printf("adding\n");
    int carry = 0;
    for (int i = 0; i < 4; i++)
    {
        copya[i] = a_real[i];
    }

    for (int i = 3; i >= 0; i--)
    {
        a_real[i] = (copya[i] + m_real[i] + carry) % 2;
        carry = (copya[i] + m_real[i] + carry) / 2;
        // printf("%d", a[i]);
    }
    rshiftop();
}

void rshiftop()
{
    int copya[4], copyq[4];
    // printf("shifting\n");
    for (int i = 0; i < 4; i++)
    {
        copya[i] = a_real[i];
        copyq[i] = q[i];
    }

    a_real[0] = copya[0];
    a_real[1] = copya[0];
    a_real[2] = copya[1];
    a_real[3] = copya[2];
    q[0] = copya[3];
    q[1] = copyq[0];
    q[2] = copyq[1];

    q[3] = copyq[2];
    q1 = copyq[3];

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d", a[i]);
    // }
    // printf("\n");
}

void subtract()
{
    // printf("subtractiong\n");

    int temp, carry = 0;
    int copya[4], copyq[4];
    //subtract a-m and rs
    for (int i = 3; i >= 0; i--)
    {
        if (m[i] == 1)

        {
            temp = i;
            break;
        }
    }
    for (int i = 0; i < temp; i++)
    {
        if (m[i] == 1)
        {
            m[i] = 0;
        }
        else
        {
            m[i] = 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        copya[i] = a_real[i];
    }

    for (int i = 3; i >= 0; i--)
    {
        a_real[i] = (copya[i] + m[i] + carry) % 2;
        carry = (copya[i] + m[i] + carry) / 2;
        // printf("%d", a_real[i]);
    }

    if (carry == 1)
    {
        rshiftop();
    }
    else
    {
        for (int i = 3; i >= 0; i--)
        {
            if (m[i] == 1)

            {
                temp = i;
                break;
            }
        }
        for (int i = 0; i < temp; i++)
        {
            if (m[i] == 1)
            {
                m[i] = 0;
            }
            else
            {
                m[i] = 1;
            }
        }
        //----------------- feri original value ma lyauna paryo ni ta next time ko lagi
        for (int i = 0; i < 4; i++)
        {
            m[i] = m_real[i];
        }

        //------------------
        // for (int i = 0; i < 4; i++)
        // {
        //     printf("%d",a_real[i]);
        // }

        rshiftop();
    }
}
