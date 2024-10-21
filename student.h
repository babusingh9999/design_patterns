#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class student{
    public:
        student(int id_i, std::string name_i);
        int get_id();
        std::string get_name();
        void set_id(int id_i);
        void set_name(std::string name_i);
    private:
        int id;
        std::string name;
};
class course{
    public:
        course(int id_i, std::string name_i, int credits_i);
        int get_id();
        std::string get_name();
        int get_credits();
        void set_id(int id_i);
        void set_name(std::string name_i);
        void set_credits(int credits_i);
    private:
        int id;
        std::string name;
        int credits;
};
class grade{
    public:
        grade(int studentid_i, int courseid_i, char gradevalue_i);
        int get_studentid();
        int get_courseid();
        char get_gradevalue();
        void set_studentid(int studentid_i);
        void set_courseid(int courseid_i);
        void set_gradevalue(int gradevalue_i);
    private:
        int studentid;
        int courseid;
        char gradevalue;
};

#endif // STUDENT_H