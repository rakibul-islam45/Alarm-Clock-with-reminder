#include <bits/stdc++.h>
#include <graphics.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <dos.h>
#include <windows.h>



using namespace std;

string s;
void graphics_clok(int zz,int choice); //Initialize graphics
int main();

class clok
{
private:
    int hh,mm,ss;

public:
    void get();  //input
    void display();
    int pass(tm *a,clok c1);
    void alarm(clok &c,int choice);
};

void clok::get()
{
e:
    cin>>hh>>mm>>ss;
    if(((hh>23)&&(hh<0))||((mm>59)&&(mm<0))||((ss>59)&&(ss<0)))
    {
        cout<<"\n You have entered invalid time ";
        cout<<"\n Please try again";
        goto e;
    }

}

void clok::display()
{
    cout<<"Alarm time: "<<hh<<":"<<mm<<":"<<ss;
}
int clok::pass(tm *a,clok c1)
{
    hh = a->tm_hour;
    mm = a->tm_min;
    ss = a->tm_sec;


    //validation check
    if(hh>c1.hh) return 0;
    if(hh==c1.hh && mm > c1.mm) return 0;
    if(hh==c1.hh && mm == c1.mm && ss>c1.ss) return 0;
    return 1;
}


void clok::alarm(clok &c,int choice)
{
    clok d;
    long int e;
    int i,j;
    d.hh = hh-c.hh;
    d.mm = mm-c.mm;
    d.ss = ss-c.ss;
    e = (d.hh*3600)+(d.mm*60)+(d.ss);

    graphics_clok(e,choice);


}

int proc(int choice,clok z)
{
    if(choice==1)
    {
        int a;
        clok c1,c2;
        time_t t;
        tm *area;
        system("cls");

        time(&t);
        area = localtime(&t);
        system("cls");
        cout<<"\nCurrent time is: "<<asctime(area);
        cout<<"\n Set the time of alarm'(hh mm ss)': ";
        c1.get();
        int x = c2.pass(area,c1);

        if(x==0)
        {
            cout<<"Invalid time"<<endl;
            getch();
            return 1;

        }
        c1.display();
        c1.alarm(c2,choice);
        getch();
    }
    else
    {
        clok c2;
        tm *area;
        system("cls");
        time_t t;
        time(&t);
        area = localtime(&t);

        z.display();
        int x =c2.pass(area,z);
        if(x==0) cout<<endl<<"Invalid Time"<<endl;
        else
        {
            // z.display();
            z.alarm(c2,choice);
        }
        getch();
        main();
    }

    return 0;
}

