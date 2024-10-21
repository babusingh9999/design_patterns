#include "student.h"

student::student(int id_i, std::string name_i){
    id = id_i;
    name = name_i;
}

int student::get_id(){
    return id;
}

std::string student::get_name(){
    return name;
}

void student::set_id(int id_i){
    id = id_i;
}

void student::set_name(std::string name_i){
    name=name_i;
}

course::course(int id_i, std::string name_i, int credits_i){
    id = id_i;
    name=name_i;
    credits=credits_i;
}

int course::get_id(){
    return id;
}

std::string course::get_name(){
    return name;
}

int course::get_credits(){
    return credits;
}

void course::set_id(int id_i){
    id = id_i;
}

void course::set_name(std::string name_i){
    name = name_i;
}

void course::set_credits(int credits_i){
    credits = credits_i;
}

grade::grade(int studentid_i, int courseid_i, char gradevalue_i){
    studentid = studentid_i;
    courseid = courseid_i;
    gradevalue = gradevalue_i;
}

int grade::get_studentid(){
    return studentid;
}

int grade::get_courseid(){
    return courseid;
}

char grade::get_gradevalue(){
    return gradevalue;
}

void grade::set_studentid(int studentid_i){
    studentid = studentid_i;
}

void grade::set_courseid(int courseid_i){
    courseid = courseid_i;
}

void grade::set_gradevalue(int gradevalue_i){
    gradevalue = gradevalue_i;
}
