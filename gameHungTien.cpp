#include<iostream>
#include<conio.h>
#include<console.h>
#include<windows.h>
#include<time.h>
#include<cstdlib>

#define consoleHeight   25
#define consoleWidth    80
#define roadWidth       25
#define MAX             2

using namespace std;
struct ToaDo{
    int x,y;
};
struct HinhDang{
    char a[3];
};
struct Tien{
    ToaDo td;
};
struct TienX2{
    ToaDo td[MAX];
};
struct Bom{
    ToaDo td[MAX];
};
struct ThemLuot{
    ToaDo td;
};
struct LamCham{
    ToaDo td;
};
struct GioDo{
    ToaDo td;
    // hinh dang
    HinhDang hd;

};


void KhoiTao(GioDo & giodo, Tien & tien, TienX2 & tienx2, Bom & bom, ThemLuot & TL,LamCham & LC){
    //-----GIODO--------
    #define HD giodo.hd.a


    giodo.td.x=roadWidth/2;
    giodo.td.y=consoleHeight;

    HD[0]=212;
    HD[1]=205;
    HD[2]=190;

    //-----TIEN---------
    tien.td.x=1 + rand()%(roadWidth-4);
    tien.td.y=-1;
    //-----TIEN_X2------
    tienx2.td[0].x=1+rand()%(roadWidth-4);
    tienx2.td[0].y=-7;

    tienx2.td[1].x=1+rand()%(roadWidth-4);
    tienx2.td[1].y=-11;
    //-----BOM-----------
    bom.td[0].x=1+rand()%(roadWidth-4);
    bom.td[0].y=-4;

    bom.td[1].x=1+rand()%(roadWidth-4);
    bom.td[1].y=-7;
    //-----TL------------
    TL.td.x=1 + rand()%(roadWidth-4);
    TL.td.y=-30;
    //-----LC------------
    LC.td.x=1 + rand()%(roadWidth-4);
    LC.td.y=-40;
}

void HienThi(GioDo giodo, Tien tien, TienX2 tienx2,Bom bom, ThemLuot TL, LamCham LC, int & diem,int & luotchoi,int & Level){
    clrscr();

    //-----BIEN-----------
    TextColor(5);
    for(int i=0;i<=consoleHeight;i++){
        cout<<"|"<<endl;
    }
    for(int i=0;i<=consoleHeight;i++){
        gotoXY(consoleHeight,i);
        cout<<"|"<<endl;
    }
    for(int i=1;i<roadWidth;i++){
        gotoXY(i,roadWidth);
        cout<<"_";
    }
    //-------GIODO-----------
    TextColor(11);
    for(int kCot=-1;kCot<=1;kCot++){

        int x=kCot+giodo.td.x;
        int y=giodo.td.y;

        gotoXY(x,y);
        putchar(giodo.hd.a[kCot+1]);
    }
    //--------TIEN----------
    TextColor(14);
    if(tien.td.y>=0 && tien.td.y<consoleHeight){
        gotoXY(tien.td.x,tien.td.y);
        putchar('$');
    }

    TextColor(9);
    for(int i=0;i<MAX;i++){
    if(tienx2.td[i].y>=0 && tienx2.td[i].y<consoleHeight){
        gotoXY(tienx2.td[i].x,tienx2.td[i].y);
        putchar(157);
    }
    }

    TextColor(12);
    for(int i=0;i<MAX;i++){
        if(bom.td[i].y>=0&&bom.td[i].y<consoleHeight){
        gotoXY(bom.td[i].x,bom.td[i].y);
        putchar(235);
    }
    }

    TextColor(1+rand()%15);
    if(TL.td.y>=0 && TL.td.y<consoleHeight){
        gotoXY(TL.td.x,TL.td.y);
        putchar(234);
    }
    TextColor(13);
    if(LC.td.y>=0 && LC.td.y<consoleHeight){
        gotoXY(LC.td.x,LC.td.y);
        putchar(246);
    }
    TextColor(11);
    gotoXY(roadWidth+5,10);
    cout<<"Diem = "<<diem;

    TextColor(9);
    gotoXY(roadWidth+5,8);
    cout<<"Luot Choi con: "<<luotchoi;

    TextColor(9);
    gotoXY(roadWidth+5,12);
    cout<<"Level : "<<Level;
}

void DieuKhien(GioDo & giodo){
    if(kbhit()){
        int key=getch();
        if((GetAsyncKeyState(VK_LEFT)||key=='a')&& giodo.td.x>2)
            giodo.td.x--;
        else if((GetAsyncKeyState(VK_RIGHT)||key=='d')&& giodo.td.x<roadWidth-2)
            giodo.td.x++;
    }
}

