#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() {
        window.create(sf::VideoMode(300, 300), "Tic Tac Toe");
        board.resize(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
        drawGrid();
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            window.clear();
            drawGrid();
            drawSymbols();
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x / 100; // 300/3 = 100
                    int y = event.mouseButton.y / 100; // 300/3 = 100
                    if (board[y][x] == ' ') {
                        board[y][x] = currentPlayer;
                        if (checkWinner(currentPlayer)) {
                            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                            window.close();
                        } else {
                            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        }
                    }
                }
            }
        }
    }

    void drawGrid() {
        sf::RectangleShape line(sf::Vector2f(300, 5));
        line.setFillColor(sf::Color::Black);
        
        // Vertical lines
        line.setPosition(100, 0);
        window.draw(line);
        line.setPosition(200, 0);
        window.draw(line);
        
        // Horizontal lines
        line.setSize(sf::Vector2f(5, 300));
        line.setPosition(0, 100);
        window.draw(line);
        line.setPosition(0, 200);
        window.draw(line);
    }

    void drawSymbols() {
        sf::Font font;
        font.loadFromFile("arial.ttf"); // Make sure to have a font file

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != ' ') {
                    sf::Text text;
                    text.setFont(font);
                    text.setString(board[i][j]);
                    text.setCharacterSize(60);
                    text.setPosition(j * 100 + 25, i * 100 + 10);
                    window.draw(text);
                }
            }
        }
    }

    bool checkWinner(char player) {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                return true;
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return true;
        return false;
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
