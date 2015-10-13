# Introduction

Your second assignment is to expand on the classes assignment. The
assignment is due on October 24, 2015. You need to submit a pull
request on a topic branch with your firstname<sub>lastname</sub>.  You must
create three directories build, src and lib. All of your header files
should be in the lib directory. Each class should have a seperate
header file.  You should also submit a an executable file in the build 
directory.

The **Prisoner** Inheritance has a Hierarchy of 3 classes/

-   The base case is **Prisoner**
    -   A prisoner has a firstName
    -   A prisoner has a lastName
    -   Each member has a unique corrections id of the form <xxx-xxxxx>
        where x is an integer.
    -   Data members called **sentance**,\*timeServed\* and **timeRemain**
    -   A member function called **credit** to give each prisoner good time
        for time served without an infraction.
    -   A member function called **debit** to peanalize the inmates for
        fighting.
    -   A member function **getTimeRemain** to get the time remaining
    -   A member function **reSentance** to reinitialize the prisoner's
        time owed.

The class **Jailed** is a class derived from **Prisoner**

-   Good time is calculated as the minimum whole day the rate percent
    of months served.
-   An additional type of double indicating the good time rate.
-   A constructor that received the original sentence, the time served
    and the good time rate.
-   A member function calculateGoodTime that returns an int indicating
    the amount of good time earned. The Function should not change the
    time served or the time remaining.
-   A member function setGoodTimeRage to reset the good time rate.
-   A member function getGoodTimeRage to get the good time rate.

The class **Parolee** is a class derived from **Prisoner**

-   A **Jailed** person is destroyed and a parolee constructed when time
    remaining <= 0.
-   The term of parole is floor(.33 \* orginal sentence)

Use the data attached to test your classes.  Write a main function to
test your classes.  For the **Jailed** class calculate good time and
apply it to time served. Overwrite the stream operator and write a
function that prints the prisoners' number, firstName, lastName,
sentence, timeServed and TimeRemaining each on a separate line.

The Justice Department just released 6,000 prisoners:

<https://www.washingtonpost.com/world/national-security/justice-department-about-to-free-6000-prisoners-largest-one-time-release/2015/10/06/961f4c9a-6ba2-11e5-aa5b-f78a98956699_story.html>

Use the data attached to impliment a priority queue to figure out the
six prisoners you will need to release.  You can use an array based
priority queue if you don't want to impliment a heap.  What is the
loss in termps of Big O notation?

Print them out.