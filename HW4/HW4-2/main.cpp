//
//  main.cpp
//  HW4-2
//
//  Created by Apple on 2019/10/21.
//  Copyright © 2019 huangly. All rights reserved.

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <time.h>
#include <functional>

using namespace std;

#define MAX_ROWS 3
#define MAX_COLS 10
#define MAX_STUDENTS 30

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define NOTHING 0
#define APPLEPIE 1
#define BEEF 2
#define CURRY 3

typedef int MEALTYPE;

class Fmart; // this line is used to identify Fmart as a type name, since class Player and class Student have pointers to Fmart.

// ------------------------------Helper functions--------------------------------------//
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    return rand() % (max - min + 1) + min;
}
// -----------------------------Class Declarations-------------------------------------//
class Player
{
public:
    //constructor
    Player(Fmart *fp);
    
    //destructor
    ~Player();
    
    //accessors
    int row() const;
    int col() const;
    int lives() const;
    int score() const;
    MEALTYPE mealInHand() const;
    MEALTYPE m_mealInHand;
    
    //mutators
    void pickup(MEALTYPE meal);
    void move(int dir);
    
    void deliver();
    void decLife();
    
private:
    int m_row;
    int m_col;
    int m_lives;
    int m_score;
    Fmart *m_fp;
};

class Student
{
public:
    //constructor
    Student(Fmart *fp, int row, int col);
    
    //destructor
    ~Student();
    
    //accessors
    int row() const;
    int col() const;
    MEALTYPE typeWanted() const;
    
    //mutators
    void moveForward();
    
private:
    Player *p1;
    Fmart *f1;
    int m_row;
    int m_col;
    MEALTYPE m_typeWanted;
    // TODO: add private members for Student class.
};

class Fmart
{
public:
    //constructor
    Fmart();
    
    //destructor
    ~Fmart();
    
    //accessors
    Player *getPlayer() const;
    int numberOfStudents() const;
    bool studentAt(int row, int col) const;
    int StudentWanted(int row, int col) const
    
    {
        for (int i = 0; i < numberOfStudents(); i++)
        {
            if (m_students[i]->row() == row && m_students[i]->col() == col)
            {
                return m_students[i]->typeWanted();
            }
        }
        return 0;
    }
    
    //mutators
    bool addStudent();
    bool deleteStudent(int row, int col);
    void display();
    void play();
    
private:
    Player *m_player;
    Student *m_students[MAX_STUDENTS]; //30�?指向Student类的指针
    int m_numStudents;

};

//---------------------------Implementions of Fmart-------------------------------------//

Fmart::Fmart()
{

    m_player=new Player(this);//在private 里声明的m_player是为了和player联系起来，但是要先构建（初始化）这个m_player。同时player构建里面也需要一个Fmart* fp和Fmart联系起来
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        m_students[i] = nullptr;
    }
    m_numStudents = 0;
    // This constructor:
    // (1) adds a new player
    // (2) initializes m_students to be NULL (or nullptr)
    // (3) initializes the number of students to be 0.
    // TODO: finish the implementation.
}

Fmart::~Fmart()
{
    delete m_player;
    for(int i=0;i<m_numStudents;i++)
    {
        delete m_students[i];
    }
    // TODO: delete everything you dynamically created.
}

Player *Fmart::getPlayer() const
{
    
    return m_player;
    // This function returns a pointer to the player.
    // TODO: finish the implementation.
    return nullptr; // This line is only for the program to compile.
}

int Fmart::numberOfStudents() const
{
    return m_numStudents;
    // This function returns the number of students.
    // TODO: finish the implementation.
    return 0; // This line is only for the program to compile.
}

bool Fmart::studentAt(int row, int col) const
{
    for (int i = 0; i < m_numStudents; i++)
    {
        if (m_students[i]->row() == row && m_students[i]->col() == col)
        {
            return true;
        }
    }
    // TODO: check if there is a student at (row, col), if so, return true, else return false.
    return false; // This line is only for the program to compile.
}

bool Fmart::addStudent()
{
    if (m_numStudents < MAX_STUDENTS)
    {
        m_numStudents++;                                                      //m_students[m_numStudents-1]�?一�?指针，可以调用类里的a函数，但不能直接等于构造函数h来构�?
        m_students[m_numStudents - 1] = new Student(this, randInt(1, 3), 10); //add student 要构建（初始化）该类（构造函数）---用new。
        //Dog d=Dog() dog.sad            Dog* d=new Dog()  d->sad
        return true;
    }
    // TODO: add a new student at the rightmost column.
    // If Student number is greater than MAX_STUDENTS, just do nothing and return false.
    // If you added a student successfully, return true.
    // You will need randInt() to get a random number.
    else
        return false; // This line is only for the program to compile.
}

