#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"

int Sudoku::oringq[MAX]={
    7,0,0,0,0,3,0,0,0,-1,-1,-1,
    1,0,5,0,0,0,8,0,0,-1,-1,-1,
    0,8,0,0,0,0,2,5,0,-1,-1,-1,
    0,0,0,0,4,0,-1,-1,-1,9,0,0,
    0,0,0,9,0,1,-1,-1,-1,5,0,0,
    3,0,0,0,6,0,-1,-1,-1,0,8,0,
    0,9,0,-1,-1,-1,0,0,0,0,0,7,
    0,0,2,-1,-1,-1,5,4,3,0,0,0,
    0,0,0,-1,-1,-1,0,2,0,0,0,0,
    -1,-1,-1,0,7,0,0,0,0,0,6,0,
    -1,-1,-1,0,0,6,0,0,0,8,3,4,
    -1,-1,-1,0,0,0,4,0,0,0,0,9
};

Sudoku::Sudoku(){
    srand(time(NULL));
}

void Sudoku::ReadIn(){
    int negative=0;
    solvable=true;success=false;unique=true;
    for(int i=0;i<MAX;i++){
        scanf("%d",&board[i]);
        if(board[i]==-1) negative++;
    }
    if(negative!=36) solvable=false;
    else{
        for(int i=0;i<MAX;i++){
            if(isCorrect(i)==false){
                solvable=false;
                break;
            }
        }
    }
    return;
}

void Sudoku::Solve(){
    if(solvable==false){
        puts("0");
        return;
    }
    solve(0);
    if(success==false){
        puts("0");
        return;
    }else if(unique==false){
        puts("2");
        return;
    }else{
        puts("1");
        for(int i=0;i<MAX;i++){
            printf("%d ",answer[i]);
            if((i+1)%12==0){
                puts("");
            }
        }
        return;
    }
}

void Sudoku::solve(int grid){
	if(unique==false) return;
    if(grid==MAX){
        if(success==false){
            success=true;
            for(int i=0;i<MAX;i++){
                answer[i]=board[i];
            }
        }else{
            unique=false;
        }
        return;
    }
    if(board[grid]==0){
        for(int i=1;i<=9;i++){
            board[grid]=i;
            if (isCorrect(grid)){
                solve(grid+1);
            }
        }
        board[grid]=0;
    }
    else{
        solve(grid+1);
    }
}

void Sudoku::GiveQuestion(){
    numchange();
    // for(int i=0;i<MAX;i++){
    //     board[i]=oringq[i];
    // }
    // for(int i=0;i<MAX;i++){
    //     if(board[i]<=0) continue;
    //     int tmp=board[i];
    //     board[i]=0;
    //     success=false;unique=true;
    //     solve(0);
    //     if(success==false){
    //         printf("Hole in %d:Not Success\n",i);
    //         board[i]=tmp;
    //     }else if(unique==false){
    //         printf("Hole in %d:Not Unique\n",i);
    //         board[i]=tmp;
    //     }else{
    //         printf("Hole in %d:Success\n",i);
    //     }
    // }
    for(int i=0;i<MAX;i++){
        printf("%d ",oringq[i]);
        if((i+1)%12==0) puts("");
    }
}

void Sudoku::numchange(){
    int list[10];
    bool used[10]={false};
    int n;
    for(int i=1;i<=9;i++){
        n=rand()%9+1;
        while(used[n]==true) n=rand()%9+1;
        used[n]=true;
        list[i]=n;
    }
    for(int i=0;i<MAX;i++){
        if(oringq[i]<=0) continue;
        oringq[i]=list[oringq[i]];
    }
}

bool Sudoku::isCorrect(int place){
    int now=board[place];
    int row=place/12;
    int col=place%12;
    if(now==-1||now==0) return true;
    //same row
    for(int i=0;i<12;i++){
        if(board[row*12+i]==now && i!=col){
            return false;
        }
    }
    //same column
    for(int i=0;i<12;i++){
        if(board[i*12+col]==now && i!=row){
            return false;
        }
    }
    //same block
    int blockrow=row/3*3;
    int blockcol=col/3*3;
    for(int i=blockrow;i<blockrow+3;i++){
        for(int j=blockcol;j<blockcol+3;j++){
            if(board[i*12+j]==now && i!=row && j!=col){
                return false;
            }else if(board[i*12+j]==-1){
                return false;
            }
        }
    }
    return true;
}