void graphics_clok(int zz,int choice)
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "\tc\bgi");



    int coordsForHourX[12] = {50, 87, 100, 87, 50, 0, -50, -87, -100, -87, -50, 0};
    int coordsForHourY[12] = {-87, -50, 0, 50, 87, 100, 87, 50, 0, -50, -87, -100};



    int coordsForMinSecX[60] = {0, 18, 35, 53, 69, 85, 100, 114, 126, 138,
                                147, 155, 162, 166, 169, 170, 169, 166, 162, 155,
                                147, 138, 126, 114, 100, 85, 69, 53, 35, 18,
                                0, -18, -35, -53, -69, -85, -100, -114, -126, -138,
                                -147, -155, -162, -166, -169, -170, -169, -166, -162, -155,
                                -147, -138, -126, -114, -100, -85, -69, -53, -35, -18
                               };
    int coordsForMinSecY[60] = {-170, -169, -166, -162, -155, -147, -138, -126, -114, -100,
                                -85, -69, -53, -35, -18, 0, 18, 35, 53, 69,
                                85, 100, 114, 126, 138, 147, 155, 162, 166, 169,
                                170, 169, 166, 162, 155, 147, 138, 126, 114, 100,
                                85, 69, 53, 35, 18, 0, -18, -35, -53, -69,
                                -85, -100, -114, -126, -138, -147, -155, -162, -166, -169
                               };


    //Time variable

    time_t rawtime;
    struct tm *currentTime;
    char a[100];


    int midX = getmaxx()/2;
    int midY = getmaxy()/2;


    int IMS;
    int coun = 0;
    while(1)
    {



        rawtime = time(NULL);
        currentTime = localtime(&rawtime);
        // circle
        setcolor(WHITE);
        circle(midX, midY, 200);

        //Position
        outtextxy(midX+95+(-5), midY-165+(-5), "1");
        outtextxy(midX+165+(-5), midY-95+(-5), "2");
        outtextxy(midX+190+(-5), midY+0+(-7), "3");
        outtextxy(midX+165+(-7), midY+95+(-7), "4");
        outtextxy(midX+95+(-5), midY+165+(-10), "5");
        outtextxy(midX+0+(-3), midY+190+(-10), "6");
        outtextxy(midX-95+(0), midY+165+(-10), "7");
        outtextxy(midX-165+(-2), midY+95+(-10), "8");
        outtextxy(midX-190+(-3), midY+0+(-7), "9");
        outtextxy(midX-165+(-5), midY-95+(-3), "10");
        outtextxy(midX-95+(-5), midY-165+(-5), "11");
        outtextxy(midX+0+(-6), midY-190+(-5), "12");


        //time info converting integer
        strftime(a, 100, "%I", currentTime); //Convert hour
        sscanf(a, "%d", &IMS);
        setcolor(RED);
        line(midX, midY, midX+coordsForHourX[IMS-1], midY+coordsForHourY[IMS-1]);

        strftime(a, 100, "%M", currentTime); //Convert minute
        sscanf(a, "%d", &IMS);
        setcolor(YELLOW);
        line(midX, midY, midX+coordsForMinSecX[IMS], midY+coordsForMinSecY[IMS]);

        strftime(a, 100, "%S", currentTime); //Convert second
        sscanf(a, "%d", &IMS);
        setcolor(GREEN);
        line(midX, midY, midX+coordsForMinSecX[IMS], midY+coordsForMinSecY[IMS]);


        delay(700);
        if(coun==zz) break;
        cleardevice();
        coun++;


    }

    if(choice!=1)
    {
        cout<<endl<<endl<<"HERE IS THE REMINDER"<<endl<<s<<endl;
    }
    for(int i=0; i<4; i++)
    {
        cout<<"\n alarm!!!! \a\a";
        Beep(523,500);
        Beep(587,500);
        Beep(659,500);
        Beep(698,500);
        Sleep(1000);
    }
    cin.get();
    main();
    return ;
}

int remind()
{
    clok c;
    //  tm *a;
    int dd,mt,yy;
    int hh,mm,ss;
    int lhh,lmm,lss;
    int ldd,lmt,lyy;


    //Detect local time
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    lhh = ltm->tm_hour;
    lmm = ltm->tm_min;
    lss = ltm->tm_sec;

    lyy = 1900 + ltm->tm_year;
    lmt = 1 + ltm->tm_mon;
    ldd = ltm->tm_mday;

    cout<<"\nCurrent time is: "<<asctime(ltm);
    cout<<"Input a name of event"<<endl;
    cin>>s;
    cout<<"Input Date: day month year"<<endl;
    cin>>dd>>mt>>yy;
    cout<<"Input alarm time: hour minute second"<<endl;
    c.get();


    int i;
    while(1)
    {


        if(ldd==dd && lmt ==mt && yy==lyy)
        {
            proc(2,c);
        }
        else
        {
            Sleep(1000);
        }
    }

}

int main()
{

    system("cls");

    char choice;
    cout << "What do you want to do? \n(1)Set Alarm Now.\n(2)Set Alarm with Reminder.\n Enter the number"<< endl;
    cin >> choice;
Z:
    int l=1;
    int x;
    if(choice == '1')
    {

        clok a;
        x = proc(1,a);

    }

    else if(choice== '2')
    {
        x =remind();

    }
    else cout << "You've chosen neither";

    if(x==1) goto Z;
    return 0;
}


