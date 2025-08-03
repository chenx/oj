class Logger {
   unordered_map<string, int> m;
public:
   Logger() {}
  
   bool shouldPrintMessage(int timestamp, string message) {
       if (m.find(message) == m.end()) {
           m[message] = timestamp;
           return true;
       }
       if (timestamp - m[message] < 10) {
           return false;  // Note don’t update m[message] here
       }
       m[message] = timestamp;
       return true;
   }
};

/*
Design a logger system that receives a stream of messages along with their timestamps. 
Each unique message should only be printed at most every 10 seconds 
(i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

* Logger() Initializes the logger object.
* bool shouldPrintMessage(int timestamp, string message) 
  Returns true if the message should be printed in the given timestamp, otherwise returns false.
*/
