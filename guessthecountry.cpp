//For Best Results run on VS Code

#include<iostream>
#include<random>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<string>
#include <algorithm>
#include <set>
#include<windows.h>
#include<fstream>
using namespace std;


static int livesPlayer1 = 0;
static int livesPlayer2 = 0;
static int pointsPlayer1 = 0;
static int pointsPlayer2 = 0;
static int currentPlayer = 1;
string player1, player2;
static bool flag = false;
set<string> usedCountries;



class Node
{
public:
    string countryName;
    string capital;
    Node* left;
    Node* right;

public:
    Node(string name, string capitalCity)
    {
       countryName=name;
       capital=capitalCity;
       left=nullptr;
       right=nullptr;
    }
};
vector<Node*> inorderNodes;

int gamePage();
int modeSelection();
int levelSelection();

void doublePlayerGame();
bool checkRepetition(const string& country);
void selectCountry(string level,Node* node, int continent);
void displayGuessQuestion(int continent, Node* &node);
void displayGuessQuestion(int continent, Node* &node, int &lives, int &points,const string& player1Name, const string& player2Name);

void playEasyLevel(int continent);
void playMediumLevel(int continent);
void playHardLevel(int continent);

string convertToLower(string input);

void displayContinent(int continent);
void displayHighscore();
void displayRules();
void displayCredits();


vector<Node*> inOrderTraversalOfNodes(Node* &node);


Node* easy_Asia_Tree();
Node* easy_Europe_Tree();
Node* easy_Africa_Tree();
Node* easy_South_America_Tree();
Node* easy_North_America_Tree();
Node* easy_Oceania_Tree();

Node* medium_Asia_Tree();
Node* medium_Europe_Tree();
Node* medium_Africa_Tree();
Node* medium_North_America_Tree();
Node* medium_South_America_Tree();
Node* medium_Oceania_Tree();

Node* hard_Asia_Tree();
Node* hard_Europe_Tree();
Node* hard_Africa_Tree();
Node* hard_North_America_Tree();
Node* hard_South_America_Tree();
Node* hard_Oceania_Tree();

void setValues(int &livesPlayer1, int &pointsPlayer1,int &livesPlayer2, int &pointsPlayer2){

    livesPlayer1 = 10;
    livesPlayer2 = 10;
    pointsPlayer1 = 0;
    pointsPlayer2 = 0;
    player1 = "";
    player2 = "";
    return;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int choice, mode;
    int level;
    int continent;

    setValues(livesPlayer1,pointsPlayer1, livesPlayer2, pointsPlayer2);
    srand(time(0));

    choice=gamePage();

    switch(choice)
    {
    case 1:
        mode=modeSelection();
        if (mode==1)
        {
            level=levelSelection();
            switch(level)
            {
            case 1:
                continent=(rand()%6) +1;
                playEasyLevel(continent);
                break;
            case 2:
                continent=(rand()%6) +1;
                playMediumLevel(continent);
                break;
            case 3:
                continent=(rand()%6) +1;
                playHardLevel(continent);
                break;
            }
        }
        else
        {
            doublePlayerGame();
            flag = true;

            level=levelSelection();
            switch(level)
            {
            case 1:
                continent=(rand()%6) +1;
                playEasyLevel(continent);
                break;
            case 2:
                continent=(rand()%6) +1;
                playMediumLevel(continent);
                break;
            case 3:
                continent=(rand()%6) +1;
                playHardLevel(continent);
                break;
            }

        }
        break;
    case 2:
        displayRules();
        break;
    case 3:
        displayHighscore();
        break;
    case 4:
        displayCredits();
        break;
    deafult:
        cout<<"Invalid choice."<<endl;

}

}
int gamePage()
{
    int choice;
    cout<<"\n\nGUESS THE COUNTRY \xF0\x9F\x8C\x8F ✈ "<<endl<<endl;


    cout<<"1. Start Game ▶"<<endl;
    cout<<"2. How to play 🤔"<<endl;
    cout<<"3. Display Highscore ✨"<<endl;
    cout<<"4. Credits 😎"<<endl;
    cout<<"0. To Quit (Mid-Game too) 🥺"<<endl;
    cout<<"Choose option : ";
    cin>>choice;
    cout<<endl;
    return choice;
}

