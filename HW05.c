//Alp Emir BİLEK
//161044049
//#HW05

#include <stdio.h>
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;
void init_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_2();
int main() {
    int a,b,c,d;
    piece board[8][8];
    int counter1=16,counter2=16,play=0,check=0;
    /* HOCAM SİZİN İSTEDİĞİNİZ OYUNU SİMÜLE EDEN FONKSİYONU ÇAĞIRDIM.
     * EĞER İSTERSENİZ AŞAĞIDAKİ COMMENTLERİ AÇARAK MULTİPLAYER BİR OYUNA ERİŞEBİLİRSİNİZ.
     */
    sample_game_2();
    /*init_board(board);
    display_board(board);
    check=check_end_of_game(board);
    while(check==0){
        if(play%2==0){
            printf("beyaz hamle yap");
            scanf("%d %d %d %d",&a,&b,&c,&d);
            move(board,a,b,c,d,white);
            check=check_end_of_game(board);
            display_board(board);
        }
        else{
            printf("siyah hamle yap");
            scanf("%d %d %d %d",&a,&b,&c,&d);
            move(board,a,b,c,d,black);
            check=check_end_of_game(board);
            display_board(board);
        }
        play++;

    }
    if(check==1){
        printf("White wins!!");
    }
    else if(check==2){
        printf("Black wins!!");
    }*/
    return 0;
}
void init_board(piece board[][8]){//ARRAYİN İNDEXLERİNE TAŞ BOŞLUK VE KİNGLERİ İNİTİLAİZE ETTİM.
    int i,j;
    for(i=0;i<8;i++){
        board[0][i]=empty;
    }
    for(i=1;i<3;i++){
        for(j=0;j<8;j++){
            board[i][j]=black_man;
        }
    }
    for(i=3;i<5;i++){
        for(j=0;j<8;j++){
            board[i][j]=empty;
        }
    }
    for(i=5;i<7;i++){
        for(j=0;j<8;j++){
            board[i][j]=white_man;
        }
    }
    for(i=0;i<8;i++){
        board[7][i]=empty;
    }
}
void display_board(piece board[][8]){//İNİTİALİZE ETTİKLERİMİ PRİNT ETTİM.
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]==empty){
            printf("-");
            }
            else if(board[i][j]==black_man){
                printf("b");
            }
            else if(board[i][j]==white_man){
                printf("w");
            }
            else if(board[i][j]==white_king){
                printf("W");
            }
            else if(board[i][j]==black_king){
                printf("B");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p) {
    int flagw = 0,flagb=0,i,j,counterw=0,counter1=0,counter2=0,counterb=0;
    if (p == white) {//EĞER SIRA BEYAZINSA
        while (flagw == 0) {//beyazın yeme işlemi için.
            if (board[from_x - 1][from_y] == (black_man || black_king) && board[from_x - 2][from_y] == empty) {//yukarı dogru yeme
                if (from_x - 2 == 0) {//KİNG OLMASI İÇİN
                    board[0][from_y] = white_king;
                    board[from_x - 1][from_y] = empty;
                    board[from_x][from_y] = empty;
                    from_x = from_x - 2;
                }
                else {//NOrmal bir taş için
                    board[from_x - 2][from_y] = white_man;
                    board[from_x - 1][from_y] = empty;
                    board[from_x][from_y] = empty;
                    from_x = from_x - 2;
                }
            }
            else if (board[from_x][from_y + 1] == (black_man || black_king) && board[from_x][from_y + 2] == empty) {//saga dogru yeme.
                board[from_x][from_y + 2] = white_man;
                board[from_x][from_y + 1] = empty;
                board[from_x][from_y] = empty;
                from_y = from_y + 2;
            }
            else if (board[from_x][from_y - 1] == (black_man || black_king) && board[from_x][from_y - 2] == empty) {//sola dogru yeme.
                board[from_x][from_y - 2] = white_man;
                board[from_x][from_y - 1] = empty;
                board[from_x][from_y] = empty;
                from_y = from_y - 2;
            }
            else {
                flagw++;
            }
        }
        if(board[from_x][from_y]==white_king) {//kingin hareketi için
            if (board[to_x][to_y] == empty && (from_y == to_y)) {
               if(from_x<to_x) {//kingin aşağı dopru gitmesi için
                   for (i = from_x; i <= to_x; i++) {
                       if (  board[i][to_y] == empty ) {
                           counterw++;
                       }
                       else if((board[i][from_y]==(black_man ) || board[i][from_y]==black_king) && board[i+1][from_y]==empty) {//kingin aşağı doğru yemesi
                           board[to_x][to_y] = white_king;
                           board[from_x][from_y] = empty;
                           board[i][from_y] = empty;
                       }
                   }
               }
               else if(to_x<from_x) {//kingin yukarı doğru gitmesi için
                   for (i = to_x; i < from_x; i++) {
                       if (board[i][to_y] == empty ) {
                           counterw++;

                       }
                       else if((board[i][from_y]==black_man|| (board[i][from_y]== black_king)) && board[i-1][from_y]==empty){//kingin yukarı doğru yemesi
                           board[to_x][to_y]=white_king;
                           board[from_x][from_y]=empty;
                           board[i][from_y]=empty;

                        }
                   }
               }
                if(counterw==(to_x-from_x) || -1*counterw==(to_x-from_x)){
                    board[to_x][to_y] = white_king;
                    board[from_x][from_y] = empty;
                }
                else{
                    p=black;
                }
            }

            else if( board[to_x][to_y]==empty &&(from_x==to_x)) {//kingin sağa gitmesi için
                if (from_y < to_y) {
                    for (i = from_y; i <= to_y; i++) {
                        if (board[to_x][i] == empty ) {
                            counter1++;
                        }
                        else if((board[to_x][i]==black_man || board[from_x][i]==black_king) && board[to_x][i + 1] ==empty) {//kingin saga doğru yemesi
                                board[to_x][to_y] = white_king;
                                board[from_x][from_y] = empty;
                                board[from_x][i] = empty;
                                i = to_y + 1;
                        }
                    }
                }
                else if(to_y<from_y){//kingin sola doğru gitmesi için
                    for (i = to_y; i <= from_y; i++) {
                        if (board[to_x][i] == empty ) {
                            counter1++;
                        }
                        else if((board[from_x][i]==black_man || board[from_x][i]==black_king) && board[from_x][i-1]==empty) {//kingin sola doğru yemesi
                            board[to_x][to_y] = white_king;
                            board[from_x][from_y] = empty;
                            board[from_x][i] = empty;
                            i=to_y+1;
                        }
                    }
                }
                if (counter1 == (from_y - to_y) || -1*counter1 == (from_y - to_y)) {
                    board[to_x][to_y] = white_king;
                    board[from_x][from_y] = empty;
                    }

            }
        }
        if ((from_x - to_x) == 1 && (from_y == to_y)) {//yanlis bisi icin
            if (board[to_x][to_y] == empty) {//yukarı için
                if (to_x == 0) {
                    board[to_x][to_y] = white_king;
                    board[from_x][from_y] = empty;
                }
                else {
                    board[to_x][to_y] = white_man;
                    board[from_x][from_y] = empty;
                }
            }
        } else if ((from_x == to_x) && (to_y - from_y) == 1) {//beyazın sağa gitmesi için
            if (board[to_x][to_y] == empty) {
                if (to_x == 0) {
                    board[to_x][to_y] = white_king;
                    board[from_x][from_y] = empty;
                }
                else {
                    board[to_x][to_y] = white_man;
                    board[from_x][from_y] = empty;
                }
            }
        } else if ((from_x == to_x) && (to_y - from_y) == -1) {//beyazın sola gitmesi için
            if (board[to_x][to_y] == empty) {
                if (to_x == 0) {
                    board[to_x][to_y] = white_king;
                    board[from_x][from_y] = empty;
                } else {
                    board[to_x][to_y] = white_man;
                    board[from_x][from_y] = empty;
                }
            }
        }
        else {//Eger yanlis bir hamle olursa,hamle sirasi digerine gecer.
            p = black;
        }
    }
    /*SIRA SİYAHTA
        SIRA SİYAHTA
        SIRA SİYAHTA
       */
    else if (p == black) {
        while (flagb == 0) {//siyahın yeme işlemi için.
            if ((board[from_x + 1][from_y] == white_man || (board[from_x + 1][from_y] ==white_king) && board[from_x + 2][from_y] == empty)) {//asagı dogru yeme
                if(from_x+2  == 7){//KINGIN ASAGI YEME
                    printf("girdi\n");
                    board[7][from_y] = black_king;
                    board[from_x + 1][from_y] = empty;
                    board[from_x][from_y] = empty;
                    from_x = from_x + 2;
                }
                else{
                    board[from_x + 2][from_y] = black_man;
                    board[from_x + 1][from_y] = empty;
                    board[from_x][from_y] = empty;

                    p = black;
                }
            }
            else if ((board[from_x][from_y + 1] == white_man || (board[from_x][from_y + 1] ==white_king) && board[from_x][from_y + 2] == empty)){//saga dogru yeme.
                board[from_x][from_y + 2] = black_man;
                board[from_x][from_y + 1] = empty;
            }
            else if ((board[from_x][from_y - 1] == white_man ||(board[from_x][from_y - 1] == white_king ) && board[from_x][from_y - 2] == empty)){//sola dogru yeme.
                board[from_x][from_y - 2] = black_man;
                board[from_x][from_y - 1] = empty;
                board[from_x][from_y] = empty;
            }
            else {
                flagb++;
            }
        }
        if(board[from_x][from_y]==black_king) {
                if (board[to_x][to_y] == empty && (from_y == to_y)) {
                    if (from_x < to_x) {
                        for (i = from_x; i <= to_x; i++) {
                            if (board[i][to_y] == empty) {
                                counterw++;
                            }
                            else if ((board[i][from_y] == (white_man) || board[i][from_y] == white_king) && board[i + 1][from_y] == empty) {//kingin yukarı doğru yemesi
                                board[to_x][to_y] = black_king;
                                board[from_x][from_y] = empty;
                                board[i][from_y] = empty;
                            }
                        }
                    }
                    else if(to_x<from_x){
                        for (i = to_x; i < from_x; i++){
                            if (board[i][to_y] == empty ) {
                                counterw++;
                            }
                            if((board[i][from_y]==white_man|| (board[i][from_y]== white_king)) && board[i-1][from_y]==empty){//kingin yukarı doğru yemesi
                                board[to_x][to_y]=black_king;
                                board[from_x][from_y]=empty;
                                board[i][from_y]=empty;
                            }
                        }
                    }
                    if(counterw==(to_x-from_x) || -1*counterw==(to_x-from_x)){
                        board[to_x][to_y] = black_king;
                        board[from_x][from_y] = empty;
                    }
                    else{
                        p=white;
                    }
                }
                else if(board[to_x][to_y]==empty &&(from_x==to_x)){
                    if (from_y < to_y){
                        for(i=from_y;i<=to_y;i++){
                            if (board[to_x][i] == empty ) {
                                counter1++;
                            }
                            if((board[to_x][i]==white_man || board[from_x][i]==white_king) && board[to_x][i + 1] == empty ){
                                board[to_x][to_y] =black_king;
                                board[from_x][from_y] = empty;
                                board[from_x][i] = empty;
                            }
                        }
                    }
                    else if(to_y<from_y){
                        for(i=to_y;i<=from_y;i++){
                            if (board[to_x][i] == empty ) {
                                counter1++;
                            }
                            if ((board[from_x][i]==white_man || board[from_x][i]==white_king) && board[from_x][i-1]==empty){
                                board[to_x][i-1] = black_king;
                                board[from_x][from_y] = empty;
                                board[from_x][i] = empty;
                            }
                        }
                        if (counter1 == (from_y - to_y) || -1*counter1 == (from_y - to_y)) {
                            board[to_x][to_y] = black_king;
                            board[from_x][from_y] = empty;
                        }
                    }
                }
            }
        if ((to_x - from_x) == 1 && (from_y == to_y)) {//YANLIS BİR HAMLE ICIN.
            if (board[to_x][to_y] == empty) {
                if (to_x==7) {
                    board[to_x][to_y] = black_king;
                    board[from_x][from_y] = empty;
                }
                else{
                    board[to_x][to_y] = black_man;
                    board[from_x][from_y] = empty;
                }
            }
        }
        else if ((from_x == to_x) && (to_y - from_y) == 1) {//Eger yanlis bir hamle olursa,hamle sirasi digerine gecer.
            if (board[to_x][to_y] == empty) {
                if (to_x == 7) {
                    board[to_x][to_y] = black_king;
                    board[from_x][from_y] = empty;
                }
                else {
                    board[to_x][to_y] = black_man;
                    board[from_x][from_y] = empty;
                }
            }
        }
        else if ((from_x == to_x) && (to_y - from_y) == -1) {//Eger yanlis bir hamle olursa,hamle sirasi digerine gecer.
            if (board[to_x][to_y] == empty) {
                if (to_x == 7) {
                    board[to_x][to_y] = black_king;
                    board[from_x][from_y] = empty;
                }
                else {
                    board[to_x][to_y] = black_man;
                    board[from_x][from_y] = empty;
                }
            }
        }
        else {
            p = white;

        }
    }
}
int check_end_of_game(piece board[][8]){//kazanani belirlemek icin
    int i,j,counterb=0,counterw=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]==black_man ||board[i][j]==black_king){
                counterb++;
            }
            if(board[i][j]==white_man || board[i][j]==white_king){
                counterw++;
            }
        }
    }
    if(counterb==0){//eger beyazin tasi biterse 1 return eder.
        return 1;
    }
    else if(counterw==0){//eger siyahin tasi biterse 2 return eder.
        return 2;
    }
    else{//oyun devam eder.
        return 0;
    }
}
void sample_game_2() {//oyun simulesi icin.
    piece board[8][8];
    int i, j, move_temp = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            board[i][j] = empty;
        }
    }
    for (i = 0; i < 4; i++) {
        board[1][2 + i] = black_man;
        board[2][1 + i] = black_man;
        board[6][2 + i] = white_man;
    }
    for (i = 0; i < 3; i++) {
        board[3][i] = black_man;
        board[4][2 + i] = white_man;
    }
    for (i = 0; i < 8; i++) {
        if (i != 5) {
            board[5][i] = white_man;
        }
    }
    for (i = 0; i < 2; i++) {
        board[4][6 + i] = white_man;
        board[2][6 + i] = black_man;
        board[3 + i][5] = black_man;
    }
    board[3][7] = black_man;
    display_board(board);
    move_temp = move(board, 5, 1, 4, 1, white);
    display_board(board);
    move_temp = move(board,3,1,5,1, black);
    display_board(board);
    move_temp=move(board,4,3,3,3,white);
    display_board(board);
    move_temp= move(board,4,5,4,3,black);
    move_temp= move(board,4,3,4,1,black);
    display_board(board);
    move_temp= move(board,3,3,3,1,white);
    move_temp= move(board,3,1,1,1,white);
    display_board(board);
    move_temp=move(board,1,2,1,0,black);
    display_board(board);
    move_temp=move(board,5,3,4,3,white);
    display_board(board);
    move_temp=move(board,5,1,5,3,black);
    move_temp=move(board,5,3,5,5,black);
    move_temp=move(board,5,5,7,5,black);
    display_board(board);
    move_temp=move(board,4,3,3,3,white);
    display_board(board);
    move_temp=move(board,2,3,4,3,black);
    display_board(board);
    move_temp=move(board,5,6,5,5,white);
    display_board(board);
    move_temp=move(board,7,5,4,5,black);
    board[4][6]=white_man;
    display_board(board);
    move_temp=move(board,4,6,4,4,white);
    board[4][5]=empty;
    board[4][4]=white_man;
    board[5][3]=white_man;
    board[6][3]=white_man;
    move_temp=move(board,4,4,4,2,white);
    display_board(board);
}