int XuLy(GioDo & giodo, Tien & tien, TienX2 & tienx2, Bom & bom, ThemLuot & TL,LamCham & LC, int & diem,int & ThoiGianSleep,int & luotchoi,int & Level){
    tien.td.y++;
    // khoảng cách Giodo và Tien
    int dXtien=abs(giodo.td.x-tien.td.x);
    int dYtien=abs(giodo.td.y-tien.td.y);
    // khoảng cách Giodo và Bom
    int dXbom_1=abs(giodo.td.x-bom.td[0].x);
    int dYbom_1=abs(giodo.td.y-bom.td[0].y);

    int dXbom_2=abs(giodo.td.x-bom.td[1].x);
    int dYbom_2=abs(giodo.td.y-bom.td[1].y);
    // khoảng cách Giodo và TiênX2
    int dXtienx2_1=abs(giodo.td.x-tienx2.td[0].x);
    int dYtienx2_1=abs(giodo.td.y-tienx2.td[0].y);

    int dXtienx2_2=abs(giodo.td.x-tienx2.td[1].x);
    int dYtienx2_2=abs(giodo.td.y-tienx2.td[1].y);
    // khoảng cách Giodo và TL
    int dXTL=abs(giodo.td.x-TL.td.x);
    int dYTL=abs(giodo.td.y-TL.td.y);
    // khoảng cách Giodo và LC
    int dXLC=abs(giodo.td.x-LC.td.x);
    int dYLC=abs(giodo.td.y-LC.td.y);
    if(dXtien<2&&dYtien<1){
        diem++;
        if(ThoiGianSleep>40){
            ThoiGianSleep-=3;
        }
    }

    if(tien.td.y>consoleHeight+1){
        if(dXtien>=2&&dYtien>=1){
            luotchoi--;
        }
        tien.td.x=1 + rand()%(roadWidth-4);
        tien.td.y=1;
    }


    if(diem>=10){
        bom.td[0].y++;
    }
    if(dXbom_1<2&&dYbom_1<1){
        luotchoi--;
    }
    if(bom.td[0].y>consoleHeight+1){

        bom.td[0].x=1 + rand()%(roadWidth-4);
        bom.td[0].y=-4;

    }

    if(diem>=20){
        tienx2.td[0].y++;
    }
    if(dXtienx2_1<2 && dYtienx2_1<1){
        diem+=2;
        if(ThoiGianSleep>40){
            ThoiGianSleep-=3;
        }
    }
    if(tienx2.td[0].y>consoleHeight+1){

        tienx2.td[0].x=1+rand()&(roadWidth-4);
        tienx2.td[0].y=-7;
    }
    if(diem>=30){
        bom.td[1].y++;
    }
    if(dXbom_2<2 && dYbom_2<1){
        luotchoi--;
    }
    if(bom.td[1].y>consoleHeight+1){

        bom.td[1].x=1 + rand()%(roadWidth-4);
        bom.td[1].y=-7;

    }

    if(diem>=40){
        tienx2.td[1].y++;
    }
    if(dXtienx2_2<2 && dYtienx2_2<1){
        diem+=2;
        if(ThoiGianSleep>40){
            ThoiGianSleep-=3;
        }
    }
    if(tienx2.td[1].y>consoleHeight+1){

        tienx2.td[1].x=1+rand()&(roadWidth-4);
        tienx2.td[1].y=-11;
    }

    if(diem>=50){
        TL.td.y++;
    }
    if(dXTL<2 && dYTL<1){
        luotchoi++;
    }
    if(TL.td.y>consoleHeight+1){
        TL.td.x=1+rand()&(roadWidth-4);
        TL.td.y=-50;
    }

    if(diem>=60){
        LC.td.y++;
    }
    if(dXLC<2 && dYLC<1){
        ThoiGianSleep+=50;
    }
    if(LC.td.y>consoleHeight+1){
        LC.td.x=1+rand()&(roadWidth-4);
        LC.td.y=-90;
    }
    Level=1 + diem/10;


    if(luotchoi==0){
        return -1;
    }
    return 0;
}

void GioiThieu(){
    cout<<" Game Hung Tien by Son Thanh"<<endl<<endl;
    cout<<" luat choi:"<<endl;
    cout<<" - cac ban dung phim A & D hoac PHIM MUI TEN de di chuyen Gio Do sang Trai hoac Phai"<<endl;
    cout<<" - sao cho hung duoc nhieu tien nhat se tang diem"<<endl;
    cout<<" - se co cac level khac nhau diem cang cao level cang tang"<<endl;
    cout<<" - khi level tang se co them nhieu item va chuong ngai vat"<<endl<<endl;
    cout<<" CHUC BAN CHOI GAME VUI VE"<<endl<<endl;
    cout<<" an Enter de choi";
}

void LoiChao(){
    TextColor(14);

    cout<<" CHON MUC DO CHOI"<<endl;
    cout<<" de \t trung binh \t kho"<<endl;
    cout<<" 1  \t     2      \t  3 "<<endl<<endl;
    cout<<" nhap do kho :";
}

int Do_Kho(){
    int do_kho;
    cin>>do_kho;
    if(do_kho==1) return 200;
    else if(do_kho==2) return 150;
    else if(do_kho==3) return 100;
}

int main(){
    srand(time(NULL));
    GioDo giodo;
    Tien tien;
    TienX2 tienx2;
    Bom bom;
    ThemLuot TL;
    LamCham LC;
    int kt=0;
    int diem=0;
    int luotchoi=5;
    int ThoiGianSleep;
    int Level=0;

    GioiThieu();
    if(getch()==13){
        clrscr();
        LoiChao();
    }
    ThoiGianSleep = Do_Kho();

    KhoiTao(giodo,tien,tienx2,bom,TL,LC);

    while(1){

        HienThi(giodo,tien,tienx2,bom,TL,LC,diem,luotchoi,Level);

        DieuKhien(giodo);

        kt=XuLy(giodo,tien,tienx2,bom,TL,LC,diem,ThoiGianSleep,luotchoi,Level);

        if(kt==-1){
            gotoXY(roadWidth+5,14);
            TextColor(12);
            cout<<"GAME OVER";
            while(getch()!=13);
            break;
        }

        Sleep(ThoiGianSleep);
    }

    return 0;
}
