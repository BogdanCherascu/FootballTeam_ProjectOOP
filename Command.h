#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual void executa() const = 0;
    virtual ~Command() = default;
};


#endif //COMMAND_H
