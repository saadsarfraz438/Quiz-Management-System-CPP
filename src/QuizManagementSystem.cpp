#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ================= QUESTION STRUCTURE =================

struct Question
{
	  string question,a,b,c,d,correct;
};

// ================= ADD QUESTIONS =================

void addQuestions(){  // To add questions to the file
    int mode;
    cout<<"Choose mode: 1. Overwrite existing questions  2. Append to existing: ";
    cin>>mode;
    ofstream file;
    //To overwrite or append
    if(mode==1) {
        file.open("questions.txt"); // overwrite mode
    }else{
    file.open("questions.txt",ios::app); // append mode
    }
    int n;
    string question,a,b,c,d,correct;
    cout<<"How many MCQs do you want to add? ";
    cin>>n;
    for (int i=0;i<n;i++){
        cout<<"\nEnter question (use_underscores_for_spaces): ";// To Input question and options
        cin>>question;
        cout<<"Option A: ";
        cin>>a;
        cout<<"Option B: ";
        cin>>b;
        cout<<"Option C: ";
        cin>>c;
        cout<<"Option D: ";
        cin>>d;
        cout<<"Correct option (A/B/C/D): ";
        cin>>correct;

        file<<question<<" "<<a<<" "<<b<< " "<<c<<" "<<d<<" "<<correct<<endl;
    }
    file.close(); //To Close the file
    cout<<"\nAll questions added successfully!\n";
}

// ================= TAKE QUIZ =================
void takeQuiz(){// To attempt the quiz
    ifstream file("questions.txt"); 
    string question,a,b,c,d,correct,answer;
    int score=0,total=0;  
    if (!file){  // Check if file exists and is accessible
        cout<<"No questions found. Please add questions first.\n";
        return;
    }
    while(file>>question>>a>>b>>c>>d>>correct) {
        total++;
        cout<<"\nQ"<<total<<": "<<question<<endl;
         cout<<"A. "<<a<<endl;
        cout<<"B. "<<b<<endl;
        cout<<"C. "<<c<<endl;
        cout<<"D. "<<d<<endl;
        cout<<"Your answer: ";
        
		cin>>answer;
        if(answer==correct) {  // Check if the user's answer is correct
            cout << "Correct!\n";
            score++;
        }else{
        cout<<"Wrong! Correct answer: "<<correct<<endl;
} 
}
		 file.close();// Close the file
    cout<<"\nQuiz Completed!\n";
    cout<<"Your Score: "<<score<<"out of "<<total<<endl;// Show final score
}

// ================= DELETE ALL QUESTIONS =================

void deleteAllQuestions() {// To delete all questions

    ofstream file("questions.txt", ios::trunc); // clears the file
    file.close();
    cout<<"All questions deleted successfully.\n";
}

// ================= MAIN FUNCTION =================

int main() { 
    int choice;
    do {
        cout<<"\n===== Quiz Management System =====\n";  // display menu system for the quiz
        cout<<"1.Add Questions (Teacher)\n";
        cout<<"2.Attempt Quiz (Student)\n";
        cout<<"3.Delete All Questions\n";
        cout<<"4.To exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1){
            addQuestions();
        }else if(choice==2) {
            takeQuiz();
        }else if(choice==3){
            deleteAllQuestions();
        }else if(choice==4){
            cout<<"Thank you for using the system!\n";
        }else{
cout<<"Invalid choice. Try again.\n";
        }
        
    } while 
	(choice != 4);// Repeat menu until user chooses to exit
    
    return 0;   
	}
