#include <iostream>
#include <vector>

struct Score {
    float math;
    float science;
    float social;
    float english;
    float nepali;
};

struct StudentRecord {
    std::string name;
    std::string dob;    // date of birth
    int classLevel;    // Class of the student
    int rollno;           // rollno (which is unique for each student)
    float quality;    // precentage showing the quality of the student
    Score scores;    // score of final exam of the current class
};

class RecordKeeper {
public:
    void insertRecord(StudentRecord sr);
    StudentRecord getRecord(int studentId);
    std::vector<StudentRecord> getRecords();

private:
    std::vector<StudentRecord> records;
};

void RecordKeeper::insertRecord(StudentRecord sr) 
{
    records.push_back(sr);
}

std::vector<StudentRecord> RecordKeeper::getRecords()
{
    return records;
}

StudentRecord RecordKeeper::getRecord(int studentId)
{
    for (auto record : records)
    {
        if (record.rollno == studentId)
            return record;
    }

    return {0};
}


class RecordUI {
public:
    bool exit;

    RecordUI(RecordKeeper& rs) : rs(rs) 
    {
    }

    void update(int choice)
    {
        clearScreen();

        switch(choice)
        {
        case '1':
            showRecords();
            break;
        case '2':
            addRecord();
            break;
        case '3':
            updateRecord();
            break;
        case 'q':
            exit = true;
            break;
        }

    }

    void run()
    {
        menu();
        
        std::cin >> choice;

        update(choice);
    }

private:
    RecordKeeper& rs;
    char choice;

    void showRecords()
    {
        for (StudentRecord record : rs.getRecords())
        {
            std::cout << "Name: " << record.name << std::endl;
            std::cout << "Date of Birth: " << record.dob << std::endl;
            std::cout << "Class: " << record.classLevel << std::endl;
            std::cout << "Rollno: " << record.rollno << std::endl;
            std::cout << "Quality: " << record.quality << std::endl;

            std::cout << "--------------Marks--------------" << std::endl;
            std::cout << "Math : " << record.scores.math << std::endl;
            std::cout << "Science : " << record.scores.science << std::endl;
            std::cout << "Nepali : " << record.scores.nepali << std::endl;
            std::cout << "English : " << record.scores.english << std::endl;
            std::cout << "Social : " << record.scores.social << std::endl;

            std::cout << std::endl;
        }   
    }

    void addRecord()
    {
        StudentRecord sr;

        std::cout << "Name: ";
        std::cin >> sr.name;

        std::cout << "DOB: ";
        std::cin >> sr.dob;

        std::cout << "Class: ";
        std::cin >> sr.classLevel;

        std::cout << "Rollno: ";
        std::cin >> sr.rollno;

        std::cout << "Quality percentage: ";
        std::cin >> sr.quality;

        std::cout << "Marks (Math, Science, Nepali, English, Social): " << std::endl;
        std::cin >> sr.scores.math >> sr.scores.science >> sr.scores.nepali
                 >> sr.scores.english >> sr.scores.social;

        rs.insertRecord(sr);
    }

    void updateRecord()
    {

    }

    void menu() 
    {
        std::cout << "        RecordKeeper                 " << std::endl;
        std::cout << " 1 ::   Show Records" << std::endl;
        std::cout << " 2 ::   Add Record" << std::endl;
        std::cout << " 3 ::   Update Record" << std::endl;
        std::cout << " q ::   Exit" << std::endl << std::endl;
    }

    void clearScreen()
    {

    }
};

int main()
{
    RecordKeeper studentRecords;

    StudentRecord sr = {
        "Rajesh Khanna",
        "2002-06-18",
        14,
        54,
        93.76,
        {94, 96, 90, 93, 88}
    };

    studentRecords.insertRecord(sr);
    
    RecordUI ui(studentRecords);

    while(!ui.exit) {
        ui.run();
    }

    return 0;
}