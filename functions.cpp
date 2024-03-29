#include <iostream>
#include <vector>
#include <iostream>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds
using namespace std;
//define functions

void greet()
{
  std::cout << "=====================\n";
  std::cout << "Hangman: The Game\n";
  std::cout << "=====================\n";
  std::cout << "Instructions: Save your friend from being hanged by guessing the letters in the codeword.\n";
  std::cout << "Guess fast! You have only one minute until your friend is hanged!\n";
}

void display_misses(int misses)
{
  if(misses==0)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==1)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==2)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==3)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==4)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==5)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==6)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" / \\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }

}

void display_status(vector<char> incorrect, string answer)
{
    cout<<"Incorrect Guesses: \n";
    //Loop thru incorrect guesses vector and print each incorrect guess
    for(int i = 0; i<incorrect.size(); i++)
    {
        cout<<incorrect[i]<<" ";
    }
    cout<<"\nCodeword:\n";

    for(int i = 0; i <answer.length(); i++)
    {
        cout<<answer[i]<<" ";
    }
}
void dance_animation() {
    const int num_frames = 4;
    const string frames[num_frames] = {
        "  O\n /|\\\n / \\\n",
        " \\O/\n  |\n / \\\n",
        "  O\n /|\\\n / \\\n",
        " \\O/\n  |\n / \\\n",
    };

    for (int i = 0; i < num_frames; i++) {
        system("clear"); // Use "cls" on Windows
        std::cout << frames[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void dead_face_animation() {
    const vector<string> frames = {
        "   X   X\n  YOU'RE DEAD",   // Eyes as 'X' with "DEAD"
        "   -   -",           // Closed eyes without "DEAD"
        "   X   X\n  YOU'RE DEAD",   // Eyes as 'X' with "DEAD"
        "   -   -",           // Closed eyes without "DEAD"
        "   X   X\n  YOU'RE DEAD",   // Final frame with 'X' eyes and "DEAD"
    };

    for (const auto& frame : frames) {
        system("clear"); // Use "cls" on Windows
        cout << frame << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}


void end_game(string answer, string codeword) {
    if (answer == codeword) {
        cout << "Hooray! You saved the person from being hanged and earned a medal of honor!\n";
        cout << "Congratulations!\n";
        dance_animation();
    } else {
        cout << "Oh no! The man is hanged!\n";
        dead_face_animation();
    }
}
