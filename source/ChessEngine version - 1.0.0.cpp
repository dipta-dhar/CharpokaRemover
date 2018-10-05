/**
 *      A Simple Chess Engine
 *
 *       author: dipta
 *      created: 10-Feb-2015 02:11:20
**/


#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<graphics.h>

char BOard_SEt[8][8] = {{'R','N','B','Q','K','B','N','R'},  {'P','P','P','P','P','P','P','P'},
                        {'\0','\0','\0','\0','\0','\0','\0','\0'},    {'\0','\0','\0','\0','\0','\0','\0','\0'},
                        {'\0','\0','\0','\0','\0','\0','\0','\0'},    {'\0','\0','\0','\0','\0','\0','\0','\0'},
                        {'p','p','p','p','p','p','p','p'},  {'r','n','b','q','k','b','n','r'}};

void BOard();
void NEw_GAme();
void MOve();
void position(int,int, int,int,  int);
char* COnvert_STring(int, int);

int main()
{
    initwindow(1365, 748);

    BOard();
    NEw_GAme();
    MOve();

    getch();
    return 0;
}

char* COnvert_STring(int x, int y)
{
    char a[20];
    a[0] = BOard_SEt[y-1][x];
    if(a[0]>='a' && a[0]<='z')  a[0] -=32;
    a[1] = '\0';
    return a;
}

void position(int x1,int y1,  int x2, int y2,  int COLor)
{
    if((x1+y1)%2==0)
    {
        setcolor(WHITE);    ///DELETE FIRST POSITION
        setlinestyle(0, 10, 26);
        circle((153 + 67*x1),(673 - y1*67), 14);
    }
    else
    {
        setcolor(BLACK);    ///DELETE FIRST POSITION
        setlinestyle(0, 10, 26);
        circle((153 + 67*x1),(673 - y1*67), 14);
    }
    if((x2+y2)%2 == 0)
    {
        setcolor(WHITE);    ///DELETE SECOND POSITION
        setlinestyle(0, 10, 26);
        circle((153 + 67*x2),(673 - y2*67), 14);
    }
    else
    {
        setcolor(BLACK);    ///DELETE SECOND POSITION
        setlinestyle(0, 10, 26);
        circle((153 + 67*x2),(673 - y2*67), 14);
    }
    if(COLor==0){
        setcolor(YELLOW);
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
        outtextxy((140 + 67*x2),(655 - y2*67), COnvert_STring(x2, y2));}
    else{
        setcolor(GREEN);
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
        outtextxy((140 + 67*x2),(655 - y2*67), COnvert_STring(x2, y2));}
}

void MOve()
{
    char con[100];
    int a, b, c, d, E,COlor_1, gap=0,count=0, dif=270;

    outtextxy(760, 50, "MOve LIke: d2d4");
    outtextxy(760, 100, "[4 LEtter, ONly LOwer CAse]");
    outtextxy(760, 150, "[exit] == EXit GAme");

    while(1){

        E=0;
        sprintf(con ,"ENter MOves [%2d]: ",++count);

        outtextxy(760, 230, con);


        con[0] = getch();   con[1]='\0';    a=con[0]-'a';       outtextxy(760, dif, con);
        con[0] = getch();   con[1]='\0';    b=con[0]-'1';       outtextxy(760+25, dif, con);
        con[0] = getch();   con[1]='\0';    c=con[0]-'a';       outtextxy(760+50, dif, con);
        con[0] = getch();   con[1]='\0';    d=con[0]-'1';       outtextxy(760+75, dif, con);


        getch();

        dif+=50;

        if(dif>650) {   gap=1;   dif=270; }

        if(gap==1)
        {
            for(int i=0; i<30; i++)     con[i]=' ';
            con[30]='\0';

            outtextxy(760, dif, con);
        }

        if(BOard_SEt[b][a]>= 'a' && BOard_SEt[b][a]<='z')   E=1;
        BOard_SEt[d][c] = BOard_SEt[b][a];
        BOard_SEt[b][a] = '\0';

        E==1 ? COlor_1=1 : COlor_1=0;

        position(a,b+1, c,d+1,  COlor_1);
    }
}

