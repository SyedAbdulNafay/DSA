#include <iostream>
using namespace std;

struct Student
{
    int S_Id;
    Student *stu_next;

    Student(int id)
    {
        S_Id = id;
        stu_next = nullptr;
    }
};

struct Course
{
    int C_Id;
    Student *stu_head;
    Course *c_next;

    Course(int id)
    {
        C_Id = id;
        stu_head = nullptr;
        c_next = nullptr;
    }
};

Course *InsertCourse(Course *head, int id)
{
    if (head == nullptr)
    {
        Course *node = new Course(id);
        return node;
    }
    head->c_next = InsertCourse(head->c_next, id);
    return head;
}

bool SearchCourse(Course *head, int id)
{
    if (head == nullptr)
    {
        return false;
    }
    if (head->C_Id == id)
    {
        return true;
    }
    return SearchCourse(head->c_next, id);
}

Course *DeleteCourse(Course *head, int id)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->C_Id == id)
    {
        Course *temp = head;
        head = head->c_next;
        delete temp;
        return head;
    }
    head->c_next = DeleteCourse(head->c_next, id);
    return head;
}

void PrintCourses(Course *head)
{
    if (head == nullptr)
    {
        return;
    }

    cout << "Course " << head->C_Id << "-> ";
    Student *curr = head->stu_head;
    while (curr != nullptr)
    {
        cout << curr->S_Id << " ";
        curr = curr->stu_next;
    }
    cout << endl;
    PrintCourses(head->c_next);
}

Course *AddStudent(Course *head, int CId, int SId)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->C_Id == CId)
    {
        Student *node = new Student(SId);
        if (head->stu_head == nullptr)
        {
            head->stu_head = node;
            return head;
        }
        Student *curr = head->stu_head;
        while (curr->stu_next != nullptr)
        {
            curr = curr->stu_next;
        }
        curr->stu_next = node;
    }
    head->c_next = AddStudent(head->c_next, CId, SId);
    return head;
}

void DeleteStudent(Course **head, int CId, int SId)
{
    // traverse to the course from which we have to delete the student from
    Course *curr = *head;
    while (curr != nullptr)
    {
        // when we find the course, now we find the student in the course
        if (curr->C_Id == CId)
        {
            if (curr->stu_head == nullptr)
            {
                cout << "No students in Course " << curr->C_Id << endl;
                break;
            }
            else
            {
                if (curr->stu_head->S_Id == SId)
                {
                    Student *temp = curr->stu_head;
                    curr->stu_head = temp->stu_next;
                    delete temp;
                    break;
                }
                else
                {
                    Student *temp = curr->stu_head->stu_next;
                    Student *prev = curr->stu_head;
                    while (temp != nullptr)
                    {
                        if (temp->S_Id == SId)
                        {
                            prev->stu_next = temp->stu_next;
                            delete temp;
                            break;
                        }
                        temp = temp->stu_next;
                    }
                }
            }
            break;
        }
        curr = curr->c_next;
    }
}

void SearchStudent(Course *head, int id)
{
    if (head == nullptr)
    {
        return;
    }
    Student *curr = head->stu_head;
    while (curr != nullptr)
    {
        if (curr->S_Id == id)
        {
            cout << "Found in " << head->C_Id << endl;
            break;
        }
        curr = curr->stu_next;
    }

    SearchStudent(head->c_next, id);
}

int main()
{
    Course *C_head = nullptr;

    while (true)
    {
        cout << "Press" << endl;
        cout << "1. Add a course" << endl;
        cout << "2. Search a course" << endl;
        cout << "3. Delete a course" << endl;
        cout << "4. Print Course Info" << endl;
        cout << "5. Add a student to a course" << endl;
        cout << "6. Delete a student from a course" << endl;
        cout << "7. Delete a student from every course" << endl;
        cout << "8. Search a student" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            int id;
            cout << "Enter course ID: ";
            cin >> id;
            C_head = InsertCourse(C_head, id);
        }
        else if (option == 2)
        {
            int id;
            cout << "Enter course ID: ";
            cin >> id;
            SearchCourse(C_head, id);
        }
        else if (option == 3)
        {
            int id;
            cout << "Enter course ID: ";
            cin >> id;
            C_head = DeleteCourse(C_head, id);
        }
        else if (option == 4)
        {
            PrintCourses(C_head);
        }
        else if (option == 5)
        {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            int cid;
            cout << "Enter course ID: ";
            cin >> cid;
            C_head = AddStudent(C_head, cid, id);
        }
        else if (option == 6)
        {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            int cid;
            cout << "Enter course ID: ";
            cin >> cid;

            DeleteStudent(&C_head, cid, id);
        }
        else if (option == 7)
        {
            cout << "Enter student ID: ";
            int id;
            cin >> id;
            Course *curr = C_head;
            while (curr != nullptr)
            {
                DeleteStudent(&curr, curr->C_Id, id);
                curr = curr->c_next;
            }
        }
        else if (option == 8)
        {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            SearchStudent(C_head, id);
        }
        else if (option == 0)
        {
            break;
        }
        else
        {
            cout << "Enter valid option" << endl;
        }
    }

    return 0;
}