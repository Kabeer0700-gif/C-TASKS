#include <iostream>
using namespace std;

class Level
{
public:
    string details;
    Level()
    {
        details = "";
    }
    Level(string details) : details(details) {}

    void display()
    {
        cout << "Details of Levels: " << details << endl;
    }

    ~Level()
    {
        if(!details.empty()){
        cout << "Level '" << details << "' deleted successfully" << endl;
    }
}
};
class VideoGame
{
public:
    string title;
    string genre;
    int count;
    Level levels[3];

    VideoGame()
    {
        title = "";
        genre = "";
        count = 0;
    }

    VideoGame(string title, string genre) : title(title), genre(genre),count(0) {}

    void displayGame()
    {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        for (int i = 0; i < count; i++)
        {
            levels[i].display();
        }
    }

    void addLevel(Level l)
    {
        if (count < 3)
        {
            levels[count++] = l;
        }
    }

    ~VideoGame()
    {
        cout << genre<<" Game deleted successfully" << endl;
    }
};

int main()
{
    Level l1("Easy: Damage 50(%) on each shot");
    Level l2("Medium: Damage 25(%) on each shot");
    Level l3("Hard: Damage 10(%) on each shot");

    VideoGame shooting("Shooting Game", "Shooting");
    shooting.addLevel(l1);
    shooting.addLevel(l2);
    shooting.addLevel(l3);

    shooting.displayGame();
}