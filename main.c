#include <iostream>

int main()
{
    int band1 = 0;
    int band2 = 0;
    int band3 = 0;
    int band4 = 0;

    int multi;
    float i;
    int i2;
    int wider;
    int wider2;
    float rechn1 = 0;
    int rechn2 = 0;

    for (int run = 1; run > 0;)
    {

        printf("Bitte geben Sie den Widerstand (Ohm) oder eine negative Zahl zum Beenden ein!\n");
        scanf_s("%d", &wider);

        wider2 = wider;

        if (wider < 0)
        {
            printf("Auf Wiedersehen!");
            run = 0;
        }
        else if (wider == 0)
        {
            band1 = 0;
            band2 = 0;
            band3 = 0;
            band4 = 0;
        }
        else if (wider >= 1000000000)       // 999000000000)
        {
            printf("Der eingegebene Betrag ist zu hoch!\n");
            band1 = 10;
            band2 = 10;
            band3 = 10;
            band4 = 100000000;
        }
        else if (wider == 1)               // GLEICH 1
        {
            band1 = 0;
            band2 = 0;
            band3 = 1;
            band4 = 0;
        }
        else if (wider < 10)               // BIS 9
        {
            for (i = 1; rechn1 != 1.0; i++)           // EINSER-STELLE
            {
                rechn1 = wider / i;
                band3 = band3 + 1;
            }
        }
        else if (wider < 100)               // BIS 99
        {
            for (i2 = 10; rechn2 != 1;)               // ZEHNER-STELLE
            {
                rechn2 = wider / i2;
                band2 = band2 + 1;
                // printf("%d / %d = %d\n", wider, i2, rechn2);
                wider = wider - 10;
            }

            if (wider != 0)
            {
                for (i = 1; rechn1 != 1.0; i++)       // EINSER-STELLE
                {
                    rechn1 = wider / i;
                    band3 = band3 + 1;
                    // printf("%d / %f = %f\n", wider, i, rechn1);
                }
            }
        }
        else if (wider < 1000)               // BIS 999
        {
            for (i2 = 100; rechn2 != 1;)              // HUNDERTER-STELLE
            {
                rechn2 = wider / i2;
                band1 = band1 + 1;
                // printf("%d / %d = %d\n", wider, i2, rechn2);
                wider = wider - 100;
            }

            rechn2 = 0;

            if (wider != 0 && wider > 9)
            {
                for (i2 = 10; rechn2 != 1;)           // ZEHNER-STELLE
                {
                    rechn2 = wider / i2;
                    band2 = band2 + 1;
                    // printf("%d / %d = %d\n", wider, i2, rechn2);
                    wider = wider - 10;
                }
            }

            if (wider != 0)
            {
                for (i = 1; rechn1 != 1.0; i++)       // EINSER-STELLE
                {
                    rechn1 = wider / i;
                    band3 = band3 + 1;
                    // printf("%d / %f = %f\n", wider, i, rechn1);
                }
            }
        }
        else if (wider == 1000)
        {
            band1 = 1;
            band4 = 10;
        }
        else                                  // BIS N
        {
            for (i2 = 1000; wider >= 1000;)              // MULTIPLIER
            {
                band4 = band4 + 10;
                wider = wider - 1000;
            }

            if (band4 < 10)           // MULTIPLIER BESTIMMEN
            {
                multi = 1;
            }
            else if (band4 < 100)
            {
                multi = 10;
            }
            else if (band4 < 1000)
            {
                multi = 100;
            }
            else if (band4 < 10000)
            {
                multi = 1000;
            }
            else if (band4 < 100000)
            {
                multi = 10000;
            }
            else if (band4 < 1000000)
            {
                multi = 100000;
            }
            else if (band4 < 10000000)
            {
                multi = 1000000;
            }
            else if (band4 < 100000000)       // UNTER 100 MILLIONEN
            {
                multi = 10000000;             // 10 MILLIONEN
            }

            wider = wider2;

            for (; wider >= 100 * multi;)              // HUNDERTER-STELLE
            {
                wider = wider - 100 * multi;
                band1 = band1 + 1;
            }

            if (wider >= 100)
            {
                for (; wider >= 10 * multi;)           // ZEHNER-STELLE
                {
                    wider = wider - 10 * multi;
                    band2 = band2 + 1;
                }
            }

            if (wider >= 10)
            {
                for (; wider >= 1 * multi;)       // EINSER-STELLE
                {
                    wider = wider - 1 * multi;
                    band3 = band3 + 1;
                }
            }
        }

        // FARBZUWEISUNGEN

        if (band1 == 0)           // BAND 1
        {
            printf("BLACK - ");
        }
        else if (band1 == 1)
        {
            printf("BROWN - ");
        }
        else if (band1 == 2)
        {
            printf("RED - ");
        }
        else if (band1 == 3)
        {
            printf("ORANGE - ");
        }
        else if (band1 == 4)
        {
            printf("YELLOW - ");
        }
        else if (band1 == 5)
        {
            printf("GREEN - ");
        }
        else if (band1 == 6)
        {
            printf("BLUE - ");
        }
        else if (band1 == 7)
        {
            printf("VIOLET - ");
        }
        else if (band1 == 8)
        {
            printf("GREY - ");
        }
        else if (band1 == 9)
        {
            printf("WHITE - ");
        }

        if (band2 == 0)           // BAND 2
        {
            printf("BLACK - ");
        }
        else if (band2 == 1)
        {
            printf("BROWN - ");
        }
        else if (band2 == 2)
        {
            printf("RED - ");
        }
        else if (band2 == 3)
        {
            printf("ORANGE - ");
        }
        else if (band2 == 4)
        {
            printf("YELLOW - ");
        }
        else if (band2 == 5)
        {
            printf("GREEN - ");
        }
        else if (band2 == 6)
        {
            printf("BLUE - ");
        }
        else if (band2 == 7)
        {
            printf("VIOLET - ");
        }
        else if (band2 == 8)
        {
            printf("GREY - ");
        }
        else if (band2 == 9)
        {
            printf("WHITE - ");
        }

        if (band3 == 0)           // BAND 3
        {
            printf("BLACK - ");
        }
        else if (band3 == 1)
        {
            printf("BROWN - ");
        }
        else if (band3 == 2)
        {
            printf("RED - ");
        }
        else if (band3 == 3)
        {
            printf("ORANGE - ");
        }
        else if (band3 == 4)
        {
            printf("YELLOW - ");
        }
        else if (band3 == 5)
        {
            printf("GREEN - ");
        }
        else if (band3 == 6)
        {
            printf("BLUE - ");
        }
        else if (band3 == 7)
        {
            printf("VIOLET - ");
        }
        else if (band3 == 8)
        {
            printf("GREY - ");
        }
        else if (band3 == 9)
        {
            printf("WHITE - ");
        }

        if (band4 < 10)           // BAND 4
        {
            printf("BLACK");
        }
        else if (band4 < 100)
        {
            printf("BROWN");
        }
        else if (band4 < 1000)
        {
            printf("RED");
        }
        else if (band4 < 10000)
        {
            printf("ORANGE");
        }
        else if (band4 < 100000)
        {
            printf("YELLOW");
        }
        else if (band4 < 1000000)
        {
            printf("GREEN");
        }
        else if (band4 < 10000000)
        {
            printf("BLUE");
        }
        else if (band4 < 10000000)
        {
            printf("VIOLET");
        }

        getchar();

        printf_s("\n\n\n");

    }
}
