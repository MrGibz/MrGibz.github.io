//Garrett Gibson
//Email: garrettgibson0530@gmail.com
//Cell: (954)559-7486
//December 5, 2023
//Version 1.0
//Purpose:
//The purpose of this assignment was to convert code from Java to C++ and
//demonstrate that the code is functional and useful to a user.
//Issues:
//Minimal issues were encountered during the development of this code.
//I learned that Java and C++ are similar in syntax and structure.
//This artifact demonstrates my ability to be able to work with multiple
//progamming languages to complete the same tasks. In the field,
//this knowledge could be useful when conducting a technical refresh
//of a legacy system or application and languages used to build
//the system or application will be different.

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <vector>

//Appointment
namespace appointmentService {
    class Appointment {
    public:
        std::string aptID, aptDesc;
        std::time_t aptDate;

        Appointment() : aptID("") {}
//defines attributes and parameters for Appointment class
        Appointment(const std::string& aptID, const std::time_t aptDate, const std::string& aptDesc) {
            if (aptID.empty() || aptID.length() > 10) {
                throw std::invalid_argument("Invalid ID.");
            }

            if (aptDate < std::time(0) || aptDate == 0) {
                throw std::invalid_argument("Date is invalid.");
            }

            if (aptDesc.empty() || aptDesc.length() > 50) {
                throw std::invalid_argument("Invalid description.");
            }

            this->aptID = aptID;
            this->aptDate = aptDate;
            this->aptDesc = aptDesc;
        }
//getter for aptID
        std::string getAptID() const {
            return aptID;
        }
//getter for aptDate
        std::time_t getAptDate() const {
            return aptDate;
        }
//getter for aptDesc
        std::string getAptDesc() const {
            return aptDesc;
        }
//compares aptIDs between two Appointments
        bool operator==(const Appointment& other) const {
            return this->aptID == other.aptID;
        }
    };

//AppointmentService
    class AppointmentService {
        //vector of apts defined
    private:
        std::vector<Appointment> appointments;

    public:
        bool add(const Appointment& appointment) {
            bool aptExists = false;

            for (const Appointment& a : appointments) {
                if (a == appointment) {
                    aptExists = true;
                    break;
                }
            }
//if apt doesn't exist, adds apt to vector
            if (!aptExists) {
                appointments.push_back(appointment);
                std::cout << "Appointment added successfully!" << std::endl;
                return true;
            }
//else doesn't allow apt to be added.
            else {
                std::cout << "Appointment already exists." << std::endl;
                return false;
            }
        }
//if apt is in vector and aptID matches, deletes apt from vector
        bool deleteAppointment(const std::string& aptID) {
            for (auto it = appointments.begin(); it != appointments.end(); ++it) {
                if (it->getAptID() == aptID) {
                    appointments.erase(it);
                    return true;
                }
            }
            return false;
        }
    };

}

//Contact

namespace contactService {
    class Contact {
    public:
        std::string contactID, firstName, lastName, number, address;

        Contact() : contactID("") {}
//defines contact attributes and parameters for each. none can be null and must be within defined lengths
        Contact(const std::string& contactID, const std::string& firstName, const std::string& lastName, const std::string& number, const std::string& address) {
            if (contactID.empty() || contactID.length() > 10) {
                throw std::invalid_argument("Invalid ID.");
            }

            if (firstName.empty() || firstName.length() > 10) {
                throw std::invalid_argument("First name is invalid.");
            }

            if (lastName.empty() || lastName.length() > 10) {
                throw std::invalid_argument("Last name is invalid.");
            }

            if (number.empty() || number.length() != 10) {
                throw std::invalid_argument("Invalid number");

            }
            if (address.empty() || address.length() > 30) {

                throw std::invalid_argument("Invalid address");

            }

            this->contactID = contactID;
            this->firstName = firstName;
            this->lastName = lastName;
            this->number = number;
            this->address = address;

        }
//contactID getter
        std::string getContactID() const {
            return contactID;
        }
//firstName getter
        std::string getFirstName() const {
            return firstName;
        }
//lastName getter
        std::string getLastName() const {
            return lastName;
        }
//number getter
        std::string getNumber() const {
            return number;
        }
//address getter
        std::string getAddress() const {
            return address;
        }
//firstName setter
        void setFirstName(const std:: string& firstName) {
            this->firstName = firstName;
        }
//lastName setter
        void setLastName(const std:: string& lastName) {
            this->lastName = lastName;
        }
//number setter
        void setNumber(const std:: string& number) {
            this->number = number;
        }
//address setter
        void setAddress(const std:: string& address) {
            this->address = address;
        }
//compares contactIDs and returns boolean
        bool operator==(const Contact& other) const {
            return this->contactID == other.contactID;
        }
    };

//ContactService
    class ContactService {
    private:
        std::vector<Contact> contacts;
//defines vector of contacts
    public:
        //adds contact to vector if it isn't already found in the vector.
        bool add(const Contact& contact) {
            bool contactExists = false;

            for (const Contact& a : contacts) {
                if (a == contact) {
                    contactExists = true;
                    break;
                }
            }

            if (!contactExists) {
                contacts.push_back(contact);
                std::cout << "Contact added successfully!" << std::endl;
                return true;
            }
            else {
                std::cout << "Contact already exists." << std::endl;
                return false;
            }
        }
        //if contactID is found in vector, removes contact from vector
        bool deleteContact(const std::string& contactID) {
            for (auto it = contacts.begin(); it != contacts.end(); ++it) {
                if (it->getContactID() == contactID) {
                    contacts.erase(it);
                    return true;
                }
            }
            return false;
        }
        //function that allows updating of contact if the contactID is found. If found, firstName, lastName, number, and address can be updated.
        bool updateContact(const std::string& contactID, const std::string& firstName, const std::string& lastName, const std::string& number, const std::string& address) {
            for (Contact& contactList : contacts) {
                if (contactList.getContactID() == contactID) {
                    if (!firstName.empty() && firstName.length() < 11) {
                        contactList.setFirstName(firstName);
                        std::cout << "Name updated!" << std::endl;
                    }

                    if (!lastName.empty() && lastName.length() < 11) {
                        contactList.setLastName(lastName);
                    }

                    if (!number.empty() && number.length() == 10) {
                        contactList.setNumber(number);
                    }

                    if (!address.empty() && address.length() < 31) {
                        contactList.setAddress(address);
                    }
                    return true;
                }
            }

            return false;
        }

    };

}