int modeSelection()
{
    int choice;
    cout<<"\nMode Selection"<<endl;
    cout<<"1. Single player mode 🧍"<<endl;
    cout<<"2. Double player mode 👬🏼"<<endl;
    cout<<"Choose mode: ";
    cin>>choice;

    return choice;
}

int levelSelection()
{
    int level;
    cout<<"\nLevels 📜"<<endl;
    cout<<"1. Easy 🤙"<<endl;
    cout<<"2. Medium 😨"<<endl;
    cout<<"3. Hard 😡"<<endl;
    cout<<"Choose level ✔: ";
    cin>>level;
    cout<<endl;
    return level;
}


void doublePlayerGame()
{
    fflush(stdin);
    cout<<"\nEnter Player 1 name 📝: ";
    getline(cin,player1);

    cout<<"\nEnter Player 2 name 📝: ";
    getline(cin,player2);
}



bool checkRepetition(const string& country) {
    if (usedCountries.find(country) != usedCountries.end()) {
    return true;
  } else {
    usedCountries.insert(country);
    return false;
  }
}


void selectCountry(string level,Node* node,int continent)
{
    Node* randomlySelectedNode;
    int tempContinent;
    vector<Node*> nodesList;
    int random;

    nodesList=inOrderTraversalOfNodes(node);
    inorderNodes.clear();

      do
        {
        random = rand() % nodesList.size();
        randomlySelectedNode = nodesList[random];
    } while (checkRepetition(randomlySelectedNode->countryName));

        if (!flag)
    {
        displayGuessQuestion(continent, randomlySelectedNode);
    }
    else
    {
        if (currentPlayer == 1) {
            cout <<"\n"<< player1 << " is playing... 🕹" << endl;
            displayGuessQuestion(continent, randomlySelectedNode, livesPlayer1, pointsPlayer1, player1, player2);
            cout <<"\n"<< player1<<"'s Score 🏆: " << pointsPlayer1 << endl;
            currentPlayer = 2;
        }
        else {
            cout <<"\n"<< player2 << " is playing... 🕹" << endl;
            displayGuessQuestion(continent, randomlySelectedNode, livesPlayer2, pointsPlayer2, player1, player2);
            cout <<"\n"<< player2<<"'s Score 🏆: " << pointsPlayer2 << endl;
            currentPlayer = 1;
        }
    }

    usedCountries.insert(randomlySelectedNode->countryName);
    nodesList.clear();

     if(!flag){
            if (livesPlayer1 != 0)
     {
        tempContinent=(rand()%6)+1;
        if (level=="easy")
        {
            playEasyLevel(tempContinent);
        }
        else if (level=="medium")
        {
            playMediumLevel(tempContinent);
        }
        else if (level=="hard")
        {
            playHardLevel(tempContinent);
        }

      }
      }
      else if (!(livesPlayer1== 0 || livesPlayer2== 0)) {
        tempContinent = (rand() % 6) + 1;
        if (level == "easy") {
            playEasyLevel(tempContinent);
        } else if (level == "medium") {
            playMediumLevel(tempContinent);
        } else if (level == "hard") {
            playHardLevel(tempContinent);
        }

        }
      }



