#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>




//class for storing coordinates of circles where players will move
class Position
{
private:
    int x,y;

public:
    void setcoord(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    void display(int b)
    {
        setcolor(8);
        circle(x,y,10);
        if(b==1)
        {
            setfillstyle(SOLID_FILL,RED);
            floodfill(x,y,8);
        }
        if(b==2)
        {
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(x,y,8);
        }
        if(b==3)
        {
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(x,y,8);
        }
        if(b==4)
        {
            setfillstyle(SOLID_FILL,BLUE);
            floodfill(x,y,8);
        }
    }
};

//class for player with required properties
class Player
{
private:
    Position pos;//player has attribute of type class Position

public:
    int posindex;
    int status;
    int homeway;

    Player()
    {
        status=0;
        homeway=0;
    }

    void setposition(int pindex,Position p)
    {
        posindex=pindex;
        pos=p;
    }

    void display(int b)
    {
        pos.display(b);
    }

};

//create board interface before player gets displayed
void showboard()
{
    int i,x=0,y=465,d=6*31;
    // setbkcolor(7);
    setcolor(8);

    for(i=0; i<=y-x; i+=31)
    {
        line(x+i,x,x+i,y);
        line(x,x+i,y,x+i);
    }

    setfillstyle(SOLID_FILL,RED);
    int sqa[]= {x,x,d,x,d,d,x,d,x,x};
    fillpoly(5,sqa);
    setfillstyle(SOLID_FILL,WHITE);
    int n[]= {31,31,d-31,31,d-31,d-31,31,d-31,31,31};
    fillpoly(5,n);
    setfillstyle(SOLID_FILL,LIGHTRED);
    int red[]= {x+62,x+d,x+62,x+d+31,x+d,x+d+31,x+d,x+d,x+d+46,x+d+46,x+d,x+d+93,x+d,x+d+62,x+31,x+d+62,x+31,x+d,x+62,x+d};
    fillpoly(10,red);

    setfillstyle(SOLID_FILL,YELLOW);
    int ny[]= {y,x,y,x+d,y-d,x+d,y-d,x,y,x};
    fillpoly(5,ny);
    setfillstyle(SOLID_FILL,WHITE);
    int sw[]= {y-d+31,31,y-31,31,y-31,d-31,y-d+31,d-31,y-d+31,31};
    fillpoly(5,sw);
    setfillstyle(SOLID_FILL,YELLOW);
    int yellow[]= {y-d,x+62,y-d-31,x+62,y-d-31,x+d,y-d,x+d,y-d-46,x+d+46,y-d-93,x+d,y-d-62,x+d,y-d-62,x+31,y-d,x+31,y-d,x+62};
    fillpoly(10,yellow);

    setfillstyle(SOLID_FILL,GREEN);
    int nb[]= {y,y,y-d,y,y-d,y-d,y,y-d,y,y};
    fillpoly(5,nb);
    setfillstyle(SOLID_FILL,WHITE);
    int gw[]= {y-d+31,y-d+31,y-31,y-d+31,y-31,y-31,y-d+31,y-31,y-d+31,y-d+31};
    fillpoly(5,gw);
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    int green[]= {y-62,y-d,y-62,y-d-31,y-d,y-d-31,y-d,y-d,y-d-46,y-d-46,y-d,y-d-93,y-d,y-d-62,y-31,y-d-62,y-31,y-d,y-62,y-d};
    fillpoly(10,green);

    setfillstyle(SOLID_FILL,BLUE);
    int ob[]= {x,y,x,y-d,x+d,y-d,x+d,y,x,y};
    fillpoly(5,ob);
    setfillstyle(SOLID_FILL,WHITE);
    int wbb[]= {31,y-d+31,d-31,y-d+31,d-31,y-31,31,y-31,31,y-d+31};
    fillpoly(5,wbb);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    int blue[]= {d,y-62,x+d+31,y-62,x+d+31,y-d,x+d,y-d,x+d+46,y-d-46,x+d+93,y-d,x+d+62,y-d,x+d+62,y-31,x+d,y-31,x+d,y-62};
    fillpoly(10,blue);
    setfillstyle(SOLID_FILL,15);
    int sa[]= {y,0,y+171,0,y+171,y+5,y,y+5,y,0};
    fillpoly(5,sa);

    line(x+62,x+d+62,x+93,x+d+93);
    line(x+93,x+d+62,x+62,x+d+93);

    line(x+d,x+62,x+d+31,x+93);
    line(x+d+31,x+62,x+d,x+93);

    line(y-62,x+d,y-62-31,x+d+31);
    line(y-62,x+d+31,y-62-31,x+d);

    line(y-d,y-62,y-d-31,y-62-31);
    line(y-d,y-62-31,y-d-31,y-62);
    setcolor(6);
    line(x+31,d,x+62,d);
    line(x+31,d+31,x+62,d+31);
    line(d+62,31,d+62,62);
    line(y-d-31,31,y-d-31,62);
    line(y-d,31,y-d,62);
    line(y-62,y-d-31,y-31,y-d-31);
    line(y-62,y-d,y-31,y-d);
    line(d,y-62,d,y-31);
    line(d+31,y-62,d+31,y-31);



}


//save all the circle coordinates where player can move to an array of object of class Position
void initializecoords(Position p[])
{
    int x=0,y=465,d=6*31,h=0,i,j;
    j=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+15+h,x+d+15);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+d+15,x+d-15-h);
        h+=31;
    }
    p[j++].setcoord(x+d+46,x+15);
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+d+77,x+15+h);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(y-d+15+h,x+d+15);
        h+=31;
    }
    p[j++].setcoord(y-15,x+d+46);
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(y-15-h,y-d-15);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(y-d-15,y-d+15+h);
        h+=31;
    }
    p[j++].setcoord(y-d-46,y-15);
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+d+15,y-15-h);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+d-15-h,y-d-15);
        h+=31;
    }
    p[j++].setcoord(x+15,y-d-46);
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+46+h,x+d+46);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+d+46,x+46+h);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(y-46-h,x+d+46);
        h+=31;
    }
    h=0;
    for(i=0; i<6; i++)
    {
        p[j++].setcoord(x+d+46,y-46-h);
        h+=31;
    }
}