//Contact

namespace taskService {
    class Task {
    public:
        std::string taskID, taskName, taskDescription;

        Task() : taskID("") {}
//defines Task class and attributes of class. attributes must not be empty and must comply with length limits
        Task(const std::string& taskID, const std::string& taskName, const std::string& taskDescription) {
            if (taskID.empty() || taskID.length() > 10) {
                throw std::invalid_argument("Invalid ID.");
            }

            if (taskName.empty() || taskName.length() > 20) {
                throw std::invalid_argument("Invalid name.");
            }

            if (taskDescription.empty() || taskDescription.length() > 50) {
                throw std::invalid_argument("Invalid description length.");
            }

            this->taskID = taskID;
            this->taskName = taskName;
            this->taskDescription = taskDescription;

        }
//taskID getter
        std::string getTaskID() const {
            return taskID;
        }
//taskName getter
        std::string getTaskName() const {
            return taskName;
        }
//taskDescription getter
        std::string getTaskDescription() const {
            return taskDescription;
        }
//taskName setter
        void setTaskName(const std:: string& taskName) {
            this->taskName = taskName;
        }
//taskDescription setter
        void setTaskDescription(const std:: string& taskDescription) {
            this->taskDescription = taskDescription;
        }
//boolean function that compares taskIDs and returns true or false
        bool operator==(const Task& other) const {
            return this->taskID == other.taskID;
        }
    };

//TaskService
    class TaskService {
    private:
        std::vector<Task> tasks;
//adds task to task vector if it isn't already in the vector.
    public:
        bool add(const Task& task) {
            bool taskExists = false;

            for (const Task& a : tasks) {
                if (a == task) {
                    taskExists = true;
                    break;
                }
            }

            if (!taskExists) {
                tasks.push_back(task);
                std::cout << "Task added successfully!" << std::endl;
                return true;
            }
            else {
                std::cout << "Task already exists." << std::endl;
                return false;
            }
        }
//if taskID is found in vector, removes task from vector.
        bool deleteTask(const std::string& taskID) {
            for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                if (it->getTaskID() == taskID) {
                    tasks.erase(it);
                    return true;
                }
            }
            return false;
        }
//if taskID found in vector, updates taskName and taskDescription
        bool updateTask(const std::string& taskID, const std::string& taskName, const std::string& taskDescription) {
            for (Task& taskList : tasks) {
                if (taskList.getTaskID() == taskID) {
                    if (!taskName.empty() && taskName.length() < 21) {
                        taskList.setTaskName(taskName);
                        std::cout << "Name updated!" << std::endl;
                    }

                    if (!taskDescription.empty() && taskDescription.length() < 11) {
                        taskList.setTaskName(taskName);
                        std::cout << "Description updated!" << std::endl;
                    }
                    return true;
                }
            }
            return false;
        }

    };

}

int main() {
    using namespace appointmentService;
    using namespace contactService;
    using namespace taskService;

    //create aptService instance
    AppointmentService aptService;

    try {
        //creates two apt instances and adds them to aptService. ensures same apt can't be added twice
        Appointment apt1("APT1", std::time(0), "Meeting with attorney.");
        aptService.add(apt1);

        Appointment apt2("APT2", std::time(0) + 3600, "Daily Scrum.");
        aptService.add(apt2);

        //tries to add apt1 twice unsuccessfully
        aptService.add(apt1);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Create contactService instance
    ContactService contactService;

    try {
        //creates two contact instances and adds them to contactService. ensures same contact can't be added twice
        Contact contact1("C1", "Garrett", "Gman", "1234567890", "123 Awesome Drive");
        contactService.add(contact1);

        Contact contact2("C2", "Mike", "Davis", "9876543210", "876 Yes Way");
        contactService.add(contact2);

        //tries to add contact1 twice unsuccessfully
        contactService.add(contact1);

        //updates contactinfo for C1
        contactService.updateContact("C1", "Ash", "Bash", "64", "000 Uh Oh Circle");
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    //Create taskService instance
    TaskService taskService;

    try {
        //creates two task instances and adds them to taskService. ensures same task can't be added twice
        Task task1("T1", "Contract", "Discuss contract goals and timeline");
        taskService.add(task1);

        Task task2("T2", "Run", "Run around the block for exercise");
        taskService.add(task2);

        //tries to add task1 twice unsuccessfully
        taskService.add(task1);

        //updates T1 info
        taskService.updateTask("T1", "Training", "Complete contract training");
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}