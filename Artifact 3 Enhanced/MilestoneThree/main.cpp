//Garrett Gibson
//Email: garrettgibson0530@gmail.com
//Cell: (954)559-7486
//December 5, 2023
//Version 1.0
//Purpose:6
//The purpose of this assignment was to create a database that stores course information
//and enable the user to perform CRUD functionality on the database.
//Issues:
//Learning how to import the sqlite library into CLion to use with C++ was a hurdle
//I had to overcome. It took hours to configure it properly but I found that the
//solution was rather simple. Once established, I was able to implement SQL commands and
//CRUD functionality using the library without issue.


#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <string>
#include "sqlite3.h"



using namespace std;



// define a structure to hold course information;
class Course {
public:
    string courseNum;
    string courseName;
    string coursePrereq;
    Course() {
        courseNum = "0";
        courseName = "0";
        coursePrereq = "0";
    }
    //setters
    void setCourseNum(string num) {
        courseNum = num;
    }

    void setCourseName(string name) {
        courseName = name;
    }

    void setCoursePrereq(string prereq) {
        coursePrereq = prereq;
    }
    //getters
    string getCourseNum() {
        return courseNum;
    }

    string getCourseName() {
        return courseName;
    }

    string getCoursePrereq() {
        return coursePrereq;
    }
};

struct Node {
    Course course;
    Node* left;
    Node* right;

    //default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }
    //initialize with a given course
    Node(Course aCourse) : Node() {
        this->course = aCourse;
    }

};

class BinarySearchTree {

private:
    Node* root;
    void addNode(Node* node, Course course);
    void inOrder(Node* node);
    void inReverseOrder(Node* node);

public:
    BinarySearchTree();
    //virtual ~BinarySearchTree();
    void InOrder();
    void InReverseOrder();
    Course Search(string courseNum);
    void Insert(Course course);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    //initialize root equal to nullptr
    root = nullptr;
}

void BinarySearchTree::addNode(Node* node, Course course) {
    //if courseNum larger than node courseNum, add to left
    if (node->course.courseNum.compare(course.courseNum) > 0) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        }
        else {
            this->addNode(node->left, course);
        }
    }
        //add to right
    else {
        if (node->right == nullptr) {
            node->right = new Node(course);
        }
        else {
            this->addNode(node->right, course);
        }
    }
}

void BinarySearchTree::inOrder(Node* node) {
    //recursively call function on itself.
    //if tree is not empty
    if (node != nullptr) {
        //print all nodes in order starting on left side of root
        inOrder(node->left);

        cout << node->course.courseNum << ", "
             << node->course.courseName << " | "
             << node->course.coursePrereq << endl;

        //print all nodes in order on right side
        inOrder(node->right);

    }
}

void BinarySearchTree::inReverseOrder(Node* node) {
    //recursively call function on itself.
    //if tree is not empty
    if (node != nullptr) {
        //print all nodes in order starting on right side of root
        inOrder(node->right);

        cout << node->course.courseNum << ", "
             << node->course.courseName << " | "
             << node->course.coursePrereq << endl;

        //print all nodes in order on left side
        inOrder(node->left);

    }
}

void BinarySearchTree::InOrder() {
    // call inOrder fuction and pass root 
    this->inOrder(root);
}

void BinarySearchTree::InReverseOrder() {
    // call inReverseOrder function and pass root as starting point
    this->inReverseOrder(root);
}

Course BinarySearchTree::Search(string courseNum) {

    Node* current = root;
    //loop downwards until bottom is reached or course is found
    while (current != nullptr) {
        //cout << courseName << " vs " << current->course.courseName << " -- ";<---used for testing
        // if current node matches
        if (current->course.courseNum.compare(courseNum) == 0) {
            //cout << "equals" << endl;<---used for testing
            return current->course;

        }
        //if courseNum is smaller than current then traverse left
        if (courseNum.compare(current->course.courseNum) < 0) {

            current = current->left;
            //cout << "left" << endl;<---used for testing
        }
            //if larger, traverse right
        else {
            current = current->right;
            //cout << "right" << endl;<---used for testing
        }
    }
    //return empty course (course not found)
    Course course;
    return course;
}

void BinarySearchTree::Insert(Course course) {
    //if root is empty, root becomes new course leaf
    if (root == nullptr) {
        root = new Node(course);
    }
        //else call addNode function to find where to insert new course node
    else {
        this->addNode(root, course);
    }

}