//save circle coordinates for initial position of player inside center of 4 big squares (i.e; before player is unlocked)
void initializecoords2(Position pi[])
{
//   int x=0,y=465,d=6*31,i,j;
    pi[0].setcoord(62,62);
    pi[1].setcoord(124,62);
    pi[2].setcoord(62,124);
    pi[3].setcoord(124,124);
    pi[4].setcoord(341,62);
    pi[5].setcoord(403,62);
    pi[6].setcoord(341,124);
    pi[7].setcoord(403,124);
    pi[8].setcoord(341,341);
    pi[9].setcoord(403,341);
    pi[10].setcoord(341,403);
    pi[11].setcoord(403,403);
    pi[12].setcoord(62,341);
    pi[13].setcoord(124,341);
    pi[14].setcoord(62,403);
    pi[15].setcoord(124,403);
}


//initialize players to initial positions defined by above function and set status to 1 for players depending upon value of n(no. of players choosen in game)
void initializeplayer(Player red[],Player yellow[],Player green[],Player blue[],Position pi[],int n)
{
    if(n==2)
    {
        for(int c=0; c<4; c++)
        {
            red[c].setposition(-1,pi[c]);
            red[c].status=1;
            yellow[c].setposition(-1,pi[c+4]);
            yellow[c].status=1;
        }
    }
    else if(n==3)
    {

        for(int c=0; c<4; c++)
        {
            red[c].setposition(-1,pi[c]);
            red[c].status=1;
            yellow[c].setposition(-1,pi[c+4]);
            yellow[c].status=1;
            green[c].setposition(-1,pi[c+8]);
            green[c].status=1;
        }

    }
    else
    {

        for(int c=0; c<4; c++)
        {
            red[c].setposition(-1,pi[c]);
            red[c].status=1;
            yellow[c].setposition(-1,pi[c+4]);
            yellow[c].status=1;
            green[c].setposition(-1,pi[c+8]);
            green[c].status=1;
            blue[c].setposition(-1,pi[c+12]);
            blue[c].status=1;

        }
    }
}


