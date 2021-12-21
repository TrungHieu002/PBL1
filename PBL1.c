#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define Maxn 101
#define Vocung 9999999
#define Dauvao "MINPATH.inp"
#define Daura "MINPATH.out"
int A[Maxn][Maxn];
int MinPath[Maxn];
int Truyvet[Maxn];
bool Free[Maxn];
int N, M, S, E;
void input_keybroad()
{
    printf("\tNhap du lieu tu ban phim:\n");
    printf("\tNhap so dinh: ");
    scanf("%d", &N);
    printf("\tNhap so cung: ");
    scanf("%d", &M);
    printf("\tNhap Diem xuat phat: ");
    scanf("%d", &S);
    printf("\tNhap Diem ket thuc: ");
    scanf("%d", &E);
    printf("\tNhap Ma Tran:\n\t");
    for (int i = 1; i <= M; i++)
    {
        int u, v, p;
        scanf("%d %d %d", &u, &v, &p);
        printf("\t");
        A[u][v] = A[v][u] = p;
    }
}
void input_file()
{
    FILE *fi = fopen(Dauvao, "r");
    fscanf(fi, "%d %d %d %d", &N, &M, &S, &E);
    for (int i = 1; i <= M; i++)
    {
        int u, v, p;
        fscanf(fi, "%d %d %d", &u, &v, &p);
        A[u][v] = A[v][u] = p;
    }
    fclose(fi);
}
void output_keybroad()
{
    if (MinPath[E] == Vocung)
    {
        printf("Khong Co Duong Di Nao");
    }
    else
    {
        printf("Duong di ngan nhat tu %d den %d : %d\n", S, E, MinPath[E]);
    }
    int a = E;
    printf("\t%d", a);
    while (a != S)
    {
        a = Truyvet[a];
        printf(" <- %d", a);
    }
    printf("\n\tKet thuc thuat toan!");
}
void output_keybroadA()
{
    if (MinPath[E] == Vocung)
    {
        printf("Khong Co Duong Di Nao");
    }
    else
    {
        printf("\tKhoang cach tu dinh bat dau %d den cac dinh con lai la\n", S);
        for (int i = 1; i <= N; i++)
        {
            printf("\tKhoang cach ngan nhat tu dinh %d den %d: %d\n", S, i, MinPath[i]);
        }
    }
}
void output_file()
{
    FILE *fo = fopen(Daura, "w");
    if (MinPath[E] == Vocung)
    {
        fprintf(fo, "Khong co duong di nao");
    }
    else
    {
        fprintf(fo, "Duong di ngan nhat tu %d den %d: %d\n", S, E, MinPath[E]);
    }
    int a = E;
    fprintf(fo, "%d", a);
    while (a != S)
    {
        a = Truyvet[a];
        fprintf(fo, " <- %d", a);
    }
    fclose(fo);
    printf("\tKet thuc thuat toan vui long mo file de xem ket qua!");
}
void output_fileA()
{
    FILE *fo = fopen(Daura, "w");
    if (MinPath[E] == Vocung)
    {
        fprintf(fo, "Khong co duong di nao");
    }
    else
    {
        fprintf(fo, "Khoang cach tu dinh bat dau %d den cac dinh con lai la\n", S);
        for (int i = 1; i <= N; i++)
        {
            fprintf(fo, "Khoang cach ngan nhat tu dinh %d den %d: %d\n", S, i, MinPath[i]);
        }
        fclose(fo);
        printf("\tKet thuc thuat toan vui long mo file de xem ket qua!");
    }
}
void Algorithm_Dijkstra()
{
    int g = S;
    for (int i = 1; i <= N; i++)
    {
        MinPath[i] = Vocung;
    }
    MinPath[S] = 0;
    do
    {
        g = E;
        for (int i = 1; i <= N; i++)
        {
            if (Free[i] == false && MinPath[g] > MinPath[i])
            {
                g = i;
            } 
        }
        Free[g] = true;
        if (MinPath[g] == Vocung || g == E)
            break;
        for (int v = 1; v <= N; v++)
        {
            if (A[g][v] > 0 && !Free[v])
            {
                if (MinPath[v] > MinPath[g] + A[g][v])
                {
                    MinPath[v] = A[g][v] + MinPath[g];
                    Truyvet[v] = g;                    
                }
            }
        } 
    }while (true);
}
void TextColor(int code)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}
int main()
{
    int choninp, chonout, chonkieu;
    TextColor(11);
    printf("\t __________________________________TRUONG DAI HOC BACH KHOA-DAI HOC DA NANG_____________________________");
    printf("\n\t*\t\t\t\t\t<===KHOA CONG NGHE THONG TIN==>\t\t\t\t\t*");
    printf("\n\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*");
    printf("\n\t*\t\t\t\t\t DO AN LAP TRINH TINH TOAN\t\t\t\t\t*");
    printf("\n\t*\t\tXay Dung Chuong Trinh Tim Duong Di Ngan Nhat Tren Do Thi Co Huong Va Trong So\t\t*");
    printf("\n\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*");
    printf("\n\t*\t Phuong Phap Thuc Hien: Thuat Toan Dijkstra\t\t  GV Huong Dan: TS Nguyen Van Hieu\t*");
    printf("\n\t*\t Sv Thuc Hien:\t\t\t\t\t\t\tSo The Sinh Vien\t\t*");
    printf("\n\t*\t Sv1: Tran Trung Hieu\t\t\t\t\t\t   102200047\t\t\t*");
    printf("\n\t*\t Sv2: Nguyen Van Trong Nguyen\t\t\t\t\t   102200060\t\t\t*");
    printf("\n\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*");
    printf("\n\t*_______________________________________________________________________________________________________*\n");
    TextColor(14);
    printf("\n\t _______________________DIJKSTRA________________________\n");
    printf("\t*\t    _Chon Phuong thuc nhap du lieu_\t\t*\n");
    printf("\t*\t+ Nhan 1 de nhap du lieu truc tiep tu ban phim\t*\n");
    printf("\t*\t+ Nhan 2 de nhap du lieu tu file MINPATH.inp\t*\n");
    printf("\t*_______________________________________________________*\n");
    printf("\tMoi ban chon!:");
    scanf("%d", &choninp);
    while (choninp != 1 && choninp != 2)
    {
        printf("\tMoi ban chon lai!:");
        scanf("%d", &choninp);
    }
    if (choninp == 1)
    {
        TextColor(2);
        printf("\n\t _______________________DIJKSTRA________________________\n");
        printf("\t*\t    _Chon Phuong thuc xuat du lieu_\t\t*\n");
        printf("\t*\t+ Nhan 1 de xuat du lieu truc tiep ra man hinh\t*\n");
        printf("\t*\t+ Nhan 2 de xuat du lieu ra file MINPATH.inp\t*\n");
        printf("\t*_______________________________________________________*\n");
        printf("\tMoi ban chon!:");
        scanf("%d", &chonout);
        while (chonout != 1 && chonout != 2)
        {
            printf("\tMoi ban chon lai!:");
            scanf("%d", &chonout);
        }
        if (chonout == 1)
        {
            TextColor(9);
            printf("\n\t _______________________DIJKSTRA________________________\n");
            printf("\t*\t\t    _Chon du lieu dau ra _\t\t*\n");
            printf("\t*\t+ Nhan 1 de xuat duong di ngan nhat voi mot dinh*\n");
            printf("\t*\t+ Nhan 2 de xuat duong di ngan nhat voi moi dinh*\n");
            printf("\t*_______________________________________________________*\n");
            printf("\tMoi ban chon!:");
            scanf("%d", &chonkieu);
            while (chonkieu != 1 && chonkieu != 2)
            {
                printf("\tMoi ban chon lai!:");
                scanf("%d", &chonkieu);
            }
            if (chonkieu == 1)
            {
                input_keybroad();
                Algorithm_Dijkstra();
                output_keybroad();
            }
            else
            {
                input_keybroad();
                Algorithm_Dijkstra();
                output_keybroadA();
            }
        }
        else
        {
            TextColor(9);
            printf("\n\t _______________________DIJKSTRA________________________\n");
            printf("\t*\t\t    _Chon du lieu dau ra _\t\t*\n");
            printf("\t*\t+ Nhan 1 de xuat duong di ngan nhat voi mot dinh*\n");
            printf("\t*\t+ Nhan 2 de xuat duong di ngan nhat voi moi dinh*\n");
            printf("\t*_______________________________________________________*\n");
            printf("\tMoi ban chon!:");
            scanf("%d", &chonkieu);
            while (chonkieu != 1 && chonkieu != 2)
            {
                printf("\tMoi ban chon lai!:");
                scanf("%d", &chonkieu);
            }
            if (chonkieu == 1)
            {
                input_keybroad();
                Algorithm_Dijkstra();
                output_file();
            }
            else
            {
                input_keybroad();
                Algorithm_Dijkstra();
                output_fileA();
            }
        }
    }
    else //........................
    {
        TextColor(2);
        printf("\n\t _______________________DIJKSTRA________________________\n");
        printf("\t*\t    _Chon Phuong thuc xuat du lieu_\t\t*\n");
        printf("\t*\t+ Nhan 1 de xuat du lieu truc tiep ra man hinh\t*\n");
        printf("\t*\t+ Nhan 2 de xuat du lieu ra file MINPATH.inp\t*\n");
        printf("\t*_______________________________________________________*\n");
        printf("\tMoi ban chon!:");
        scanf("%d", &chonout);
        while (chonout != 1 && chonout != 2)
        {
            printf("\tMoi ban chon lai!:");
            scanf("%d", &chonout);
        }
        if (chonout == 1)
        {
            TextColor(9);
            printf("\n\t _______________________DIJKSTRA________________________\n");
            printf("\t*\t\t    _Chon du lieu dau ra _\t\t*\n");
            printf("\t*\t+ Nhan 1 de xuat duong di ngan nhat voi mot dinh*\n");
            printf("\t*\t+ Nhan 2 de xuat duong di ngan nhat voi moi dinh*\n");
            printf("\t*_______________________________________________________*\n");
            printf("\tMoi ban chon!:");
            scanf("%d", &chonkieu);
            while (chonkieu != 1 && chonkieu != 2)
            {
                printf("\tMoi ban chon lai!:");
                scanf("%d", &chonkieu);
            }
            if (chonkieu == 1)
            {
                input_file();
                Algorithm_Dijkstra();
                printf("\t");
                output_keybroad();
            }
            else
            {
                input_file();
                Algorithm_Dijkstra();
                output_keybroadA();
            }
        }
        else
        {
            TextColor(9);
            printf("\n\t _______________________DIJKSTRA________________________\n");
            printf("\t*\t\t    _Chon du lieu dau ra _\t\t*\n");
            printf("\t*\t+ Nhan 1 de xuat duong di ngan nhat voi mot dinh*\n");
            printf("\t*\t+ Nhan 2 de xuat duong di ngan nhat voi moi dinh*\n");
            printf("\t*_______________________________________________________*\n");
            printf("\tMoi ban chon!:");
            scanf("%d", &chonkieu);
            while (chonkieu != 1 && chonkieu != 2)
            {
                printf("\tMoi ban chon lai!:");
                scanf("%d", &chonkieu);
            }
            if (chonkieu == 1)
            {
                input_file();
                Algorithm_Dijkstra();
                output_file();
            }
            else
            {
                input_file();
                Algorithm_Dijkstra();
                output_fileA();
            }
        }
    }
    return 0;
}
