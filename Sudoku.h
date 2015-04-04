#define MAX 144
class Sudoku{
public:
    Sudoku();
    void ReadIn();
    void Solve();
    void GiveQuestion();
private:
    int board[MAX],answer[MAX];
    static int oringq[MAX];
    bool unique,success,solvable;
    void solve(int grid);
    bool isCorrect(int place);
    void numchange();
};