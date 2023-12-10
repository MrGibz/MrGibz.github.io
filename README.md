# <code style="color : green">Garrett Gibson ePortfolio</code>

## <code style="color : green">Table of Contents</code>

### <code style="color : green">1. Professional Self-Assessment</code>
### <code style="color : green">2. Code Review</code>
### <code style="color : green">3. Software Design and Engineering: Artifact 1</code>
### <code style="color : green">4. Algorithms and Data Structure: Artifact 2</code>
### <code style="color : green">5. Databases: Artifact 3</code>

## <code style="color : green">1. Professional Self-Assessment</code>

I began my journey to complete my BS in Computer Science at SNHU in 2020. When I began, I had about 30 credits towards my degree and had ambitions to earn a commission in the military. About halfway to my BS in Computer Science, I met this goal. With that, my ambition continued to flourish and my intent is to apply for graduate school once I earn my undergrad after this term. I am incredibly grateful to this University for enabling me to achieve my personal and professional goals and earning this degree is a momentous milestone in my life.

As I have discussed in my narratives that you will read below, this capstone course has taught me a lot about myself. First, I have learned that I possess the skills to solve problems I may not be familiar with. The ability to research and understand computer science and the many technical terms that comes with the field has been prevalent throughout this program and continued to be vital to my success in this course. I learned that, while I may not remember everything about every class, I have learned the fundamental building blocks required to effectively and competently write code to achieve different objectives, such as the required course outcomes associated with the rubric for this project.

Overall, this program has taught me a lot of fundamental coding concepts that will be useful for me as an entry level developer. More notably, this program has taught me how to use resources, tools, and networking to aid in understanding and finding solutions. Throughout the program, I have relied on classmates to collaborate with and have even found myself able to offer assistance to others. Collaborative team environments allow for additional growth as you are either learning something new from somebody that really understands it, or you have the opportunity to teach what you know to someone else, further solidifying your experience in the process. I have had the pleasure of working in IT management for about a year now and I know firsthand that communicating requirements and expectations to stakeholders is the single most important aspect of software development. Getting good requirements and user stories is a must in order to develop most effectively for a client.

### Outcome 1:
Employ strategies for building collaborative environments that enable diverse audiences to support organizational decision making in the field of computer science

I achieved Outcome 1 by utilizing a code review to communicate what I thought were areas of improvement for previous projects. Once I identified insufficiencies, I discussed how I intended to approach the enhancement. I maintained an open mind and asked multiple questions during the review in hopes of receiving feedback from the professor. Once feedback was received, I incorporated it into my final solution. Without that feedback, my enhancement solution would not have been as capable or effective.

I also implemented industry standard, function level commenting throughout my code with the mindset that any future collaborator could pick up my code where I left off and easily understand what I was trying to do with each block of code and why. In the programming industry, this is best practice and often the only interaction that will ever take place between two different teams. It is important to ensure simplicity and conciseness in your commenting to help enable diverse audiences to effectively review and modify your code. 

### Outcome 2:
Design, develop, and deliver professional-quality oral, written, and visual communications that are coherent, technically sound, and appropriately adapted to specific audiences and contexts

During my code review, I succinctly discussed the original artifacts that I planned to enhance. In a video code review, I spent upwards of 30 minutes taking a line by line deep dive into the code and how there was room for improvement. For each required enhancement, I described the current functionality of the code and briefly covered how my enhancement plans would take place. I did this in a clear, professional manner, knowing that the audience was my professor. I had 3+ takes of my code review to ensure I provided a top level description of the artifacts and my intentions moving forward.

### Outcome 3:
Design and evaluate computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to its solution, while managing the trade-offs involved in design choices

To meet Outcome 3, I enhanced an artifact from a 300 level course to include a reverse sorting algorithm on a binary search tree. In the original artifact, only an in order sort existed. I was able to combine reverse engineering and algorithmic research to determine how to implement a reverse order sorting algorithm on the data in the binary search tree. Additionally, I incorporated a standard computer science practice called abstraction to access the private inReverseOrder() method with a public accessor method.

### Outcome 4:
Demonstrate an ability to use well-founded and innovative techniques, skills, and tools in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals

I meet Outcome 4 in a lot of ways. Most notably in Artifact 3, I incorporate the SQLite library into C++ code to create a Course database that holds course information that users can conduct CRUD functionality on. Using SQLite with the CLion IDE proved to be challenging but I was able to troubleshoot the combination of tools effectively enough to find a working solution. Once I got the SQLite library working, I was able to add CRUD functionality in an industry standard manner where any entry level developer can look at and understand what my code is doing. I was especially proud of this artifact because it demonstrated effectiveness in working with databases in a way that I believe will be especially useful when I enter the field as a new developer.

### Outcome 5:
Develop a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources

I met the objectives in Outcome 5 by removing hardcoded ways of accessing course data in Artifact 3. Originally, the code allowed for manual user entry to load data from a .txt file to the binary search tree. I identified this early on as a non-optimal solution to the problem the original code was trying to solve. This led me to wanting to implement a database solution that would outright prevent this from happening. While the intent of the original assignment was not to have the most effective solution, I believe that I addressed a major design flaw by adding this database capability to the code, resulting in a more secure program for handling course information.

## Below, you will have the opportunity to review my portfolio in its entirety. Each artifact is accompanied with screenshots of some of the code at work, a narrative describing each artifact and what I did to enhance it, as well as a link to the source code for the original artifact and the enhanced version. Thank you for this wonderful opportunity to showcase some of the hardest work I have done yet!

## <code style="color : green">2. Code Review</code>
[Click to watch my Code Review on YouTube!](https://www.youtube.com/watch?v=rhpFhrwW_X4&list=PLZdwj6aeoqEC1B0XgmjcImfCOB5T__tAr&index=1)

## <code style="color : green">3. Software Design and Engineering: Artifact 1</code>
[Click here to navigate to Artifact 1 Source Code](https://github.com/MrGibz/MrGibz.github.io.git)

Screenshot of the original code written in Java:

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/77d9cb60-b74c-45d2-b5a9-dcad305798dc)

Screenshot of the code converted to C++:

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/d0e39661-b666-461b-919a-cdc96dfc6e87)

This artifact was part of CS-320’s MobileApplication assignment. This course covered testing automation in programming. I originally wrote this code in Java and utilized JUnit testing to check for accuracy of all of the functions. I wrote this program in early 2022 when I took this course and haven’t touched it since. The purpose was to ensure 100% test coverage using JUnit.

One of the possible ways to meet the requirement for a Software Design and Engineering enhancement was to convert a program into a different language and I found this exciting. I went through old assignments and found this one and thought it would be really neat to include it in my ePortfolio after converting it to C++. It shows my ability to understand key concepts of Object-Oriented programming by being able to use two different languages to accomplish the same tasks of creating/editing appointments, contacts, and tasks for an application. This showcases my ability to be able to remain flexible and change languages last minute without losing accuracy or capability. I was able to also demonstrate using completely different tools (C++ and CLion) to accomplish the same task. This time, I included a main function to run my code and demonstrate that it all works. This was not in scope of the original assignment.

This assignment does meet the original course objectives I set out to meet in this enhancement. In this enhancement, I demonstrate using innovative skills and techniques for implementing design solutions and accomplishing goals and I demonstrate the ability to address potential design flaws related to security.

Something I learned while modifying this code and transferring functionality from Java to C++ was the nuances between the two languages. They are similar in some ways and completely different in others. This assignment also taught me that programming concepts rule over knowing the ins and outs of a language. Once you understand a concept, you can use your resources and documentation  to figure out how to do something in another language. One challenge I faced was just getting started. I had to brush up on my C++ skills. Luckily, I have used C++ throughout this program so it was easy to look back at other assignments to see how I did things like classes and functions. It made implementation very easy once I got going. The code was also very similar for appointments, contacts, and tasks so once I had one down, the remaining ones were easy to complete.
	

## <code style="color : green">4. Algorithms and Data Structure: Artifact 2</code>
[Click here to navigate to Artifact 2 Source Code](https://github.com/MrGibz/MrGibz.github.io.git)

Sorting Algorithm to traverse BST in Reverse Order:

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/aa8fb65d-36fc-4183-bbd2-9143dfad95c3)

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/46df4d4c-5b07-42e0-b263-12303333bf1d)

Output when conducting Reverse Order Sort:

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/56369c99-4507-467e-9c45-fe6eed30377d)


