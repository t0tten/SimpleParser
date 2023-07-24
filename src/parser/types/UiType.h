#ifndef _UI_TYPE_H_
#define _UI_TYPE_H_

class UiType {
    public:
        typedef enum TYPE {
            NOOP = -2,              
            MISSING = -1,
            IF,             // 0
            ELSE_IF,        // 1
            ELSE,           // 2
            FOR,            // 3
            ARI_END,        // 4
            LINE,           // 5
            CIRCLE,         // 6
            TEXT,           // 7
            RECTANGLE,      // 8
            COLOR,          // 9
            CLOCK,          // 10
            CLOCK_FULL,     // 11
            CLOCK_HOUR,     // 12
            CLOCK_MIN,      // 13
            CLOCK_SEC,      // 14
            STRING,         // 15
            BOOLEAN_TRUE,   // 16
            BOOLEAN_FALSE,  // 17
            HEART,          // 18
            BT,             // 19
            DATE,           // 20
            DATE_FULL,      // 21
            DATE_FULL_YEAR, // 22
            DATE_YEAR,      // 23
            DATE_MONTH,     // 24
            DATE_DAY,       // 25
            STEPS,          // 26
            BATT,           // 27
            INDEX           // 28
        } TYPE;
};

#endif // _UI_TYPE_H_