bool Fmart::deleteStudent(int row, int col)
{
    for (int i = 0; i < m_numStudents; i++)
    {
        if (m_students[i]->row() == row && m_students[i]->col() == col)
        {
           delete m_students[i] ;//后面还要再用,得结合写p=nullptr
//            m_students[i]=nullptr;//??????????????
            for(int m=i;m+1<m_numStudents;m++)//删除一个后,i之后的STUDENT数组还应整体向前移动一位（remove）
            {
                m_students[m]=m_students[m+1];
            }
            for (int n = 0; n < m_numStudents; n++)
            {
                if (m_students[n]->col() > col)
                    m_students[n]->moveForward();
            }
            
             m_numStudents--;
            return true;
        }
    }
    
    // TODO: delete a student at position (row, col) from m_students.
    // If no student is at this position, return false.
    // If there is a student, delete the student, and shift all students after it to the left.
    // Maybe there are extra things to deal with?
    // YOUR CODE HERE
    return false; // This line is only for the program to compile.
}

/** Display the game grid
 * It will display grids, players and students.
 * There are a few blanks for you to fill in.
 */
void Fmart::display()
{
    char **disp = new char *[3];
    for (int i = 0; i < 3; i++)
    {
        disp[i] = new char[10];
        for (int j = 0; j < 10; j++)
            disp[i][j] = '.';
    }
    
    // TODO: Visit each student and:
    // (Assume this student is at (r, c))
    // If this student wants the meal the player is atholding, change disp[r-1][c-1] to '@'.
    // If this student doesn't want the meal, change disp[r-1][c-1] to 'S'.
    for (int i = 0; i < m_numStudents; i++)
    {
        if (m_students[i]->typeWanted() == m_player->mealInHand())
            disp[m_students[i]->row() - 1][m_students[i]->col() - 1] = '@';
        else
            disp[m_students[i]->row() - 1][m_students[i]->col() - 1] = 'S';
    }

    
    if (m_player->mealInHand() == APPLEPIE)
        disp[m_player->row() - 1][m_player->col() - 1] = 'A';
    else if (m_player->mealInHand() == BEEF)
        disp[m_player->row() - 1][m_player->col() - 1] = 'B';
    else if (m_player->mealInHand() == CURRY)
        disp[m_player->row() - 1][m_player->col() - 1] = 'C';
    else if (m_player->mealInHand() == NOTHING)
    {
        disp[m_player->row() - 1][m_player->col() - 1] = 'P';
    }
    // TODO: Check the type of meal the player is holding.
    // (Assume the player is at (r, c))
    // If it is APPLEPIE, change disp[r-1][c-1] to 'A';
    // If it is BEEF, change disp[r-1][c-1] to 'B';
    // If it is CURRY, change disp[r-1][c-1] to 'C';
    // If it is NOTHING, change disp[r-1][c-1] to 'P';
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << disp[i][j];
        cout << endl;
    }
    
    for (int i = 0; i < 3; i++)
        delete[] disp[i];
    delete[] disp;
}

void Fmart::play()
{
    addStudent(); //Adds the first student.
    while (m_player->lives() > 0)
    {
        display();
        cout << "You have " << m_player->lives() << " lives, and your score is " << m_player->score() << "." << endl;
        cout << "make a move (a, b, c, u, d, g): " << endl;
        string input;
        getline(cin, input);
        cout << endl
        << endl
        << endl;
        
        char option = input[0]; //Here, option is 'a', 'b', 'c', 'u', 'd', or 'g'.
        if (option == 'a')
            m_player->pickup(1);
        else if (option == 'b')
            m_player->pickup(2);
        else if (option == 'c')
            m_player->pickup(3);
        else if (option == 'u')
            m_player->move(1);
        else if (option == 'd')
            m_player->move(2);
        else if (option == 'g')
            m_player->deliver();
        // TODO: Let your player behave according to 'option'.
        // You should call member functions of class Player.
        
        // Moves all students forward
        for (int i = 0; i < m_numStudents; i++)
        {
            int detector = m_numStudents; // Detect whether a student has reached col 1 and is deleted.
            m_students[i]->moveForward();
            if (m_numStudents != detector)
                i--; // If so, move back 1 iteration.
        }
        // A 30% chance for adding a new student
        if (randInt(1, 10) <= 3)
            addStudent();
    }
    cout << "You lose. Your score is " << m_player->score() << ". Press any key to quit." << endl;
    getchar();
}

