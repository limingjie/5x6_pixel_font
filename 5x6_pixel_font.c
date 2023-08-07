#include <stdio.h>

unsigned int font[] = {
    0b100011000110001111111000101110,  // A
    0b011111000110001011111000101111,  // B
    0b011101000100001000011000101110,  // C
    0b011111000110001100011000101111,  // D
    0b111110000100001011110000111111,  // E
    0b000010000100001011110000111111,  // F
    0b011101000110001111010000101110,  // G
    0b100011000110001111111000110001,  // H
    0b011100010000100001000010001110,  // I
    0b001100100101000010000100011100,  // J
    0b100010100100101000110010101001,  // K
    0b111110000100001000010000100001,  // L
};

void reverse()
{
    for (int i = 0; i < sizeof(font) / sizeof(font[0]); i++)
    {
        unsigned int f = 0;
        for (int j = 0; j < 30; j += 5)
        {
            for (int k = 0; k < 5; k++)
            {
                f |= ((font[i] >> (j + k)) & 1) << (j + 4 - k);
            }
        }
        font[i] = f;
        putchar('0');
        putchar('b');
        for (int j = 30; j-- > 0;)
        {
            // putchar(((f >> j) & 1) + '0');
            printf("%d,", j);
        }
        putchar('\n');
    }
}

int main()
{
    // reverse();
    size_t chars = sizeof(font) / sizeof(font[0]);
    size_t start = 0, end;
    while (start < chars)
    {
        end = (chars - start) >= 15 ? start + 15 : chars;
        printf("start = %lu, end = %lu\n", start, end - 1);

        // print ruler
        printf("  ");
        for (size_t c = start; c < end; c++)
        {
            printf("01234|");
        }
        printf("\n");

        size_t bit = 1;
        // 5x6 pixel font, print 6 lines of pixels
        for (size_t line = 0; line < 6; line++)
        {
            printf("%lu ", line);
            // loop through the font in [start, end).
            for (size_t c = start; c < end; c++)
            {
                // loop through the pixels in each line.
                for (size_t dot = 0; dot < 5; dot++)
                {
                    putchar(font[c] & (bit << dot) ? '#' : ' ');
                }
                putchar(' ');
            }
            bit <<= 5;
            putchar('\n');
        }
        start += 15;
    }

    return 0;
}
