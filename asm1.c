/******************************************************************************
 * Họ và tên: [Trần Quốc Cường]
 * MSSV:      [PS48626]
 * Lớp:       [CS21302-COM108]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// ====== CHUC NANG 1 ======
void cau1(){
    int x, i, dem = 0;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    if(x < 2){
        printf("Khong phai so nguyen to\n");
    } else {
        for(i = 1; i <= x; i++){
            if(x % i == 0) dem++;
        }
        if(dem == 2)
            printf("La so nguyen to\n");
        else
            printf("Khong phai so nguyen to\n");
    }

    int can = sqrt(x);
    if(can * can == x)
        printf("La so chinh phuong\n");
    else
        printf("Khong phai so chinh phuong\n");
}

// ====== CHUC NANG 2 ======
void cau2(){
    int a,b,i;
    printf("Nhap 2 so: ");
    scanf("%d%d",&a,&b);

    int ucln=1;
    for(i=1;i<=a && i<=b;i++){
        if(a%i==0 && b%i==0)
            ucln=i;
    }

    int bcnn=(a*b)/ucln;
    printf("UCLN = %d\n",ucln);
    printf("BCNN = %d\n",bcnn);
}

// ====== CHUC NANG 3 ======
void cau3(){
    int gio;
    printf("Nhap so gio hat: ");
    scanf("%d",&gio);

    int tien=0;
    if(gio<=3)
        tien=gio*150000;
    else
        tien=3*150000 + (gio-3)*100000;

    printf("Tien phai tra: %d\n",tien);
}

// ====== CHUC NANG 4 ======
void cau4(){
    int soDien;
    printf("Nhap so dien: ");
    scanf("%d",&soDien);

    int tien;
    if(soDien<=50)
        tien=soDien*1678;
    else if(soDien<=100)
        tien=50*1678+(soDien-50)*1734;
    else
        tien=50*1678+50*1734+(soDien-100)*2014;

    printf("Tien dien: %d\n",tien);
}

// ====== CHUC NANG 5 ======
void cau5(){
    int tien;
    printf("Nhap so tien: ");
    scanf("%d",&tien);

    printf("500k: %d\n",tien/500000);
    tien%=500000;
    printf("200k: %d\n",tien/200000);
    tien%=200000;
    printf("100k: %d\n",tien/100000);
}

// ====== CHUC NANG 6 ======
void cau6(){
    float tienVay,laiSuat;
    int thang;
    printf("Nhap tien vay: ");
    scanf("%f",&tienVay);
    printf("Nhap lai suat (%%/thang): ");
    scanf("%f",&laiSuat);
    printf("Nhap so thang vay: ");
    scanf("%d",&thang);

    float tienTra=tienVay/thang;
    for(int i=1;i<=thang;i++){
        float lai=tienVay*(laiSuat/100);
        printf("Thang %d: Lai=%.0f  Tong=%.0f\n",i,lai,lai+tienTra);
        tienVay-=tienTra;
    }
}

// ====== CHUC NANG 7 ======
void cau7(){
    float giaXe=500000000;
    float traTruoc=giaXe*0.2;
    float vay=giaXe-traTruoc;
    printf("Gia xe: %.0f\n",giaXe);
    printf("Tra truoc 20%%: %.0f\n",traTruoc);
    printf("Tien vay: %.0f\n",vay);
}

// ====== CHUC NANG 8 ======
void cau8(){
    char ten[50];
    float diem;
    printf("Nhap ten sinh vien: ");
    scanf("%s",ten);
    printf("Nhap diem: ");
    scanf("%f",&diem);

    if(diem>=9) printf("Xuat sac\n");
    else if(diem>=8) printf("Gioi\n");
    else if(diem>=6.5) printf("Kha\n");
    else printf("Trung binh/Yeu\n");
}

// ====== CHUC NANG 9 ======
void cau9(){
    int so;
    srand(time(NULL));
    int random=rand()%10;

    printf("Nhap so tu 0-9: ");
    scanf("%d",&so);

    if(so==random)
        printf("Chuc mung ban trung!\n");
    else
        printf("Chuc ban may man lan sau. So dung la %d\n",random);
}

// ====== CHUC NANG 10 ======
void cau10(){
    int tu1,mau1,tu2,mau2;
    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d%d",&tu1,&mau1);
    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d%d",&tu2,&mau2);

    int tu=tu1*mau2+tu2*mau1;
    int mau=mau1*mau2;

    printf("Tong 2 phan so = %d/%d\n",tu,mau);
}

// ====== MAIN ======
int main(){
    int chonChucNang;
    do{
        printf("\n===== MENU =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Lai suat vay\n");
        printf("7. Vay mua xe\n");
        printf("8. Thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh phan so\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d",&chonChucNang);

        switch(chonChucNang){
            case 1:
                printf("DA CHON CHUC NANG 1\n");
                cau1();
                break;
            case 2:
                printf("DA CHON CHUC NANG 2\n");
                cau2();
                break;
            case 3:
                printf("DA CHON CHUC NANG 3\n");
                cau3();
                break;
            case 4:
                printf("DA CHON CHUC NANG 4\n");
                cau4();
                break;
            case 5:
                printf("DA CHON CHUC NANG 5\n");
                cau5();
                break;
            case 6:
                printf("DA CHON CHUC NANG 6\n");
                cau6();
                break;
            case 7:
                printf("DA CHON CHUC NANG 7\n");
                cau7();
                break;
            case 8:
                printf("DA CHON CHUC NANG 8\n");
                cau8();
                break;
            case 9:
                printf("DA CHON CHUC NANG 9\n");
                cau9();
                break;
            case 10:
                printf("DA CHON CHUC NANG 10\n");
                cau10();
                break;
            case 0:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while(chonChucNang!=0);

    return 0;
}