void displayGuessQuestion(int continent, Node* &node) {
    string input;
    const int TIMER_DURATION = 180;

    time_t start_time = time(nullptr);
    time_t end_time = start_time + TIMER_DURATION;


    while (time(nullptr) < end_time) {
        fflush(stdin);
        int remaining_seconds = end_time - time(nullptr);


        cout<<"Lives \xE2\x9D\xA4: "<< livesPlayer1<<endl;
        cout<<"\nContinent 🗺: ";
        displayContinent(continent);

        cout<<"Hint (Capital) 🗼: "<<node->capital<<endl;

        cout<<"Your answer 📝: ";
        getline(cin, input);


        if (input.empty()) {

            continue;
        }

        if (input == "0") {
            cout<<"Game Exited 👋"<<endl;
            cout<<"\nPoints Earned 🏆: "<<pointsPlayer1<<endl;
            exit(0);
        }

        if (convertToLower(input) == convertToLower(node->countryName)) {
            pointsPlayer1+= 15;
            cout<<"\nCorrect Guess🥳!"<<endl;
            cout<<"Points +15 "<<endl;
            return;
        }


        livesPlayer1--;
        cout << "\nWrong Guess 😭. \nLives remaining \xE2\x9D\xA4: " << livesPlayer1 << endl;
        cout<<"\nPoints deducted 📉"<<endl;
        if (pointsPlayer1 != 0)
        {
            pointsPlayer1-=5;
            if (pointsPlayer1<0)
            {
                pointsPlayer1=0;
            }
        }
        cout<<"Points 🏆: "<<pointsPlayer1<<endl;
        if (livesPlayer1 == 0) {
            cout << "Game Over 💔!" << endl;
            cout<<"\nPoints Earned 🏆: "<<pointsPlayer1<<endl;
            ofstream writeFile("score.txt",ios::app);
            writeFile<<pointsPlayer1<<endl;
            writeFile.close();
            cout<<"\n\nDo you want to restart game 👀 👉👈(y/n) : ";
            char c;
            cin>>c;
            if(c=='y')
            {
                main();
            }
             else
                exit(0);
        }
    }

    cout << "\nGame Idle for too long!....Exiting Game. 👋" << endl;
}


void displayGuessQuestion(int continent, Node* &node, int &lives, int &points,const string& player1Name, const string& player2Name) {
    string input;
    const int TIMER_DURATION = 180;

    time_t start_time = time(nullptr);
    time_t end_time = start_time + TIMER_DURATION;

    while (time(nullptr) < end_time) {
        fflush(stdin);
        int remaining_seconds = end_time - time(nullptr);

        cout<<"Lives \xE2\x9D\xA4: "<< lives<<endl;
        cout<<"\nContinent 🗺: ";
        displayContinent(continent);

        cout<<"Hint (Capital) 🗼: "<<node->capital<<endl;

        cout<<"Your answer 📝: ";
        getline(cin, input);

        if (input.empty()) {
            continue;
        }

        if (input == "0") {
            cout<<"\nGame Exited 👋"<<endl;
            exit(0);
        }

        if (convertToLower(input) == convertToLower(node->countryName)) {
            points += 15;
            cout<<"\nCorrect Guess 🥳!"<<endl;
            cout<<"\nPoints +15"<<endl;
            return;
        }

        lives--;
        cout << "\nWrong Guess 😭. \nLives remaining \xE2\x9D\xA4: " << lives << endl;
        cout<<"\nPoints deducted 📉"<<endl;

        if (points != 0) {
            points -= 5;
            if (points < 0) {
                points = 0;
            }
        }
        cout<<"Points : "<<points<<endl;
        if (lives == 0) {
            cout << "\nGame Over 💔!" << endl;
            cout << "\n"<<player1<<" Points: " << pointsPlayer1 << "\t\n"<<player2<<" Points: " << pointsPlayer2 << endl;
            if (pointsPlayer1 > pointsPlayer2)
            {
                cout<<"Player 1 wins 👑🥳!! "<<endl;
            }
            else if (pointsPlayer1 < pointsPlayer2)
            {
                cout<<"Player 2 wins 👑🥳!! "<<endl;
            }
            else
            {
                cout<<"Game draw 🤝!!"<<endl;
            }
            cout<<"\n\nDo you want to restart game (y/n) 👀 👉👈: ";
            char c;
            cin>>c;
            if(c=='y')
            {
                main();
            }
             else
                exit(0);
            return;

        }
    }

    cout << "\nGame Idle for too long!....Exiting Game.👋" << endl;
}

