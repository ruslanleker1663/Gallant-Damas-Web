#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Representasi bidak-bidak catur
enum class Piece { Pawn, Knight, Bishop, Rook, Queen, King, Empty };

// Representasi warna bidak
enum class Color { White, Black };

// Struktur yang merepresentasikan kotak di papan catur
struct Square {
    Piece piece;
    Color color;
};

// Representasi papan catur
class Board {
private:
    map<string, Square> squares; // Kotak pada papan catur

public:
    // Konstruktor untuk inisialisasi papan catur
    Board() {
        // Inisialisasi bidak-bidak awal pada papan catur
        squares["a1"] = {Piece::Rook, Color::White};
        squares["b1"] = {Piece::Knight, Color::White};
        squares["c1"] = {Piece::Bishop, Color::White};
        squares["d1"] = {Piece::Queen, Color::White};
        squares["e1"] = {Piece::King, Color::White};
        squares["f1"] = {Piece::Bishop, Color::White};
        squares["g1"] = {Piece::Knight, Color::White};
        squares["h1"] = {Piece::Rook, Color::White};

        squares["a2"] = {Piece::Pawn, Color::White};
        squares["b2"] = {Piece::Pawn, Color::White};
        squares["c2"] = {Piece::Pawn, Color::White};
        squares["d2"] = {Piece::Pawn, Color::White};
        squares["e2"] = {Piece::Pawn, Color::White};
        squares["f2"] = {Piece::Pawn, Color::White};
        squares["g2"] = {Piece::Pawn, Color::White};
        squares["h2"] = {Piece::Pawn, Color::White};

        squares["a8"] = {Piece::Rook, Color::Black};
        squares["b8"] = {Piece::Knight, Color::Black};
        squares["c8"] = {Piece::Bishop, Color::Black};
        squares["d8"] = {Piece::Queen, Color::Black};
        squares["e8"] = {Piece::King, Color::Black};
        squares["f8"] = {Piece::Bishop, Color::Black};
        squares["g8"] = {Piece::Knight, Color::Black};
        squares["h8"] = {Piece::Rook, Color::Black};

        squares["a7"] = {Piece::Pawn, Color::Black};
        squares["b7"] = {Piece::Pawn, Color::Black};
        squares["c7"] = {Piece::Pawn, Color::Black};
        squares["d7"] = {Piece::Pawn, Color::Black};
        squares["e7"] = {Piece::Pawn, Color::Black};
        squares["f7"] = {Piece::Pawn, Color::Black};
        squares["g7"] = {Piece::Pawn, Color::Black};
        squares["h7"] = {Piece::Pawn, Color::Black};

        for (char file = 'a'; file <= 'h'; ++file) {
            for (int rank = 3; rank <= 6; ++rank) {
                string squareName = string(1, file) + to_string(rank);
                squares[squareName] = {Piece::Empty, Color::White}; // Semua kotak kosong
            }
        }
    }

    // Fungsi untuk menampilkan papan catur
    void display() const {
        cout << "  a b c d e f g h" << endl;
        cout << " +----------------" << endl;
        for (int rank = 8; rank >= 1; --rank) {
            cout << rank << "|";
            for (char file = 'a'; file <= 'h'; ++file) {
                string squareName = string(1, file) + to_string(rank);
                if (squares.at(squareName).piece == Piece::Empty) {
                    cout << " ";
                } else {
                    cout << static_cast<char>(squares.at(squareName).piece);
                }
                cout << " ";
            }
            cout << "|" << rank << endl;
        }
        cout << " +----------------" << endl;
        cout << "  a b c d e f g h" << endl;
    }
};

int main() {
    Board board;
    board.display();
    return 0;
}
