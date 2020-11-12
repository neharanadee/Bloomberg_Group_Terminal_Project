#include <bits/stdc++.h>
using namespace std;

class Time {

 public:
    int hour;
    int minute;

    Time() {
    }

    //any constructor
    Time(int hour, int minute) {
        this->hour = hour;
        this->minute = minute;
    }

    //copy constructor
    Time(const Time& initTime) {
        this->hour = initTime.hour;
        this->minute = initTime.minute;
    }

    //copy assignment
    Time& operator=(const Time& initTime) {
        this->hour = initTime.hour;
        this->minute = initTime.minute;   
        return *this;    
    }

    //Destructor
    ~Time(){
    }
};


class CDay {

 public:
    int day;
    int month;
    int year;

    CDay () {
    }
    //any constructor
    CDay (int day, int month) {
        
        this->day = day;
        this->month = month;
        this->year = 2020;
    }

    //copy constructor
    CDay( const CDay& initDay) {
        
        this->day = initDay.day;
        this->month = initDay.month;
        this->year = initDay.year;
    }

    //copy assignment
    CDay& operator=(const CDay& initDay) {
        this->day = initDay.day;
        this->month = initDay.month;
        this->year = initDay.year;
        return *this;
    }

//   Destructor   
   ~CDay() {
   }
};

class Meeting {

 public:
    
    CDay day;
    Time startTime;
    Time endTime;
    string topic;

    //any constructor
    Meeting() {
    }

    Meeting(Time startTime, Time endTime, string topic, CDay day) {
        
        this->day = day;
        this->startTime = startTime;
        this->endTime = endTime;
        this->topic = topic;
    }

    //copy constructor
    Meeting( const Meeting& initMeet) {
        
        this->day = initMeet.day;
        this->startTime = initMeet.startTime;
        this->endTime = initMeet.endTime;
        this->topic = initMeet.topic;
    }

    //copy assignment
    Meeting& operator=(const Meeting& initMeet) {

        this->day = initMeet.day;
        this->startTime = initMeet.startTime;
        this->endTime = initMeet.endTime;
        this->topic = initMeet.topic;
        return *this;
    }

//    Destructor
    ~Meeting() {  
    }

};

static bool compare(Meeting m1, Meeting m2) {
    if(m1.day.month == m2.day.month) {
        if(m1.day.day == m2.day.day) {
            if(m1.startTime.hour == m2.startTime.hour) {
                return m1.startTime.minute < m2.startTime.minute;
            }
            else {
                return m1.startTime.hour < m2.startTime.hour;
            }
        }
        else {
            return m1.day.day < m2.day.day;
        }
    }
    else {
        return m1.day.month < m2.day.month;
    }
}

class Calendar {

 private:

    unordered_map<string, vector<Meeting>> userMeetings;
    unordered_map<string, int> monthsConversion;
    unordered_map<int,string> minutesConversion;
 public: 

    void conversion() {
        monthsConversion["Jan"] = 1;
        monthsConversion["Feb"] = 2;
        monthsConversion["Mar"] = 3;
        monthsConversion["Apr"] = 4;
        monthsConversion["May"] = 5;
        monthsConversion["Jun"] = 6;
        monthsConversion["Jul"] = 7;
        monthsConversion["Aug"] = 8;
        monthsConversion["Sep"] = 9;
        monthsConversion["Oct"] = 10;
        monthsConversion["Nov"] = 11;
        monthsConversion["Dec"] = 12;

        minutesConversion[0] = "00";
        minutesConversion[1] = "01";
        minutesConversion[2] = "02";
        minutesConversion[3] = "03";
        minutesConversion[4] = "04";
        minutesConversion[5] = "05";
        minutesConversion[6] = "06";
        minutesConversion[7] = "07";
        minutesConversion[8] = "08";
        minutesConversion[9] = "09";

    }

    void addMeeting(vector<string> listOfUsers, Time startTime, Time endTime,
        string topic, CDay day) {
    
        Meeting newMeeting(startTime, endTime, topic, day);

        for (auto id : listOfUsers) {
            userMeetings[id].push_back(newMeeting);
        }
    }

    void formattedPrint(Time startTime, Time endTime) {

        conversion();
        if(startTime.hour < 10) {
            cout << minutesConversion[startTime.hour] << ":";
        }
        else {
            cout << startTime.hour << ":";
        }
        if(startTime.minute < 10) {
            cout << minutesConversion[startTime.minute] << "  -  ";
        }
        else {
            cout << startTime.minute << "  -  "; 
        }
        if(endTime.hour < 10) {
            cout << minutesConversion[endTime.hour] << ":";
        }
        else {
            cout << endTime.hour << ":";
        }
        if(endTime.minute < 10) {
            cout << minutesConversion[endTime.minute] << "\n\n";
        }
        else {
            cout << endTime.minute << "\n\n"; 
        }
    }

    void displayUsersDay(string userID) {
        
        conversion();
        
        string token;

        time_t rawtime;
        time(&rawtime);
        string currentTimeString = string(ctime(&rawtime));

        vector<string> currentTimeParts;

        istringstream sstime(currentTimeString);
        
        while (getline(sstime, token, ' ')) {
            currentTimeParts.push_back(token);
        }

        CDay currentDay(stoi(currentTimeParts[2]), monthsConversion[currentTimeParts[1]]);
        cout << "Meetings planned on " << currentDay.day << " " << currentTimeParts[1] << " for user with ID " << userID << "\n\n";
            
        vector<Meeting> meets = userMeetings[userID];
        sort(meets.begin(), meets.end(), compare);
        
        for (auto currMeeting : meets) {
            if( currMeeting.day.day == currentDay.day && currMeeting.day.month == currentDay.month) {
                formattedPrint(currMeeting.startTime, currMeeting.endTime);
            }
        } 
    }