void playEasyLevel(int continent)
{
    usedCountries.clear();
    Node* node;
    string level="easy";
    srand(time(0));

    switch(continent)
        {
        case 1:
            node=easy_Asia_Tree();
            selectCountry(level,node,continent);
            break;
        case 2:
            node=easy_Europe_Tree();
            selectCountry(level,node,continent);
            break;
        case 3:
            node=easy_Africa_Tree();
            selectCountry(level,node,continent);
            break;
        case 4:
            node=easy_North_America_Tree();
            selectCountry(level,node,continent);
            break;
        case 5:
            node=easy_South_America_Tree();
            selectCountry(level,node,continent);
            break;
        case 6:
            node=easy_Oceania_Tree();
            selectCountry(level,node,continent);
            break;
        default:
            cout<<"Invalid option ❌"<<endl;
        }

}
void playMediumLevel(int continent)
{
    usedCountries.clear();
    Node* node;
    string level="medium";
    srand(time(0));

    switch(continent)
        {
        case 1:
            node=medium_Asia_Tree();
            selectCountry(level,node,continent);
            break;
        case 2:
            node=medium_Europe_Tree();
            selectCountry(level,node,continent);
            break;
        case 3:
            node=medium_Africa_Tree();
            selectCountry(level,node,continent);
            break;
        case 4:
            node=medium_North_America_Tree();
            selectCountry(level,node,continent);
            break;
        case 5:
            node=medium_South_America_Tree();
            selectCountry(level,node,continent);
            break;
        case 6:
            node=medium_Oceania_Tree();
            selectCountry(level,node,continent);
            break;
        default:
            cout<<"Invalid option ❌"<<endl;
        }

}


void playHardLevel(int continent)
{
    usedCountries.clear();
    Node* node;
    string level="hard";
    srand(time(0));

    switch(continent)
        {
        case 1:
            node=hard_Asia_Tree();
            selectCountry(level,node,continent);
            break;
        case 2:
            node=hard_Europe_Tree();
            selectCountry(level,node,continent);
            break;
        case 3:
             node=hard_Africa_Tree();
            selectCountry(level,node,continent);
            break;
        case 4:
            node=hard_North_America_Tree();
            selectCountry(level,node,continent);
            break;
        case 5:
            node=hard_South_America_Tree();
            selectCountry(level,node,continent);
            break;
        case 6:
            node=hard_Oceania_Tree();
            selectCountry(level,node,continent);
            break;
        default:
            cout<<"Invalid option ❌"<<endl;
        }

}

string convertToLower(string input)
{
    string output="";
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    for (int i=0; input[i]!='\0'; i++)
    {
        output+=(char)tolower(input[i]);
    }

    return output;
}



void displayContinent(int continent)
{
    switch (continent)
    {
    case 1:
        cout<<"Asia"<<endl;
        break;
    case 2:
        cout<<"Europe"<<endl;
        break;
    case 3:
        cout<<"Africa"<<endl;
        break;
    case 4:
        cout<<"North America"<<endl;
        break;
    case 5:
        cout<<"South America"<<endl;
        break;
    case 6:
        cout<<"Oceania"<<endl;
        break;

}
}


void displayHighscore()
{
    int highscore= 0;
    int tempScore;
    ifstream readFile("score.txt");

    while (!readFile.eof())
    {
        readFile>>tempScore;
        highscore = (tempScore > highscore) ? tempScore : highscore;

    }
    cout<<"Highscore 👑🏆: "<<highscore<<endl;
    readFile.close();

    cout<<"\nPress b to go back or 0 to exit: ";
            char c;
            cin>>c;

            if(c=='b'||c=='B')
            {
                main();
            }
             else if(c==0)
                exit(0);
}


