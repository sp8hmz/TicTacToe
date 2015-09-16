#include <iostream>

using namespace std;

string board[3][3];     //tablica będąca planszą gry
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
            cout << "Pole zajęte!" << endl;
        }
    } else {
        if (board[a][b] == "") {
            board[a][b] = "X";
            user--;
        } else {
            cout << "Pole zajęte!" << endl;
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
                    cout << "X wygrał!" << endl;
                    finish = true;
                }
            }
            if (board[i][j] == "O") {
                ycount++;
                if (ycount >=3) {
                    cout << "O wygrał!" << endl;
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
                    cout << "X wygrał!" << endl;
                    finish = true;
                    
                }
            }
            if (board[j][i] == "O") {
                ycount++;
                if (ycount >=3) {
                    cout << "O wygrał!" << endl;
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
                cout << "X wygrał!" << endl;
                finish = true;
            }
        }
        if (board[i][i] == "O") {
            ycount++;
            if (ycount == 3) {
                cout << "O wygrał!" << endl;
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
                    cout << "X wygrał!" << endl;
                    finish = true;
                }
            }
            if (board[i][2-i] == "O") {
                ycount++;
                if (ycount == 3) {
                    cout << "O wygrał!" << endl;
                    finish = true;
                }
            }
            
    }
    
    
    if (fullcount >=9 && finish == false) {                                        //sprawdzanie wyjątku, kiedy nikt nie wygrywa
        cout << "Nikt nie wygrał!" << endl;
        finish = true;
    }
    
}

void wyswietlPlansze() {
    for (int i = 0; i<=2; i++) {
        for (int j = 0; j<=2; j++) {
            cout.width(3);
            cout << board[i][j];
        }
        cout << endl;
    }
    
    sprawdz();
}


void mapujKlawisze() {
    switch (value)
    {
        case 1:
            wprowadzWartosc(0,0);
            wyswietlPlansze();
            break;
            
        case 2:
            wprowadzWartosc(0,1);
            wyswietlPlansze();
            break;
            
        case 3:
            wprowadzWartosc(0,2);
            wyswietlPlansze();
            break;
            
        case 4:
            wprowadzWartosc(1,0);
            wyswietlPlansze();
            break;
            
        case 5:
            wprowadzWartosc(1,1);
            wyswietlPlansze();
            break;
            
        case 6:
            wprowadzWartosc(1,2);
            wyswietlPlansze();
            break;
            
        case 7:
            wprowadzWartosc(2,0);
            wyswietlPlansze();
            break;
            
        case 8:
            wprowadzWartosc(2,1);
            wyswietlPlansze();
            break;
            
        case 9:
            wprowadzWartosc(2,2);
            wyswietlPlansze();
            break;
            
        default:
            cout << "Podano złą wartość. Podaj liczbę w zakresie 1-9." << endl;
            break;
    }
}

void start() {
    cout << "---------------------------------------------------" << endl;
    cout << "--                  KÓŁKO KRZYŻYK                --" << endl;
    cout << "--               by Karol Karczewski             --" << endl;
    cout << "---------------------------------------------------" << endl << endl;
    cout << "Wprowadzane lokalizacje obrazuje poniższy schemat: " << endl;
    cout << "                      1  2  3                      " << endl;
    cout << "                      4  5  6                      " << endl;
    cout << "                      7  8  9                      " << endl << endl;
    cout << "Jeśli chcesz więc wstawić znak w konkretne miejsce," << endl;
    cout << "po prostu podaj cyfrę odpowiadającą miejscu.       " << endl << endl;
    cout << "                    POWODZENIA!                    " << endl;
}

int main() {
    if (startValue == 0) {
        start();
        startValue++;
    }
    //mapowanie = 0;
    while (finish == false) {
        if (user == 0) cout << "Wprowadź lokalizację O: "; else if (user == 1) cout << "Wprowadź lokalizację X: ";
        if (cin >> value) {
            mapujKlawisze();
        } else {
            cout << "Podano złą wartość. Podaj liczbę w zakresie 1-9."<<endl;
            cin.clear();
            
            string str;
            cin >> str;
        }
    }
    
    
    cout << "Czy chcesz zagrać ponownie? Wprowadź 't' żeby zatwierdzić lub każdy inny znak, aby wyjść. ";
    string response;
    cin >> response;
    
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
