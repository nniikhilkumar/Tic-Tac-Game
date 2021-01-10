#include<iostream>
using namespace std;

      char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
      char uturn = 'X';
      int r,c;
      bool draw=false;
void display(){
    system("cls");
    cout<<"\n\n\t\t\t\t\t\tTIC TAC GAME\n";
    cout<<"\n\t\t\tPlayer1=[X]\n";
    cout<<"\n\t\t\tPlayer2=[O]\n";
    cout<<"\n\n\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t___"<<arr[0][0]<<"____|___"<<arr[0][1]<<"___|___"<<arr[0][2]<<"____\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
     cout<<"\t\t\t\t\t___"<<arr[1][0]<<"____|___"<<arr[1][1]<<"___|___"<<arr[1][2]<<"____\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t   "<<arr[2][0]<<"    |   "<<arr[2][1]<<"   |   "<<arr[2][2]<<"\n";
}
void turn(){
    int n;
    if (uturn=='X')
    cout<<"\n\t\t\tPlayer1[X] turn:";
     if (uturn=='O')
    cout<<"\n\t\t\tPlayer2[O] turn:";
    cin>>n;
    switch(n){
    case 1:
        r=0;c=0;
        break;
        case 2:
        r=0;c=1;
        break;
        case 3:
        r=0;c=2;
        break;
        case 4:
        r=1;c=0;
        break;
        case 5:
        r=1;c=1;
        break;
        case 6:
        r=1;c=2;
        break;
        case 7:
        r=2;c=0;
        break;
        case 8:
        r=2;c=1;
        break;
        case 9:
        r=2;c=2;
        break;
        default:
            cout<<"\n\n\t\t\t\t\tEnter invalid  key!!"<<endl;
            break;
    }
    if(uturn=='X' && arr[r][c]!='X'&& arr[r][c]!='O'){
        arr[r][c]='X';
        uturn ='O';
    }
    else if(uturn=='O' && arr[r][c]!='X'&& arr[r][c]!='O'){
        arr[r][c]='O';
        uturn ='X';
    }
    else{
        cout<<"\n\n\t\t\t\t\t\tPlease try again\n\n";
        turn();
    }
    display();
}
bool gameover(){
    for(int i=0;i<3;++i){
        if(arr[i][0]==arr[i][1]&&arr[i][0]==arr[i][2])
            return false;
        if(arr[0][0]==arr[1][i]&&arr[0][i]==arr[2][i])
            return false;
    }
    if(arr[0][2]==arr[1][1]&&arr[0][2]==arr[2][0]){
        return false;
    }
    if(arr[0][0]==arr[1][1]&& arr[0][0]==arr[2][2]){
        return false;
    }
    for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
    if(arr[i][j]!='X'&& arr[i][j]!='O')
    return true;
    }
    }
    draw =true;
    return false;
}
int main(){
    while(gameover()){
    display();
    turn();
    }
    if(uturn =='X'&& draw==false)
    cout<<"\n\n\t\t\t\tPlayer2[O] WINS!! Congrats!!!!\n";
     if(uturn =='O'&& draw==false)
    cout<<"\n\n\t\t\t\tplayer1[X] WINS!! Congrats!!!!\n";
    else
        cout<<"\n\n\t\t\t\t\tGame Draw!!!!!!!\n";
    return 0;


}
