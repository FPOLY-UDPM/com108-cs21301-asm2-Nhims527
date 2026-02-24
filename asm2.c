#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int UCLN(int a, int b){
    a = abs(a);
    b = abs(b);
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int BCNN(int a, int b){
    return abs(a*b)/UCLN(a,b);
}

void chucNang1(){
    int n, i, flag = 1;

    printf("Nhap so nguyen: ");
    scanf("%d",&n);

    if(n < 2){
        printf("Khong phai so nguyen to\n");
        return;
    }

    for(i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        printf("La so nguyen to\n");
    else
        printf("Khong phai so nguyen to\n");
}

void chucNang2(){
    int a,b;
    printf("Nhap 2 so: ");
    scanf("%d%d",&a,&b);

    printf("UCLN = %d\n",UCLN(a,b));
    printf("BCNN = %d\n",BCNN(a,b));
}

void chucNang3(){
    int gio;
    float tien;
    printf("Nhap so gio hat: ");
    scanf("%d",&gio);

    if(gio <= 3) tien = gio * 150000;
    else tien = 3*150000 + (gio-3)*120000;

    if(gio >= 4) tien *= 0.9;

    printf("Tien phai tra: %.0f\n",tien);
}

void chucNang4(){
    int soDien;
    float tien = 0;
    printf("Nhap so dien: ");
    scanf("%d",&soDien);

    if(soDien <= 50) tien = soDien*1678;
    else if(soDien <= 100) tien = 50*1678 + (soDien-50)*1734;
    else if(soDien <= 200) tien = 50*1678 + 50*1734 + (soDien-100)*2014;
    else tien = 50*1678 + 50*1734 + 100*2014 + (soDien-200)*2536;

    printf("Tien dien: %.0f\n",tien);
}

void chucNang5(){
    int tien;
    printf("Nhap so tien: ");
    scanf("%d",&tien);

    int menhGia[] = {500000,200000,100000,50000,20000,10000,5000,2000,1000};
    for(int i=0;i<9;i++){
        printf("%d : %d to\n",menhGia[i],tien/menhGia[i]);
        tien %= menhGia[i];
    }
}

void chucNang6(){
    float tienVay, laiSuat;
    int thang;
    printf("Nhap tien vay: ");
    scanf("%f",&tienVay);
    printf("Nhap lai suat thang (%%): ");
    scanf("%f",&laiSuat);
    printf("Nhap so thang: ");
    scanf("%d",&thang);

    float gocHangThang = tienVay/thang;

    for(int i=1;i<=thang;i++){
        float lai = tienVay * laiSuat/100;
        printf("Thang %d: Goc %.0f Lai %.0f Tong %.0f\n",
               i,gocHangThang,lai,gocHangThang+lai);
        tienVay -= gocHangThang;
    }
}

void chucNang7(){
    float giaXe, traTruoc;
    printf("Nhap gia xe: ");
    scanf("%f",&giaXe);
    printf("Nhap tra truoc: ");
    scanf("%f",&traTruoc);

    float vay = giaXe - traTruoc;
    printf("So tien can vay: %.0f\n",vay);
}

struct SinhVien{
    char ten[50];
    float diem;
};

void chucNang8(){
    struct SinhVien sv[3];
    for(int i=0;i<3;i++){
        printf("Nhap ten: ");
        scanf("%s",sv[i].ten);
        printf("Nhap diem: ");
        scanf("%f",&sv[i].diem);
    }

    for(int i=0;i<3-1;i++){
        for(int j=i+1;j<3;j++){
            if(sv[i].diem < sv[j].diem){
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }

    for(int i=0;i<3;i++){
        printf("%s - %.2f\n",sv[i].ten,sv[i].diem);
    }
}

void chucNang9(){
    int so = rand()%100 + 1;
    int doan;

    printf("Doan so tu 1-100: ");
    scanf("%d",&doan);

    if(doan == so) printf("Trung thuong!\n");
    else printf("Chuc may man lan sau. So dung la %d\n",so);
}

void chucNang10(){
    int a,b,c,d;
    printf("Nhap phan so 1 (a/b): ");
    scanf("%d%d",&a,&b);
    printf("Nhap phan so 2 (c/d): ");
    scanf("%d%d",&c,&d);

    int tu = a*d + b*c;
    int mau = b*d;

    int uc = UCLN(tu,mau);
    tu /= uc;
    mau /= uc;

    printf("Tong = %d/%d\n",tu,mau);
}

int main(){
    int chon;
    do{
        printf("\n------ MENU ------\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. UCLN & BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Lai suat vay\n");
        printf("7. Vay mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. FPOLY-LOTT\n");
        printf("10. Tinh phan so\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d",&chon);

        switch(chon){
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
        }
    }while(chon != 0);

    return 0;
}