void displayRules()
{
    cout<<"\nHow to play "<<endl;

    cout<<"1. Choose a Difficulty Level: Players can choose between Easy 🤙, Medium 😨, and Hard😡 levels."<<endl;
    cout<<"3. Guess the Country: Players must guess the name of the country based on the given hint 🗼 (Capital City)."<<endl;
    cout<<"4. Lives: Players start with 10 lives \xE2\x9D\xA4. A wrong guess results in the loss of a life 💔."<<endl;
    cout<<"5. Correct Guess: If the player guesses the country name correctly, they are prompted to the next guess."<<endl;
    cout<<"6. Game Over: The game ends when the player loses all 10 lives 💔. The player's score is based on the number of correct guesses."<<endl;
    cout<<"7. High Score: Players can aim to beat their high score in subsequent plays."<<endl;


    cout<<"\nPress b to go back or 0 to exit: ";
            char c;
            cin>>c;

            if(c=='b'||c=='B')
            {
                main();
            }
             else if(c==0)
                exit(0);

}


void displayCredits()
{
    cout<<"\nGame Title : Guess the country\n"<<endl;

    cout<<"Development Team 😎: "<<endl;

    cout<<"Cybil Fatima 👩🏻 (SP23-BAI-013)"<<endl;

    cout<<"Eman Butt 👩🏻 (SP23-BAI-014)"<<endl;

    cout<<"Esha Alvi 👩🏻 (SP23-BAI-015)"<<endl;

    cout<<"Muhammad Ibtihaj 🧑🏻 (SP23-BAI-037)\n"<<endl;


    cout<<"\nPress b to go back or 0 to exit: ";
            char c;
            cin>>c;

            if(c=='b'||c=='B')
            {
                main();
            }
             else if(c==0)
                exit(0);

}

//Trees for the continents and game difficulty level

vector<Node*> inOrderTraversalOfNodes(Node* &node)
{
    if (node != nullptr)
    {
        inOrderTraversalOfNodes(node->left);
        inorderNodes.push_back(node);
        inOrderTraversalOfNodes(node->right);
    }
    return inorderNodes;
}


Node* easy_Asia_Tree()
{
    Node* root;
    root=new Node("Iran", "Tehran");
    root->left=new Node("India", "New Delhi");
    root->left->left=new Node("Bangladesh", "Dhaka");
    root->left->left->left=new Node("Afghanistan", "Kabul");
    root->left->left->right=new Node("China", "Beijing");

    root->right=new Node("Japan", "Tokyo");
    root->right->left=new Node("Iraq", "Baghdad");
    root->right->right=new Node("Pakistan", "Islamabad");
    root->right->right->left=new Node("Nepal", "Kathmandu");
    root->right->right->right=new Node("Qatar", "Doha");

    return root;

}

Node* easy_Europe_Tree()
{
    Node* root;
    root=new Node("Netherlands", "Amsterdam");
    root->left=new Node("Germany", "Berlin");
    root->left->left=new Node("Denmark", "Copenhagen");
    root->left->right=new Node("Italy", "Rome");
    root->left->left->left=new Node("Belgium", "Brussels");
    root->left->left->right=new Node("France", "Paris");

    root->right=new Node("Poland", "Warsaw");
    root->right->left=new Node("Norway", "Oslo");
    root->right->right=new Node("Sweden", "Stockholm");
    root->right->right->right=new Node("Switzerland", "Bern");

    return root;

}

