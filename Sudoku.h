#define MAX 144
class Sudoku{
public:
    void ReadIn();
    void Solve();
    void GiveQuestion();
private:
    int board[MAX],answer[MAX];
    bool unique,success,solvable;
    void solve(int grid);
    bool isCorrect(int place);
};