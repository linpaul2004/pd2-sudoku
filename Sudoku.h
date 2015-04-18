#define MAX 144
class Sudoku{
public:
    Sudoku();
    void ReadIn();
    void Solve();
    void GiveQuestion();
private:
    int board[MAX],answer[MAX];
    static int oringq[MAX],specq[MAX];
    bool unique,success,solvable;
    void solve(int grid);
    bool isCorrect(int place);
    void numchange();
    void rotate();
    void order();
};