Node* easy_Africa_Tree()
{
    Node* root;
    root=new Node("Egypt", "Cairo");
    root->left=new Node("South Africa", "Cape Town");
    root->left->left=new Node("Nigeria", "Abuja");
    root->left->right=new Node("Kenya", "Nairobi");
    root->left->left->left=new Node("Morocco", "Rabat");
    root->left->left->right=new Node("Ethiopia", "Addis Ababa");

    root->right=new Node("Ghana", "Accra");
    root->right->left=new Node("Uganda", "Kampala");
    root->right->right=new Node("Algeria", "Algiers");
    root->right->right->right=new Node("Tanzania", "Dodoma");

    return root;

}
Node* easy_North_America_Tree()
{
    Node* root;
    root=new Node("United States", "Washington,D.C");
    root->left=new Node("Canada", "Ottawa");
    root->left->left=new Node("Mexico", "Mexico City");
    root->left->right=new Node("Cuba", "Havana");
    root->left->left->left=new Node("Haiti", "Port au Prince");
    root->left->left->right=new Node("Belize", "Belmopan");

    root->right=new Node("Bahamas", "Nassau");
    root->right->left=new Node("Panama", "Panama City");
    root->right->right=new Node("Jamaica", "Kingston");
    root->right->right->right=new Node("Costa Rica", "San Jose");

    return root;

}
Node* easy_South_America_Tree()
{
    Node* root;
    root=new Node("Argentina", "Buenos Aires");
    root->left=new Node("Brazil", "Brasilia");
    root->left->left=new Node("Colombia", "Bogota");
    root->left->right=new Node("Peru", "Lima");

    root->right=new Node("Guyana", "Georgetown");
    root->right->left=new Node("Uruguay", "Montevideo");
    root->right->right=new Node("French Guiana", "Cayenne");
    root->right->right->right=new Node("Ecuador", "Quito");

    return root;

}
Node* easy_Oceania_Tree()
{
    Node* root;
    root=new Node("Australia", "Canberra");
    root->left=new Node("Fiji", "Suva");
    root->left->left=new Node("Kiribati", "South Tarawa");

    root->right=new Node("Samoa", "Apia");
    root->right->left=new Node("Palau", "Ngerulumud");

    return root;

}

Node* medium_Asia_Tree()
{
    Node* root;
    root=new Node("Saudia Arabia", "Riyadh");
    root->left=new Node("Philippines", "Manila");
    root->left->left=new Node("Malaysia", "Kuala Lumpur");
    root->left->left->left=new Node("Jordan", "Amman");
    root->left->left->right=new Node("Oman", "Muscat");

    root->right=new Node("Thailand", "Bangkok");
    root->right->right=new Node("Vietnam", "Hanoi");
    root->right->right->left=new Node("Turkey", "Ankara");
    root->right->right->right=new Node("Yemen", "Sanaa");

    return root;
}

Node* medium_Europe_Tree()
{
    Node* root;
    root=new Node("Romania", "Bucharest");
    root->left=new Node("Greece", "Athens");
    root->left->left=new Node("Crotia", "Zagreb");
    root->left->left->left=new Node("Albania", "Tirana");
    root->left->left->right=new Node("Georgia", "Tbilisi");

    root->right=new Node("Serbia", "Belgrade");
    root->right->left=new Node("Russia", "Moscow");
    root->right->right=new Node("Ukraine", "Kyiv");
    root->right->right->left=new Node("Spain", "Madrid");
    root->right->right->right=new Node("United Kingdom", "London");

    return root;
}

Node* medium_Africa_Tree()
{
    Node* root;
    root=new Node("Mali","Bamako");
    root->left=new Node("Libya", "Tripoli");
    root->left->left=new Node("Guinea", "Conakry");
    root->left->right=new Node("Madagascar","Antananarivo");
    root->left->left->left=new Node("Gambia", "Banjul");
    root->left->left->right=new Node("Liberia", "Monrovia");

    root->right=new Node("Senegal", "Dakar");
    root->right->left=new Node("Niger", "Niamey");
    root->right->right=new Node("Tunisia", "Tunis");
    root->right->right->left=new Node("Somalia", "Mogadishu");
    root->right->right->right=new Node("Zimbabwe", "Harare");

    return root;
}

