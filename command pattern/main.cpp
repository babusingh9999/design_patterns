#include <iostream>

class TextEditor{
    private:
        std::string content;
    public:
        void datatyped(const std::string &data){
            content += data;
            std::cout<<"Data is : "<<data<<std::endl;
        }
        void save(){
            std::cout<<"File saved with content : "<<content<<std::endl;
        }
        void undo(){
            std::cout<<"clearing the content : "<<content<<std::endl;
            content.clear();
        }
};

int main(int argc, const char *argv[]){
    TextEditor te;
    te.datatyped("Hello");
    te.datatyped("world!");
    te.datatyped("phone!");
    te.save();
    te.undo();
    return 0;
}