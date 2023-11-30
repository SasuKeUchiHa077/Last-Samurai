#include <iostream>
#include <ctime>
using std::cout;
using std::cin;

int PlayerDamage() {
    int playerAttack = (rand() % 22) + 1;
    
    if (playerAttack  > 10) {
        cout << "Enemy got hit : -" << playerAttack << '\n';
        return playerAttack;
    }
    
    else {
        cout << "You missed the attack\n";
        return 0;
    }
}

int EnemyDamage() {
    int enemyAttack = (rand() % 30) + 1;
    
    if (enemyAttack > 10) {
        cout << "You got hit : -" << enemyAttack;
        return enemyAttack;
    }
    
    else {
        cout << "Enemy Missed the attack.";
        return 0;
    }
}

void DecideWinner(int yourHealth) {
    if (yourHealth < 0) {
        cout << "You Lose, better luck next time!\n";
    }
    
    else {
        cout << "Congratulations, You Win!\n";
    }
}

int main() {
    srand(time(0));
    int choice = 0;
    int yourHealth = 100,enemyHealth = 100;
    
    cout << "~~~~~~⚔ Last Samurai ⚔~~~~~~\n\n";
    
    do {
        cout << "Your Health : " << yourHealth;
        cout << "\nEnemy Health : " << enemyHealth;
        cout << "\n\n1 - Attack\n2 - Defend\n";
        cout << "Enter : ";
        cin >> choice;
        cout << '\n';
        
        if (choice == 1) {
            enemyHealth -= PlayerDamage();
            yourHealth -= EnemyDamage();
        }
        
        else if (choice == 2) {
            cout << "Enemy attacked you.\nBut you defended yourself :)";
        }
        
        else {
            continue;;
        }
        cout << "\n\n-----------------------------\n\n";
    } while (yourHealth > 0 && enemyHealth > 0);
    
    DecideWinner(yourHealth);
    
    return 0;
}
