#include <iostream>
#include <vector>
#include <stack>

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TextEditor {
public:
    void datatyped(const std::string &data) {
        saveState();
        content += data;
        std::cout << "Data is : " << content << std::endl;
    }

    void save() {
        saveState(); // Save current content before saving it
        std::cout << "File saved with content : " << content << std::endl;
    }

    void undo() {
        if (!history.empty()) {
            std::cout << "Current content before undo: " << content << std::endl;
            content = history.top();
            history.pop();
            std::cout << "undo performed. Current content is now: " << content << std::endl;
        } else {
            std::cout << "<No state to undo> " << std::endl;
        }
    }

private:
    std::string content;
    std::stack<std::string> history;

    void saveState() {
        history.push(content); // Save the current state
    }
};

class TypeCommand : public Command {
public:
    TypeCommand(TextEditor &editor, const std::string &text)
        : editor(editor), text(text) {}

    void execute() {
        editor.datatyped(text);
    }

    void undo() {
        editor.undo();
    }

private:
    TextEditor &editor;
    const std::string &text;
};

class SaveCommand : public Command {
public:
    SaveCommand(TextEditor &editor)
        : editor(editor) {}

    void execute() {
        editor.save();
    }

    void undo() {
        std::cout << "cannot undo save." << std::endl;
    }

private:
    TextEditor &editor;
};

class CommandManager {
public:
    void executeCommand(Command *cmd) {
        cmd->execute();
        cmdhistory.push_back(cmd);
    }

    void undoLastCommand() {
        if (!cmdhistory.empty()) {
            cmdhistory.back()->undo();
            cmdhistory.pop_back();
        }
    }

private:
    std::vector<Command *> cmdhistory;
};

int main(int argc, const char* argv[]) {
    TextEditor editor;
    CommandManager commandmanager;

    Command *cmd1 = new TypeCommand(editor, "hello");
    Command *cmd2 = new TypeCommand(editor, " world");
    Command *save = new SaveCommand(editor);

    commandmanager.executeCommand(cmd1);
    commandmanager.executeCommand(cmd2);
    commandmanager.executeCommand(save);

    commandmanager.undoLastCommand(); // Undo save
    commandmanager.undoLastCommand(); // Undo last type command
    commandmanager.undoLastCommand(); // Undo first type command

    // Clean up
    delete cmd1;
    delete cmd2;
    delete save;

    return 0;
}
