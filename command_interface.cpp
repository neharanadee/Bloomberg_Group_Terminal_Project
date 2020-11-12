#include <bits/stdc++.h>
#include "calendar.cpp"
#define DELIMITER "-------------------------------------------"
using namespace std;

class Test {

 public:
    void solve() {
        readAndDisplayStream();
    }

 private:
    Calendar *calendar = new Calendar();

    void add() {

        vector<string> listOfUsers, startTimeParts, endTimeParts, thisDayParts;
        string topic, token;
        string listUsersString, startTimeString, endTimeString, thisDayString;

        cout << "Welcome!\n Action: add a meeting\n\n";
	    cout << "please insert LIST OF USERS:\n";
	    getline(cin, listUsersString);
        istringstream ss(listUsersString);
        
        while (getline(ss, token, ',')) {
            listOfUsers.push_back(token);
        }

	    cout << "please insert DAY:\n";
        getline(cin, thisDayString);

        istringstream ssday(thisDayString);
        
        while (getline(ssday, token, '.')) {
            thisDayParts.push_back(token);
        }

        CDay thisDay(stoi(thisDayParts[0]), stoi(thisDayParts[1]));

	    cout << "please insert START TIME:\n";
	    getline(cin, startTimeString);

        istringstream sstime(startTimeString);
        
        while (getline(sstime, token, ':')) {
            startTimeParts.push_back(token);
        }

        Time startTime(stoi(startTimeParts[0]), stoi(startTimeParts[1]));
        
        cout <<"please insert END TIME:\n";
	    getline(cin, endTimeString);

        istringstream sstime2(endTimeString);
        
        while (getline(sstime2, token, ':')) {
            endTimeParts.push_back(token);
        }

        Time endTime(stoi(endTimeParts[0]), stoi(endTimeParts[1]));

        cout <<"please insert TOPIC:\n";
	    getline(cin, topic);

        calendar->addMeeting(listOfUsers, startTime, endTime, topic, thisDay);
        cout << endl << DELIMITER << endl;
    }

    void displayDay() {
        string userID;

        cout << "Welcome!\n Action: display a user's current day\n\n";
	    cout << "please insert USER ID:\n";
	    getline(cin, userID);

        calendar->displayUsersDay(userID);
        cout << endl << DELIMITER << endl;
    }

    void displayGivenDay() {
        string userID;
        string dayString, token;
        vector<string> dayParts;

        cout << "Welcome!\n Action: display a user's day of choice\n\n";
	    cout << "please insert USER ID:\n";
	    getline(cin, userID);

	    cout << "please insert DAY and MONTH:\n";
	    getline(cin, dayString);
        istringstream ss(dayString);

        while (getline(ss, token, '.')) {
            dayParts.push_back(token);
        }

        CDay chosenDay(stoi(dayParts[0]), stoi(dayParts[1]));

        calendar->displayUsersCalendarForGivenDay(userID, chosenDay);
        cout << endl << DELIMITER << endl; 
    }

    void timeSuggestion() {

        string organisingUser, token, dayString, timeIntervalString;
        string earliestTimeString, latestTimeString, calendarDayString;
        float timeInterval;
        vector<string> dayParts, earliestTimeParts, latestTimeParts;

        cout << "Welcome!\n Action: display time suggestions for a new meeting\n\n";
	    cout << "please insert ORGANISING USER ID:\n";
	    getline(cin, organisingUser);

        cout<< "please insert DAY and MONTH:\n";
        getline(cin, calendarDayString);

        istringstream ss(calendarDayString);

        while (getline(ss, token, '.')) {
            dayParts.push_back(token);
        }

        CDay calendarDay(stoi(dayParts[0]), stoi(dayParts[1]));

        cout << "please insert EARLIEST TIME:\n";
	    getline(cin, earliestTimeString);

        istringstream sstime(earliestTimeString);
        
        while (getline(sstime, token, ':')) {
            earliestTimeParts.push_back(token);
        }

        Time earliestTime(stoi(earliestTimeParts[0]), stoi(earliestTimeParts[1]));
        
        cout <<"please insert LATEST TIME:\n";
	    getline(cin, latestTimeString);

        istringstream sstime2(latestTimeString);
        
        while (getline(sstime2, token, ':')) {
            latestTimeParts.push_back(token);
        }

        Time latestTime(stoi(latestTimeParts[0]), stoi(latestTimeParts[1]));

        cout <<"please insert TIME INTERVAL:\n";
	    getline(cin, timeIntervalString);
        timeInterval = stof(timeIntervalString);

        calendar->meetingTimeSuggestion(organisingUser, calendarDay, earliestTime, latestTime, timeInterval);
        cout << endl << DELIMITER << endl;
    }

    void timeScheduler() {

        string listUsersString, dayString, token, timeIntervalString;
        string earliestTimeString, latestTimeString, calendarDayString;
        float timeInterval;
        vector<string> listOfUsers, dayParts, earliestTimeParts, latestTimeParts;

        cout << "Welcome!\n Action: display time scheduler for a new meeting\n\n";
	    cout << "please insert LIST OF USERS:\n";
	    getline(cin, listUsersString);

        istringstream ss(listUsersString);
        
        while (getline(ss, token, ',')) {
            listOfUsers.push_back(token);
        }

        cout<< "please insert DAY and MONTH:\n";
        getline(cin, calendarDayString);
        istringstream ssDay(calendarDayString);

        while (getline(ssDay, token, '.')) {
            dayParts.push_back(token);
        }

        CDay calendarDay(stoi(dayParts[0]), stoi(dayParts[1]));

        cout << "please insert EARLIEST TIME:\n";
	    getline(cin, earliestTimeString);

        istringstream sstime(earliestTimeString);
        
        while (getline(sstime, token, ':')) {
            earliestTimeParts.push_back(token);
        }

        Time earliestTime(stoi(earliestTimeParts[0]), stoi(earliestTimeParts[1]));
        
        cout <<"please insert LATEST TIME:\n";
	    getline(cin, latestTimeString);

        istringstream sstime2(latestTimeString);
        
        while (getline(sstime2, token, ':')) {
            latestTimeParts.push_back(token);
        }

        Time latestTime(stoi(latestTimeParts[0]), stoi(latestTimeParts[1]));

        cout <<"please insert TIME INTERVAL:\n";
	    getline(cin, timeIntervalString);
        timeInterval = stof(timeIntervalString);

        calendar->meetingTimeScheduler(listOfUsers, calendarDay, earliestTime, latestTime, timeInterval);
        cout << endl << DELIMITER << endl;
    }

    void wrongCommand() {
        cout << endl << "WRONG COMMAND!" << endl << DELIMITER << endl;
    }

    // reads commands from stdin in real time
    void readAndDisplayStream() {
        bool notExit = 1;
        while (notExit) {
            string command;
            cout << "COMMAND: ";
		    getline(cin, command);
            transform(command.begin(), command.end(), command.begin(), ::tolower);
            if (command == "exit") {
				break;

            } else if (command == "add meeting") {
                add();

            } else if (command == "display day") {
                displayDay();

            } else if (command == "display given day") {
                displayGivenDay();
            
            } else if (command == "time suggestion") {
                timeSuggestion();
            
            }else if (command == "time scheduler") {
                timeScheduler();

            } else {
                wrongCommand();
            }
        }
    }
};


int main() {
    Test *test = new Test();
    test->solve();
    delete test;
    return 0;
}