//display all the players which are active
void displayplayer(Player red[],Player yellow[],Player green[],Player blue[])
{
    int i;
    for(i=0; i<4; i++)
    {
        if(red[i].status==1)
        {
            red[i].display(1);
        }
        if(yellow[i].status==1)
        {
            yellow[i].display(2);
        }
        if(green[i].status==1)
        {
            green[i].display(3);
        }
        if(blue[i].status==1)
        {
            blue[i].display(4);
        }
    }

}

//main logic of rolling a dice for each player turn
void rolldice(Player red[], Player yellow[], Player green[], Player blue[], Position p[], Position pi[], int turn)
{
    setcolor(0);
    int x=0,y=465,i,j,k;
    char  *name;

    if(turn==1)
    {
        name="Red";
    }
    if(turn==2)
    {
        name="Yellow";
    }
    if(turn==3)
    {
        name="Green";
    }
    if(turn==4)
    {
        name="Blue";
    }
    setcolor(0);
    outtextxy(y+10,x+10,"Press Enter to roll...");
    outtextxy(y+45,x+40,"Turn: ");
    outtextxy(y+90,x+40,name);
    outtextxy(y+10,y-10,"Press Esc to exit");

    char ch1;
    char ch2;

    char ch;
    while(1)
    {
        ch=getch();
        if(ch==27 || ch==13)
            break;
    }
    if(ch==27) //exit if player presses Escape key
    {
        exit(0);
    }
    if(ch==13) //execute if player presses Enter key
    {
        char roll[1];
        time_t t;
        srand((unsigned) time(&t));//for generating random number based on time
        int n=rand()%6+1;
        itoa(n,roll,10);

        outtextxy(y+40,x+100,"You rolled:");
        outtextxy(y+130,x+100,roll);


        if((turn==1 && red[0].posindex==-1)||(turn==1 && red[1].posindex==-1)||(turn==1 && red[2].posindex==-1)||(turn==1 && red[3].posindex==-1)||(turn==2 && yellow[0].posindex==-1)||(turn==2 && yellow[1].posindex==-1)||(turn==2 && yellow[2].posindex==-1)||(turn==2 && yellow[3].posindex==-1)||(turn==3 && green[0].posindex==-1)||(turn==3 && green[1].posindex==-1)||(turn==3 && green[2].posindex==-1)||(turn==3 && green[3].posindex==-1)||(turn==4 && blue[0].posindex==-1)||(turn==4 && blue[1].posindex==-1)||(turn==4 && blue[2].posindex==-1)||(turn==4 && blue[3].posindex==-1))
        {
            //for initial 1 to unlock player

            if(turn==1 && n==1)
            {
                outtextxy(y+20,x+200,"PICK UP THE TOKEN");

                while(1)
                {

                    ch1=getch();
                    break;
                }
                int k=49;
                for(int v=0;v<4;v++)
                {
                    if(ch1==k)
                {


                    red[v].posindex=1;
                    red[v].setposition(1,p[1]);
                }
                k++;
                }}

            if(turn==2 && n==1)
            {
                outtextxy(y+40,x+200,"PICK UP THE TOKEN");
                while(1)
                {
                    ch1=getch();
                    break;
                }
                int k=49;
                for(int v=0;v<4;v++)
                {
                if(ch1==k)
                {
                    yellow[v].posindex=14;
                    yellow[v].setposition(14,p[14]);

                }
                k++;
                }}



            if(turn==3 && n==1)
            {
                outtextxy(y+40,x+200,"PICK UP THE TOKEN");
                while(1)
                {


                    ch1=getch();
                    break;
                }
                int k=49;
                for(int v=0;v<4;v++)
                {
                    if (ch1==k)
                {
                    green[v].posindex=27;
                    green[v].setposition(27,p[27]);
                }
                k++;
                }}

            if(turn==4 && n==1)
            {
                outtextxy(y+40,x+200,"PICK UP THE TOKEN");
                while(1)
                {

                    ch1=getch();
                    break;
                }
                int k=49;
                for(int v=0;v<4;v++)
                {

                if(ch1==k)
                {

                    blue[v].posindex=40;
                    blue[v].setposition(40,p[40]);
                }k++;}}



            delay(100);
            cleardevice();
            showboard();
            displayplayer(red,yellow,green,blue);


        }


        if((((turn==1&&red[0].homeway!=1)||(turn==1&&red[0].homeway==1&&red[0].posindex+n<=57)||
                (turn==1&&red[1].homeway!=1)||(turn==1&&red[1].homeway==1&&red[1].posindex+n<=57)||
                (turn==1&&red[2].homeway!=1)||(turn==1&&red[2].homeway==1&&red[2].posindex+n<=57)||
                (turn==1&&red[3].homeway!=1)||(turn==1&&red[3].homeway==1&&red[3].posindex+n<=57))&&(red[0].posindex!=-1
                        ||red[1].posindex!=-1
                        ||red[2].posindex!=-1
                        ||red[3].posindex!=-1))||
                (((turn==2&&yellow[0].homeway!=1)||(turn==2&&yellow[0].homeway==1&&yellow[0].posindex+n<=63)||
                  (turn==2&&yellow[1].homeway!=1)||(turn==2&&yellow[1].homeway==1&&yellow[1].posindex+n<=63)||
                  (turn==2&&yellow[2].homeway!=1)||(turn==2&&yellow[2].homeway==1&&yellow[2].posindex+n<=63)||
                  (turn==2&&yellow[3].homeway!=1)||(turn==2&&yellow[3].homeway==1&&yellow[3].posindex+n<=63))&&(yellow[0].posindex!=-1
                          ||yellow[1].posindex!=-1
                          ||yellow[2].posindex!=-1
                          ||yellow[3].posindex!=-1))||
                (((turn==3&&green[0].homeway!=1)||(turn==3&&green[0].homeway==1&&green[0].posindex+n<=69)||
                  (turn==3&&green[1].homeway!=1)||(turn==3&&green[1].homeway==1&&green[1].posindex+n<=69)||
                  (turn==3&&green[2].homeway!=1)||(turn==3&&green[2].homeway==1&&green[2].posindex+n<=69)||
                  (turn==3&&green[3].homeway!=1)||(turn==3&&green[3].homeway==1&&green[3].posindex+n<=69))&&(green[0].posindex!=-1
                          ||green[1].posindex!=-1
                          ||green[2].posindex!=-1
                          ||green[3].posindex!=-1))||
                (( (turn==4&&blue[0].homeway!=1)||(turn==4&&blue[0].homeway==1&&blue[0].posindex+n<=75)||
                   (turn==4&&blue[1].homeway!=1)||(turn==4&&blue[1].homeway==1&&blue[1].posindex+n<=75)||
                   (turn==4&&blue[2].homeway!=1)||(turn==4&&blue[2].homeway==1&&blue[2].posindex+n<=75)||
                   (turn==4&&blue[3].homeway!=1)||(turn==4&&blue[3].homeway==1&&blue[3].posindex+n<=75))&&(blue[0].posindex!=-1
                           ||blue[1].posindex!=-1
                           ||blue[2].posindex!=-1
                           ||blue[2].posindex!=-1)))//after player is unlocked
        {

            setcolor(8);
            outtextxy(y+45,x+40,"Turn: ");
            outtextxy(y+90,x+40,name);
            outtextxy(y+40,x+100,"You rolled:");
            outtextxy(y+130,x+100,roll);

            if(turn==1)
            {

                outtextxy(y+40,x+200,"PICK THE TOKEN");
                while(1)
                {
                    ch2=getch();
                    break;
                }
                for(i=0; i<n; i++)
                {

                    j=49;
                    for( int m=0; m<4; m++)
                    {
                        if(ch2==j)
                        {
                            if(red[0].posindex!=-1)
                            {


                                int index=red[m].posindex;
                                red[m].setposition(index+1,p[index+1]);
                                if(index==51)
                                {
                                    red[m].homeway=1;
                                }
                                if(index==56)
                                {
                                    red[m].status=0;
                                    delay(500);
                                    cleardevice();
                                    showboard();
                                    displayplayer(red,yellow,green,blue);
                                    return;
                                }
                            }
                        }

                        j++;
                    }
                }

            }
            if(turn==2)
            {
                outtextxy(y+40,x+200,"PICK THE TOKEN");
                while(1)
                {
                    ch2=getch();
                    break;
                }
                for(i=0; i<n; i++)
                {
                    j=49;
                    for (int m=0; m<4; m++)
                    {

                        if(ch2==j)
                        {
                            if(yellow[m].posindex!=-1)
                            {



                                int index=yellow[m].posindex;
                                if(index==51)
                                {
                                    index=-1;
                                }
                                if(index==12)
                                {
                                    index=57;
                                    yellow[m].homeway=1;
                                }
                                yellow[m].setposition(index+1,p[index+1]);
                                if(index==62)
                                {
                                    yellow[m].status=0;
                                    delay(100);
                                    cleardevice();
                                    showboard();
                                    displayplayer(red,yellow,green,blue);
                                    return;
                                }
                            }

                        }
                        j++;
                    }
                }
            }


            if(turn==3)
            {
                outtextxy(y+40,x+200,"PICK THE TOKEN");
                while(1)
                {
                    ch2=getch();
                    break;
                }
                for(i=0; i<n; i++)
                {
                    j=49;
                    for(int m=0; m<4; m++)
                    {
                        if(ch2==j)
                        {
                            if(green[m].posindex!=-1)
                            {





                                int index=green[m].posindex;
                                if(index==51)
                                {
                                    index=-1;
                                }
                                if(index==25)
                                {
                                    index=63;
                                    green[m].homeway=1;
                                }
                                green[m].setposition(index+1,p[index+1]);
                                if(index==68)
                                {
                                    green[m].status=0;
                                    delay(100);
                                    cleardevice();
                                    showboard();
                                    displayplayer(red,yellow,green,blue);
                                    return;
                                }
                            }
                        }
                        j++;
                    }
                }
            }


            if(turn==4)
            {
                outtextxy(y+40,x+200,"PICK THE TOKEN");
                while(1)
                {
                    ch2=getch();
                    break;
                }

                for(i=0; i<n; i++)
                {

                    j=49;
                    for(int m=0; m<4; m++)
                    {

                        if(ch2==j)
                        {
                            if(blue[m].posindex!=-1)
                            {


                                int index=blue[m].posindex;
                                if(index==51)
                                {
                                    index=-1;
                                }
                                if(index==38)
                                {
                                    index=69;
                                    blue[j].homeway=1;
                                }
                                blue[m].setposition(index+1,p[index+1]);
                                if(index==74)
                                {
                                    blue[m].status=0;
                                    delay(100);
                                    cleardevice();
                                    showboard();
                                    displayplayer(red,yellow,green,blue);
                                    return;
                                }
                            }
                        }
                        j++;
                    }
                }
            }

        }


    }
    int e=0,f=0;
    //cut player if two player has same position
    if(turn==1)
    {



        for(e=0; e<4; e++)
        {
            for(f=0; f<4; f++)
            {
                if(red[e].posindex==yellow[f].posindex)
                {
                    yellow[f].setposition(-1,pi[f+4]);
                    yellow[f].homeway=0;
                }
                if(red[e].posindex==green[f].posindex)
                {
                    green[f].setposition(-1,pi[f+8]);
                    green[f].homeway=0;
                }
                if(red[e].posindex==blue[f].posindex)
                {
                    blue[f].setposition(-1,pi[f+12]);
                    blue[f].homeway=0;
                }

            }
        }



    }

    if(turn==2)
    {
        for(e=0; e<4; e++)
        {
            for(f=0; f<4; f++)
            {
                if(yellow[e].posindex==red[f].posindex)
                {
                    red[f].setposition(-1,pi[f]);
                    red[f].homeway=0;
                }
                if(yellow[e].posindex==green[f].posindex)
                {
                    green[f].setposition(-1,pi[f+8]);
                    green[f].homeway=0;
                }
                if(yellow[e].posindex==blue[f].posindex)
                {
                    blue[f].setposition(-1,pi[f+12]);
                    blue[f].homeway=0;
                }

            }
        }


        //delay(500);
        //cleardevice();
        //showboard();
        //displayplayer(red,yellow,green,blue);
    }

    if(turn==3)
    {
        for(e=0; e<4; e++)
        {
            for(f=0; f<4; f++)
            {
                if(green[e].posindex==red[f].posindex)
                {
                    red[f].setposition(-1,pi[f]);
                    red[f].homeway=0;
                }
                if(green[e].posindex==yellow[f].posindex)
                {
                    yellow[f].setposition(-1,pi[f+4]);
                    yellow[f].homeway=0;
                }
                if(green[e].posindex==blue[f].posindex)
                {
                    blue[f].setposition(-1,pi[f+12]);
                    blue[f].homeway=0;
                }

            }
        }



    }
    if(turn==4)
    {
        for(e=0; e<4; e++)
        {
            for(f=0; f<4; f++)
            {
                if(blue[e].posindex==red[f].posindex)
                {
                    red[f].setposition(-1,pi[f]);
                    red[f].homeway=0;
                }
                if(blue[e].posindex==green[f].posindex)
                {
                    green[f].setposition(-1,pi[f+8]);
                    green[f].homeway=0;
                }
                if(blue[e].posindex==yellow[f].posindex)
                {
                    yellow[f].setposition(-1,pi[f+4]);
                    yellow[f].homeway=0;
                }

            }
        }



    }


    delay(500);
    cleardevice();
    showboard();
    displayplayer(red,yellow,green,blue);
}



