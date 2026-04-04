#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#define MINX 2 
#define MINY 2 
#define MAXX 35 
#define MAXY 20 
using namespace std;
void gotoxy( int column, int line );
struct Point{
    int x,y;
};
class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
     void Ve(Point Qua){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(Qua.x, Qua.y);
        cout << "*";
    }

    void DiChuyen(int Huong, Point& Qua){
        // Dịch thân
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        // Di chuyển đầu
        if (Huong == 0) A[0].x++;
        if (Huong == 1) A[0].y++;
        if (Huong == 2) A[0].x--;
        if (Huong == 3) A[0].y--;

        // Ăn quả
        if (A[0].x == Qua.x && A[0].y == Qua.y){
            DoDai++;
            Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
            Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;
        }
    }
};
void VeKhung(){ 
    for (int i = MINX; i <= MAXX; i++){
        for (int j = MINY; j <= MAXY; j++){
            if (i == MINX || i == MAXX || j == MINY || j == MAXY){
                gotoxy(i, j);
                cout << "+";
            }
        }
    }
}
int main()
{
    CONRAN r;
    int Huong = 0;
    char t;
    Point Qua;
    srand((int)time(0));
    Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
    Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;
    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='s') Huong = 1;
        }
        system("cls");
        VeKhung();
        r.Ve(Qua);
        r.DiChuyen(Huong, Qua);
          // Kiểm tra đụng tường 
        if (r.A[0].x <= MINX || r.A[0].x >= MAXX ||
            r.A[0].y <= MINY || r.A[0].y >= MAXY)
        {
            system("cls"); 
            gotoxy(10,10); 
            cout << "===== YOU LOST ====="; 
            gotoxy(10,12); 
            cout << "Press any key to exit..."; 
            getch(); 
            break;
        }
        Sleep(300);
    }
    return 0;
}
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
