#include <cstdio>
#include "Sudoku.h"

void Sudoku::ReadIn(){
    int negative=0,num=0;
    solvable=true;success=false;unique=true;
    for(int i=0;i<MAX;i++){
        scanf("%d",&board[i]);
        if(board[i]==-1) negative++;
        else if(board[i]>=1 && board[i]<=9) num++;
    }
    if(negative!=36 || num<17) solvable=false;
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
            }
        }
    }
    return true;
}