//main function
void main()
{
    int gd=DETECT,gm,i,j,k,n;
    char ch;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");


    while(1)
    {
        cleardevice();
    outtextxy(100,170,"*Enter number of players(2,3,4) & press Enter key to play*");
        outtextxy(310,200,"_");
        ch=getch();
        if(ch==27)
        {
            exit(0);
        }
        if(ch==50||ch==51||ch==52)
        {
            if(ch==50)
            {
                outtextxy(310,190,"2");
                n=2;
            }
            if(ch==51)
            {
                outtextxy(310,190,"3");
                n=3;
            }
            if(ch==52)
            {
                outtextxy(310,190,"4");
                n=4;
            }
            while(1)
            {
                ch=getch();
                if(ch==13)
                {
                    break;
                }
                if(ch==27)
                {
                    exit(0);
                }
            }
            break;
        }
    }

    showboard();
    Position p[76];
    Position pi[16];
    initializecoords(p);
    initializecoords2(pi);

    Player red[4];
    Player yellow[4];
    Player green[4];
    Player blue[4];
    initializeplayer(red,yellow,green,blue,pi,n);
    displayplayer(red,yellow,green,blue);

    i=1;
    while(1)
    {
        if((i==1 && red[0].status==1)||(i==1 && red[1].status==1)||(i==1 && red[2].status==1)||(i==1 && red[3].status==1)||(i==2 && yellow[0].status==1)||(i==2 && yellow[1].status==1)||(i==2 && yellow[2].status==1)||(i==2 && yellow[3].status==1)||(i==3 && green[0].status==1)||(i==3 && green[1].status==1)||(i==3 && green[2].status==1)||(i==3 && green[3].status==1)||(i==4 && blue[0].status==1)||(i==4 && blue[1].status==1)||(i==4 && blue[2].status==1)||(i==4 && blue[3].status==1)) //execute rolldice for only active player
        {
            rolldice(red,yellow,green,blue,p,pi,i);
        }
        i++;
        if(i==5)
            i=1;
    }


}









