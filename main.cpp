// Alexis Diaz ID223
// Adventure #1 Program

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <thread>           // sleep_for function
#include <chrono>           // sleep_for function
using namespace std;

int main() {
    // Welcoming the player
    cout << "Hello there! Welcome to this adventure game!\n";
    string playerName;
    cout << "What is your name? >> ";
    cin >> playerName;
    cout << "Welcome " << playerName << "!\n";

    // Seeding the random number generator
    srand(time(0));

    // Setting up the game
    int health = 10, attack = 0, block = 0, turns = 0;


    // Main game loop
    while (health > 0 && turns < 4) {
        turns++;
        attack = rand() % 4 + 1;  // Generates random attack #
        block = rand() % 4 + 1;     // Generates random block #

        cout << "Attack: " << attack << endl;
        cout << "Block: " << block << endl;
        if (block >= attack) {
            cout << "Successful block!\n";
            std::chrono::milliseconds timespan(2000); // Used to delay program for 2 seconds
            std::this_thread::sleep_for(timespan);  // Used to delay program for 2 seconds
        }
        else {
            health = health - attack;
            cout << "You took damage!\n";
            std::chrono::milliseconds timespan(2000); // Used to delay program for 2 seconds
            std::this_thread::sleep_for(timespan); // Used to delay program for 2 seconds
        }
        cout << "Health: " << health << endl;

        //Checks players current health to see if they need to go to the doctor
        if (health <= 0) {
            cout << "Go see a doctor " << playerName << ", your health is below 0!\n";
        }
        else if (health < 5) {
            cout << "Go see a doctor " << playerName << ", your health is running low!\n";
            }
        }
        
        // Checks player health to see if they won or not
        if (health > 0) {
            cout << "Congrats, you won!\n\n";
        }
        else {
            cout << "You died!\n\n";
        }
        
        cout << "Thanks for playing " << playerName << "!\n";
}