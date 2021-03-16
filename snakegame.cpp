// code for simple snake game
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>


using namespace std;


int i , j ,k , flag , score = 0  , gameover= 0 , width = 20 , height= 20 , tailcount= 0 , snakex , snakey , foodx ,foody , x1 ,x2 ,y1 , y2 ;

int tailx[100] , taily[100]  , counttail=0 ;

void draw() // code for drawing diagram within snake will move 
{
		system("cls");
	for(i=0 ; i<width; i++)
	{
	
		for(j=0 ; j<height ; j++)
		{
			if(i==0 || i==width-1 || j==0 ||j== height-1)
			
			cout<<"#";
			
			else if(i==snakex && j==snakey)
			cout<<"O";
			
			else if(i==foodx && j==foody)
			cout<<"*";
			
			else 
			 {
			 	int ch =0;
			 	for(k=0 ; k<counttail ; k++)
			 	{
			 		if( i==tailx[k] && j==taily[k])
			 		{
			 			cout<<"o";
			 			ch =1;
					 }
				 }
				 if(ch==0) 
				 cout<<" ";
			 }
			 
				
		}
		cout<<endl;
	}
	
	cout<<" SCORE = "<<score;
	cout<<"\n press e to exit .";
}


// code for fixing intial position of snake and food
void setposition()
{
	snakex= width/2;
	snakey= height/2;
	
	level1:
	foodx= rand()%20;
	if (foodx ==0 )
	goto level1;
	
	level2:
	foody = rand()%20;
	if(foody==0)
	goto level2;
}
  // code for input 
  
  void input()
  {
  	if(kbhit())

    	switch(getch())
	{
		case 'a':
		flag =1;
		break;
		case 's':
		 flag = 2;
		break;
		case 'w':
		 flag = 3;
		break;
		case 'q':
	     flag = 4;
		break;
		case 'e':
		gameover = 1;
		break;	
	}
	
  	
  }
  

// code for move  or real logic

void move()
{

	 x1= tailx[0];
	 y1= taily[0];
	 tailx[0]= snakex;
	 
	 taily[0]= snakey;
	 
	 for(i=1; i<counttail ; i++)
	 {
	 	x2= tailx[i];
	 	y2= taily[i];
	 	
	 	tailx[i]= x1;
	 	taily[i]= y1;
	 	
	 	x1= x2;
	 	y1= y2;
	 	
	 }  
		sleep(1);
	switch(flag)
	{
		case 1:
			snakex++;
		break;
		case 2:
			snakey++;
		break;
		case 3:
			snakex--;
		break;
		case 4:
			snakey--;
		break;
		default:
		 break;
	}
	
	// code for gameover
	
 	if(snakex<0 || snakex>width-1 ||snakey<0 || snakey>height-1)  // when snake touch boundary 
 	{
	 gameover=1;
	 cout<< "\ngame over!";
	 
    }
	// code for updating food location while snake reaching to food 
	if (foodx==snakex && foody==snakey)
	{
	  level3:
	  foodx=rand()%20;
	  if(foodx==0)
	  	goto level3;	
	 level4:
		
	foody=rand()%20;
	if(foody==0)
	 goto level4;

     counttail++;     // it will increase tail of snake after eating food 
     score+=10;
	}
	
	
} 

//driver function

int main()
{
    
	char key;
	int m , n;
 
  	
	setposition();
	while(!gameover)
	{
	
			draw();
			input();
			move();	
			for(m=0; m<1000; m++)
			{
				for(n=0; n<1000 ; n++)
				{
					
				}
			}
		
		
    }
	
    
	 
	      
	return 0;
}
