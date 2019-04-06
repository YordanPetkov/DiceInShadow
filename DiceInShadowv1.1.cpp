#include<iostream>
#include<cstdlib>
#include<string>
#include <time.h>
#include <ctime>
using namespace std;
int a[7],bra[7],b[7],brb[7],c[7],brc[7],d[7],brd[7],zalozi[25][10],plizbor,pas[5],poslzalbr,poslzalz,vuzmzalog[8],posledniqigral=4,poslzaligr[5][4],f=4,s=4,t=4,l=4,all[7];

bool role()
{
    cout<<"Ako iska6 da zapo4ne6 igra kato 1 igra4 napi6i 1"<<endl;
    cout<<"Ako iska6 da zapo4ne6 igra kato 2 igra4 napi6i 2"<<endl;
    cout<<"Ako iska6 da zapo4ne6 igra kato 3 igra4 napi6i 3"<<endl;
    cout<<"Ako iska6 da zapo4ne6 igra kato 4 igra4 napi6i 4"<<endl;
    cout<<"Ako iska6 pravilata napi6i 5 "<<endl;
    cin>>plizbor;
    if(plizbor==1||plizbor==2||plizbor==3||plizbor==4)return 1;
    if(plizbor==5)
    {
        cout<<"Ima6 5 zara , robotite su6to imat po pet zara."<<endl;
        cout<<"Trqbva da zaloji6 kolko zara ot edna stoinost ima ob6to,"<<endl;
        cout<<"kato ima6 pravo da zaloji6 broi po-golqm ot broq na minaliq zalog ili"<<endl;
        cout<<"da zaloji6 stoinost na zar po-golqma ot stoinostta na minaliq zalog."<<endl;
        cout<<"PRIMER ako minaliq e zalojil 3 4  ( tri 4etvorki) "<<endl;
        cout<<"ti moje6 da zaloji6 broi po-golqm ot tri ili stoinost po-golqma ot 4etiri"<<endl;
        cout<<"naprimer moje6 da kaje6 3 5 ili 4 1 , no ne moje6 2 3 ( dve troiki)"<<endl;
        cout<<"Ako nqma kakvo da kaje6 ili iska6 da zapazi6 tvoq posleden zalog"<<endl;
        cout<<"moje6 da kaje6 pas toest da napishesh pas ."<<endl;
        cout<<"Uspeh , dano pobedi6 v igrata . ZABAVLQVAI SE :)"<<endl;
        role();

    }
    if(plizbor!=5)
        {
            cout<<"trqbva mejdu 1,2,3,4 i 5 ..."<<endl;
            role();
        }

}
void podrejdane(int first)
{
    if(s==first)
    {
        s=f;
        f=first;
    }

    if(t==first)
    {
        t=s;
        s=f;
        f=first;
    }

    if(l==first)
    {
        l=t;
        t=s;
        s=f;
        f=first;
    }
}
void populvanezalozi(int broi,int zar4e)
{
    for(int i=1;i<=broi;i++)
        for(int j=1;j<=zar4e;j++)
              {
                   zalozi[i][j]=1;
              }
         poslzalbr=broi;
         poslzalz=zar4e;
         for(int i=1;i<=zar4e;i++)
         {
             if(vuzmzalog[i]<broi)vuzmzalog[i]=broi;

         }

}
bool proverka(int broi,int zar4e)
{
    if(broi>20 || zar4e>6)return 0;
    if(zalozi[broi][zar4e]==1)return 0;
    if(zalozi[broi][zar4e]==0)return 1;
}

