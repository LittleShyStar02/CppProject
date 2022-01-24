#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Key{
	public:
		static int getKey(){
			int ch = getch();
			if(ch == 0 || ch == 224) ch = getch();
			return ch;
		}
};

const int DIM = 16;
const int ESC = 27;

void change(int &N,int &M);
void copy(char first[][DIM],int N,int M,char second[][DIM]);
void home(int gradi);
void insertMatrix(char matrix[][DIM],int &N,int &M);
void insertValueInRange(int &value,int min,int max,string msg);
void print(char matrix[][DIM],int N,int M);
void rotateDX(char matrix[][DIM],int &N,int &M,int gradi);
void rotateSX(char matrix[][DIM],int &N,int &M,int gradi);

void fake_animation(){
	cout<<"Primo avvio...";
	Sleep(1000);
	system("cls");
	cout<<"Preparazione primo inserimento della matrice...";
	Sleep(2000);
	system("cls");
}

main(){
	int gradi = 90;
	int ch,N,M;
	char matrix[DIM][DIM];
	fake_animation();
	insertMatrix(matrix,N,M);
	do{
		 system("CLS");
		 home(gradi);
		 print(matrix,N,M);
		 ch = Key::	getKey();
		 switch(ch){
		 	case 105:
	 		case 73:
	 			system("CLS");
	 			insertMatrix(matrix,N,M);
	 			cout<<endl;
	 			system("pause");
	 			break;
			case 72:
				if(gradi < 270) gradi += 90;
				break;
			case 80:
				if(gradi > 90) gradi -= 90;
				break;
			case 75:
		    rotateSX(matrix,N,M,gradi);
				break;
			case 77:
				rotateDX(matrix,N,M,gradi);
				break;
			case ESC:
				cout<<"Bye bye";
				Sleep(2000);
		 }
	}while(ch != ESC);
	
}

void change(int &N,int &M){
	if(N != M){
		int tmp = N;
		N = M;
		M = tmp;
	}
}

void copy(char first[][DIM],int N,int M,char second[][DIM]){
	for(int x = 0;x < N;x++){
		for(int y = 0;y < M;y++){
			second[x][y] = first[x][y];
		}
	}
}

void home(int gradi){
	cout<<"\nPremi: "<<endl;
	cout<<"  'I' per inserire una matrice"<<endl;
	cout<<"  'freccia destra' per ruotare la matrice verso destra"<<endl;
	cout<<"  'freccia sinistra' per ruotare la matrice verso sinistra"<<endl;
	cout<<"  'freccia su' per aumentare i gradi di +90"<<endl;
	cout<<"  'freccia giu'' per diminuire i gradi di -90"<<endl;
	cout<<"  'ESC' per uscire dal programma"<<endl;
	cout<<"  Gradi attuali: "<<gradi<<endl<<endl;
}

void insertMatrix(char matrix[][DIM],int &N,int &M){
	insertValueInRange(N,0,DIM,"\nInserisci il numero delle righe della matrice: ");
	insertValueInRange(M,0,DIM,"\nInserisci il numero delle colonne della matrice: ");
	for(int x = 0;x < N;x++){
		for(int y = 0;y < M;y++){
			cout<<"\nInserisci un carattere nella matrice nella posizione ["<<x<<"]["<<y<<"]: ";
			cin>>matrix[x][y];
		}
	}
}

void insertValueInRange(int &value,int min,int max,string msg){
	do{
		cout<<msg;
		cin>>value;
		if(value < min || value > max){
			cout<<"\nRange massimo "<<min<<"/"<<max<<endl;
			system("pause");
		}
	}while(value < min || value > max);
}

void print(char matrix[][DIM],int N,int M){
	for(int x = 0;x < N;x++){
		for(int z = 0;z < 10;z++) cout<<" ";
		for(int y = 0;y< M;y++){
			cout<<matrix[x][y]<<" ";
		}
		cout<<endl;
	}
}

void rotateDX(char matrix[][DIM],int &N,int &M,int gradi){
	int round = gradi/90;
	char mat_tmp[DIM][DIM];
	for(int z = 0;z < round;z++){
		for(int x = 0;x < N;x++){
			for(int y = 0;y < M;y++){
				mat_tmp[y][N-1-x] = matrix[x][y]; 
			}
		}
		copy(mat_tmp,M,N,matrix);
		change(N,M);
	}
	
}

void rotateSX(char matrix[][DIM],int &N,int &M,int gradi){
	int round = gradi/90;
	char mat_tmp[DIM][DIM];
	for(int z = 0;z < round;z++){
		for(int x = 0;x < N;x++){
			for(int y = 0;y < M;y++){
				mat_tmp[M-1-y][x] = matrix[x][y]; 
			}
		}
		copy(mat_tmp,M,N,matrix);
		change(N,M);
	}
}