This artifact is project two from the CS-300 Data Structures and Algorithms course. In this project, we load course information from a .txt file into a Binary Search Tree and then perform sorting algorithms and search functions on the nodes of the BST. My enhancement to this artifact is an algorithm that conducts a sort of the BST in reverse alphabetic order. I am including this artifact in my ePortfolio because I believe that it demonstrates fundamental understanding of how essential algorithms are built and how they can be used with a BST. Additionally, I utilize the concept of recursion to call the algorithm multiple times within itself to achieve the desired result. I am excited to be able to show knowledge of algorithms, data structures, and recursion all in a simple, effective program like this one.

I meet the course objectives that I intended to meet with this artifact enhancement. I believe I even exceed them by utilizing recursion in my algorithm as well. This is a useful enhancement that shows an understanding of potential user requirements that is useful in the field of computer science where you are developing to a customer’s needs. In this instance, there was no way to sort the courses from Z to A. I added this functionality because if there is a database of 300 courses, you might want to have that capability. I also utilize secure coding practices by having a private inReverseOrder() function and a public InReverseOrder() function that calls on inReverseOrder() to perform the sort. This further shows my ability to execute efficient, secure coding to perform a function.

When I initially set out to enhance this artifact, I was nervous that writing this algorithm would be challenging. I decided to think about my problem and did a search online for how to implement a reverse sort on a BST. I was able to read about different ways it can be implemented and was happy to see that it was very similar to an in order sort like that one that already existed in my code. The biggest challenge was trying to figure out what exactly I was trying to do with the reverse sort. I was certainly rusty on the lessons taught in CS-300 so this was a great reintroduction to the concepts and I found myself quickly able settle in and code what was needed to add the desired enhancement.

## <code style="color : green">5. Databases: Artifact 3</code>
[Click here to navigate to Artifact 3 Source Code](https://github.com/MrGibz/MrGibz.github.io.git)

Course Info Table created using SQLite library:

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/9cd8ca11-3ca1-4e8a-823b-ec7def4120cc)

Create, Read, Update, Delete functionality:

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/612d8007-07a9-4f38-9c8a-cb9d3d859e9f)

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/39886907-e21c-4c84-bba7-b50115374ed8)

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/7950aa4f-f609-417f-9bd8-ce267badd7d6)

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/ae4335e2-ea52-4ec3-b55f-91f5ef6b93b9)

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/71691fc4-3f0c-468a-869a-eef029fca363)

![image](https://github.com/MrGibz/MrGibz.github.io/assets/66959283/8e6653e1-7b74-471b-b3aa-b9c33fa8756d)

This artifact is project two from the CS-300 Data Structures and Algorithms course. In this project, we load course information from a .txt file into a Binary Search Tree and then perform sorting algorithms and search functions on the nodes of the BST. My enhancement to this artifact is an algorithm that conducts a sort of the BST in reverse alphabetic order. I am including this artifact in my ePortfolio because I believe that it demonstrates fundamental understanding of how essential algorithms are built and how they can be used with a BST. Additionally, I utilize the concept of recursion to call the algorithm multiple times within itself to achieve the desired result. I am excited to be able to show knowledge of algorithms, data structures, and recursion all in a simple, effective program like this one.

I meet the course objectives that I intended to meet with this artifact enhancement. I believe I even exceed them by utilizing recursion in my algorithm as well. This is a useful enhancement that shows an understanding of potential user requirements that is useful in the field of computer science where you are developing to a customer’s needs. In this instance, there was no way to sort the courses from Z to A. I added this functionality because if there is a database of 300 courses, you might want to have that capability. I also utilize secure coding practices by having a private inReverseOrder() function and a public InReverseOrder() function that calls on inReverseOrder() to perform the sort. This further shows my ability to execute efficient, secure coding to perform a function.

When I initially set out to enhance this artifact, I was nervous that writing this algorithm would be challenging. I decided to think about my problem and did a search online for how to implement a reverse sort on a BST. I was able to read about different ways it can be implemented and was happy to see that it was very similar to an in order sort like that one that already existed in my code. The biggest challenge was trying to figure out what exactly I was trying to do with the reverse sort. I was certainly rusty on the lessons taught in CS-300 so this was a great reintroduction to the concepts and I found myself quickly able to settle in and code what was needed to add the desired enhancement.