//---------------------------Implementions of Student -------------------------------------//
Student::Student(Fmart *fp, int row, int col)//Fmart中addstudent时传入的值
{
    f1=fp;//将Fmart  与该类联系起来
    p1=fp->getPlayer();//将Fmart链接的Player 与该类联系起来 p1->decLife();f1->deleteStudent(m_row, m_col);才有效
    m_row = row;
    m_col = col;
    int i = randInt(1, 3);
    if (i == 1)
        m_typeWanted = APPLEPIE;
    else if (i == 2)
        m_typeWanted = BEEF;
    else if (i == 3)
        m_typeWanted = CURRY;
    else
        m_typeWanted = NOTHING;
    // TODO: this constructor initializes a student, at (row, col).
    // You should randomly choose 1 meal type, and store it in the student object.
    // fp is a pointer to the Fmart this student is in.
}

Student::~Student()
{
    // TODO: delete everything you dynamically created.
}

int Student::row() const
{
    return m_row;
    // TODO: return the row number.
    return 0; // This line is only for the program to compile.
}

int Student::col() const
{
    return m_col;
    // TODO: return the column number.
    return 0; // This line is only for the program to compile.
}

MEALTYPE Student::typeWanted() const
{
    return m_typeWanted;
    // TODO: return the type of meal this student wants.
    return NOTHING; // This line is only for the program to compile.
}

void Student::moveForward()
{
    m_col--;
    if (m_col == 1)
    {
        p1->decLife();
        f1->deleteStudent(m_row, m_col);
    }
    // TODO:
    // Move the student forward for one step.
    // If this student reaches the first column, player's lives will be decreased by 1, and this student will be deleted.
    // YOUR CODE HERE
    return; // This line is only for the program to compile.
}

//---------------------------Implementions of Player -------------------------------------//

Player::Player(Fmart *fp)
{
    m_fp = fp;//将PLayer与Fmart链接
    m_row = 2;
    m_col = 1;
    m_lives = 3;
    m_score = 0;
    m_mealInHand = NOTHING;
    // TODO: this constructor initializes the player.
    // For example, the player should be at (2, 1), have 3 lives, and have 0 score.
    // Please consider other parameters to initialize.
}

Player::~Player()
{
    // TODO: delete everything you dynamically created.
}

int Player::row() const
{
    return m_row;
    // TODO: return the row number.
    return 0; // This line is only for the program to compile.
}
int Player::col() const
{
    return m_col;
    // TODO: return the column number.
    return 0; // This line is only for the program to compile.
}

int Player::lives() const
{
    return m_lives;
    // TODO: return the number of lives.
    return 1; // This line is only for the program to compile.
}

int Player::score() const
{
    return m_score;
    // TODO: return the score.
    return 0; // This line is only for the program to compile.
}

MEALTYPE Player::mealInHand() const
{
    
    return m_mealInHand;
    // TODO: return the type of meal in player's hand.
    return NOTHING; // This line is only for the program to compile.
}

void Player::pickup(MEALTYPE meal)
{
    if (meal == 1)
        m_mealInHand = APPLEPIE;
    else if (meal == 2)
        m_mealInHand = BEEF;
    else if (meal == 3)
        m_mealInHand = CURRY;
    else
        m_mealInHand = NOTHING;
    // TODO: pick up a box meal of type 'meal'.
    return; // This line is only for the program to compile.
}

void Player::move(int dir)
{
    if (dir == 1)
    {
        if (m_row > 1)
            m_row--;
    }
    if (dir == 2)
    {
        if (m_row < 3)
        {
            m_row++;
        }
    }
    // TODO: Move the player upwards of downwards.
    // dir will be either UP or DOWN.
    return; // This line is only for the program to compile.
}

void Player::deliver()
{
    if (m_mealInHand != NOTHING)
    {
        for (int i = 2; i <= 10; i++)
        {
            bool t = m_fp->studentAt(m_row, i);
            if (t == true)
            {
                if (m_mealInHand == m_fp->StudentWanted(m_row, i))
                {
                    m_fp->deleteStudent(m_row, i);
                    m_score = m_score + 10;
                    m_mealInHand = NOTHING;
                }
                break;
            }
        }
    }
    // TODO:
    // Send the meal to left-most student in that row.//�?能给到最左边那个
    // If (1) He/She doesn't want this meal
    //    (2) No student at this row
    //    (3) Player has no meal in hand
    // just do nothing and returns.
    // If success, delete the student, increment m_score by 10, and set player's hand to NOTHING
    return; // This line is only for the program to compile.
}

void Player::decLife()
{
    m_lives--;
    // TODO: decrease player's life by 1.
    return; // This line is only for the program to compile.
}

// ------------------------------Main function--------------------------------------//
int main()
{
    srand(time(NULL));
    Fmart f = Fmart();
    f.play();
}
