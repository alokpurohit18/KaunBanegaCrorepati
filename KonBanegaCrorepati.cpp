//KBC - The Game
#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<conio.h>
using namespace std;
struct node //linked list of type node used to store all the questions in order of difficulty. Hence this linked list acts as database of questions.
{
   int qno;
   string correct;
   string question[5];
   struct node *next;
};
    string name;//to store name of the player.
    string guess3;//used to store a guess option for a lifeline
    int counter1=0; //used to keep track to the denomination of the question which the player has most recently cleared
    int fifty1=0;
    struct node *head=NULL; //head or start node of the linked list
    struct node *temp=head;
    string friends[3]; // used to store the names of the 3 friends for phone a friend lifeline
    string ans1[]={"I AM CONFIDENT THE ANSWER IS ","I AM SURE THE CORRECT OPTION IS ","MY ANSWER WOULD BE "};
    string ans2[]={"I AM CONFUSED BETWEEN ","ACCORDING TO ME THE CORRECT ANSWER MIGHT BE ","NOT SURE. MAYBE THE CORRECT ANSWER IS BETWEEN "};
    string ans3[]={"I AM SORRY BUT I HAVE NO IDEA ABOUT THIS QUESTION. ","I APOLOGIZE, I DONT HAVE ANY ANSWER FOR THIS QUESTION. ", "I REGRET TO SAY THAT I HAVE NO CLUE ABOUT THE CORRECT ANSWER."};
