#include <iostream>
#include <cstring>
using namespace std;

/*Ricreare il gioco del tris,
gioca prima il giocatore 1 (X) e poi il giocatore 2 (O)*/

int main()
{
    char tabella[3][3] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };

    char backup[3][3] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };

    string giocatoreX;
    string giocatoreO;
    cout << "Benvenuti a TRIS, giochera' prima il giocatore X, poi il giocatore O" << endl;
    cout << endl;
    
    cout << "Inserisci il nome del giocatore X: ";
    getline(cin, giocatoreX);
    cout << "Inserisci il nome del giocatore O: ";
    getline(cin, giocatoreO);
    cout << endl;
    
    //stampo la tabella
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << tabella[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    bool finito=false;
    char mossa;
    int counter=0;
    int carattere_attuale=0;
    char carattere_giocato='X';
    string giocatore_attuale=giocatoreX;
    char ricominciare, ricominciare_pareggio;

    while (!finito)
    {
        bool validoX=false;
        while (!validoX)
        {
            //faccio scegliere al giocatore la posizione e controllo che sia una mossa valida
            cout << "Il giocatore " << giocatore_attuale << " (" << carattere_giocato << ") fa la sua mossa: ";
            cin >> mossa;

            //cerco la posizione data dal giocatore
            for (int i=0;i<3;i++)
            {
                for (int j=0;j<3;j++)
                {
                    if (tabella[i][j]==mossa)
                    {
                        tabella[i][j]=carattere_giocato;
                        validoX=true;
                    }
                }
            }
            if (!validoX) cout << "Inserisci una mossa valida." << endl;
        }

        //stampo la tabella aggiornata
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                cout << tabella[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        //controllo le possibilità di vittoria e chiedo se si vuole ricominciare una nuova partita
        if (tabella[0][0]==carattere_giocato && tabella[0][1]==carattere_giocato && tabella[0][2]==carattere_giocato || tabella[1][0]==carattere_giocato && tabella[1][1]==carattere_giocato && tabella[1][2]==carattere_giocato || tabella[2][0]==carattere_giocato && tabella[2][1]==carattere_giocato && tabella[2][2]==carattere_giocato || tabella[0][0]==carattere_giocato && tabella[1][1]==carattere_giocato && tabella[2][2]==carattere_giocato || tabella[2][0]==carattere_giocato && tabella[1][1]==carattere_giocato && tabella[0][2]==carattere_giocato || tabella[0][0]==carattere_giocato && tabella[1][0]==carattere_giocato && tabella[2][0]==carattere_giocato || tabella[0][1]==carattere_giocato && tabella[1][1]==carattere_giocato && tabella[2][1]==carattere_giocato || tabella[0][2]==carattere_giocato && tabella[1][2]==carattere_giocato && tabella[2][2]==carattere_giocato)
        {
            cout << "Gioco finito, vince il giocatore " << giocatore_attuale << " (" << carattere_giocato << "). Congratulazioni!!" << endl;
            bool verita=false;
            while (!verita)
            {
                cout << "Volete riconinciare una nuova partita? (S/N) ";
                cin >> ricominciare;
                if (ricominciare=='S' || ricominciare=='N' || ricominciare=='s' || ricominciare=='n') verita=true;
            }
            if (ricominciare=='N' || ricominciare=='n')
            {
                //finito=true;
                cout << "Tornate presto!!" << endl;
                break;
            }
            else
            {
                system ("cls");
                for (int i=0;i<3;i++)
                {
                    for (int j=0;j<3;j++)
                    {
                        tabella[i][j]=backup[i][j];
                    }
                }
                carattere_attuale=-1;
            }
        }

        //Gestisco il caso del pareggio
        int counter_pareggio=0;
        bool verita_pareggio=false;
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (tabella[i][j]!='X' && tabella[i][j]!='O') counter_pareggio++;
            }
        }
        if (counter_pareggio==0)
        {
            while (!verita_pareggio)
            {
                cout << "La partita e' finita in pareggio. Volete ricominciare una nuova partita? (S/N) ";
                cin >> ricominciare_pareggio;
                if (ricominciare_pareggio=='S' || ricominciare_pareggio=='N' || ricominciare_pareggio=='s' || ricominciare_pareggio=='n') verita_pareggio=true;
            }
            if (ricominciare_pareggio=='N' || ricominciare_pareggio=='n')
            {
                //finito=true;
                cout << "Tornate presto!!" << endl;
                break;
            }
            else
            {
                system ("cls");
                for (int i=0;i<3;i++)
                {
                    for (int j=0;j<3;j++)
                    {
                        tabella[i][j]=backup[i][j];
                    }
                }
                carattere_attuale=-1;
            }
        }

        //Scambio dei due giocatori partecipanti
        carattere_attuale++;
        if(carattere_attuale%2==0)
        {
            carattere_giocato='X';
            giocatore_attuale=giocatoreX;
        }
        else
        {
            carattere_giocato='O';
            giocatore_attuale=giocatoreO;
        }
    }
    
    system ("pause");
    return 0;
}