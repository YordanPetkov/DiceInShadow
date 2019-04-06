#include<iostream>
#include<cstdlib>
#include <time.h>
#include <ctime>
using namespace std;
int a[6],c[6],cb[7],f=0,pl=0,cbr=0,cz=0,plbr,plz,pas=0,t[6],posl=0,plp=0,cp=0;
bool role()
{
    cout<<"Ako iska6 da zapo4ne6 igra kato 1 igra4 napi6i 1"<<endl;
    cout<<"Ako iska6 da zapo4ne6 igra kato 2 igra4 napi6i 2"<<endl;
    cout<<"Ako iska6 pravilata napi6i 3 "<<endl;
    cin>>pl;
    if(pl==1||pl==2)return 1;
    if(pl==3)
    {
        cout<<"Ima6 5 zara , robotut su6to ima pet zara."<<endl;
        cout<<"Trqbva da zaloji6 kolko zara ot edna stoinost ima ob6to,"<<endl;
        cout<<"kato ima6 pravo da zaloji6 broi po-golqm ot broq na minaliq zalog ili"<<endl;
        cout<<"da zaloji6 stoinost na zar po-golqma ot stoinostta na minaliq zalog."<<endl;
        cout<<"PRIMER ako minaliq e zaloji6 3 4  ( tri 4etvorki) "<<endl;
        cout<<"ti moje6 da zaloji6 broi po-golqm ot tri ili stoinost po-golqma ot 4etiri"<<endl;
        cout<<"naprimer moje6 da kaje6 3 5 ili 4 1 , no ne moje6 2 3 ( dve troiki)"<<endl;
        cout<<"Ako nqma kakvo da kaje6 ili iska6 da zapazi6 tvoq posleden zalog"<<endl;
        cout<<"moje6 da kaje6 pas toest da vuvede6 0 0 ."<<endl;
        cout<<"Uspeh , dano pobedi6 robota . ZABAVLQVAI SE :)"<<endl;
        role();
        return 0;

    }
    if(pl!=3){cout<<"trqbva mejdu 1,2 i 3 ..."<<endl;role();return 0;}

}
bool pl1()
{
    if(plbr==1)
    {
        if(cb[plz]>1){if(cb[plz]+1==cbr&&plz==cz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[plz]+1<<" "<<plz<<endl;cbr=cb[plz]+1;cz=plz;posl=2;return 0;}
        for(int i=plz+1;i<=6;i++)
        if(cb[i]>0){if(cb[plz]+1==cbr&&i==cz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[i]+1<<" "<<i<<endl;cbr=cb[i]+1;cz=i;posl=2;return 0;}
        cout<<"pas"<<endl;pas=1;return 0;
    }
    if(cb[plz-1]>=plbr){if(cb[plz]+1==cbr&&plz==cz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[plz]+1<<" "<<plz<<endl;cbr=cb[plz]+1;cz=plz;posl=2;return 0;}
    for(int i=plz+1;i<=6;i++)
        {if(cb[i-1]>0){if(cb[i-1]+1==cbr&&i==cz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[i-1]+1<<" "<<i<<endl;cbr=cb[i-1]+1;cz=i;posl=2;return 0;}}
        cout<<"pas"<<endl;pas=1;return 0;

}
bool pl2()
{
    int maax=0,j;
    if(f==0)
    {
        for(int i=5;i>=0;i--)
        {
         if(cb[i]>maax){maax=cb[i];j=i+1;}}
         cout<<maax<<" "<<j<<endl;f=1;
         cbr=maax;cz=j;posl=2;
         return 0;
    }
    if(f==1)
    {
        if(plbr==1)
    {
        if(cb[plz-1]>1){if(cb[plz-1]+1==cbr&&plz==cz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[plz-1]+1<<" "<<plz<<endl;cbr=cb[plz-1]+1;cz=plz;posl=2;return 0;}
        for(int i=plz+1;i<=6;i++)
        if(cb[i-1]>0){if(cb[i-1]==cbr&&i==cz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[i-1]<<" "<<i<<endl;cbr=cb[i-1];cz=i;posl=2;return 0;}
        cout<<"pas"<<endl;pas=1;return 0;
    }
    if(cb[plz-1]>1){if(cb[plz]+1==cbr&&cz==plz){cout<<"pas"<<endl;pas=1;return 0;}cout<<cb[plz]+1<<" "<<plz<<endl;cbr=cb[plz]+1;cz=plz;posl=2;return 0;}
    for(int i=plz+1;i<=6;i++)
        if(cb[i-1]>0){if(cb[i-1]+1==cbr&&i==cz){break;}cout<<cb[i-1]+1<<" "<<i<<endl;cbr=cb[i-1]+1;cz=i;posl=2;return 0;}
        for(int i=0;i<=plz;i++)
        if(cb[i-1]>0){if(cb[i-1]+1==cbr&&i==cz){break;}cout<<cb[i-1]+1<<" "<<i<<endl;cbr=cb[i-1]+1;cz=i;posl=2;return 0;}
        cout<<"pas"<<endl;pas=1;return 0;

    }
}
bool vhod()
{
    int plbr1,plz1;
    cin>>plbr1>>plz1;
    if(plbr1==0&&plz1==0){pas=1;return 0;}
    if(plbr1==plbr && plz1==plz){vhod();return 0;}
    plbr=plbr1;
    plz=plz1;
    posl=1;

    if((plbr>=cbr)||(plz>=cz)&&pl==1){pl1();return 0;}
    if((plbr>=cbr)||(plz>=cz)&&pl==2){pl2();return 0;}
    vhod();
    return 0;
}

int main()
{
    int l;
    srand(time(NULL));
    int iz,r=1;
    for(int i=0;i<5;i++)
    {
    a[i] = rand()%6+1;
    c[i] = rand()%6+1;
    }
    for(int i=0;i<5;i++)
    {
        cb[c[i]-1]++;
    }


    role();
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
    if(pl==2)pl2();
    while(r==1)
    {
    if(pl==1)vhod();
    if(pl==2)vhod();
    if(pas==1)r=0;
    }
    for(int i=0;i<5;i++)
    {
        t[a[i]-1]++;
        t[c[i]-1]++;
    }
    for(int i=0;i<6;i++)
    {
        if(t[i]==plbr&&plz==i+1)plp=1;
        if(t[i]==cbr&&cz==i+1)cp=1;
    }
    cout<<"Tvoite zar4eta sa : ";
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        cout<<"Na robota zar4etata sa : ";
    for(int i=0;i<5;i++)
        cout<<c[i]<<" ";
        cout<<endl;
        cout<<"Tvoq posleden zalog e : "<<plbr<<" "<<plz<<endl;
        cout<<"Posledniq zalog na robota e : "<<cbr<<" "<<cz<<endl;
    if(plp==1&&cp==1)
    {
        if(posl==1)cout<<"Ti pobedi"<<endl;
        if(posl==2)cout<<"Ti zagubi"<<endl;
        return 0;

    }

    if(plp==1)cout<<"Ti pobedi"<<endl;
    if(cp==1)cout<<"Ti zagubi"<<endl;
    if(cp==0&&plp==0)cout<<"Naravno"<<endl;


cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cin>>l;

    return 0;
}