int main()// displays start screen of the game and calls the main game function
{
    int loop;
    int ch;
    void database();
    void the_game();
    database();
    system("Color 3F");
    while(1)
    {
     system("cls");
    cout<<"\n********************************************************************************"<<endl;
    cout<<"\t\t\t  KON BANEGA CROREPATI"<<endl;
    cout<<"********************************************************************************\n"<<endl;
    cout<<"PLEASE ENTER PLAYER NAME....."<<endl;
    cin>>name;
    cout<<"\n\nWELCOME TO KON BANEGA CROREPATI GAME, "<<name<<".................\n\n\n RULES OF THE GAME -\n*******************\n"<<endl;
    cout<<"   5 CRORE\n   1 CRORE\n   50,00,000\n   25,00,000\n   12,50,000\n   6,40,000\n   3,20,000\n   1,60,000\n   80,000\n   40,000\n   20,000\n   10,000\n   5000 "<<endl;
    cout<<"\n1.THERE ARE A TOTAL OF 13 QUESTIONS LEADING UPTO 5 CRORE."<<endl;
    cout<<"2.THERE AT 3 CHECKPOINTS IN BETWEEN, ONE AT INR 10,000 , ANOTHER AT INR 3,20,000 AND LAST AT 1 CRORE."<<endl;
    cout<<"3.YOU WILL 4 LIFELINES - AUDIENCE POLL, 50/50 , PHONE A FRIEND AND EXPERT ADVICE. EACH OF THESE LIFELINES CAN BE USED ONCE DURING THE GAME.  "<<endl;
    cout<<"4.YOU CAN QUIT AT ANY POINT OF TIME. YOU WILL WIN THE MONEY CORRESPONDING TO THE LAST CORRCTLY ANSWERED QUESTION. "<<endl;
    cout<<"5.IF YOU ANSWER A QUESTION IS WRONG, YOU WILL FALL DOWN TO THE LAST CHECKPOINT."<<endl;
    cout<<"\n**************************************************************************************************************"<<endl;
    cout<<"\nOUR EXPERT FOR TODAY IS DR. KAVITA DIXIT. SHE IS A SENIOR JOURNALIST AT THE TIMES GROUP."<<endl;
    cout<<"\nPLEASE ENTER THE NAMES OF 3 FRIENDS AS YOUR OPTIONS FOR PHONE A FRIEND LIFELINE....."<<endl;
    for(loop=0;loop<3;loop++)
    {
        cin>>friends[loop];
    }
    cout<<"\n***********************************************GOOD LUCK******************************************************"<<endl;
    getch();
    the_game();
    getch();
    cout<<"\n1.PLAY AGAIN 2.EXIT GAME"<<endl;
    cin>>ch;
    if(ch==1)
    {
        continue;
    }
    else if(ch==2)
    {
        break;
    }
    else
    {
        cout<<"OOPS!!! WRONG CHOICE. NOW THE SYSTEM WILL EXIT."<<endl;
        break;
    }
    }
    return 0;
}
void the_game() // the function where the main game is played from start to end
{
    int fifty_fifty(int,int);
    int audience_poll(int);
    int expert_advice(int);
    int phone_friend(int);
    temp=head;
    counter1=0;
    string answer;
    int rando,j=0,i,aud=0,phone=0,fifty=0,expert=0, counter=0,amount=5000;
    char ch;
    char answer1;
    int ch3=1;
    while(counter==0&&counter1<13)
    {
        fifty1=0;
        while(1)//loop to ensure that if node/question found is already used then another node/question is generated
        {
        system("cls");
        temp=head;
        srand(time(NULL));
        rando=(rand()%5)+j+1;
        for(i=2;i<=rando;i++)
        {
            temp=temp->next;
        }
            if(temp->qno==0)
             continue;
            else
             break;
        }
        if(counter1==11)
            {
                cout<<" QUESTION FOR RS. 1 CRORE"<<endl;
                cout<<"*******************************\n"<<endl;
            }
        else if(counter1==12)
        {
             cout<<"  JACKPOT QUESTION FOR RS. 5 CRORE!!!!"<<endl;
             cout<<"*******************************************\n"<<endl;
        }
        else//header line for each question
        {
        cout<<" QUESTION FOR RS. "<<amount<<endl;
        cout<<"*************************************\n"<<endl;
        }
        cout<<temp->question[0]<<endl;//printing the question and all its options for that particular denomination of the loop
        cout<<temp->question[1]<<endl;
        cout<<temp->question[2]<<endl;
        cout<<temp->question[3]<<endl;
        cout<<temp->question[4]<<endl;
        while(1)
        {
            cout<<"\n1.USE LIFELINE 2.ANSWER"<<endl;
            cin>>ch3;
            if(ch3==1)
            {
                if(aud!=0&&phone!=0&&expert!=0&&fifty!=0)
                {
                    cout<<"\nALL LIFELINES EXHAUSTED."<<endl;
                    continue;
                }
                else
                {
                cout<<"\nLIFELINES AVAILABLE -"<<endl;
                if(aud==0)
                     cout<<"A. AUDIENCE POLL"<<endl;
                if(phone==0)
                     cout<<"P. PHONE A FRIEND"<<endl;
                if(fifty==0)
                     cout<<"F. 50-50"<<endl;
                if(expert==0)
                     cout<<"E. EXPERT ADVICE"<<endl;
                }
            cin>>ch;
            ch=toupper(ch);
        if(ch=='A')
        {
            if(aud!=0)
                cout<<"\nLIFLINE EXHAUSTED.\n"<<endl;
            else
                aud=audience_poll(aud);//calls audience poll lifeline
        }
        else if(ch=='P')
        {
            if(phone!=0)
                cout<<"\nLIFLINE EXHAUSTED.\n"<<endl;
            else
                phone=phone_friend(phone);//calls phone a friend lifeline
        }
        else if(ch=='E')
        {
            if(expert!=0)
                cout<<"\nLIFLINE EXHAUSTED.\n"<<endl;
            else
               expert=expert_advice(expert);//calls expert advice lifeline
        }
        else if(ch=='F')
        {
            if(fifty!=0)
                cout<<"\nLIFLINE EXHAUSTED.\n"<<endl;
            else
            fifty=fifty_fifty(fifty,amount);//calls 50-50 lifeline
        }
        else
            cout<<"WRONG CHOICE..."<<endl;
        }
        else if(ch3==2)
            break;
        else
         cout<<"WRONG CHOICE..."<<endl;
        }
        while(1)
        {
        cout<<"\nENTER YOUR ANSWER OR Q TO QUIT..."<<endl;
        cin>>answer;
        answer1=answer.at(0);
        if((int)answer1>=97&&(int)answer1<=122)
        {
           answer1=answer1-32;
        }
        answer.at(0)=answer1;
        if(answer=="Q")//code for quitting the game
        {
            string guess;
            char guess1;
            cout<<"\nYOU HAVE QUIT THE GAME..."<<endl;
            cout<<"TAKE A GUESS AT THIS QUESTION SINCE WE NEED TO TELL THE CORRECT ANSWER TO OUR AUDIENCE...."<<endl;
            cin>>guess;
            guess1=guess.at(0);
            guess1=toupper(guess1);
            guess.at(0)=guess1;
            if(guess==temp->correct)
            {
                cout<<"\nTHAT WOULD WE HAVE BEEN THE CORRECT ANSWER!!!\n"<<endl;
            }
            else
            {
                cout<<"\nI AM SORRY, THAT WOULD HAVE BEEN THE WRONG ANSWER...."<<endl;
            cout<<"THE CORRECT ANSWER FOR THIS QUESTION IS "<<temp->correct<<" .\n"<<endl;
            }
            break;
        }
        else if(answer==temp->correct)//code to check if player's answer is correct and display the money winning accordingly
        {
            cout<<"CORRECT ANSWER!!!!!!!"<<endl;
            counter1++;
            if(counter1==1)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 5,000 "<<endl;
            if(counter1==2)
            {
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 10,000 "<<endl;
                cout<<"\nYOU HAVE CLEARED THE FIRST CHECKPOINT... "<<endl;
                cout<<"YOU WILL ATLEAST WIN RS. 10,000 FROM HERE... "<<endl;
            }
            if(counter1==3)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 20,000 "<<endl;
            if(counter1==4)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 40,000 "<<endl;
            if(counter1==5)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 80,000 "<<endl;
            if(counter1==6)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 1,60,000 "<<endl;
            if(counter1==7)
            {
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 3,20,000 "<<endl;
                cout<<"\nYOU HAVE CLEARED THE SECOND CHECKPOINT... "<<endl;
                cout<<"YOU WILL ATLEAST WIN RS. 3,20,000 FROM HERE... "<<endl;
            }
            if(counter1==8)
            {
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 6,40,000"<<endl;
            }
            if(counter1==9)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 12,50,000"<<endl;
            if(counter1==10)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 25,00,000"<<endl;
            if(counter1==11)
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 50,00,000"<<endl;
            if(counter1==12)
            {
                cout<<"CONGRATULATIONS!!! YOU HAVE WON RS. 1 CRORE"<<endl;
                cout<<"\nYOU ARE A CROREPATI!!!!!"<<endl;
                cout<<"YOU WILL ATLEAST WIN RS. 1 CRORE FROM HERE... "<<endl;
            }
            if(counter1==13)
                cout<<"JACKPOT!!!!!!YOU HAVE WON RS. 5 CRORE"<<endl;
                break;
        }
        else if(answer=="A"||answer=="B"||answer=="C"||answer=="D")// Code for when player gives wrong answer
        {
            cout<<"\nWRONG ANSWER!"<<endl;
            cout<<"THE CORRECT ANSWER FOR THIS QUESTION IS "<<temp->correct<<" .\n"<<endl;
            counter++;
            if(counter1<=1)
            {
                counter1=0;
            }
            else if(counter1<=6)
            {
                counter1=2;
            }
            else if(counter1<=11)
            {
                counter1=7;
            }
            else{}
            break;
        }
        else
        {
            cout<<"\nPLEASE CHOOSE YOUR OPTION FROM THE 4 AVAILABLE OPTIONS ONLY..."<<endl;
            continue;
        }
        }
        getch();
        temp->qno=0;
        if(answer=="Q")
            break;
        if(amount==640000)
            amount=625000;
        amount=amount*2;
        j=j+5;
    }
//code to display the final amount won by the player either when he quits the game or when he gives the wrong answer
    cout<<name<<", YOU HAVE WON ";
    if(counter1==0)
        cout<<"NOTHING."<<endl;
        else
        {
    if(counter1==1)
        cout<<"RS 5,000 ."<<endl;
    else if(counter1==2)
        cout<<"RS 10,000 ."<<endl;
    else if(counter1==3)
        cout<<"RS 20,000 ."<<endl;
    else if(counter1==4)
        cout<<"RS 40,000 ."<<endl;
    else if(counter1==5)
        cout<<"RS 80,000 ."<<endl;
    else if(counter1==6)
        cout<<"RS 1,60,000 ."<<endl;
    else if(counter1==7)
        cout<<"RS 3,20,000 ."<<endl;
    else if(counter1==8)
        cout<<"RS 6,40,000 ."<<endl;
    else if(counter1==9)
        cout<<"RS 12,50,000 ."<<endl;
    else if(counter1==10)
        cout<<"RS 25,00,000 ."<<endl;
    else if(counter1==11)
        cout<<"RS 50,00,000 ."<<endl;
    else if(counter1==12)
        cout<<"RS 1 CRORE ."<<endl;
    else if(counter1==13)
        cout<<"RS 5 CRORE ."<<endl;
    else{}
    cout<<"CONGRATULATIONS!!!!!!";
    cout<<"THANK YOU FOR PLAYING!!!!!!"<<endl;
        }
}
 int fifty_fifty(int fifty,int amount)//function to implement 50-50 lifeline
{
            cout<<endl;
            system("cls");
            int rand6;
            if(counter1==11)
            {
                cout<<" QUESTION FOR RS. 1 CRORE"<<endl;
                cout<<"*******************************\n"<<endl;
            }
            else if(counter1==12)
            {
             cout<<"  JACKPOT QUESTION FOR RS. 5 CRORE!!!!"<<endl;
             cout<<"*******************************************\n"<<endl;
            }
           else
           {
             cout<<" QUESTION FOR RS. "<<amount<<endl;
             cout<<"*************************************\n"<<endl;
           }
            cout<<temp->question[0]<<endl;
            do
            {
            srand(time(NULL));
            rand6=(rand()%4);
            if(rand6==0)
                guess3="A";
            else if(rand6==1)
                guess3="B";
            else if(rand6==2)
                guess3="C";
            else
                guess3="D";
            }while(guess3==temp->correct);

            if(temp->correct=="A")
            {
                cout<<temp->question[1]<<endl;
                if(guess3=="B")
                {
                    cout<<temp->question[2]<<endl;
                }
                if(guess3=="C")
                {
                    cout<<temp->question[3]<<endl;
                }
                if(guess3=="D")
                {
                    cout<<temp->question[4]<<endl;
                }
            }
            if(temp->correct=="B")
            {
                if(guess3=="A")
                {
                    cout<<temp->question[1]<<endl;
                    cout<<temp->question[2]<<endl;
                }
                if(guess3=="C")
                {
                    cout<<temp->question[2]<<endl;
                    cout<<temp->question[3]<<endl;
                }
                if(guess3=="D")
                {
                    cout<<temp->question[2]<<endl;
                    cout<<temp->question[4]<<endl;
                }
            }

            if(temp->correct=="C")
            {
                if(guess3=="A")
                {
                    cout<<temp->question[1]<<endl;
                    cout<<temp->question[3]<<endl;
                }
                if(guess3=="B")
                {
                    cout<<temp->question[2]<<endl;
                    cout<<temp->question[3]<<endl;
                }
                if(guess3=="D")
                {
                    cout<<temp->question[3]<<endl;
                    cout<<temp->question[4]<<endl;
                }
            }

            if(temp->correct=="D")
            {
                if(guess3=="A")
                {
                    cout<<temp->question[1]<<endl;
                    cout<<temp->question[4]<<endl;
                }
                if(guess3=="B")
                {
                    cout<<temp->question[2]<<endl;
                    cout<<temp->question[4]<<endl;
                }
                if(guess3=="C")
                {
                    cout<<temp->question[3]<<endl;
                    cout<<temp->question[4]<<endl;
                }
            }
            fifty++;//returns to indicate that 50-50 lifeline has been used/exhausted
            fifty1++;
            return fifty;
}
int audience_poll(int aud)// function to implement audience poll lifeline
{
           cout<<endl;
           int APoll,diff1,BPoll,diff2,CPoll,DPoll,random;
           if(fifty1==0)//code to implement audience poll lifeline when when phone a friend lifeline hasn't been implemented/used
           {
           if(counter1>=0&&counter1<=3)
          {
            srand(time(NULL));
            APoll=(rand()%31)+70;
            diff1=100-APoll;
            srand(time(NULL));
            BPoll=rand()%(diff1+1);
            diff2=diff1-BPoll;
            srand(time(NULL));
            CPoll=rand()%(diff2+1);
            DPoll=diff2-CPoll;
           }
          else if(counter1>3 && counter1<=9)
          {
            srand(time(NULL));
            APoll=(rand()%21)+50;
            diff1=100-APoll;
            srand(time(NULL));
            BPoll=rand()%(diff1+1);
            diff2=diff1-BPoll;
            srand(time(NULL));
            CPoll=rand()%(diff2+1);
            DPoll=diff2-CPoll;
          }
          else
          {
            srand(time(NULL));
            APoll=(rand()%11)+35;
            srand(time(NULL));
            BPoll=(rand()%6)+35;
            diff1=100-APoll-BPoll;
            srand(time(NULL));
            CPoll=rand()%(diff1+1);
            DPoll=diff1-CPoll;
          }
          cout<<"\nTHE AUDIENCE POLL RESULTS ARE -"<<endl;


            if(temp->correct=="A")
            {
                cout<<temp->question[1]<<" "<<APoll<<"%"<<endl;
                cout<<temp->question[2]<<" "<<BPoll<<"%"<<endl;
                cout<<temp->question[3]<<" "<<CPoll<<"%"<<endl;
                cout<<temp->question[4]<<" "<<DPoll<<"%\n"<<endl;
            }
            else if(temp->correct=="B")
            {
                cout<<temp->question[1]<<" "<<BPoll<<"%"<<endl;
                cout<<temp->question[2]<<" "<<APoll<<"%"<<endl;
                cout<<temp->question[3]<<" "<<CPoll<<"%"<<endl;
                cout<<temp->question[4]<<" "<<DPoll<<"%\n"<<endl;
            }
            else if(temp->correct=="C")
            {
                cout<<temp->question[1]<<" "<<CPoll<<"%"<<endl;
                cout<<temp->question[2]<<" "<<BPoll<<"%"<<endl;
                cout<<temp->question[3]<<" "<<APoll<<"%"<<endl;
                cout<<temp->question[4]<<" "<<DPoll<<"%\n"<<endl;
            }
            else
            {
                cout<<temp->question[1]<<" "<<DPoll<<"%"<<endl;
                cout<<temp->question[2]<<" "<<BPoll<<"%"<<endl;
                cout<<temp->question[3]<<" "<<CPoll<<"%"<<endl;
                cout<<temp->question[4]<<" "<<APoll<<"%\n"<<endl;
            }
           }
           else //code to implement audience poll lifeline when when phone a friend lifeline has been implemented/used
           {
              if(counter1>=0&&counter1<=3)
           {
            srand(time(NULL));
            APoll=(rand()%31)+70;
            BPoll=100-APoll;
           }
           else if(counter1>3 && counter1<=9)
          {
            srand(time(NULL));
            APoll=(rand()%21)+50;
            BPoll=100-APoll;
          }
          else
          {
            srand(time(NULL));
            APoll=(rand()%21)+35;
            BPoll=100-APoll;
          }
          srand(time(NULL));
          random=rand()%2;
          if(random==0)
          {
           cout<<"\nTHE AUDIENCE POLL RESULTS ARE -"<<endl;
            if(temp->correct=="A")
                cout<<temp->question[1]<<" "<<APoll<<"%"<<endl;
            else if(temp->correct=="B")
                cout<<temp->question[2]<<" "<<APoll<<"%"<<endl;
            else if(temp->correct=="C")
                cout<<temp->question[3]<<" "<<APoll<<"%"<<endl;
            else
                cout<<temp->question[4]<<" "<<APoll<<"%"<<endl;
            if(guess3=="A")
                cout<<temp->question[1]<<" "<<BPoll<<"%\n"<<endl;
            else if(guess3=="B")
                cout<<temp->question[2]<<" "<<BPoll<<"%\n"<<endl;
            else if(guess3=="C")
                cout<<temp->question[3]<<" "<<BPoll<<"%\n"<<endl;
            else
                cout<<temp->question[4]<<" "<<BPoll<<"%\n"<<endl;
          }
          else
          {
               if(guess3=="A")
                cout<<temp->question[1]<<" "<<BPoll<<"%\n"<<endl;
            else if(guess3=="B")
                cout<<temp->question[2]<<" "<<BPoll<<"%\n"<<endl;
            else if(guess3=="C")
                cout<<temp->question[3]<<" "<<BPoll<<"%\n"<<endl;
            else
                cout<<temp->question[4]<<" "<<BPoll<<"%\n"<<endl;
               if(temp->correct=="A")
                cout<<temp->question[1]<<" "<<APoll<<"%"<<endl;
            else if(temp->correct=="B")
                cout<<temp->question[2]<<" "<<APoll<<"%"<<endl;
            else if(temp->correct=="C")
                cout<<temp->question[3]<<" "<<APoll<<"%"<<endl;
            else
                cout<<temp->question[4]<<" "<<APoll<<"%"<<endl;
          }
            fifty1=1;
            }
            aud++;//returns to indicate that audience poll lifeline has been used/exhausted
            return aud;

}
int expert_advice(int expert)// function to implement expert advice lifeline
{
                cout<<endl;
                int rando4,rando5;
                srand(time(NULL));
                rando4=(rand()%3);
                cout<<"HELLO, "<<name<<". I AM DR. KAVITA DIXIT AND I AM THE EXPERT FOR TODAY!!!"<<endl;
                if(counter1<=9)
                {
                    cout<<ans1[rando4]<<temp->correct<<"\n"<<endl;
                }
                else
                {
                srand(time(NULL));
                rando5=rand()%2;
                if(rando5 ==0)
                {
                cout<<ans1[rando4]<<temp->correct<<"\n"<<endl ;
                }
                else
                {
                string guess;
                int rando3;
                do
                {
                    srand(time(NULL));
                    rando3=rand()%4;
                    if(rando3==0)
                        guess="A";
                    if(rando3==1)
                        guess="B";
                    if(rando3==2)
                        guess="C";
                    if(rando3==3)
                        guess="D";
                }while(guess==temp->correct);
                srand(time(NULL));
                rando3=rand()%2;
                if(rando3==0)
                   cout<<ans2[rando4]<<guess<<" OR "<<temp->correct<<"\n"<<endl;
                else
                    cout<<ans2[rando4]<<temp->correct<<" OR "<<guess<<"\n"<<endl;
               }
                }
                expert++;//returns to indicate that expert advice lifeline has been used/exhausted
                return expert;
}
int phone_friend(int phone)// function to implement phone a friend lifeline
{
            cout<<endl;
            int ch2;
            int loop;
            srand(time(NULL));
            int rando2=rand()%3;
            srand(time(NULL));
            int rando3=rand()%4;
            cout<<"\nWHICH FRIEND WOULD YOU LIKE TO CALL?"<<endl;
            for(loop=0;loop<3;loop++)
                cout<<loop+1<<". "<<friends[loop]<<endl;
            cin>>ch2;
            cout<<"\nRINGING..."<<endl;
            cout<<"CONNECTED TO "<<friends[ch2-1]<<"...\n"<<endl;
            if(counter1<=4)
                cout<<ans1[rando2]<<temp->correct<<endl ;
            else
            {
                srand(time(NULL));
                int rando1=rand()%3;
                if(rando1 ==0)
                {
                cout<<ans1[rando2]<<temp->correct<<endl ;
                }
                else if(rando1==1)
                {
                string guess;
                do
                {
                    srand(time(NULL));
                    if(rando3==0)
                        guess="A";
                    if(rando3==1)
                        guess="B";
                    if(rando3==2)
                        guess="C";
                    if(rando3==3)
                        guess="D";
                }while(guess==temp->correct);
                srand(time(NULL));
                rando2=rand()%3;
                cout<<ans2[rando2]<<guess<<" OR "<<temp->correct<<endl;
               }
              else
              {
                 cout<<ans3[rando2]<<endl;
              }
            }
            cout<<"\nDISCONNECTED...\n"<<endl;
            phone++;//returns to indicate that audience poll lifeline has been used/exhausted
            return phone;
}
void database()//function to create database of questions by using a linked list by storing/copying all the questions from a data/text file into a big data structure i.e. linked list
{
    ifstream file;//variable with name file of type input file stream is created
    file.open("questions.txt");//to open the text file and store it in the variable "file"
    int i;//counter
    int j=0;
    for(i=1;i<=65;i++)//loop to copy each line from the file into each node of the linked list
    {
        node *p=new node;
        node *current=head;
        if(head==NULL)
        {
            p->qno=i;
            while(j<5)
            {
                getline(file,p->question[j]);//copying each line from the file and into the node of the linked list
                j++;
            }
            getline(file,p->correct);
            p->next=NULL;
            head=p;
        }
        else
        {
            j=0;
            while(current->next!=NULL)//loop to traverse till the last node of the linked list
                current = current->next;
            p->qno=i;
            while(j<5)
            {
                getline(file,p->question[j]);
                j++;
            }
            getline(file,p->correct);
            current->next=p;//linking the current node of the linked list to the next node i.e. linking the last node of the linked list to the new node
            p->next=NULL;
        }
    }
    file.close();//to close the file in order to avoid source leak
}

