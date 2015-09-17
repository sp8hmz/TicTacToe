#include <iostream>

std::string board[3][3];//tablica będąca planszą gry
int startValue = 0;     //zmienna, która mówi o pierwszym uruchomieniu
int user = 0;           //zmienna do sprawdzania, który user wprowadza wartość
                        //0 - kółko
                        //1 - krzyżyk
int value;              //wartość wprowadzona przez usera od 1 do 9
                        //  1  2  3
                        //  4  5  6
                        //  7  8  9
bool finish = false;    //zmienna modyfikowana przy zakończeniu rozgrywki

void wprowadzWartosc( int a, int b) {
    if (user == 0) {
        if (board[a][b] == "") {
            board[a][b] = "O";
            user++;
        } else {
            std::cout << "Pole zajęte!" << std::endl;
        }
    } else {
        if (board[a][b] == "") {
            board[a][b] = "X";
            user--;
        } else {
            std::cout << "Pole zajęte!" << std::endl;
        }
    }
}

void sprawdz() {
    int xcount = 0, ycount = 0, fullcount = 0;                 //liczniki w pętlach sprawdzających
    
    for (int i = 0; i<=2; i++) {
        for (int j = 0; j<=2; j++) {
            if (board[i][j] != "") {
                fullcount++;
            }
        }
    }
    
    
    for (int i = 0; i<=2; i++) {                                //sprawdzanie pionów i poziomów
        xcount = 0;
        ycount = 0;
        for (int j = 0; j <=2; j++) {
            if (board[i][j] == "X") {
                xcount++;
                if (xcount >=3) {
                    std::cout << "X wygrał!" << std::endl;
                    finish = true;
                }
            }
            if (board[i][j] == "O") {
                ycount++;
                if (ycount >=3) {
                    std::cout << "O wygrał!" << std::endl;
                    finish = true;
                }
            }
        }
    }
    
    for (int i = 0; i<=2; i++) {
        xcount = 0;
        ycount = 0;
        for (int j = 0; j <=2; j++) {
            if (board[j][i] == "X") {
                xcount++;
                if (xcount >=3) {
                    std::cout << "X wygrał!" << std::endl;
                    finish = true;
                    
                }
            }
            if (board[j][i] == "O") {
                ycount++;
                if (ycount >=3) {
                    std::cout << "O wygrał!" << std::endl;
                    finish = true;
                    
                }
            }
        }
    }
    
    xcount = 0;
    ycount = 0;
    for (int i = 0; i<=2; i++) {                                //sprawdzanie skosów
        if (board[i][i] == "X") {
            xcount++;
            if (xcount == 3) {
                std::cout << "X wygrał!" << std::endl;
                finish = true;
            }
        }
        if (board[i][i] == "O") {
            ycount++;
            if (ycount == 3) {
                std::cout << "O wygrał!" << std::endl;
                finish = true;
            }
        }
    }
    
    xcount = 0;
    ycount = 0;
    for (int i = 2; i>=0; i--) {
            if (board[i][2-i] == "X") {
                xcount++;
                if (xcount == 3) {
                    std::cout << "X wygrał!" << std::endl;
                    finish = true;
                }
            }
            if (board[i][2-i] == "O") {
                ycount++;
                if (ycount == 3) {
                    std::cout << "O wygrał!" << std::endl;
                    finish = true;
                }
            }
            
    }
    
    
    if (fullcount >=9 && finish == false) {                                        //sprawdzanie wyjątku, kiedy nikt nie wygrywa
        std::cout << "Nikt nie wygrał!" << std::endl;
        finish = true;
    }
    
}

void wyswietlPlansze() {
    for (int i = 0; i<=2; i++) {
        for (int j = 0; j<=2; j++) {
            std::cout.width(3);
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    
    sprawdz();
}


void mapujKlawisze() {
    switch (value)
    {
        case 11:
            wprowadzWartosc(0,0);
            wyswietlPlansze();
            break;
            
        case 12:
            wprowadzWartosc(0,1);
            wyswietlPlansze();
            break;
            
        case 13:
            wprowadzWartosc(0,2);
            wyswietlPlansze();
            break;
            
        case 21:
            wprowadzWartosc(1,0);
            wyswietlPlansze();
            break;
            
        case 22:
            wprowadzWartosc(1,1);
            wyswietlPlansze();
            break;
            
        case 23:
            wprowadzWartosc(1,2);
            wyswietlPlansze();
            break;
            
        case 31:
            wprowadzWartosc(2,0);
            wyswietlPlansze();
            break;
            
        case 32:
            wprowadzWartosc(2,1);
            wyswietlPlansze();
            break;
            
        case 33:
            wprowadzWartosc(2,2);
            wyswietlPlansze();
            break;
            
        default:
            std::cout << "Podano złą wartość. Podaj odpowiednią liczbę." << std::endl;
            break;
    }
}

void start() {
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "--                  KÓŁKO KRZYŻYK                --" << std::endl;
    std::cout << "--               by Karol Karczewski             --" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl << std::endl;
    std::cout << "Wprowadzane lokalizacje obrazuje poniższy schemat: " << std::endl;
    std::cout << "                     11  12  13                    " << std::endl;
    std::cout << "                     21  22  23                    " << std::endl;
    std::cout << "                     31  32  33                    " << std::endl << std::endl;
    std::cout << "Jeśli chcesz więc wstawić znak w konkretne miejsce," << std::endl;
    std::cout << "po prostu podaj liczbę odpowiadającą miejscu.      " << std::endl << std::endl;
    std::cout << "                    POWODZENIA!                    " << std::endl;
}

int main() {
    if (startValue == 0) {
        start();
        startValue++;
    }
    while (finish == false) {
        if (user == 0) std::cout << "Wprowadź lokalizację O: "; else if (user == 1) std::cout << "Wprowadź lokalizację X: ";
        if (std::cin >> value) {
            mapujKlawisze();
        } else {
            std::cout << "Podano złą wartość. Podaj odpowiednią liczbę." << std::endl;
            std::cin.clear();
            
            std::string str;
            std::cin >> str;
        }
    }
    
    
    std::cout << "Czy chcesz zagrać ponownie? Wprowadź 't' żeby zatwierdzić lub każdy inny znak, aby wyjść. ";
    std::string response;
    std::cin >> response;
    
    if (response == "t") {
        finish = false;
        
        for (int i = 0; i<=2; i++) {
            for (int j = 0;j<=2; j++) {
                board[i][j] = "";
            }
        }
        
        main();
    }
    return(0);
}
