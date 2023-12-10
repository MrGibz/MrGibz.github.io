//Garrett Gibson
//CS300 Project 2
//ABCU Course Information Storing and Reading


#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <string>

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

public:
    BinarySearchTree();
    //virtual ~BinarySearchTree();
    void InOrder();
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

void BinarySearchTree::InOrder() {
    // call inOrder fuction and pass root 
    this->inOrder(root);
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

    BinarySearchTree* bst{};

    Course course;

    int choice = 0;
    while (choice != 4) {
        cout << "Menu:" << endl;
        cout << "  1. Load Course File" << endl;
        cout << "  2. Print Course List in alphanumeric Order" << endl;
        cout << "  3. Print Specific Course's Information" << endl;
        cout << "  4. Exit" << endl;
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

            case 2:
                //prints bst nodes in alphanumeric order from low to high.
                bst->InOrder();                
                break;

            case 3:
                //searches BST for matching courseNum based on the courseNum input from user.
                string num;
                cout << "What course number are you searching for? " << endl;
                getline(cin >> ws, num);
                course = bst->Search(num);              
                cout << "Course Number: " << course.getCourseNum() << " | Course Name: " << course.getCourseName() << " | Course Prerequisites: " << course.getCoursePrereq() << endl;
                break;
        }
    }
    //exits program!
    cout << "Thanks for using the course planner and good luck!" << endl;

    return 0;




    
}