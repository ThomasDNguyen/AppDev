// header file for screen manipulation
#define UNICODE

#define BAR "\u2590" //unicode for bar
enum COLORS{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE}; //vt100 escape codes

//function prototypes
void clearScreen(void);
void setFGcolor(int fg);
void resetColors(void);
void gotoXY(int row, int col);
void displayBar(int col, double rms);