void NEw_GAme()
{
    setcolor(GREEN);
    int i,x1,x2,y1,y2;
    x1=120, y1=119;
    settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
    outtextxy(x1+=17,  y1, "R");    outtextxy(x1+=67,  y1, "N");    outtextxy(x1+=67,  y1, "B");
    outtextxy(x1+=67,  y1, "Q");    outtextxy(x1+=67,  y1, "K");    outtextxy(x1+=67,  y1, "B");
    outtextxy(x1+=67,  y1, "N");    outtextxy(x1+=67,  y1, "R");
    x1=120, y1=186;
    outtextxy(x1+=20,  y1, "P");    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");
    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");
    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");

    x1=120, y1=521;   setcolor(YELLOW);
    outtextxy(x1+=20,  y1, "P");    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");
    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");
    outtextxy(x1+=67,  y1, "P");    outtextxy(x1+=67,  y1, "P");
    x1=120, y1=588;
    outtextxy(x1+=17,  y1, "R");    outtextxy(x1+=67,  y1, "N");    outtextxy(x1+=67,  y1, "B");
    outtextxy(x1+=67,  y1, "Q");    outtextxy(x1+=67,  y1, "K");    outtextxy(x1+=67,  y1, "B");
    outtextxy(x1+=67,  y1, "N");    outtextxy(x1+=67,  y1, "R");

}

void BOard()
{
    int i,j,x1,x2,y1,y2,c;
    setcolor(9);
    setlinestyle(0, 10, 15);
    rectangle(112, 96, 663, 647);
    x1=120, y1=104, x2=187, y2=171;
    for(i=c=0; i<8; i++)
    {
        if(c%2 == 0)
            for(j=0; j<8; j++)
            {
                if(j%2==0)
                    bar(x1, y1,  x2,y2);

                x1 += 67,   x2 += 67;
            }
        else
            for(j=0; j<8; j++)
            {
                if(j%2 != 0)
                    bar(x1, y1,  x2,y2);

                x1 += 67,   x2 += 67;
            }
        y1 += 67,   y2 += 67,   x1 = 120,    x2 = 187;
        c++;
    }
    settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
    x1=60,y1=50, y2=67;                   /// LEFT SIDE NUMBER  Y axis
    outtextxy(x1,  y1+=y2, "8");    outtextxy(x1,  y1+=y2, "7");    outtextxy(x1,  y1+=y2, "6");
    outtextxy(x1,  y1+=y2, "5");    outtextxy(x1,  y1+=y2, "4");    outtextxy(x1,  y1+=y2, "3");
    outtextxy(x1,  y1+=y2, "2");    outtextxy(x1,  y1+=y2, "1");
    x1=690,y1=50, y2=67;                  /// RIGHT SIDE NUMBER Y axis
    outtextxy(x1,  y1+=y2, "8");    outtextxy(x1,  y1+=y2, "7");    outtextxy(x1,  y1+=y2, "6");
    outtextxy(x1,  y1+=y2, "5");    outtextxy(x1,  y1+=y2, "4");    outtextxy(x1,  y1+=y2, "3");
    outtextxy(x1,  y1+=y2, "2");    outtextxy(x1,  y1+=y2, "1");
    x1=120, y1=45;                        /// TOP SIDE NUMARIC VALUE X axis
    outtextxy(x1+=17,  y1, "a");    outtextxy(x1+=67,  y1, "b");    outtextxy(x1+=67,  y1, "c");
    outtextxy(x1+=67,  y1, "d");    outtextxy(x1+=67,  y1, "e");    outtextxy(x1+=67,  y1, "f");
    outtextxy(x1+=67,  y1, "g");    outtextxy(x1+=67,  y1, "h");
    x1=120, y1=660;                        /// BOTTOM SIDE NUMARIC VALUE X axis
    outtextxy(x1+=17,  y1, "a");    outtextxy(x1+=67,  y1, "b");    outtextxy(x1+=67,  y1, "c");
    outtextxy(x1+=67,  y1, "d");    outtextxy(x1+=67,  y1, "e");    outtextxy(x1+=67,  y1, "f");
    outtextxy(x1+=67,  y1, "g");    outtextxy(x1+=67,  y1, "h");
    setcolor(8);       ///  OUTSIDE RECTANGLE
    setlinestyle(0, 10, 15);
    rectangle(42, 30, 730, 710);

}


