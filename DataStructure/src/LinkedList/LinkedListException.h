/* 
 * File:   LinkedListException.h
 * Author: 
 *
 * Created on May 21, 2015, 4:32 AM
 */

#ifndef LINKEDLISTEXCEPTION_H
#define	LINKEDLISTEXCEPTION_H

#include <exception>
#include <string>

//TODO refactor to make this more like built in exceptions
//TODO maybe create a separate exception class for each type of exception?

using std::exception;
using std::string;

class LinkedListException : public exception {
    public:
        LinkedListException(const string exceptionMessage) {
            message = exceptionMessage;
        }

        string GetMessage() const {
            return message;
        }

    private:
        string message;
};

#endif	/* LINKEDLISTEXCEPTION_H */

