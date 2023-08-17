#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

class CasinoGame {
private:
    int secretNumber;
    int playerBalance;

public:
    CasinoGame() : secretNumber(0), playerBalance(1000) {
        srand(time(0));
    }

    void generateSecretNumber(int min, int max) {
        secretNumber = rand() % (max - min + 1) + min;
    }

    int getPlayerBalance() const {
        return playerBalance;
    }

    void playGame() {
        int guess;
        std::cout << "Welcome to the Casino Number Guessing Game!" << std::endl;
        std::cout << "Your current balance: $" << playerBalance << std::endl;

        while (playerBalance > 0) {
            int bet;
            std::cout << "Enter your bet: ";
            std::cin >> bet;

            if (bet > playerBalance) {
                std::cout << "Insufficient balance. Please enter a valid bet." << std::endl;
                continue;
            }

            playerBalance -= bet;

            int minRange = 1;
            int maxRange = 100;
            generateSecretNumber(minRange, maxRange);

            std::cout << "Guess a number between " << minRange << " and " << maxRange << ": ";
            std::cin >> guess;

            if (guess == secretNumber) {
                int winnings = bet * 3;
                std::cout << "Congratulations! You guessed right. You win $" << winnings << "!" << std::endl;
                playerBalance += winnings;
            } else {
                std::cout << "Sorry, the secret number was " << secretNumber << ". You lose $" << bet << "." << std::endl;
            }

            std::cout << "Your current balance: $" << playerBalance << std::endl;

            char playAgain;
            std::cout << "Play again? (y/n): ";
            std::cin >> playAgain;

            if (playAgain != 'y' && playAgain != 'Y') {
                break;
            }
        }

        std::cout << "Thank you for playing!" << std::endl;
    }
};

int main() {
    CasinoGame game;
    game.playGame();

    return 0;
}