    void displayUsersCalendarForGivenDay(string userID, CDay calendarDay) {

        cout << "Meetings planned on << calendarDay.day" << "." << calendarDay.month << "for user with ID " << userID << "\n\n";

        conversion();
        vector<Meeting> meets = userMeetings[userID];
        sort(meets.begin(), meets.end(), compare);
        
        for (auto currMeeting : meets) {

            if( currMeeting.day.day == calendarDay.day && currMeeting.day.month == calendarDay.month) {

                formattedPrint(currMeeting.startTime, currMeeting.endTime);
            }
             
        }
    
    }

    string timeToString(int startHour, int startMinute, int endHour, int endMinute){
        
        string finalString;
        vector<int> elements{startHour, startMinute, endHour, endMinute};
        
        for(auto elem : elements) {
            finalString.append(to_string(elem));
            finalString.append(".");
        }


        return finalString;
    }

    void findMeetingInterval(vector<string> listOfUsers, CDay calendarDay, Time earliestTime, Time latestTime, float timeInterval, set<string> &foundIntervals) {

        vector<int> halfHours(48,0);

        for(auto user : listOfUsers) {

            vector<Meeting> meetsForThisDay;

            for( auto meet : userMeetings[user]) {
                if(meet.day.day == calendarDay.day && meet.day.month == calendarDay.month) {
                    meetsForThisDay.push_back(meet);
                }
            }      

            for(auto meet : meetsForThisDay) {
                int startpos = meet.startTime.hour * 2;
                if(meet.startTime.minute == 30) {
                    startpos++;
                }
                int endpos = meet.endTime.hour*2;
                if(meet.endTime.minute == 30) {
                    endpos++;
                }

                for(int i = startpos; i < endpos; i++) {
                    halfHours[i]++;
                }
            }

        }

        int earliest = earliestTime.hour * 2;
        if(earliestTime.minute == 30) {
            earliest++;
        }

        int latest = latestTime.hour * 2;
        if(latestTime.minute == 30) {
                latest++;
        }
        int interval = (int)(timeInterval / 0.5);

        int countInterval = 0;

        for(int i = earliest; i < latest; i++) {
            if(halfHours[i] == 0) {
                for(int j = 0; j < interval && ((i + j) < latest); j++) {
                    if(halfHours[i + j] == 0) {
                        countInterval++;
                    }
                }
        
                if(countInterval == interval) {

                    int newStartHour, newStartMinute, newEndHour, newEndMinute;
                    int aux = i;
                    if(aux % 2 == 1) {
                        aux -= 1;
                        newStartMinute = 30;
                    }
                    else {
                        newStartMinute = 0;
                    }
                    newStartHour = aux/2;

                    int lateval = i + countInterval;
                    if(lateval % 2 == 1) {
                        lateval -= 1;
                        newEndMinute = 30;
                    }
                    else {
                        newEndMinute  = 0;
                    }
                    newEndHour = lateval/2;

                    string newSlot = timeToString(newStartHour, newStartMinute, newEndHour, newEndMinute);
                    cout << "adaugam intervalul i:" << i  << " " << newSlot << endl;
                    foundIntervals.insert(newSlot);
                }
                countInterval = 0;
            }
        }
    }

    void meetingTimeSuggestion(string organisingUser, CDay calendarDay, Time earliestTime, Time latestTime, float timeInterval) {

        set<string> foundIntervals;
        vector<string> listOfUsers;
        listOfUsers.push_back(organisingUser);
        findMeetingInterval(listOfUsers, calendarDay, earliestTime, latestTime, timeInterval, foundIntervals);

        if(foundIntervals.empty()) {
            cout << "Sorry, there are no available intervals";
        }
        else {
            cout<< "We have found these free intervals:\n";
             for(auto interval : foundIntervals) {
                
                vector<string> intervalParts;
                string itoken;

                istringstream sstime3(interval);
        
                while (getline(sstime3, itoken, '.')) {
                intervalParts.push_back(itoken);
                }

                Time intStart(stoi(intervalParts[0]), stoi(intervalParts[1]));
                Time intEnd(stoi(intervalParts[2]), stoi(intervalParts[3]));
                formattedPrint(intStart, intEnd);
 
             }
        } 
    }

    void meetingTimeScheduler(vector<string> listOfUsers, CDay calendarDay, Time earliestTime, Time latestTime, float timeInterval) {

        set<string> foundCommonIntervals;

        findMeetingInterval(listOfUsers, calendarDay, earliestTime, latestTime, timeInterval, foundCommonIntervals);

        if(foundCommonIntervals.empty()) {
            cout << "Sorry, there are no available intervals";
        }
        else {
            cout<< "We have found these free intervals:\n";
             for(auto interval : foundCommonIntervals) {
                
                vector<string> intervalParts;
                string itoken;

                istringstream sstime3(interval);
        
                while (getline(sstime3, itoken, '.')) {
                intervalParts.push_back(itoken);
                }

                Time intStart(stoi(intervalParts[0]), stoi(intervalParts[1]));
                Time intEnd(stoi(intervalParts[2]), stoi(intervalParts[3]));
                formattedPrint(intStart, intEnd);
 
             }
        } 
    }


    //any constructor
    Calendar() {
    }

    Calendar(unordered_map<string, vector<Meeting>> userMeetings) {
        this->userMeetings = userMeetings;
        conversion();
    }

    //copy constructor
    Calendar(const Calendar& initCalendar) {

        this->userMeetings = initCalendar.userMeetings;
    }

    //copy assignment
    Calendar& operator=(const Calendar& initCalendar) {

        this->userMeetings = initCalendar.userMeetings;
        return *this;
    }

//    Destructor
    ~Calendar() {     
    }

};