Node* medium_North_America_Tree()
{
    Node* root;
    root=new Node("Grenada", "St.Georges");
    root->left = new Node("Barbados", "Bridgetown ");
    root->left->left = new Node("Anguilla", "The Valley");
    root->left->right = new Node("Denmark", "Nuuk");

    root->right=new Node("Honduras", "Tegucigalpa");
    root->right->right = new Node("Montserrat", "Plymouth");

    return root;
}
Node* medium_South_America_Tree()
{
    Node* root;
    root=new Node("Curacao", "Willemstad");
    root->left=new Node("Chile", "Santiago");
    root->left->left= new Node("Bolivia", "Sucre");

    root->right=new Node("Venezuela", "Caracas");

    return root;
}


Node* medium_Oceania_Tree()
{
    Node* root;
    root=new Node("Tonga", "Nuku alofa");
    root->left=new Node("New Zealand", "Wellington");
    root->left->left=new Node("Federal States of Micronesia", "Palikir");

    root->right=new Node("Vanuatu", "Port-Vila");

    return root;
}

Node* hard_Asia_Tree()
{
    Node* root;
    root=new Node("Kazakhstan","Astana");
    root->left-new Node("South Korea", "Seoul");
    root->left->left=new Node("Cambodia","Phnom Penh");

    root->right=new Node("Lebanon", "Beirut");
    root->right->left=new Node("Laos", "Vientiane");
    root->right->right=new Node("Mongolia", "Ulaanbaatar");
    root->right->right->right=new Node("Palestine", "Jerusalem");

    return root;
}

Node* hard_Europe_Tree()
{
    Node* root;
    root=new Node("Hungary","Budapest");
    root->left=new Node("Bulgaria", "Sofia");
    root->left->left=new Node("Czechia", "Prague");
    root->left->right=new Node("Estonia","Tallian");
    root->left->right->right=new Node("Finland", "Helsinki");

    root->right=new Node("Malta", "Valleta");
    root->right->left=new Node("Portugal", "Lisbon");
    root->right->right=new Node("Slovakia", "Bratislava");

    return root;
}

Node* hard_Africa_Tree()
{
    Node* root;
    root=new Node("Lesotho","Maseru");
    root->left=new Node("Comoros", "Moroni");
    root->left->left=new Node("Angola", "Luanda");
    root->left->right=new Node("Botswon", "Gaborone");

    root->right=new Node("Lusaka", "Zambia");
    root->right->left=new Node("Rwanda", "Kigali");
    root->right->right=new Node("Togo ", "Lome");

    return root;
}

Node* hard_North_America_Tree()
{
    Node* root;
    root=new Node("Guatemala", "Guatemala City");
    root->left=new Node("El Savador", "San Salvador");
    root->left->left=new Node("Anguilla", "The Valley");

    root->right = new Node("Nicaragua", "Managua");
    root->right->left = new Node("Saint Lucia ", "Castries");
    root->right->right = new Node("Sain Martin ", "Marigot");

    return root;
}

Node* hard_South_America_Tree()
{
    Node* root;
    root = new Node("Ecuador","Quito");
    root->left=new Node("Bolivia", "Sucre");
    root->left->left=new Node("Aruba", "Oranjestad");

    root->right = new Node("Paraguay", "Asunción");
    root->right->right=new Node("Suriname", "Paramaribo");

    return root;
}

Node* hard_Oceania_Tree()
{
    Node* root;
    root = new Node("Papua New Guinea","Port Moresby");
    root->left=new Node("Norfolk Islands", "Kingston");
    root->left->left=new Node("Cook Islands", "Avarua");

    root->right =new Node("Solomon Islands", "Honiara");
    root->right->right= new Node("Tonga", "Nuku'alofa");

    return root;
}
