#include<iostream>
#include<ctime>            //this header file for srand(time()) function
#include<windows.h>       //this header file for time Sleep(time in mSec)
#include<string>          // this header file for srting

using namespace std;
void demo(void);
void manu(void);         //function prototype declaration
void hang (int);
void m_manu(void);

int g_w;               //g_w means guess word
int chackGuess( char, string, string&);

using namespace std;
int main()
{


    int n,len;
    string word;
    char lan,ch;
    string words[]=                 //string diclaration
    {
        "game",
        "hangman",
        "pacman",
        "university",
        "name",
        "rupak",
        "name",
        "modern",
        "crown"
        "hitman"
    };                      //they are word will came randomly
top:
    srand(time(NULL));
    n=rand()%10;             //randomly select a word in 10
    word=words[n];          //after came a word put in one variable which name word
    len=word.length();      //put word length in len
    g_w=7;
                                //cout<<"\t\t\t\t\t\xB2\xB2\xB2 Welcome to HANGMAN \xB2\xB2\xB2  ";
    m_manu();
    manu();                 //function call
    cout<<"\n\n\t\t\tIf you can't do it,You will be hang like this...";
    demo();
    Sleep(6000);           //this function for time in miliseconds
    string hide_w(len,'X');                             //word length times X put in a variable
    system("cls");              //this function for clear screen
    m_manu();
    manu();
    // g_w=7;
    while(g_w>0)
    {

        cout<<"\n\n\n\t"<<hide_w<<endl;
        cout<<"\n\tEnter guess a latter: ";
        cin>>lan;
        system("cls");
        m_manu();
        if(chackGuess(lan,word,hide_w)==0)
        {
            g_w-=1;
            manu();
            cout<<"\n\t\t\t\t   Your word is INCORRECT!!"<<endl;


        }
        else
        {
            manu();
            cout<<"\n\t\t\t\t Your result is correct!!!  ^_^  ^_^ \n";

        }
        if(word==hide_w)
        {
            system("cls");              //this function for clear screen
            m_manu();
            manu();
            cout<<"\n\t\t\tYou got the right word. It's ==>>"<<word;
            Sleep(6000);
            break;
        }

    }

    if(g_w==0)
    {
        system("cls");
        m_manu();
        manu();
        Sleep(2000);
        system("cls");

        cout<<"\n\t\t\tYou are hanged";
        demo();
    }
    system("cls");

try_again:
    system("cls");
    m_manu();
    cout<<"\t\t\t\t\nDo you want to play this game again?(y/n)";
    cin>>ch;
    if(ch=='y')
    {
        goto top;
    }
    else if(ch=='n')
    {
        cout<<"\t\t==>>>Thanks for play this GAME";
    }
    else
    {
        cout<<"\t\t\t\t\n\nYour choice is wrong !! Please try it again!!!\n\n";
        goto try_again;
    }
    return 0;
}



void manu(void)
{

    cout<<"\n\t\t\t\tYou have "<<g_w<<" chance to try word\n";
    if(g_w==6)
    {
        cout<<"\t\t  O\n\n\n"<<endl;
    }
    else if(g_w==5)
    {
        cout<<"\t\t  O"<<endl<<endl;
        cout<<"\t\t/\n\n"<<endl;
    }
    else if(g_w==4)
    {
        cout<<"\t\t  O"<<endl<<endl;
        cout<<"\t\t/ |\n\n"<<endl;
    }
    else if(g_w==3)
    {
        cout<<"\t\t  O"<<endl<<endl;
        cout<<"\t\t/ | \\\n"<<endl<<endl;
    }
    else if(g_w==2)
    {
        cout<<"\t\t  O"<<endl<<endl;
        cout<<"\t\t/ | \\"<<endl<<endl;
        cout<<"\t\t/\n"<<endl;
    }
    else if(g_w==1)
    {
        cout<<"\t\t  O"<<endl<<endl;
        cout<<"\t\t/ | \\"<<endl<<endl;
        cout<<"\t\t/ |\n"<<endl;

    }
    else if(g_w==0)
    {
        cout<<"\t\t  O"<<endl<<endl;
        cout<<"\t\t/ | \\"<<endl<<endl;
        cout<<"\t\t/ | \\\n"<<endl;


    }
}




void demo(void)
{
    Sleep(250);
    cout<<"\n\t\t\t\t\t\t_";
    Sleep(250);
    cout<<"_";
    Sleep(250);
    cout<<"_";
    Sleep(250);
    cout<<"_";
    Sleep(250);
    cout<<"_";
    Sleep(250);
    cout<<"_";
    Sleep(250);
    cout<<"_";
    Sleep(250);
    cout<<"\n\t\t\t\t\t\t   |";
    Sleep(250);
    cout<<"\n\t\t\t\t\t\t   |";

    Sleep(500);
    cout<<"\n\t\t\t\t\t\t   O"<<endl<<endl;
    Sleep(700);
    cout<<" \t\t\t\t\t\t / ";
    Sleep(700);
    cout<<"| ";
    Sleep(700);
    cout<<"\\"<<endl<<endl;
    Sleep(700);
    cout<<" \t\t\t\t\t\t / ";
    Sleep(700);
    cout<<"| ";
    Sleep(700);
    cout<<"\\";
    Sleep(700);


}
int chackGuess(char guess,string s_word,string &g_word)
{
    int i;
    int match=0;
    int len=s_word.length();

    for(i=0; i<len; i++)
    {
        if(guess==g_word[i])
        {
            return 0;
        }
        if(guess==s_word[i])
        {
            g_word[i]=guess;
            match++;
        }
    }
    return match;
}
void m_manu(void)
{
    system("color A");
    cout<<"\n\t\t\t\t       \xB2\xB2\xB2    Welcome to HANGMAN Game!!!   \xB2\xB2\xB2  "<<endl;

    cout<<"\n\t\t\t\t\t   \xB2\xB2\xB2   Play and Enjoy the Game   \xB2\xB2\xB2  \n";
    cout<<"\n\t\t\t\t\t      \xB2\xB2\xB2   The HANGMAN   \xB2\xB2\xB2  \n";
    cout<<"\n\t\t\t\t\t\t\t\t  O"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t/ | \\"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t/ | \\\n"<<endl;
}
