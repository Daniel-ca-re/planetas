#ifndef TXTINFO_H
#define TXTINFO_H
#include <list>
#include <array>
#include <vector>


class txtinfo
{
private:
    std::string txt;

public:
    txtinfo();
    txtinfo(std::string donde);
    std:: list < std::vector <float> > info;
    void addnewinfo(float masa, float px, float py, float vx, float vy);
    std::array<float,2> getarray(int i, int ii);
    void saveinfo();
    void add_new_info(std::vector <float> x);

};

#endif // TXTINFO_H