int player()
{
    if(pas[0]==1)return 0;
    if(posledniqigral==0)return 0;
    cout<<"Tvoite zar4eta sa : "<<endl;
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
    int vhodplbr,vhodplz;
    string zalpas;
    cout<<"Ako iska6 da vuvede6 zalog napi6i zalog: "<<endl;
    cout<<"Ako iska6 da si pas napi6i pas: "<<endl;
    cin>>zalpas;
    if(zalpas!="zalog" && zalpas!="pas"){cout<<"Ne si go napisal pravilno!"<<endl;player();}
    if(zalpas=="zalog")
    {
        cout<<"BROI : ";cin>>vhodplbr;
        cout<<"CHISLO : ";cin>>vhodplz;
        if(!proverka(vhodplbr,vhodplz)){cout<<"Tozi zalog ne e pozvolen , napravi drug!"<<endl;player();}
        populvanezalozi(vhodplbr,vhodplz);posledniqigral=0;
    poslzaligr[0][1]=vhodplbr;
    poslzaligr[0][2]=vhodplz;
    podrejdane(0);
    }
    if(zalpas=="pas")
    {
        pas[0]=1;
    }
    return 0;

}
int bot1()
{
    if(pas[1]==1)return 0;
    if(posledniqigral==1)return 0;
    for(int i=1;i<=poslzalz;i++)
    {
        if(brb[i]+2>poslzalbr)
            {
                if(proverka(brb[i]+2,i))
                {
                    populvanezalozi(brb[i]+2,i);
                    cout<<"Zalogut na BOT1 e : "<<brb[i]+2<<" "<<i<<endl;
                    posledniqigral=1;
                    poslzaligr[1][1]=brb[i]+2;
                    poslzaligr[1][2]=i;
                    podrejdane(1);
                    return 0;
                }


            }
    }
    for(int i=1;i<=6;i++)
    {
        if(brb[i]+2>vuzmzalog[i])
        {
            if(proverka(brb[i]+2,i))
                {
                    populvanezalozi(brb[i]+2,i);
                    cout<<"Zalogut na BOT1 e : "<<brb[i]+2<<" "<<i<<endl;
                    posledniqigral=1;
                    poslzaligr[1][1]=brb[i]+2;
                    poslzaligr[1][2]=i;
                    podrejdane(1);
                    return 0;
                }
        }
    }
    cout<<"Zalogut na BOT1 e : pas "<<endl;
    pas[1]=1;
    return 0;
}
int bot2()
{
    if(pas[2]==1)return 0;
    if(posledniqigral==2)return 0;
    for(int i=1;i<=poslzalbr;i++)
    {
        if(brc[poslzalz+1]>=i)
        {
            if(proverka(brc[poslzalz+1]+1,poslzalz+1))
                {
                    populvanezalozi(brc[poslzalz+1]+1,poslzalz+1);
                    cout<<"Zalogut na BOT2 e : "<<brc[poslzalz+1]+1<<" "<<poslzalz+1<<endl;
                    posledniqigral=2;
                    poslzaligr[2][1]=brc[poslzalz+1]+1;
                    poslzaligr[2][2]=poslzalz+1;
                    podrejdane(2);
                    return 0;
                }
        }
    }
    for(int i=1;i<=6;i++)
    {
        if(brc[i]>vuzmzalog[i])
        {
            if(proverka(brc[i],i))
                {
                    populvanezalozi(brc[i],i);
                    cout<<"Zalogut na BOT2 e : "<<brc[i]<<" "<<i<<endl;
                    posledniqigral=2;
                     poslzaligr[2][1]=brc[i];
                    poslzaligr[2][2]=i;
                    podrejdane(2);
                    return 0;
                }
        }
    }
    cout<<"Zalogut na BOT2 e : pas "<<endl;
    pas[2]=1;
    return 0;
}
int bot3()
{
    if(pas[3]==1)return 0;
    if(posledniqigral==3)return 0;
    for(int i=1;i<=poslzalz;i++)
    {
        if(brd[i]+3>poslzalbr)
            {
                if(proverka(brd[i]+3,i))
                {
                    populvanezalozi(brd[i]+3,i);
                    cout<<"Zalogut na BOT3 e : "<<brd[i]+3<<" "<<i<<endl;
                    posledniqigral=3;
                    poslzaligr[3][1]=brd[i]+3;
                    poslzaligr[3][2]=i;
                    podrejdane(3);
                    return 0;
                }


            }
    }
    for(int i=1;i<=6;i++)
    {
        if(brd[i]+3>vuzmzalog[i])
        {
            if(proverka(brd[i]+3,i))
                {
                    populvanezalozi(brd[i]+3,i);
                    cout<<"Zalogut na BOT3 e : "<<brd[i]+3<<" "<<i<<endl;
                    posledniqigral=3;
                    poslzaligr[3][1]=brd[i]+3;
                    poslzaligr[3][2]=i;
                    podrejdane(3);
                    return 0;
                }
        }
    }
    cout<<"Zalogut na BOT3 e : pas "<<endl;
    pas[3]=1;
    return 0;
}
int ple1()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=0;
    s=1;
    t=2;
    l=3;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {
        player();
        bot1();
        bot2();
        bot3();
        ple1();
    }
    return 0;


}
int ple2()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=1;
    s=0;
    t=2;
    l=3;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {

        bot1();
        player();
        bot2();
        bot3();
        ple2();
    }
    return 0;


}
int ple3()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=1;
    s=2;
    t=0;
    l=3;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {

        bot1();
        bot2();
        player();
        bot3();

        ple3();
    }
    return 0;


}
int ple4()
{

    if(pas[0]+pas[1]+pas[2]+pas[3]==3)return 0;
    cout<<endl;cout<<endl;cout<<endl;
    f=1;
    s=2;
    t=3;
    l=0;
    if(pas[0]+pas[1]+pas[2]+pas[3]<3)
    {

        bot1();
        bot2();
        bot3();
        player();
        ple4();
    }
    return 0;


}
void sumall()
{
    for(int i=1;i<=6;i++)
    {
        all[i]=bra[i]+brb[i]+brc[i]+brd[i];
        cout<<"VSI4KITE "<<i<<" sa "<<all[i]<<endl;
    }
}
int winner()
{
    sumall();
    if(poslzaligr[f][1]==all[poslzaligr[f][2]])
    {
        if(f==0)cout<<"BRAVO TI POBEDI :)"<<endl;
        else
            if(f<4)cout<<"BOT"<<f<<" POBEDI. TI ZAGUBI. PROBVAI OTNOVO :)"<<endl;
            return f;
    }

    if(poslzaligr[s][1]==all[poslzaligr[s][2]])
    {
        if(s==0)cout<<"BRAVO TI POBEDI :)"<<endl;
        else
           if(s<4) cout<<"BOT"<<s<<" POBEDI. TI ZAGUBI. PROBVAI OTNOVO :)"<<endl;
            return s;
    }

    if(poslzaligr[t][1]==all[poslzaligr[t][2]])
    {
        if(t==0)cout<<"BRAVO TI POBEDI :)"<<endl;
        else
            if(t<4)cout<<"BOT"<<t<<" POBEDI. TI ZAGUBI. PROBVAI OTNOVO :)"<<endl;
            return t;
    }

    if(poslzaligr[l][1]==all[poslzaligr[l][2]])
    {
        if(l==0)cout<<"BRAVO TI POBEDI :)"<<endl;
        else
        {
            if(l<4)cout<<"BOT"<<l<<" POBEDI. TI ZAGUBI. PROBVAI OTNOVO :)"<<endl;
            return l;
        }

    }
    return 4;
}
int main()
{
    cout<<"DiC v1.1"<<endl;
    int win;
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
    a[i] = rand()%6+1;
    b[i] = rand()%6+1;
    c[i] = rand()%6+1;
    d[i] = rand()%6+1;
    }
    for(int i=0;i<5;i++)
    {
        bra[a[i]]++;
        brb[b[i]]++;
        brc[c[i]]++;
        brd[d[i]]++;
    }

    role();
    if(plizbor == 1)ple1();
    if(plizbor == 2)ple2();
    if(plizbor == 3)ple3();
    if(plizbor == 4)ple4();
    cout<<"Posledniq ti zalog e : "<<poslzaligr[0][1]<<" "<<poslzaligr[0][2]<<endl;
    cout<<"Posledniq zalog na BOT1 e : "<<poslzaligr[1][1]<<" "<<poslzaligr[1][2]<<endl;
    cout<<"Posledniq zalog na BOT2 e : "<<poslzaligr[2][1]<<" "<<poslzaligr[2][2]<<endl;
    cout<<"Posledniq zalog na BOT3 e : "<<poslzaligr[3][1]<<" "<<poslzaligr[3][2]<<endl;

    cout<<"Tvoite zar4eta sa : "<<endl;
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
        cout<<"Zar4etata na BOT1 sa :"<<endl;
        cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;
        cout<<"Zar4etata na BOT2 sa :"<<endl;
        cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<endl;
        cout<<"Zar4etata na BOT3 sa :"<<endl;
        cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<" "<<d[4]<<endl;
        cout<<endl;cout<<endl;cout<<endl;cout<<endl;

    win=winner();

    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    if(win==0)cout<<"$$$$$$$$$$$$$$$ YOU WIN $$$$$$$$$$$$$$$"<<endl;
    if(win==1||win==2||win==3)cout<<"*************** YOU LOSE ***************"<<endl;
    if(win==4)cout<<"*************** DRAW ***************"<<endl;
     cout<<endl;cout<<endl;cout<<endl;cout<<endl;

return 0;
}