int main(int argc, char* argv[])
{

    sqlite3* db;
    char* errMsg = 0;

    //Open our database
    int rc = sqlite3_open("CourseInfo.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }

    BinarySearchTree* bst{};

    Course course;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Course File" << endl;
        cout << "  2. Print Course List in alphanumeric Order" << endl;
        cout << "  3. Print Course List in reverse alphanumeric Order" << endl;
        cout << "  4. Print Specific Course's Information" << endl;
        cout << "  5. Create Course" << endl;
        cout << "  6. Read Course" << endl;
        cout << "  7. Update Course" << endl;
        cout << "  8. Delete Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            //read's file name text from user and reads that file's data into array of objects. then stores those objects in BST
            case 1: {
                bst = new BinarySearchTree();
                string line;
                Course courses[100];
                string file;
                cout << "Please enter the file name you would like to open: " << endl; //courseinfo.txt or whatever the .txt file name is that contains the course list
                cin >> file;

                ifstream myCourseData;
                myCourseData.open(file);

                if (!myCourseData) {
                    cout << "Error opening file." << endl;
                }

                int index = 0;
                string number, name, prerequisite;

                while (!myCourseData.eof() && getline(myCourseData, line, '\n')) {

                    string s, t, u;

                    s = line.substr(0, line.find(','));
                    courses[index].setCourseNum(s);
                    line.erase(0, line.find(',') + 1);

                    t = line.substr(0, line.find(','));
                    courses[index].setCourseName(t);
                    line.erase(0, line.find(',') + 1);

                    u = line.substr(0);
                    courses[index].setCoursePrereq(u);
                    line.erase(0, line.find(',') + 1);

                    //cout << courses[index].getCourseNum() << " " << courses[index].getCourseName() << " " << courses[index].getCoursePrereq() << endl; <---used for testing
                    bst->Insert(courses[index]);
                    index++;

                }

                cout << "File loaded into Binary Search Tree Data Structure!" << endl;

                break;
            }

            case 2:{
                //prints bst nodes in alphabetic order from low to high.
                bst->InOrder();
                break;
            }

            case 3:{
                //prints bst nodes in alphabetic order from high to low.
                bst->InReverseOrder();
                break;
            }

            case 4:{
                //searches BST for matching courseNum based on the courseNum input from user.
                string num;
                cout << "What course number are you searching for? " << endl;
                getline(cin >> ws, num);
                course = bst->Search(num);
                cout << "Course Number: " << course.getCourseNum() << " | Course Name: " << course.getCourseName() << " | Course Prerequisites: " << course.getCoursePrereq() << endl;
                break;
            }
//create functionality for our CourseInfo table. Prompts user for 3 data fields and performs INSERT on table with the user's input.
            case 5: {
                string num, name, prereqs;
                cout << "Please enter the Course Number: " << endl;
                cin >> num;
                cout << "Please enter the Course Name: " << endl;
                cin >> name;
                cout << "Please enter the Course Prereqs: " << endl;
                cin >> prereqs;
                string sql = "INSERT INTO CourseInfo (CourseNum, CourseName, CoursePrereqs) VALUES ('" +
                        num + "', '" +
                        name + "', '" +
                        prereqs + "');";
                rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);
                if (rc != SQLITE_OK) {
                    std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
                } else {
                    std::cout << "Course created successfully!" << std::endl;
                }
                break;
            }
//performs read functionality. prompts user for course number and returns the callback function to print course details to console.
            case 6: {
                string num;
                cout << "Please enter the Course Number you are searching for: " << endl;
                cin >> num;
                string sql = "SELECT * FROM CourseInfo WHERE CourseNum = '" + num + "';";
                auto callback = [](void *data, int argc, char **argv, char **colNames) -> int {
                    for (int i = 0; i < argc; ++i) {
                        std::cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
                    }
                    return 0;
                };
                rc = sqlite3_exec(db, sql.c_str(), callback, 0, 0);

                if (rc != SQLITE_OK) {
                    std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
                }
                break;
            }
//performs update functionality on CourseInfo table. prompts user for course number to update and then prompts user for updates data.
// Then UPDATE query is performed on our table to add updated data to that course number.
            case 7: {
                string num, newNum, newName, newPrereqs;
                cout << "Which course would you like to update? (Enter a Course Number): " << endl;
                cin >> num;
                cout << "Enter new Course Number: " << endl;
                cin >> newNum;
                cout << "Enter new Course Name: " << endl;
                cin >> newName;
                cout << "Enter new Course Prereqs: " << endl;
                cin >> newPrereqs;
                string sql = "UPDATE CourseInfo SET CourseNum = '" +
                        newNum + "', CourseName = '" +
                        newName + "', CoursePrereqs = '" +
                        newPrereqs + "' WHERE CourseNum = '" +
                        num + "';";
                rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);

                if (rc != SQLITE_OK) {
                    std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
                } else {
                    std::cout << "Course updated successfully!" << std::endl;
                }
                break;
            }
//performs delete functionality on CourseInfo table. user is prompted to enter a course number and that course is then deleted from our table
            case 8: {
                string num;
                cout << "Which course would you like to delete? (Enter a Course Number): " << endl;
                cin >> num;
                string sql = "DELETE FROM CourseInfo WHERE CourseNum = '" + num + "';";
                rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);

                if (rc != SQLITE_OK) {
                    std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
                } else {
                    std::cout << "Course deleted successfully!" << std::endl;
                }
                break;
            }
        }
        }
    //exits program!
    cout << "Thanks for using the course planner and good luck!" << endl;
    // Close the database
    cout << "Closing DB" << endl;
    sqlite3_close(db);
    return 0;
    }



