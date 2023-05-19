#include <stdio.h>

int main(){
    char c;
    while(scanf("%c", &c)!=EOF){
        if(c=='1') c='`';
        else if (c=='2') c='1';
        else if (c=='3') c='2';
        else if (c=='4') c='3';
        else if (c=='5') c='4';
        else if (c=='6') c='5';
        else if (c=='7') c='6';
        else if (c=='8') c='7';
        else if (c=='9') c='8';
        else if (c=='0') c='9';
        else if (c=='-') c='0';
        else if (c=='=') c='-';
        else if (c=='W') c='Q';
        else if (c=='E') c='W';
        else if (c=='R') c='E';
        else if (c=='T') c='R';
        else if (c=='Y') c='T';
        else if (c=='U') c='Y';
        else if (c=='I') c='U';
        else if (c=='O') c='I';
        else if (c=='P') c='O';
        else if (c=='[') c='P';
        else if (c==']') c='[';
        else if (c=='\\') c=']';
        else if (c=='S') c='A';
        else if (c=='D') c='S';
        else if (c=='F') c='D';
        else if (c=='G') c='F';
        else if (c=='H') c='G';
        else if (c=='J') c='H';
        else if (c=='K') c='J';
        else if (c=='L') c='K';
        else if (c==';') c='L';
        else if (c=='\'') c=';';
        else if (c=='X') c='Z';
        else if (c=='C') c='X';
        else if (c=='V') c='C';
        else if (c=='B') c='V';
        else if (c=='N') c='B';
        else if (c=='M') c='N';
        else if (c==',') c='M';
        else if (c=='.') c=',';
        else if (c=='/') c='.';
        else if (c==' ') c=' ';
        printf("%c", c);
    }
}