Imagine you work at a company that creates polling software, and you've been
asked to recommend which language to use to implement a new project on
approval voting.
Your task is to implement the same program using three different
programming languages, and write a report comparing the three different
implementations.

The Program
Approval voting is a kind of
voting where voters "approve" of any number of candidates. In traditional
first past the post
voting, a voter
picks their one favorite candidate, but in approval voting they can pick any
number of candidates. In approval voting, voting for a candidate is called
approving of that candidate.
For example, suppose candidates A, B, C and D are running in an election for
president. Assume there are 5 voters who each cast a ballot. An approval
voting ballot is a list of 0, or more, candidates. For example, the ballots
might look like this:

Ballot 1: A D B
Ballot 2: B
Ballot 3: B D B
Ballot 4: none
Ballot 5: A B C D

Here, ballot 1 approves of candidates A, C, and D, i.e. the voter who cast it
is okay with any of A, C, or D becoming president. Ballot 2 only approves of
candidate B. Ballot 3 approves of B and D, and B appears twice. When a
candidate appears more than once, only the first appearance is counted in the
final tally.
The order of candidates on a ballot doesn't matter. Different ballots
can approve of the same set of candidates.
Ballot 4 and 5 are special cases. Ballot 4 doesn't approve of anyone, and so
it is called an empty ballot. Ballot 5 is at the other extreme and
approves of everyone, and it's called a full ballot.
Ballots are counted by summing the total number of approvals for each
candidate. The final tally for the above ballots is:

A: 2
B: 4 (winner)
C: 1
D: 3

B is the winner because they have the most approvals. Note that even though
ballot 3 wrote B twice, it only counts as 1 approval for B.
Write a program that asks the user to enter the name of a text file of
ballots, called the ballot file. Each line of the ballot file consists of
one ballot formatted as a space-separated list of candidate names. For ballots
that have no approvals, the word "none" is given. You can assume the file is
non-empty, properly formatted, and has no blank lines or unnecessary
characters. A candidates name can be any non-empty string of alphabetic
letters other than "none".
Your program should read the input file, and print the name and counts for
each candidate on the screen in order from most ballots to least ballots. In
addition, it should also print a count of how many ballots where empty
(i.e. approved of no one), and how many ballots were full (i.e. approved
of everyone).
For example, the ballots in the example above could be written in a text file
named example5.txt like this:
A B D
B
B D B
none
A B C D
When your program runs its output  should look something like this:
What is the name of the ballot file?
example5.txt

Total # of ballots: 5

B: 4
D: 3
A: 2
C: 1

empty: 1
full: 1
Your program should work with ballot files that contains millions of
ballots, and any number of candidates. Some sample ballot files are provided:
example5.txt, example10.txt,
example100.txt, example100000.txt.

Languages
The three languages you must use are:


Racket. Put your Racket implementation in
final_project.rkt. If you want to, you can use
miniKanren, but it's not required. Include a function named main that can
be called in the interpreter to run your program.


Haskell. Put your Haskell implementation in
final_project.hs. Include a function named main that
can be called in the interpreter to run your program.
As part of your Haskell program, include type signatures for all functions.


A popular mainstream language that you already know, such as C, C++, or
Python. Put this in a file named final_project.???, where ??? depends
on the name of the language you're using. Important: this language
must be freely available on Ubuntu Linux, and you must clearly tell the
markers how to compile and run the code.


Please stick to just built-in functions, or standard libraries. The one
exception to this is that you can use miniKanren with Racket if you like
(but it's not required).
You can use functions based on the ones in the notes if you like.
Important: cite the source of all code that you didn't entirely write
yourself. Put your citations in the source code as comments.

Written Report
Write a report that compares and contrasts your three implementations. Please
submit it as a PDF and call it final_report.pdf.
See report_outline.md for the format of the report.

What to Submit
Compress all these files into a single zip archive named final_report.zip:


final_report.hs, final_report.rkt, and the file for your third
implementation.


Include any sample data files you used to help test your programs.


final_report.pdf


Submit final_report.zip on Canvas when you're done.
