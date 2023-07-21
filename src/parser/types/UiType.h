#ifndef _UI_TYPE_H_
#define _UI_TYPE_H_

class UiType {
    public:
        typedef enum TYPE {
            NOOP = -2,
            MISSING = -1,
            IF,
            ELSE_IF,
            ELSE,
            FOR,
            ARI_END,
            LINE,
            CIRCLE,
            TEXT,
            RECTANGLE,
            COLOR
        } TYPE;
};

#endif // _UI_TYPE_H_