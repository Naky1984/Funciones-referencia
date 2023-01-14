// referencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP1 = 100;
string enemyName1 = "Zombie";
bool enemyIsAlive1 = true;

//Atributos del enemigo 2
int enemyHP2 = 150;
string enemyName2 = "Creeper";
bool enemyIsAlive2 = true;

//Atributos del personaje
int heroHP = 350;
int heroDamage;
string heroName;
bool heroIsAlive = true;

//Atributos del juego
int enemyChoosed = 0;
int magicPoints = 2;
int sopapoValue = 10;
int espadazoValue = 30;
int magicValue = 50;

void gameStart() {
    cout << "El enemigo " << enemyName1 << " ha aparecido\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}


void checkEnemys(string name, int& eneHp, bool& enemyLive) {
    if (eneHp <= 0) {
        cout << "Te has cargado al enemigo " << name << " \n";
        eneHp = 0;
        enemyLive = false;
    }
    else {
        cout << "El enemigo " << name << " tiene " << eneHp << " puntos de vida\n";
        enemyLive = true;
    }
}
void chooseEnemy(string namesEnemy,int&Choose, bool&lifeEnemys) {
          Choose = 0;
    while (Choose != 1 && Choose != 2) {
        cout << "A que enemigo quieres atacar? \n";
        if (lifeEnemys) {
            cout << "1.- " << namesEnemy << "\n";
            lifeEnemys = true;
        }
        cin >> Choose;
        if (Choose <= 0 || Choose > 2) {
            cout << "La opcion elegida no es correcta. Por favor, elige una opcion valida. \n";
        }
        if (!lifeEnemys && Choose == 1 && Choose == 2) {
            cout << "El enemigo " << namesEnemy << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo." " \n";
            Choose = 0;
            lifeEnemys = false;
        }  
    }
}

int chooseAttack() {
    int attackChoose = 0;
    while (attackChoose != 1 && attackChoose != 2 && attackChoose != 3) {
        cout << "Que ataque quieres usar? \n";
        cout << "1.- Espadazo \n";
        cout << "2.- Sopapo \n";
        if (magicPoints > 0) {
            cout << "3.- Magia\n";
        }
        cin >> attackChoose;
        if (attackChoose <= 0 || attackChoose > 3) {
            cout << "El ataque seleccionado no es correcto. Por favor, elige una opcion valida. \n";
        }
        if (attackChoose == 3) {
            if (magicPoints > 0) {
                magicPoints--;
            }
            else {
                attackChoose = 0;
                cout << "No te queda magia. Por favor selecciona un ataque que puedas usar. \n";
            }
        }
    }
    if (attackChoose == 1) {
        return espadazoValue;
    }
    else if (attackChoose == 2) {
        return sopapoValue;
    }
    else {
        return magicValue;
    }
}


void heroAttack(string name,int damage, int& Life) {
    cout << "Atacas al enemigo " << name << " y le haces un danyo de " << damage << " \n";
    Life = Life - damage;
}

void enemyAttack(string name,int damage) {
    heroHP = heroHP - damage;
    if (heroHP > 0) {
        cout << "El enemigo " << name << " te ha atacado y te quedan " << heroHP << " puntos de vida\n";
    }
    else {
        cout << "El enemigo " << name << " te ha atacado y te ha matado. El mundo esta condenado. \n";
        heroIsAlive = false;
    }
}

int main()
{
    gameStart();
    while (heroIsAlive && (enemyIsAlive1 || enemyIsAlive2)) {
        //ELEGIMOS ENEMIGO AL QUE ATACAR
         chooseEnemy(enemyName1,enemyChoosed,enemyIsAlive1);
         chooseEnemy(enemyName2, enemyChoosed, enemyIsAlive2);
        //ELEGIMOS ATAQUE Y CAPTURAMOS EL VALOR DEL DANYO QUE HAREMOS
        heroDamage = chooseAttack();

        if (enemyChoosed == 1) {
            //ATACAMOS AL ENEMIGO 1
           heroAttack(enemyName1, heroDamage,enemyHP1);          
           checkEnemys(enemyName1, enemyHP1, enemyIsAlive1);
        }
        else {
            //ATACAMOS AL ENEMIGO 2
            heroAttack(enemyName2, heroDamage,enemyHP2);        
            checkEnemys(enemyName2, enemyHP2, enemyIsAlive2);
                
        }
        //ATACA EL ENEMIGO 1 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive1 && heroIsAlive) {
            enemyAttack(enemyName1 ,30 + rand() % 20);
        }
        //ATACA EL ENEMIGO 2 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive2 && heroIsAlive) {
            enemyAttack(enemyName2,30 + rand() % 20);
        }
    }
}
