#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>
#include <time.h>
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void main()
{
    char sendFrame[4], receivedFrame[4], b;
    int acknowledge[4];
    int i, j, noFrame, sent, totalSent = 0;
    
    printf("Enter the number of frames: ");
    scanf("%d", &noFrame);
    for (i = 0; i < noFrame; i++)
    {
        for (j = 0; j < 4; j++)
        {
            sendFrame[j] = '0' + rand() % 2;
        }
        printf("\n\nThe frame being sent is: %s", sendFrame);
    retrysend:
        for (j = 0; j < 4; j++)
        {
            if (rand() % 500 > 80)
            {
                acknowledge[j] = 1;
                receivedFrame[j] = sendFrame[j];
            }
            else
            {
                acknowledge[j] = 0;
                receivedFrame[j] = 'x';
            }
        }
        sent = 1;
        for (j = 0; j < 4; j++)
        {
            if (acknowledge[j] == 0)
                sent = 0;

            delay(40);
            printf("\nAcknowlegment for %d", j);
            printf("th bit was: %d", acknowledge[j]);
        }
        receivedFrame[4] = NULL;
        printf("\nThe frame received was:%s ", receivedFrame);
        if (sent == 1)
        {
            printf("\nThe frame sent was sent successfully ");
            getch();
        }
        else
        {
            printf("\nThe frame was not sent!");
        }
        if (sent == 0)
        {
            printf("\nDo you want to retry sending frame (y/n) ");
            scanf("%c", &b);
            if (b == 'y' || b == 'Y')
                goto retrysend;
        }
        if (sent == 1)
            totalSent++;
    }
    printf("\n\nTotal Frames to be sent: %d", noFrame);
    printf("\nTotal Frames sent successfully:%d ", totalSent);
    getch();
}